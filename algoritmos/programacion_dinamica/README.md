### Aqui se encuentran todas las descripciones de Programacion Dinamica

# Cutting Rod

## Que es?

El problema de cutting rod consiste en tomar una vara de una longitud determinada e ir realizando cortes que nos permitan obtener la mayor ganancia posible. 
Cada corte podra ser vendido por un precio indicado en un arreglo. De esta manera, al igual que el problema de la mochila, trataremos de maximizar la rentabilidad
realizando los cortes mas adecuados con la restriccion del precio.

## Como funciona?

Para poder codificar, crearemos un arreglo `dp[INT_MAX]` el cual ira guardando los resultados comparados para entregar la ganancia maxima. El proceso consiste en
verificar primero si llegamos al caso base y luego si ya se hizo el corte de un tamanho especifico. Despues recorremos un arreglo de tipos de cortes `length[]` el 
cual nos ayudara a cortar la barra, comprobando la rentabilidad maxima que se pueda obtener de la siguiente manera:
```
int gananciaMaxima = -1;
        for(int i = 0; i < sizeof(length)/sizeof(length[0]); i++) { 
            if(tamanioBarra >= length[i]) { 
                gananciaMaxima = max(gananciaMaxima,precios[i] + solve_dp(tamanioBarra - length[i]));
            }
        }
        dp[tamanioBarra] = gananciaMaxima;
```
Finalmente, en el dp[i] donde i es el largo de la barra, obtendremos la rentabilidad maximizada.

# Digit DP

## Que es?

El digit dp es un metodo que utlizamos para recorrer intervalos grandes entre dos numeros a y b. El objetivo es obtener informacion del intervalo. Por ejemplo, si 
desearamos saber cuantos numeros son multiplos de 9 entre a = 1 y b = 780, el iterar en el intervalo nos costaria O(n), lo cual puede ser un problema en casos donde n
es un valor elevado a la 18; el problema no podria ser resuelto en menos de un segundo. Para ello, implementamos programacion dinamica, la cual nos permite explorar
digito a digito y optimizando el tiempo de exploracion.

## Como funciona?

El digitDP en este caso necesitara un arreglo de 3 dimensiones `dp[20][2][20]`, donde primero guardamos la posicion en la que estamos (pensando en numeros grandes), 
luego colocamos si es mayor o no (valor booleano de 2 opciones) y finalmente colocamos la suma, residuo o lo que sea que deseemos guardar por cada digito. Lo importante
de este codigo, es que podemos alterar muy poco para ajustarlo a nuestras necesidades, especificamente en esta parte:
```
 if(pos == number.size()) {
        if(isPrime(sumaDigitos)) {
            return 1;
        }
        else {
            return 0;
        }
    }
```

# Edit Distance

## Que es?

Edit distance es una manera de poder determinar la cantidad de pasos que se deben utilizar como minimo para poder modificar una cadena de caracteres. Es posible utilizar
backtracking, pero la limitante de tamanho nos empuja a utilizar programacion dinamica. Teniendo un string "ABC" y para convertirlo a "AFDS", queremos saber cuantos pasos
son optimos. Las operaciones disponibles son editar, borrar o agregar un caracter. Para ello, se va recorriendo las posiciones, jugando con todas las opciones, donde editar
implica recorrer en ambas palabras un espacio atras; borrar implica recorrer un espacio atras en la palabra inicial; agregar implica recorrer un espacio atras en la palabra
segunda. El caso base se da cuando uno de los pivotes de las palabras llega a `-1`, en donde se calcula lo que falta agregar para terminar el proceso.

## Como funciona?

Las lineas de codigo clave son las que comprueban el caso base en cualquiera de los pivotes, y que van llenando el dp[] con los valores minimos obtenidos por rama y opcion
escogida (editar, borrar y agregar):
```
int solve(int posA, int posB) {
    if(posA == -1){
        return posB + 1;
    }
    if(posB == -1){
        return posA + 1;
    }
    if(dp[posA][posB] == -1){
        int minimoEditDistance = 100000000;
    
        // editar el caracter
        int sonDiferentes  = wordA[posA] != wordB[posB]; // True o False -> 1 o 0
        minimoEditDistance = min(minimoEditDistance,solve(posA-1, posB-1)+sonDiferentes);
        // eliminar el caracter
        minimoEditDistance = min(minimoEditDistance,solve(posA-1, posB)+1);
        // adicionar el caracter
        minimoEditDistance = min(minimoEditDistance,solve(posA, posB-1)+1);

        dp[posA][posB] = minimoEditDistance;
    }
    return dp[posA][posB];
}
```
