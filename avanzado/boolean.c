#include <string.h>
#include <stdio.h>
#define bool int
#define false 0
#define true 1

int op_preced(const char c) {
    switch (c) {
        case '|':
            return 6;
        case '&':
            return 5;
        case '!':
            return 4;
        case '*': case '/': case '%':
            return 3;
        case '+': case '-':
            return 2;
        case '=':
            return 1;
    }
    return 0;
}

bool op_left_assoc(const char c) {
    switch (c) {
            // left to right
        case '*': case '/': case '%': case '+': case '-': case '|': case '&':
            return true;
            // right to left
        case '=': case '!':
            return false;
    }
    return false;
}

unsigned int op_arg_count(const char c) {
    switch (c) {
        case '*': case '/': case '%': case '+': case '-': case '=': case '&': case '|':
            return 2;
        case '!':
            return 1;
        default:
            return c - 'A';
    }
    return 0;
}

#define is_operator(c)  (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=' || c == '&' || c == '|')
#define is_function(c)  (c >= 'A' && c <= 'Z')
#define is_ident(c)     ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))

//Funcion que recibe la expresion ingresada por el usuario
//Y el arreglo que servira para cambiar valores si cambian y no modificar
//Los datos de la entrada
bool shunting_yard(const char *input, char *output) {
    //Constantes que sirven para almacenar temporalmente el valor de la entrada
    //Y para saber el tamaño de la cadena
    const char *strpos = input, *strend = input + strlen(input);
    //Variables temporales para almacenar un caracter que se saque de la cadena
    //Y un arreglo que guardara al arreglo de salida
    char c, *outpos = output;

    //Pila que ira metiendo los caracteres de la expresion
    char stack[32]; // operator stack
    //Puntero de la pila
    unsigned int sl = 0; // stack length
    //Variable para almacenar dato por dato de la pila
    char sc; // used for record stack element

    //Se recorre laexpresion mientras tenga el mismo tamaño que la 
    //expresion de entrada
    while (strpos < strend) {
        // Lee uno a uno el valor de la expresion
        c = *strpos;
        //Compara si es diferente de vacio
        if (c != ' ') {
            // If the token is a number (identifier), then add it to the output queue.
            //Valida si es un numero
            if (is_ident(c)) {
                //Almacena el valor en el arreglo de salida
                *outpos = c;
                //Aumenta el controlador del while
                ++outpos;
            }// If the token is a function token, then push it onto the stack.
            //Si son mayusculas
            else if (is_function(c)) {
                //Almacena el valor en la pila
                stack[sl] = c;
                //Aumenta el puntero de la pila
                ++sl;
            }// If the token is a function argument separator (e.g., a comma):
            //Si tiene una coma
            else if (c == ',') {
                //Se desactiva una bandera para tener el control
                bool pe = false;
                //Mientras existan elementos en la pila
                while (sl > 0) {
                    //Pasamos el dato de la pila a la variable sc
                    sc = stack[sl - 1];
                    //Si es parentesis que abre
                    if (sc == '(') {
                        //Activamos la bandera control
                        pe = true;
                        break;
                    } else {
                        //Si al principio de la pila hay un parentesis, se 
                        //sacan los operadores y se almacenan en el arreglo outpos
                        // Until the token at the top of the stack is a left parenthesis,
                        // pop operators off the stack onto the output queue.
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
                // If no left parentheses are encountered, either the separator was misplaced
                // or parentheses were mismatched.
                //Si despues o antes de un parentesis hay un espacio, se manda un error
                if (!pe) {
                    //Mensage de error
                    printf("Error: separator or parentheses mismatched\n");
                    //Falso
                    return false;
                }
            }// If the token is an operator, op1, then:
            //Si es un operador
            else if (is_operator(c)) {
                //Si el puntero es mayor a cero, quere decir que si hay elementos a recorrer
                while (sl > 0) {
                    //Se saca de la pila el valor
                    sc = stack[sl - 1];
                    
                    //Se evalua el valor de los operadores en su respectiva funcion
                    if (is_operator(sc) &&
                            ((op_left_assoc(c) && (op_preced(c) >= op_preced(sc))) ||
                            (op_preced(c) > op_preced(sc)))) {
                        // Pop op2 off the stack, onto the output queue;
                        //Almacenamos el operador
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    } else {
                        break;
                    }
                }
                //Metemos el operador a la pila
                // push op1 onto the stack.
                stack[sl] = c;
                //Aumentamos el indice de la pila
                ++sl;
            }// If the token is a left parenthesis, then push it onto the stack.
            
            //Si el caracter a evaluar es parentesis que abre
            else if (c == '(') {
                //Lo guardamos en la variable c
                stack[sl] = c;
                //Aumentamos el puntero
                ++sl;
            }// If the token is a right parenthesis:
            //Si es parentesis que cierra
            else if (c == ')') {
                //Desactivamos la bandera
                bool pe = false;
                // Until the token at the top of the stack is a left parenthesis,
                // pop operators off the stack onto the output queue
                //Mientras en la pila exista parentesis que cierra
                while (sl > 0) {
                    //Se saca el valor de la pila
                    sc = stack[sl - 1];
                    //Si es un parentesis que abre
                    if (sc == '(') {
                        //Se activa la bandera
                        pe = true;
                        break;
                        //Si no, se guarda el valor en el arreglo outpos
                    } else {
                        *outpos = sc;
                        //aumenta el puntero del arreglo
                        ++outpos;
                        //Disminuye la pila
                        sl--;
                    }
                }
                // If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
                if (!pe) {
                    printf("Error: parentheses mismatched\n");
                    return false;
                }
                // Pop the left parenthesis from the stack, but not onto the output queue.
                sl--;
                // If the token at the top of the stack is a function token, pop it onto the output queue.
                if (sl > 0) {
                    sc = stack[sl - 1];
                    if (is_function(sc)) {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
            } else {
                printf("Unknown token %c\n", c);
                return false; // Unknown token
            }
        }
        ++strpos;
    }
    // When there are no more tokens to read:
    // While there are still operator tokens in the stack:
    while (sl > 0) {
        sc = stack[sl - 1];
        if (sc == '(' || sc == ')') {
            printf("Error: parentheses mismatched\n");
            return false;
        }
        *outpos = sc;
        ++outpos;
        --sl;
    }
    *outpos = 0; // Null terminator
    return true;
}

//Funcion que evalua la expresion ingresada por el usuario
//Y retorna un valor booleano
bool evalBoolExpr(char * expr) {
    //Arreglo de caracteres que recibe el que viene como parametro
    char output[500] = {0};
    //Arreglo temporal para ir guardando los operadores
    char *op;
    //Variable booleana que cambiara segun las comparaciones y sera la que
    //se retornara en la funcion
    bool tmp;
    //Arreglos que dividen la expresion en partes para evaluar de un lado y otro
    char part1[250], part2[250];

    //Funcion que se le envia la expresion y el arreglo de salida
    //Para almacenar algo si se cambia en la funcion shunting_yard
    if (!shunting_yard(expr, output))
        return false; // oops can't convert to postfix form

    while (strlen(output) > 1) {
        op = &output[0];
        while (!is_operator(*op) && *op != '\0')
            op++;
        if (*op == '\0') {
            return false; // oops - zero operators found
        } else if (*op == '!') {
            tmp = !(*(op - 1) - 48);
            *(op - 1) = '\0';
        } else if (*op == '&') {
            tmp = (*(op - 1) - 48) && (*(op - 2) - 48);
            *(op - 2) = '\0';
        } else if (*op == '|') {
            tmp = (*(op - 1) - 48) || (*(op - 2) - 48);
            *(op - 2) = '\0';
        }

        memset(part1, 0, sizeof (part1));
        memset(part2, 0, sizeof (part2));
        strcpy(part1, output);
        strcpy(part2, op + 1);
        memset(output, 0, sizeof (output));
        strcat(output, part1);
        strcat(output, ((tmp == false) ? "0" : "1"));
        strcat(output, part2);
    }
    return *output - 48;
}

int main() {
    
    //Arreglo de dos pocisiones para indicar si es V|F
    char * boolString[2] = {"FALSE", "TRUE"};
    
    //Arreglo para pedir la entrada del usuario
    char expr[100];
    //Arreglo para convertir la entrada del usuario en unos y ceros
    //y luego en la salida en V y F
    char expr2[100];
    printf("Enter expression: ");//Pides un dato
    scanf("%s", expr);//Escribes un dato

    int i,j;//contadores del for
    
    //Recorres el arreglo ingresado por el usuario, para pasarle su valor
    //a un arreglo temporal que sera el de salida
    for (j = 0; j < 100; j++) {
    expr2[j] = expr[j];
    }
    
    //Validas si es una V se cambia el valor a 1
    //Si es una F se cambia el valor a 0
    for (i = 0; i < 100; i++) {
        if (expr[i] == 'V') {
            expr[i] = '1';
        }
        if (expr[i] == 'F') {
            expr[i] = '0';
        }
    }

    //Se manda el arreglo a la funcion que retorna un valor booleano
    //y lo almacena en la variable result
    bool result = evalBoolExpr(expr);
    //Imprimes el resultado, enviando dos parametros de salida:
    //La expresion para que se muestre la cadena ingresada por el usuario
    //Y el arreglo booString que dependiendo de la expresion, dira si es true o false
    printf("Boolean expr. %s is %s", expr2, boolString[result]);
    return 0;
}