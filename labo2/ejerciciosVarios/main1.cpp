#include <iostream>

int main()
{
    int miVec[4]={1,2,3,4};
    int *pVec=miVec;

    for (int i = 0; i <4 ; i++)
    {
      printf("%i\n", *(pVec-- + 3));
    }
    
    getchar();
    return 0;

}