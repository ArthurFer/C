#include <stdio.h>
#include <math.h>
#define PI 3.14159

int main(){
//C = 2 x PI x r formula do cumprimento do circulo
  float perimetro, area;
  int raio;
  printf("Entre com o Raio do círculo\n");
  scanf("%d", &raio);
  perimetro = 2 * PI * raio;
  area = PI * pow (raio,2);
  printf("O perimetro da circunferência de raio %d é %.2f\n", raio, perimetro);
  printf("A área do círculo é %.2f\n", area);

}