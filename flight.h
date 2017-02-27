#ifndef __FLIGHT_H__
#define __FLIGHT_H__


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>

//typedef struct datatype;
#define N 20
#define SIZE 200

typedef struct data 
{   
      char number[N];        
      char staddress[N];       
      char arraddress[N];    
      char DATE[N];           
      char TYPE[N];           
      int stime;           
      int atime; 
      int value;
}datatype;

typedef struct data datatype;
typedef struct linklist
{
      datatype info;
      struct linklist *next;
}link_list,*link_plist;

FILE *fp;

extern int menu ();
extern void flight_writeinfo(link_plist h);
extern void linklist_init(link_plist *H);
extern void  linklist_create(link_plist h);
extern void flight_store (link_plist h);
extern void flight_output(link_plist h);
extern void linklist_show (link_plist h);
extern void flight_search (link_plist h);

#endif


