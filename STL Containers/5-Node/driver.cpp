#include "nodeD.h"
#include <iostream>

int main()
{
   Node <int> * n = NULL;
   insert(10, n);
   insert(20, n);
   insert(30, n);
   insert(40, n);
   insert(45, n, true);
   display(n);
   
   freeData(n);
   display(n);
   
   insert(10, n);
   insert(20, n);
   insert(30, n);
   insert(40, n);
   insert(45, n, true);
   display(n);
   
   return 0;
}
