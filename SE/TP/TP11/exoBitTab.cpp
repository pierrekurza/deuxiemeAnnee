#include <iostream>
#include <time.h>
#include <stdlib.h>
#define NB_VALUE (1<<28)
using namespace std;
int main()
{
    srand(time(NULL));

  unsigned int *tab = new unsigned int[NB_VALUE];
  for(int i = 0 ; i<NB_VALUE ; i++) tab[i] = rand();
  cout << "Initialization" << endl;

  unsigned int iteration = 0;
  while(iteration < 30)
    {
      iteration++;

      for(int i = 0 ; i<NB_VALUE ; i++)
        {
          if(tab[i]&1 == 0)
            {
              // on regarde si c'est une puissance de 2
              unsigned int j, v = 1;
              for(j = 0 ; j < (sizeof(unsigned int) * 8) ; j++)
                {
                  if(tab[i] == v) break;
                  v << 1;
                }

              // si j < (sizeof(unsigned int) * 8) alors c'est une puissance de 2
              if(j < (sizeof(unsigned int) * 8))
                {
                  v << 1;
                  tab[i] = tab[i] / v;
                }
            }else tab[i] = tab[i] + iteration;
        }
    }

  delete(tab);

}
