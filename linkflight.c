#include "flight.h"

//菜单函数
int  menu (void)
{
      int n;
      printf ("1.录入信息\t2.查询信息\t3.显示信息\t4.退出\n请选择:");
      scanf ("%d",&n);
      return n;
}


//信息录入函数
void flight_writeinfo (link_plist h)
{
      int k;
      while (1)
      {
	    printf ("1.从终端输入\t2.从文件读取\t3.退出\n");
	    printf ("请选择:");
	    scanf ("%d",&k);
	    switch (k)
	    {
		  case 1:
			linklist_create(h);
			flight_store(h);
			break;
		  case 2:
			flight_output(h);
			linklist_show (h);

			break;
		  case 3:
			break;
		  default:
			printf ("您的输入有误!\n");
			break;
	    }
	    if (k==3)
		  break;
      }
}



//初始化单链表,空结点
void linklist_init(link_plist *H)                     
{
      *H = (link_plist)malloc(sizeof(link_list));
      if(NULL == *H)
      {
	    perror("malloc");
	    exit(1);
      }
      (*H)->next = NULL;
}

//录入信息函数（创建单向链表）
void  linklist_create(link_plist h)                              
{

      int n,i;     

      link_plist new,p = h;        


      printf("请问您要录入几条航班信息?\n请输入:");
      scanf("%d",&n);
      for(i = 0; i < n; i++)                                    
      {
	    new = (link_plist)malloc(sizeof(link_list));
	    if(NULL == new)
	    {
		  perror("malloc failed");
		  exit(1);
	    }

	    printf("请您按照以下顺序输入航班信息:\n1.航班号\t2.起点站\t3.终点站\t4.班期\t5.机型\t6.起飞时间\t7.到达时间\t8.票价\n请输入:\n");
	    scanf("%s%s%s%s%s%d%d%d",new->info.number,new->info.staddress,new->info.arraddress,new->info.DATE,new->info.TYPE,&new->info.stime,&new->info.atime,&new->info.value);

	    new->next=p->next;
	    p->next=new;
	    p=p->next;
      }
}

//把结构体数据写入流文件
void flight_store (link_plist h)
{
      link_plist t;
      char buf[SIZE];


      fp=fopen("flight.txt","a+");
      if (NULL==fp)
      {
	    perror ("fopen failed");
	    exit (1);
      }
      for (t = h->next;t !=NULL;t=t->next)
      {
	    bzero(buf,SIZE);
	    sprintf(buf,"%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",t->info.number,t->info.staddress,t->info.arraddress,t->info.DATE,t->info.TYPE,t->info.stime,t->info.atime,t->info.value);
	    fputs (buf,fp);
      }
      //  flcose(fp);
}



//查询信息函数
void flight_search(link_plist h)
{
      int j,price;
      link_plist t;
      char ch[18];

      while (1)
      {
	    printf ("1.航班号\t2.起点站\t3.终点站\t4.票价\t5.退出\n");
	    printf("请选择您要查询信息的编号:");
	    scanf ("%d",&j);
	    switch (j)
	    {
		  case 1:
			printf("请输入您要查询的航班号:");
			scanf ("%s",ch);
			for(t=h->next;t!=NULL;t=t->next)
			{
			      if (strcmp(t->info.number,ch)==0)
				    printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",t->info.number,t->info.staddress,t->info.arraddress,t->info.DATE,t->info.TYPE,t->info.stime,t->info.atime,t->info.value);
			}
			break;
		  case 2:
			printf("请输入您要查询的起点站:");
			scanf ("%s",ch);
			for(t=h->next;t!=NULL;t=t->next)
			{
			      if (strcmp(t->info.staddress,ch)==0)
				    printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",t->info.number,t->info.staddress,t->info.arraddress,t->info.DATE,t->info.TYPE,t->info.stime,t->info.atime,t->info.value);
			}
			break;
		  case 3:
			printf("请输入您要查询的终点站:");
			scanf ("%s",ch);
			for(t=h->next;t!=NULL;t=t->next)
			{
			      if (strcmp(t->info.arraddress,ch)==0)
				    printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",t->info.number,t->info.staddress,t->info.arraddress,t->info.DATE,t->info.TYPE,t->info.stime,t->info.atime,t->info.value);
			}
			break;
		  case 4:
			printf("请输入您要查询票价:");
			scanf ("%d",&price);
			for(t=h->next;t!=NULL;t=t->next)
			{
			      if (price == t->info.value)
				    printf("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",t->info.number,t->info.staddress,t->info.arraddress,t->info.DATE,t->info.TYPE,t->info.stime,t->info.atime,t->info.value);
			}
			break;
		  case 5:
			break;
		  default:
			{
			      printf ("您的输入有误!\n");
			      break;
			}
	    }
	    if (j==5)
		  break;
      }
}

//从流文件里读取数据
void  flight_output(link_plist h)
{
      link_plist t;
      char buf[SIZE];
      fp=fopen("flight.txt","r");
      if (NULL==fp)
      {
	    perror ("fopen failed");
	    exit (1);
      }
      for(t = h->next;t!=NULL;t=t->next)
      {
	    sscanf(buf,"%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",t->info.number,t->info.staddress,t->info.arraddress,t->info.DATE,t->info.TYPE,&t->info.stime,&t->info.atime,&t->info.value);
      }
}

//链表遍历函数
void linklist_show(link_plist h)
{
      link_plist t;
      for(t = h->next; t != NULL; t = t->next)
	    printf ("%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n",t->info.number,t->info.staddress,t->info.arraddress,t->info.DATE,t->info.TYPE,t->info.stime,t->info.atime,t->info.value);
}






     
     
     



#if 0
{
      char buf[10];
      int min;

#if 0
      scanf("%s",buf);
      min = fun1(buf);
      printf("min = %d\n",min);
#else
      scanf("%d",&min);
      fun2(min,buf);
      printf("%s\n",buf);
#endif
      return 0;

}
//将字符串时间转换成分钟返回
int fun1(char buf[])
{
      int hour,min;

      sscanf(buf,"%d:%d",&hour,&min);

      return hour * 60 + min;
}
//将分钟时间转换成字符串
void fun2(int time,char *buf)
{
      sprintf(buf,"%02d:%02d",time/60,time%60);
}

#endif

















