#include<stdio.h>
#include<string.h>

void soma(int *a, int *b, int *c);
long long conversor8(int*x);
long long conversor9(int*x);
void Adjust(int h[]);
long long p(int x, int y);

void main(void)
{
    int i, j=0, a1[8]={0,0,0,0,0,0,0,0}, a2[8]={0,0,0,0,0,0,0,0}, a3[9]={0,0,0,0,0,0,0,0,0}, op, op2;
    printf("Digite o Numero Binario a ser lido: ");
    Adjust(a1);
    printf("Digite o outro Numero Binario a ser lido: ");
    Adjust(a2);
    soma(a1, a2, a3);
    inicio:
    do{
        if(j>0)printf("Digite um valor entre 1 e 4");
        printf("\n\nDigite a opcao desejada:\n1 - Soma dos Binarios\n2 - Conversao para decimal\n3 - Releitura dos Binarios\n4 - Sair\n");
        fflush(stdin);
        scanf("%d", &op);
        j++;
    }while(op<1||op>4); j=0;
    switch(op)
    {
        case 1:
        printf("A soma do Primeiro Numero (");
        for(i=0;i<8;i++)printf("%d",a1[i]);printf(") com o Segundo Numero(");for(i=0;i<8;i++)printf("%d",a2[i]);
        printf(") resulta em: ");for(i=0;i<9;i++)printf("%d",a3[i]);
        goto inicio; break;
        case 2:do{
        if(j>0)printf("Digite um valor entre 1 e 3\n");
        printf("Digite qual binario converter:\n1 - Primeiro binario escrito\n2 - Segundo binario escrrito\n3 - Soma dos dois binarios\n");
        scanf("%d", &op2);
        j++;}
        while(op2<1||op2>3); j=0;
        switch(op2)
        {
            case 1:
            printf("\nO valor convertido e: %d", conversor8(a1)); break;
            case 2:
            printf("\nO valor convertido e: %d", conversor8(a2)); break;
            case 3:
            printf("\nO valor convertido e: %d", conversor9(a3)); break;
        }
        goto inicio; break;
        case 3:
        main(); break;
        case 4:
        return;
    }
    }

void Adjust(int *h)
{
char c[8];
int b[8];
int i, j=0,a=0, k, n;

  do{
     fflush(stdin);
     gets(c);
     k = strlen(c);
     for(i=0;i<k;i++){
        if(c[i]!='0' && c[i]!='1'){
            a++;
            break;}
        else a=0;}
     if(a>0)printf(" Digite novamente o numero binario. ");
 }while (a>0);

    for(i=0; i<k; i++)
    {
        if(c[i]==48)
        h[i]=0;
        else h[i]=1;
        }
    for(i=0;i<8;i++) b[i]=h[i];


  if(k<8)for(i=0; i<k;i++)
    {
        h[7-i]=b[k-i-1];
    }
    for(i=0; i<8-k;i++)
    {
        h[i]=0;
    }
}


void soma(int *a,int *b,int*c)
{
    int i;
    for(i=0;i<8;i++) c[i+1]=a[i]+b[i];
    for(i=8; i>=1; i--)
    {
        if(c[i]==3)
        {
            c[i]=1;
            c[i-1]+=1;
        }
        else if (c[i]==2)
        {
            c[i]=0;
            c[i-1]+=1;
        }
    }

}

long long conversor8(int*x)
{
   int i;
   long long y=0;
   for(i=0;i<8;i++){
       y=y + x[7-i]*p(2,i);}
    return y;

   }
long long conversor9(int*x)
{
   int i;
   long long y=0;
   for(i=0;i<9;i++){
       y=y + x[8-i]*p(2,i);}
    return y;

   }

long long p(int x, int y)
{
    int i;
    long long pot=1;
    for(i=1; i<=y; i++)
    {
        pot*=x;
    }
    if(y==0) return 1;
    else return pot;


}

