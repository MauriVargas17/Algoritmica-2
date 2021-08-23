# 8 queens
## Que es?

El problema de las 8 reinas consiste en conseguir la ubicacion de las piezas de ajedrez conocidas como reinas en un tablero de 8x8. Como conocemos, la reina en el ajedrez
tiene un comportamiento particular, en el que puede atacar de manera horizontal y diagonal, por lo cual colocar 8 reinas sin que estas se coman las unas a las otras 
es una tarea complicada. El codigo de este problema busca explorar por backtracking todas las opciones posibles hasta hallar la que le funcione y retornar un tablero con la 
solucion.

## Como funciona?

El codigo consiste en manejar un tablero `grid[][]` que almacene la solucion. Las funciones que usamos son `isValid()` que verifica si es valido colocar a una reina en una posicion especifica (es decir, que otra reina no puede comersela), despues tenemos al metodo `solveNQueen()` el cual usa el metodo anterior para verificar y recien colocar a la reina en la posicion de fila `i` y columna `col`; a continuacion, seguira verificando llamandose a si mismo. Si una solucion no es factible, el valor de esa casilla modificada volvera a ser 0 y se proseguira a explorar la fila siguiente. Si finalmente despues de explorar todas las opciones no se consigue una solucion, el metodo retorna 0:

```
bool solveNQueen(int board[N][N], int col) {
   if (col >= N) 
      return true;
   for (int i = 0; i < N; i++) { 
      if (isValid(board, i, col) ) {
         board[i][col] = 1; 
         if ( solveNQueen(board, col + 1)) 
            return true;
         board[i][col] = 0; 
      }
   }
   return false; 
}
```
