#include <stdio.h>
/*
int main(){
    int m=14;

    int *ptr=&m;
    int *ptr2=ptr+1;

    printf("%p\n",ptr);
    printf("%p\n",ptr2);

    printf("%d\n",*ptr);
    printf("%d\n",*ptr2);

    printf("%d\n",sizeof(*ptr2));
    printf("%d\n",sizeof(*ptr));
    
   
    return 0;
}*/
int * test() {

  static int x[4];

  for(int i=0;i<4;i++){

    x[i] = i%2;

  }

  return x;

} 

int main() {

  int * arr = test();

  printf("%d", *(arr+3));

  return 0;

}