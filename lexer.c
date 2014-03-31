#include<stdio.h>
#include<malloc.h>
#include<string.h>

char INT[]="int";char FLOAT[]="float";char DOUBLE[]="double";char CHAR[]="char";
char buf[100],buf2[20];
int ide=0;
char kw[][20]={"return","if","else","void","return","do","while","printf","int","float","char","double"};

struct node
{
int id;
char name[50];
char dtype[50];
struct node *next;
}*start=NULL;


struct node *new_node,*current;
void insert()
{
  new_node=(struct node *)malloc(sizeof(struct node));
  new_node->id=++ide;
  (void)strcpy(new_node->dtype,buf2);
  (void)strcpy(new_node->name,buf);
  new_node->next=NULL;

  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }
 }
 
 int getid()
 {
 	int pos=0;
 	struct node *new_node;

 new_node=start;
 while(new_node!=NULL)
   {
  	if(!strcmp(new_node->name,buf))
  	{pos=1;break;}
   new_node=new_node->next;
   }
   return new_node->id;
 }
 int stable()
 {
 	int pos=0;
 	struct node *new_node;

 new_node=start;
 while(new_node!=NULL)
   {
  	if(!strcmp(new_node->name,buf))
  	{pos=1;break;}
   new_node=new_node->next;
   }
   if(pos==1)
   return 1;
   else 
   return 0;
   
 }
 int keyword()
{
int pos=0,i;
   for( i=0;i<12;i++)
   {
   	//printf("keyword comparison \n%s",kw[i]);
   	if(!strcmp(kw[i],buf))
   	{//printf("keyword comparison \n%s",kw[i]);
   	pos=1;break;}
   }
   if(pos==1)
   return 1;
   else 
   return 0;
}
 void display()
{
struct node *new_node;
 printf("The Linked List : \n");
 new_node=start;
 while(new_node!=NULL)
   {
   printf("%d, %s, %s\n",new_node->id,new_node->name,new_node->dtype);
   new_node=new_node->next;
   }
 
}


void main()
{
   FILE *fp,*fp2;int pos=1;
   int i=0,j=-1,rid;
   char *filename,*filename2,c,c2,rcid;
   filename="file1.txt";
   filename2="token_file";
   fp=fopen(filename,"r");
   fp2=fopen(filename2,"w");
   c=getc(fp);
   while(c!=EOF)
   {
   if(c>=97 && c<=122)
   {
   	i=0;
   	buf[i++]=c;
   	c=getc(fp);
   	while(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||(c>=97&&c<=122))
   	{
   	 
   	  buf[i++]=c;
   	   c=getc(fp);
   	}
   	buf[i]='\0';
   	if(!strcmp(INT,buf))
   	{(void)strcpy(buf2,INT);}
   	else if(!strcmp(FLOAT,buf))
   	(void)strcpy(buf2,FLOAT);
   	else if(!strcmp(CHAR,buf))
   	(void)strcpy(buf2,CHAR);
   	else if(!strcmp(DOUBLE,buf))
   	(void)strcpy(buf2,DOUBLE);
   	else
   	{
   	  if(!keyword() && !stable())
   	  insert();
   	  }
   	  
   	  
   	  if(keyword())
   	  {
   	  	putc('<', fp2);
   	  	fprintf(fp2,buf);
   	  	putc('>',fp2);
   	  	putc('\n',fp2);
   	  }
   	  else
   	   {
   	  	putc('<', fp2);
   	  	fprintf(fp2,"id-");
   	  	rid=getid()+48;
   	  	rcid=(char)rid;
   	  	putc(rid,fp2);
   	  	putc('>',fp2);
   	  	putc('\n',fp2);
   	  }
   }
   else
   {	if(!(c==' '||c=='\t'||c=='\n'))
   	{
   	  if(c=='='||c=='<'||c=='>'||c=='!')
   	  {	c2=getc(fp);
   	  	if(c2=='=')
   	  	{	
	   		putc('<', fp2);
			putc(c,fp2);
	   	  	putc('=',fp2);
	   	  	putc('>',fp2);
	   	  	putc('\n',fp2);
	   	  	c=getc(fp);
	   	 }
   	  	else
   	  	{	
	   		putc('<', fp2);
			putc(c,fp2);
	   	  	putc('>',fp2);
	   	  	putc('\n',fp2);
	   	  	c=c2;
	   	 }
	   	 
   	  }
   	  else if(c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9')
   	  {
		  putc('<', fp2);
		  //putc(c,fp2);
		  c2=getc(fp);
   	  	while(c2=='0'||c2=='1'||c2=='2'||c2=='3'||c2=='4'||c2=='5'||c2=='6'||c2=='7'||c2=='8'||c2=='9')
   	  	{
			//putc(c2,fp2);
			c2=getc(fp);
		}
		putc('n',fp2);
		putc('u',fp2);
		putc('m',fp2);
		putc('>',fp2);
   	  	putc('\n',fp2);
   	  	c=c2;
	  }
   	  else
   	  {	putc('<', fp2);
		putc(c,fp2);
   	  	
   	  	putc('>',fp2);
   	  	putc('\n',fp2);
   	  	c=getc(fp);
   	  }
   	}
     else
     c=getc(fp);
   } 
   		
   
  }
   display();
   	
}




