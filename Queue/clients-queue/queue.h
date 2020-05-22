/*
 * =====================================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  Header file, declaration of types, new structure & functions
 *
          Author:  Fayssal404, 
 *   Organization:  
 *
 * =====================================================================================
 */

#define MALLOC(t)      ((t*)malloc(sizeof(t)))

typedef struct clfile
{
    Client c;
    struct clfile *next;
} Clfile;


typedef struct cfile {
    Clfile *head; //Pointor to queue head
    Clfile *tailp; //Pointor to permium client
    Clfile *tailc; //Pointor to classic client
} Queue;


Queue newqueue();
bool empty(Queue f);
Queue adjc(Queue f, Client c);
Queue supt(Queue f);


// Getter
Client head(Queue f);
Client tail(Queue f);
Client tailp(Queue f);
Queue adjc(Queue f, Client c);
Client isempty(Queue f);
