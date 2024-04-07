#include <stdio.h>

int fatorial(int n){
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fatorial(n-1);
}

int main(){
    int n;
    printf("Fatorial de: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int result = fatorial(i);
        int controle = i +1;
        printf("Fatorial de %d! = %d x %d = %d\n", i +1, i+1, result, controle * result);        
        }
        
    return 0;
}