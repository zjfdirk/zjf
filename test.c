#include "flight.h"

int main (void)
{
      link_plist h;
      int i;
      linklist_init(&h);
      while (1)
      {
	    
	    i = menu();
	    switch (i)
		  {
			case 1:
			      flight_writeinfo(h);
			      break;
			case 2:
			      flight_output(h);
			      flight_search(h);
			      break;
			case 3:
			      flight_output(h);
			      linklist_show(h);
			      break;
			case 4:
			      break;
			default:
			      printf ("您的输入有误!");	
			      break;
		  }
	    if(i==4)
		  break;
      }
      printf ("\n");
      return 0;
}































