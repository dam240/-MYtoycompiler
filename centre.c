#include "list.h"
#include "sybla.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "uril.h"
#include "ops.h"

#define random(x) (rand()%x)

int   greaterthan(char c,char * code);
int Thans(char c,char * code);




void prinfgf(struct Arraylist *   paraname,struct operation opre,struct Arraylist *storageCode,struct Arraylist *   other){



	int size=paraname->length,i;
	//printf("指令码operaiton code=%d \n",opre.code);
//	if(opre.code!=0)
     //operationCODE(storageCode,opre.code);

  
	  if(size==2){
				
			//MICODE(storageCode,PUS,AX);
			//MICODE(storageCode,PUS,BX);
			
			  struct	 parameter * p	=(struct parameter * )getarray(paraname,0);
			  int o=  compareName(other,p->parametername);
			   if(o==0){
				    LOADStr(storageCode,AX,p->value);
			   }else
				 LOADStr(storageCode,AX,p->parametername);
		       	//printf("变量%s %s  %s \n",p->parametername,p->type,p->value);
            



			
			  
			  
			 
			  i++;
			   p=(struct parameter * )getarray(paraname,1);
			    o=  compareName(other,p->parametername);
			   
			  if(o==0) 
			  LOADStr(storageCode,BX,p->value);
			  else
			   LOADStr(storageCode,BX,p->parametername);
			  
		      if(opre.code!=0)
			  MI(storageCode,opre.code,AX,BX);
			 
			   
			  /*if(p->typem==INT){
				  printf("int \n");

			  }else if(p->typem==CHAR){
				    printf("char \n");
			  }*/
	
	  }else if(size==1){
		  		    struct	 parameter * p	=(struct parameter * )getarray(paraname,0);
					
               int o=  compareName(other,p->parametername);
			   if(o==0){
				    LOADStr(storageCode,AX,p->value);
			   }else
				   LOADStr(storageCode,AX,p->parametername);
						   
                          if(opre.code!=0)
		                    MICODE(storageCode,opre.code,AX);
		                    						
		  
	  }





}






int Sign(char c,char * code){
	int r=returnIndex(c,code);
	r++;
	if(strlen(code)<r)
		return 0;

	if(code[r]==c){
		//printf("%c %c \n",code[r-1],code[r]);
		return r;

	}else{ 
			return 0;
	}
}

struct Arraylist *  ANDOR(char * code,int h,int end);
char * divideStr(char * p,int index,int ty);
struct IFLR IFprocess(char * code,int end,int index){
		//printf("IFprocess=================\n");
		struct IFLR rl;
		rl.ob=inif();
		rl.operns=inif();
	char * p=(char *)malloc(end+2);
	int i=returnIndex('(',code);
	int j=0;
	i++;
	int sd=i;
	for(;i<end;i++,j++){
		p[j]=code[i];
	}
	 p[j]='\0';

	//printf("%s \n",p);
	
	//vector<ANDORS> lin
		struct Arraylist * lin=ANDOR(code,sd,end);

		int size=lin->length;
	int b=0,e=0;
	int count=1,opera=1;
	if(size>0){

	for( i=0;i<size;i++){

	struct	ANDORS * ps=(struct ANDORS *)getarray(  lin,i);

			if(i==0){
				b=sd;
				e=ps->B;
				
			}else{

			//struct	ANDORS * pss=(struct ANDORS *)getarray(  lin,i-1);
				b=e+2;
				e=ps->B;
			}



		if(ps->type==AND){
			//printf("and   %d  %d \n",ps.B,ps.E);
		struct	instruct * in=(struct instruct *)malloc(sizeof(struct instruct));
			 if(!in)
				 exit(-1);
			in->index=index;
			if(!in)
				exit(-1);

		     char * q=returnsCH(code,b,e);
			 in->step=count;
			 count++;
			 in->code=q;
			 add( rl.ob,in);
			 //rl.ob.push_back(in);
		struct	 operation * o=(struct  operation *)malloc(sizeof(struct  operation));
			 if(!o)
				 exit(-1);
			 o->code=AND;
			 o->step=opera;
				 opera++;
			 add( rl.operns,o);
			// rl.operns.push_back(o);
			// printf(" and %s \n",q);

		}if(ps->type==OR){
		
		
	struct	instruct * in=(struct  instruct *)malloc(sizeof(struct instruct));
			in->index=index;
			if(!in)
				exit(-1);

		     char * q=returnsCH(code,b,e);
			 in->step=count;
			 count++;
			 in->code=q;
			  add( rl.ob,in);
			// rl.ob.push_back(in);
		struct	 operation * o=(struct operation *)malloc(sizeof(struct operation));
			 if(!o)
				 exit(-1);
			 o->code=OR;
			 o->step=opera;
				 opera++;
			 add( rl.operns,o);
					//printf("or  %s \n",q);
		}



	}






         

struct	ANDORS * pss=(struct ANDORS *)getarray(  lin,size-1);
	b=pss->E+1;
	e=end;

	//char * psd	=returnsCH(code,b,e);
		
	   struct   instruct * in=(struct  instruct *)malloc(sizeof(struct instruct));
			in->index=index;
			if(!in)
				exit(-1);

		     char * q=returnsCH(code,b,e);
			 
			 int ri=Thans('|',q);
			 
			 	if(ri!=0){
                                            ri=returnIndex('|',q);
					//printf("=============('l',q)!===\n");
		    char * ps=divideStr(q,ri,0);
			 in->step=count;
			 count++;
			 in->code=ps;
		     add( rl.ob,in);
			// printf("=============('l',q)!= %s==\n",ps);
		    struct	 operation * op=(struct operation *)malloc(sizeof(struct operation));
			 if(!op)
				 exit(-1);
			 op->code=R;
			 op->step=opera;
				 opera++;
			 
			  add( rl.operns,op);
			  
			   in=(struct  instruct *)malloc(sizeof(struct instruct));
			  
			   in->step=count;
			   count++;
			     ps=divideStr(q,ri+1,1);
			   in->code=ps;
// printf("=sd============('l',q)!= %s==\n",ps);
		     add( rl.ob,in);
			  
			 
				}else if(Thans('&',q)!=0){
				

		       		ri=returnIndex('&',q);
					char * ps=divideStr(q,ri,0);
					 in->step=count;
			            count++;
			           in->code=ps;
//printf("=============%s===\n",ps);
		                add( rl.ob,in);
						
			struct	 operation * op=(struct operation *)malloc(sizeof(struct operation));
			 if(!op)
				 exit(-1);
			    op->code=AN;
			   op->step=opera;
				 opera++;
			 
			  add( rl.operns,op);
			 
						
			 in=(struct  instruct *)malloc(sizeof(struct instruct));
			  
			   in->step=count;
			   count++;
			   ps=divideStr(q,ri+1,1);
			   in->code=ps;
//printf("======s=======%s===\n",ps);
		     add( rl.ob,in);
			  
						
					
				
				}else{
			     in->step=count;
			    count++;
			    in->code=q;
			   add( rl.ob,in);
				}
			// rl.ob.push_back(in);
			//  printf("  %s \n",q);


















	}else
	{




		 
            //  int rei=  returnIndex('|',p);
              if(cIncude('|',p)){
				  int rei=  returnIndex('|',p);
				  if(rei==0){
				    printf(" 语法错误 %s \n",p);
					exit(-1);
				  }
		    struct	instruct * in=(struct instruct *)malloc(sizeof(struct instruct));
			 if(!in)
				 exit(-1);
			in->index=index;
			if(!in)
				exit(-1);
				  
				char * ps=divideStr(p,rei,0);
				   
				    in->step=count;
			     count++;
			 in->code=ps;
		     add( rl.ob,in);
				   
		   struct	 operation * op=(struct operation *)malloc(sizeof(struct operation));
			 if(!op)
				 exit(-1);
			 op->code=R;
			 op->step=opera;
				 opera++;
			 
			  add( rl.operns,op);
				  
				  
			in=(struct  instruct *)malloc(sizeof(struct instruct));
			  if(!in)
				exit(-1);
			   in->step=count;
			   count++;
			   ps=divideStr(p,rei+1,1);
			   in->code=ps;
		     add( rl.ob,in);
				  
             
			  }else if(cIncude('&',p)){
				  
				    int rei=  returnIndex('&',p);
				  if(rei==0){
				    printf(" 语法错误 %s \n",p);
					exit(-1);
				  }
		    struct	instruct * in=(struct instruct *)malloc(sizeof(struct instruct));
			 if(!in)
				 exit(-1);
			in->index=index;
			if(!in)
				exit(-1);
				  
				char * ps=divideStr(p,rei,0);
				   
				    in->step=count;
			     count++;
			 in->code=ps;
		     add( rl.ob,in);
				   
		   struct	 operation * op=(struct operation *)malloc(sizeof(struct operation));
			 if(!op)
				 exit(-1);
			 op->code=AN;
			 op->step=opera;
				 opera++;
			 
			  add( rl.operns,op);
				  
				  
			in=(struct  instruct *)malloc(sizeof(struct instruct));
			  if(!in)
				exit(-1);
			   in->step=count;
			   count++;
			   ps=divideStr(p,rei+1,1);
			   in->code=ps;
		     add( rl.ob,in);
				    
			  }else{
				  
				  if(cIncude('!',p)||Thans('<',p)==1||Thans('>',p)==1||greaterthan('!',p)||greaterthan('<',p)||greaterthan('>',p)||Sign('=',p)!=0){
				
				  	  struct   instruct * in=(struct instruct *)malloc(sizeof(struct instruct));
		      	 in->index=index;
			      if(!in)
				   exit(-1);
		
			       in->oper.code=NOT;
				  in->oper.step=0;

			

			       in->step=count;
			        count++;
			       in->code=p;
			  			 add( rl.ob,in);
				  }else{
					   printf(" 错误 %s \n",p);
					   exit(-1);
				  }
				  
			  }
			  
			
			 
			  




	}


	//if()


	
   //free(p);
	return rl;
}











int compareName( struct Arraylist * paraname,char * name){

	int size=paraname->length,i;

	for( i=0;i<size;i++){
		struct parameter* p=(struct parameter* )getarray( paraname,i);
		
		if(compareNames(p->parametername,name)){
			//printf("compareName=============  %d =0\n ",i);
	
 			return i+1;
		}

	}

	//printf("compareName=============  -- \n");

	return 0;


}




char * divideStr(char * p,int index,int ty){
	int size=0,h=0;
	char * ps;
		//printf("===============divideStr=============\n");
		//printf("===============divideStr=  %s============\n",p);
	if(ty==0){
		size=index;
	    ps=(char *)malloc(index+2);
	    if(!ps)
			exit(-1);

	}else{
		h=index;
		size=strlen(p);
   
		//printf("===============divideStr== %d===========\n",size-index+2);
		ps=(char *)malloc(size-index+2);
	    if(!ps)
			exit(-1);
	}


	int j=0,i;
	for( i=h;i<size;i++,j++){
		ps[j]=p[i];
		//printf("%c \n",ps[j]);

			//printf("==================== %c end===========\n",i);
	}

	ps[j]='\0';

			//printf("===============divideStr==  end===========\n");

	return ps;


}










int Thans(char c,char * code){
	int size=strlen(code); 
	int count=0,i;
	for(i=0;i<size;i++){
	 if(code[i]==c)
	    count++;

	}

	return count;

}




int   greaterthan(char c,char * code){
	
	int r=returnIndex(c,code);
	if(r==0)
		return 0;
	int size=strlen(code); 
	r++;
	if(r>=size)
		return 0;

	if(code[r]=='=')
		if(r+1<size)
			return 1;
		else
		{
			printf("错误在 %s \n",code);
			exit(-1);
		}


	return 0;
}











int  IF(char * code){
	//printf("==================IF========== %s========\n",code);
	int size=strlen(code);
	//char FI[]="if";
	if(size<3)
		return 0;


	if(code[0]!='i'){
			//printf("==================IF========== %c========\n",code[0]);
			return 0;
	}
	if(code[1]!='f'){
		// printf("==================IF========== %c========\n",code[1]);
			return 0;
	}
	
	 if(code[2]!='('){
		// printf("==================IF========== %c========\n",code[2]);
		 return 0;
	 }
	//printf("==================IF========== end========\n",code);
   return 1;

}

int ELSE(char * code){
//   printf("==================ELSE========== %s========\n",code);
	int size=strlen(code);
	if(size<4)
		return 0;
	int index=0;

	if(code[index]=='}'){
		index++;

	}

	if(code[index]!='e')
	  return 0;
	else
		index++;

	if(code[index]!='l')
	  return 0;
	else
		index++;

	if(code[index]!='s')
	  return 0;
	else
		index++;


	if(code[index]!='e')
	  return 0;
	
	//  printf("==================ELSE==========end ========\n");

	return 1;



}










void testdte(struct Arraylist * list,struct Arraylist * list2){


		///printf("testdte======open=========\n");

		int size=list2->length;
	struct	Arraylist * lin=inif();
	int j,i;
	for(i=0;i<size;i++){
	struct	Structpost * p	=(struct Structpost * )getarray( list2,i);
		int y= list->length;
	 unsigned int in=y/2;
	// printf("testdte======%d====%d=====\n",in,y);
	 
		for( j=0;j<y;j++){
		struct	Structpost * sd=(struct Structpost *)	getarray(list,j);
		if(sd->index==p->index){			
			int sddd=in;
		   add(lin,&sddd);
			break;
		}

	}
	}


//	printf("testdte===============\n");

	size=lin->length;
	for( i=size-1;i>=0;i--){
		//printf("%d=======\n",lin[i]);
	  //  list->erase(list->begin()+lin[i]+1);
  


	}


//printf("testdte=====dsd======end====\n");
}






/*

ios 多维
*/
struct Arraylist *    testje( struct Arraylist *  list,struct Arraylist *  ps){

	int size=list->length;
//	Arraylist *  top=inif(); 


struct  Arraylist *  ios=inif(); 
//vector<vector<Structpost>>ios;
	//printf("-----------------ssssss---\n");
	int i,j;
	for( i=0;i<size;i++){
	struct	Structsend * p=	(struct Structsend *)getarray(list,  i);
	    int s=  p->b->index;
		int e=p->e->index;
	struct	Arraylist *lisd =inif();
		
	//    printf("  begin{  type= %d  index= %d  in= %d \n",p->b->type,p->b->index,p->b->in);
		//printf("  end}  type= %d  index= %d  in= %d \n",p->e->type,p->e->index,p->e->in);
	  for( j=s;j<=e;j++){
	struct	  Structpost * sd=(struct Structpost *)malloc(sizeof(struct Structpost));
		  sd->index=j;
		  sd->step=(char *)getarray(ps,j);
		   //lisd.push_back(sd);
		  add(lisd,sd);
		//  printf("%s \n",getarray( ps,j));  
	  }
	  add(ios,lisd);
	 // ios.push_back(lisd);
	////  printf("===================================\n");


	}

	size=ios->length;
	if(size==2){
		testdte((struct Arraylist *)getarray(ios,1),(struct Arraylist *)getarray(ios,0));
		//printf("%d  \n",size);
		for(i=0;i<size;i++){
		struct	Arraylist * lp=(struct  Arraylist *)getarray(ios,i);
			
			
			int s=lp->length;
			for( j=0;j<s;j++){
			struct	Structpost * p=(struct  Structpost *)getarray(lp,j);
				//printf("第%d 条   %s \n",p->index,p->step);
			}

		}


	}else
	for( i=0;i<size;i++){
		
		if(i+1<size){
			testdte((struct  Arraylist *)getarray(ios,i+1),(struct Arraylist *)getarray(ios,i));
		}
	}
	
	
	return ios;


}











struct Arraylist *  teanIF(struct Arraylist * list){
	//printf("========teanIF======\n");
	struct Arraylist * min;
	min=inif();
	
	int i,bin=0,raigth=0;
	
	for(i=0;i<list->length;i++){
	 
				struct   Structpost * p=(struct Structpost * )getarray( list,i);
				 char * ps=p->step;
		if(IF(ps)){
		  bin=i;
//printf("========teanIF= if==%d===\n",bin);
		}else if(ELSE(ps)){	
			if(bin==0){

            printf("不能单独只有else %s\n",ps);
			 exit(-1);
			 
			 
			}
			raigth=i;
			struct  Vsort * mo=(struct  Vsort *)malloc(sizeof(struct  Vsort));
			if(!mo)
			exit(-1);
		   
		mo->ip=bin;
		mo->index=raigth;
		add(min,mo);
//printf("========teanIF= else==%d= %d==\n",bin,raigth);
		bin=0;
		raigth=0;
			
			
		}
		//
		
			
			
		
		
	}
	
	
	return min;
	
	
}










struct Arraylist *  ANDOR(char * code,int h,int end){

	//printf("==================ANDOR========== %d====%d   %d====\n",strlen(code),h,end);
	 
	struct Arraylist * lin,*list;
	list=inif();
	lin=inif();
	//vector<ANDORS> lin;
//   vector<int> list;
int i;
   for( i=h;i<end;i++){
	   if(code[i]=='|'){

		// list.push_back(i);
		   //int b=i;
		   int * b=(int *)malloc(sizeof(int));
		   *b=i;
		   add(list,b);
	   }
	    if(code[i]=='&'){
			int * b=(int *)malloc(sizeof(int));
		   *b=i;
		   add(list,b);

		}
   }
//      printf("==================ANDOR=========ssss=========\n");
	  int size=list->length%2;
  

//   printf("==================ANDOR==========size %d ========\n",size);
   char c='|';
  
  
   if(size==0){
	   size=list->length;
   }else
   {
	   size=list->length-1;
   }


   for( i=0;i<size;i++){
	
	   int * b=(int *)getarray(  list,i);
	//   printf("================ddd   %d \n",*b);
	   if(code[*b]=='|'){
		    int * d=(int *)getarray(  list,i+1);
		//	 printf("================ddff   %d \n",*d);
		   if(code[*b]==code[*d]&&*b+1==*d){
           //    printf("------------------\n");
			   OPER o=OR;
			struct	ANDORS * ps=(struct  ANDORS * )malloc(sizeof(struct ANDORS));
				 ps->B=*b;
				 ps->E=*d;
				 ps->type=o;
			     i++;
				// lin.push_back(ps);
                                        //    printf("-------|-----------\n");
				 add(lin,ps);
                                         //    printf("------|------------\n");
				 continue;

		   }
	   }

	   if(code[*b]=='&'){
		   int * d=(int *)getarray(  list,i+1);
		   	//	 printf("================ddff   %d \n",*d);
		   if(code[*b]==code[*d]&&*b+1==*d){
			//   printf("=================================\n");
			  OPER o=AND;
				struct ANDORS  * ps=(struct  ANDORS * )malloc(sizeof(struct  ANDORS));
				 ps->B=*b;
				 ps->E=*d;
				 ps->type=o;
//   printf("-------------&-----\n");
				 add(lin,ps);
//   printf("------------&------\n");
			     i++;
				 continue;

		   }
	   }

	   
	//   printf("%c  %d\n",code[list[i]],list[i]);

   }





	return lin; 

}





void setLOad(struct instruct* ob, struct Arraylist *  paraname,int indexs,int index,OPER ty){
   char * p=ob->code;
	int size=strlen(p);

		char * ps=divideStr(p,index-1,0);
	//	printf("%s ===== \n",ps);
		
		int re=compareName(paraname,ps);
			//	printf("%d ===== \n",re);
		if(re==0){
			printf("找不到 %s 变量\n",ps);
			exit(-1);
		}
	

	struct	parameter * qn =(struct parameter * )getarray( paraname,re-1);
	
		add(ob->parameter,qn);
	

		char * qs=divideStr(p,index+1,1);
		

		 re=compareName(paraname,qs);
		if(re!=0){
		struct	parameter * qn1=(struct parameter * )getarray( paraname,re-1);
		    add(ob->parameter,qn1);
			ob->oper.step=indexs;
			ob->oper.code=EQ;
			return;
		}
		
	 struct   parameter * qn1=(struct parameter*)malloc(sizeof(struct parameter));
		char * name=(char *)malloc(sizeof(20));;
		sprintf(name,"test%d\0",random(10000));

		qn1->parametername=name;
		if(!qn1)
			exit(-1);

		if(qn->typem==INT){
			if(standardINT(qs)==0){
	             printf("值%s的类型不对 \n",qs);
				 exit(-1);
			}else
			{
			
				qn1->typem=INT;
				qn1->type=qn->type;
					//printf("=========dfff============%d  %d \n",qn1->typem,INT);
			}
		}else{
			qn1->typem=qn->typem;
             qn1->type=qn->type;
			// printf("=========dfff=s===========%d \n",qn1->typem);


		}

		qn1->value=qs;
		//printf("%s ---------- \n",qs);
	    add(ob->parameter,qn1);
	     ob->oper.step=indexs;
			ob->oper.code=EQ;
		//printf("=========================sgg=== sdd=========\n");


}








void isolate(struct instruct* ob, struct Arraylist *  paraname,int indexs){
		//printf("===============isolate=============\n");
	char * p=ob->code;
	int size=strlen(p);
	char typeschar[]="char";
	char  typesint[]="int";
	ob->parameter=inif();
//	printf("===============isolate=== %s==========\n",p);
	int index=Sign('=',p);
	
	if(index!=0){
		     
		char * ps=divideStr(p,index-1,0);
		//printf("%s ===== \n",ps);
		
		int re=compareName(paraname,ps);
			//	printf("%d ===== \n",re);
		if(re==0){
			printf("找不到 %s 变量\n",ps);
			exit(-1);
		}
	

	struct	parameter * qn =(struct parameter * )getarray( paraname,re-1);
	
		add(ob->parameter,qn);
	

		char * qs=divideStr(p,index+1,1);
		

		 re=compareName(paraname,qs);
		if(re!=0){
		struct	parameter * qn1=(struct parameter * )getarray( paraname,re-1);
		    add(ob->parameter,qn1);
			ob->oper.step=indexs;
			ob->oper.code=EQ;
			return;
		}
		
	struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
		char * name=(char *)malloc(sizeof(20));;
		sprintf(name,"test%d\0",random(10000));

		qn1->parametername=name;
		if(!qn1)
			exit(-1);

		if(qn->typem==INT){
			if(standardINT(qs)==0){
	             printf("值%s的类型不对 \n",qs);
				 exit(-1);
			}else
			{
				qn1->typem=INT;
				qn1->type=qn->type;
			}
		}else{
			qn1->typem=qn->typem;
             qn1->type=qn->type;
	


		}

		qn1->value=qs;
		//printf("%s ---------- \n",qs);
	    add(ob->parameter,qn1);
	     ob->oper.step=indexs;
			ob->oper.code=EQ;
		//printf("=========================sgg=== sdd=========\n");
	}else if(greaterthan('>',p))//》=
     {





   int index=returnIndex('=',p);
		   char * one=divideStr(p,index-1,0);
           char * two=divideStr(p,index+1,1);

              int re1=compareName(paraname,one);
				//printf("%d  \n",re1);
	           int re2=compareName(paraname,two);
			 //    printf(" <\n");
	           //   printf("%d  \n",re2);
			  if(re2==0&&re1==0){
			  	printf("语法错误  %s\n",p);
		     	exit(-1);
			  }
			  
			  
			  
			  
			  int tyrm=0;
			  if(re1){
			  struct	parameter * qn= (struct parameter * )getarray( paraname,re1-1);
		        add(ob->parameter,qn);
			   ob->oper.step=indexs;
			  ob->oper.code=BG;
			  tyrm=qn->typem;
			  }else{
				  
				  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
		        if(!qn1)
			    exit(-1);

                if(standardINT(one)==1){
				    qn1->typem=INT;
					 tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				 tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=one;
		  //     printf("%s ---------- \n",one);
	          add(ob->parameter,qn1);
				  
	     	  ob->oper.step=indexs;
			  ob->oper.code=BG;
			   }
			   
			   if(re2){
			    struct	parameter * qn =(struct parameter * )getarray( paraname,re2-1);
				if(qn->typem!=tyrm){
				  printf("类型错误  %s\n",p);
		        	exit(-1);
				}
				
		        add(ob->parameter,qn);
			    return;
			  
			   }else{
			  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
			   if(!qn1)
			    exit(-1);
                 
                if(standardINT(two)==1){
				    qn1->typem=INT;
					// tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				// tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=two; 
             
			 if(qn1->typem!=tyrm){

				 printf("类型错误  %s\n",p);
		        exit(-1);
			  }
                 
               add(ob->parameter,qn1);
			  
			  
			  return;
			  
			   }
			
			   
			   
			   









				
				
     }else if(greaterthan('<',p))//《=
			  {
  





		     int index=returnIndex('=',p);
		   char * one=divideStr(p,index-1,0);
           char * two=divideStr(p,index+1,1);

              int re1=compareName(paraname,one);
				//printf("%d  \n",re1);
	           int re2=compareName(paraname,two);
			  //   printf(" <\n");
	            //  printf("%d  \n",re2);
			  if(re2==0&&re1==0){
			  	printf("语法错误  %s\n",p);
		     	exit(-1);
			  }
			  
			  
			  
			  
			  int tyrm=0;
			  if(re1){
			  struct	parameter * qn= (struct parameter * )getarray( paraname,re1-1);
		        add(ob->parameter,qn);
			   ob->oper.step=indexs;
			  ob->oper.code=SG;
			  tyrm=qn->typem;
			  }else{
				  
				  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
		        if(!qn1)
			    exit(-1);

                if(standardINT(one)==1){
				    qn1->typem=INT;
					 tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				 tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=one;
		 //      printf("%s ---------- \n",one);
	          add(ob->parameter,qn1);
				  
	     	  ob->oper.step=indexs;
			  ob->oper.code=SG;
			   }
			   
			   if(re2){
			    struct	parameter * qn =(struct parameter * )getarray( paraname,re2-1);
				if(qn->typem!=tyrm){
				  printf("类型错误  %s\n",p);
		        	exit(-1);
				}
				
		        add(ob->parameter,qn);
			    return;
			  
			   }else{
			  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
			   if(!qn1)
			    exit(-1);
                 
                if(standardINT(two)==1){
				    qn1->typem=INT;
					// tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				// tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=two; 
             
			 if(qn1->typem!=tyrm){

				 printf("类型错误  %s\n",p);
		        exit(-1);
			  }
                 
               add(ob->parameter,qn1);
			  
			  
			  return;
			  
			   }
			
			   








			  }else if(greaterthan('!',p))//!=
			  {
  

                                                   
           int index=returnIndex('=',p);
		   char * one=divideStr(p,index-1,0);
           char * two=divideStr(p,index+1,1);
              int re1=compareName(paraname,one);
         if(re1==0){
			printf("找不到 %s 变量\n",one);
			exit(-1);
		}
	
        struct	parameter * qn =(struct parameter * )getarray( paraname,re1-1);
	
		add(ob->parameter,qn);
	          int  re=compareName(paraname,two);
        if(re!=0){
		struct	parameter * qn1=(struct parameter * )getarray( paraname,re-1);
		   if(qn1->typem==qn->typem){
		       printf("值%s的类型不对 \n",one);
				 exit(-1);
		   }
		    add(ob->parameter,qn1);
			ob->oper.step=indexs;
			ob->oper.code=NOTG;
			return;
		}
		
		
		
		
 


	  struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
		char * name=(char *)malloc(sizeof(20));;
		sprintf(name,"test%d\0",random(10000));

		qn1->parametername=name;
		if(!qn1)
			exit(-1);

		if(qn->typem==INT){
			if(standardINT(two)==0){
	             printf("值%s的类型不对 \n",two);
				 exit(-1);
			}else
			{
				qn1->typem=INT;
				qn1->type=qn->type;
			}
		}else{
			qn1->typem=qn->typem;
             qn1->type=qn->type;

		}

		qn1->value=two;
		//printf("%s ---------- \n",two);
	    add(ob->parameter,qn1);
	     ob->oper.step=indexs;
			ob->oper.code=NOTG;
















			  }else if(Thans('>',p)==1){//》
                             
                            
                           int index=returnIndex('>',p);
               char * one=divideStr(p,index,0);
               char * two=divideStr(p,index+1,1);
               int re1=compareName(paraname,one);
				//printf("%d  %s\n",re1,one);
	           int re2=compareName(paraname,two);
			  //   printf(" <\n");
	             //printf("%d  %s \n",re2,two);
			  if(re2==0&&re1==0){
			  	printf("语法错误  %s\n",p);
		     	exit(-1);
			  }
			  
			int tyrm=0;
			  if(re1){
			  struct	parameter * qn= (struct parameter * )getarray( paraname,re1-1);
		        add(ob->parameter,qn);
				 ob->oper.step=indexs;
			  ob->oper.code=BIG;
			  tyrm=qn->typem;
			  }else{
				  
				  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
		        if(!qn1)
			    exit(-1);

                if(standardINT(one)==1){
				    qn1->typem=INT;
					 tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				 tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=one;
		  //     printf("%s ---------- \n",one);
	          add(ob->parameter,qn1);
				  
	     	  ob->oper.step=indexs;
			  ob->oper.code=BIG;
			   }
			  
			  
			   if(re2){
			    struct	parameter * qn =(struct parameter * )getarray( paraname,re2-1);
				if(qn->typem!=tyrm){
				  printf("类型错误  %s\n",p);
		        	exit(-1);
				}
				
		        add(ob->parameter,qn);
			    return;
			  
			   }else{
			  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
			   if(!qn1)
			    exit(-1);
                 
                if(standardINT(two)==1){
				    qn1->typem=INT;
					// tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				// tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=two; 
             
			 if(qn1->typem!=tyrm){

				 printf("类型错误  %s\n",p);
		        exit(-1);
			  }
                 
               add(ob->parameter,qn1);
			  
			  
			  return;
			  
			   }
















			  
			  }else if(Thans('<',p)==1){//《
                                      //      printf("Thans('<',p)==1===============\n");


                               int index=returnIndex('<',p);
               char * one=divideStr(p,index,0);
               char * two=divideStr(p,index+1,1);
               int re1=compareName(paraname,one);
				//printf("  %s %d  \n",one,re1);
	           int re2=compareName(paraname,two);
			   //  printf("<\n");
	           //  printf("%d  \n",re2);
			  if(re2==0&&re1==0){
			  	printf("0000语法错误  %s\n",p);
		     	exit(-1);
			  }
			  
			int tyrm=0;
			  if(re1){
			  struct	parameter * qn= (struct parameter * )getarray( paraname,re1-1);
		        add(ob->parameter,qn);
				 ob->oper.step=indexs;
			  ob->oper.code=SM;
			  tyrm=qn->typem;
			  }else{
				  
				  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
		        if(!qn1)
			    exit(-1);

                if(standardINT(one)==1){
				    qn1->typem=INT;
					 tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				 tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=one;
		  //     printf("%s ---------- \n",one);
	          add(ob->parameter,qn1);
				  
	     	  ob->oper.step=indexs;
			  ob->oper.code=SM;
			   }
			  
			  
			   if(re2){
			    struct	parameter * qn =(struct parameter * )getarray( paraname,re2-1);
				if(qn->typem!=tyrm){
				  printf("类型错误  %s\n",p);
		        	exit(-1);
				}
				
		        add(ob->parameter,qn);
			    return;
			  
			   }else{
			  
			    struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	             char * name=(char *)malloc(sizeof(20));;
		         sprintf(name,"test%d\0",random(10000));

		        qn1->parametername=name;
			   if(!qn1)
			    exit(-1);
                 
                if(standardINT(two)==1){
				    qn1->typem=INT;
					// tyrm=INT;
				     qn1->type=typesint;
		        }else{
		         qn1->typem=CHAR;
				// tyrm=CHAR;
	     	    qn1->type=typeschar;
				}
	
		      qn1->value=two; 
             
			 if(qn1->typem!=tyrm){

				 printf("类型错误  %s\n",p);
		        exit(-1);
			  }
                 
               add(ob->parameter,qn1);
			  
			  
			  return;
			  
			   }
 






         









			  }else if(cIncude('!',p)==1){//！

	
                            int index=returnIndex('!',p);

               char * one=divideStr(p,index+1,1);
               
               int re1=compareName(paraname,one);

               if(re1==0){
                  printf("语法错误 %s  \n",p);
				   exit(-1);
               }
			   
			  struct	parameter * qn= (struct parameter * )getarray( paraname,re1-1);
		 if(qn->typem!=INT){
                    printf("语法错误 %s  \n",p);
				   exit(-1);
				   }					   
			  	  		  
			add(ob->parameter,qn);
			ob->oper.step=indexs;
			ob->oper.code=EQ;
			   
	      struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	       char * name=(char *)malloc(sizeof(20));;
		          sprintf(name,"test%d\0",random(10000));
		         qn1->parametername=name;
			      if(!qn1)
			      exit(-1);   
			   
			     qn1->typem=INT;
			  qn1->type=typesint;
			  
			  char va[]="0";
			    qn1->value=va; 
			 
			 add(ob->parameter,qn1);
			 
















			  }else{//！
			  
			         
			     int re1=compareName(paraname,p);
				 if(re1!=0){

				  struct	parameter * qn= (struct parameter * )getarray( paraname,re1-1);
				  add(ob->parameter,qn);
				 
				 }else{
                     if(standardINT(p)==1){
                  struct    parameter * qn1=(struct parameter*)malloc(sizeof(struct  parameter));
	              char * name=(char *)malloc(sizeof(20));;
		          sprintf(name,"test%d\0",random(10000));
		         qn1->parametername=name;
			      if(!qn1)
			      exit(-1);


                     qn1->typem=INT;
					// tyrm=INT;
				     qn1->type=typesint;
                 
                    qn1->value=p; 
                   add(ob->parameter,qn1);
					 }else{
				    printf("语法错误 %s  \n",p);
				    exit(-1);
					 }
					 
				 }
			  }


	//index=Sign('=',p);


//	index=Sign('',p);

	//for(int i=0;i<siz)



}



 struct Arraylist *  centre(  struct Arraylist *  list,struct symbolMethod * sp,struct Arraylist *  smethods,struct Arraylist * nxt){
	 struct Arraylist *  code=sp->code;
	 int size=list->length,i,j,count,iconfi=0,iends=0,econf=0,eends=0,ifi=0,fori=0,inc=0,din=0,forid=0;
 struct Arraylist *  storageCode;
  char * codename=NULL;
 storageCode=inif();
	//   printf("==================centre==================\n");
 setMethodesn(storageCode,sp->MethodName);


	   
struct parameter * pae=sp->partParams;
	   int r;
       for(r=0;r<sp->params;r++){
            
                       //    printf("=====================ssss====\n");

			MICODE(storageCode,POP,CX);//pae[r].value;
			   //  printf("========5=========%s====ssss====\n",pae[r].type);
			 if(compareNames(pae[r].type,"int")){
					// operationCODE(storageCode,RET);
					 
					  //           printf("========1=55============ssss====\n");
					    struct parameter paraname =pae[r];
						paraname.typem=INT;
						setDatas(storageCode,paraname);

					    MOVTS(storageCode,paraname.parametername,CX);
					 
					 
					 //continue;
				 }else{
					       //  printf("========2=============ssss====\n");
					    struct parameter  paraname =pae[r];
					
						setDatas(storageCode,paraname);
					    MOVTS(storageCode,paraname.parametername,CX);
					 
				 }


			
			
	   }


	   for(i=0;i<size;i++){
		struct   Structpost * p=(struct Structpost * )getarray( list,i);
		   char * ps=p->step;
                   


		//   if(ps[0]=='{')
			 //  ps= (char *)getarray(code,p->index-1);

		   if(IF(ps)){
			//  printf("if %s \n",ps);
			  int in=returnIndex(')',ps);
			  if(in==0){
				  printf(" %s在少了)",ps);
				  return  -6;
			  }

		struct	IFLR rl=  IFprocess(ps,in,i);
			

               if(cIncude('{',ps))
			    iconfi++;
            else{
				if(i+1!=size){
		struct          Structpost * dfp=(struct Structpost * )getarray( list,i+1);
		       char * psds=dfp->step;
// printf("---------psds-----------\n");
			  if(psds[0]=='{'){
			    iconfi++;

     i++;
			   //continue;
			   
				}else
					iends++;
				}else{
			   printf("判断语句不能没有下个操作 %s\n",ps );
                exit(-1);
					
				}
			}
			
			





			int s=rl.ob->length;
		 struct Arraylist *  po=rl.ob;
//        printf("===============if===centre==================\n");

	      for(j=0;j<s;j++){
			struct  instruct *in=(struct instruct *)getarray(	 po,j);
	       isolate(in,sp->MethodStruct->paraname,j);
    //    printf("======%s=====%d== %d======\n",in->code,in->index,in->step);

	 }


		  //   printf("=====================================================\n");
			 int sds = rl.operns->length;
		 int io=0;

    char * name=(char *)malloc(20);  

					
						sprintf(name,"%s@%d\0",sp->MethodName,i);

		  setIFs(storageCode,name);


	 for( j=0;j<s;j++){


		struct  instruct *in=	(struct  instruct *)getarray(	 po,j);
		
		
		  prinfgf(in->parameter,in->oper,storageCode,sp->MethodStruct->paraname);
		  if(io<sds){
			struct   operation * osd=(struct operation * )getarray(	rl.operns,j);
			   printf("operation code  %d  \n",osd->code);
operationCODE(storageCode,osd->code);
			   io++;		
	  }
	 //    printf("=====================================================\n");






	 }

  //   printf("=====================end=====\\\\\\\\\\\\===========================\n");
// printf("==========ss==%d========%d===\n",ifi,nxt->length);
                  
	   if(ifi<nxt->length){
	 
	   
	    struct  Vsort * vd=(struct  Vsort *)getarray(nxt,ifi);

                //   printf("=    if(vd->ip==i||vd->ip==(i-1)){===  %d====%d=\n",vd->ip,i);
	      if(vd->ip==i||vd->ip==(i-1)){
	           //   printf("=========vd->ip========\n");
		  char * names=(char *)malloc(20);  
		  sprintf(names,"%s@%d\0",sp->MethodName,vd->index);
	                 JPMs(storageCode,JPM,names);
		  ifi++;
free(names);
		   }
	   }

		   }else if(ELSE(ps)){

 char * name=(char *)malloc(20);  
		sprintf(name,"%s@%d\0",sp->MethodName,i);

                                          if(cIncude('}',ps)){
			   if(iconfi>=1){
				operationCODE(storageCode,END);
                                                                      iconfi--;						 
					   }
			}
			
			  if(iends>=1){
				operationCODE(storageCode,END);
			  iends--;
			  
			  }
			
			   
			   if(cIncude('{',ps))
			    econf++;
            else{
				if(i+1!=size){
		  struct       Structpost * dfp=(struct Structpost * )getarray( list,i+1);
		       char * psds=dfp->step;
                     //         printf("psds=dfp---2\n");
			   if(psds[0]=='{'){
                                            //        printf("psds=dfp---2\n");
			    econf++;
 i++;
				//continue;
              } else
				  eends++; 
				}else{
			   printf("判断语句不能没有下个操作 %s\n",ps );
                exit(-1);
					
				}
			}
			   
		
                            //  JPMs(storageCode,JPM,name);
		  setIFs(storageCode,name);


			//     printf("else %s \n",ps);
		   } else if(compareNames(ps,"return")!=0){
//  printf("===============else=============(ps,'return')!===\n");
 
                  





                                                 if(compareNames(sp->retParam,"void")){
					 operationCODE(storageCode,RET);
					 continue;
				 }

//   printf("===============else=============(ps,'return')!= 2= =\n");
             
			   i++;
                                        if(i>=list->length){
                                                                           p=(struct Structpost * )getarray( list,i);
ps=p->step;
                                                                        //printf("%s\n",ps);
					 printf("该函数不能没返回值%s\n",sp->MethodName);
					 exit(-1);
					 
				 }

			   p=(struct Structpost * )getarray( list,i);
		       ps=p->step;
		        
			if(compareNames(sp->retParam,"int")){
				
			   if(cIncude('+',ps)||cIncude('-',ps)||cIncude('*',ps)||cIncude('/',ps)){
			             
						int stn= strlen(ps);
			            if(ps[stn-1]!=';'){
                          printf("少了; %s\n",ps);					
					     exit(-1);
						}
				  
						  //afte[stn-1]=';';
						  //afte[stn]='\0';
						   
				  struct Arraylist *  linst =FindExpressionV(ps);
						   
						   
						   
				   setfiguregot(linst,sp->MethodStruct->paraname,sp->partParams,sp->params,storageCode,"0",0);
			       MICODE(storageCode,PUS,AX);
                  operationCODE(storageCode,RET);
			   
			   }else{
				   


                          	int stn= strlen(ps);
			            if(ps[stn-1]!=';'){
                                                        printf("少了; %s\n",ps);					
					     exit(-1);
						}
						
						ps[stn-1]='\0';

				   
				   
		 int bools=compareName(sp->MethodStruct->paraname,ps);
	      if(bools!=0){
		      LOADStr(storageCode,AX,ps);
	  }else{
		  int ui,bo=0;
		  
		  struct parameter  * partParams=sp->partParams;
		  for(ui=0;ui<sp->params;ui++){
			
			 
			   if(compareNames(ps,partParams[ui].parametername)){
			      bo=1;
			     break;
			   }
		  }
		  
		  if(bo){
			  LOADStr(storageCode,AX,ps);
		  }else{
			  if(standardINT(ps)){
			   LOADStr(storageCode,AX,ps);
			  }else{
			  printf("该类型不能当做返回类型 %s\n",ps);
			  exit(-1);
			  }
		  }
		  
		  
		  
		  
	  }			   
	   MICODE(storageCode,PUS,AX);
        operationCODE(storageCode,RET);
	  continue; 
			   }
				 
				 
				 }else{
					 
					  LOADStr(storageCode,AX,ps);
					  MICODE(storageCode,PUS,AX);
                     operationCODE(storageCode,RET);
	          continue; 
					 
					 
					 
					 
				 }









		   }else if(FORDORN(ps)){


//  printf("=====for============begin===\n");
			   
			   	 int  pbooles=0;
			//   printf("%s====\n",ps);
		


	                                                i++;
			  p=(struct Structpost * )getarray( list,i);
		           char * objsybla=p->step;
		
			
			  // int reble= returnIndex('=',ps);
			  int syblahalf=strlen(ps);
			  int booltype=0;
			  
			  if(ps[syblahalf-1]==';'&&syblahalf==5){//处理后面的条件
				  
				    
			  
			  
			  
			  }else if(cIncude('=',ps)){//变量已经存在
                                                          pbooles=1;
//         printf("===============(cIncude('=',ps)=======sort=======\n");

				   int rebei= returnIndex('(',ps);
				   char * txt=divideStr(ps,rebei+1,1);
  //       printf("===============(cIncude('=',ps)=====%s==sort=======\n",txt);

				   rebei= returnIndex('=',txt);
				    char * forbein=divideStr(txt,rebei,0);
 //  printf("===============(cIncude('=',ps)=====%s==sort=======\n",forbein);
				    char * forend=divideStr(txt,rebei+1,1);
				  
                     int bindex=compareName(sp->MethodStruct->paraname,forbein);
                     if(bindex==0){
                      printf("找不到该变量 %s \n",ps);
                      exit(-1);
					 }
                     












					
                                                                         struct parameter * para =(struct parameter *)getarray( sp->MethodStruct->paraname,bindex-1);
				
					if(!compareNames(para->type,"int")){ 
					  printf("只有整型能在for里做表达式 %s \n",ps);
                      exit(-1);
					}
					
					//printf("===============(cIncude('=',ps)=====%s==sort=======\n",forend);







   objsybla=ps;
   booltype=0;
   }else{//创建变量
	
				    int rebei= returnIndex('(',ps);
				    char * txt=divideStr(ps,rebei+1,1);
				    if(!compareNames(txt,"int")){
					 printf("创建类型错误 %s \n",txt);
                      exit(-1);
						
					}
				   
				    
				    booltype=1;
				   
			   
			   
			   }
			   
			   
			   
			 
			   
			   
			  
			  
			  
			  
			  
			        //         printf("======================sort=======\n");

			    
			       int pop_heap=0;
			   struct Arraylist *  sort=NULL;
			     if(cCount(';',objsybla)>=2){
			  
			    sort  =splitchar(objsybla,';');	
//    printf("======================sort===%d==11==\n",sort->length);

 char * test=getarray(sort,0);
//    printf("======================test===%s====\n",test);


				 if(sort->length>=2){
                                                                     //  printf("======================sort=====1==\n");

				  char * oprt=getarray(sort,sort->length-1);
				  int oprts=strlen(oprt);
				  
				  //if()
				  int booleas=0;
				  
				  if(oprt[oprts-1]=='{'){
					  
					  if(oprt[oprts-2]!=')'){
			            printf("少了) %s\n",objsybla);
					     exit(-1);
					  }
				  }else if(oprt[oprts-1]==')'){
					    i++;
					    p=(struct Structpost * )getarray( list,i);
		               char * pou=p->step;
					  // oprts=strlen(pou);
					   if(pou[0]!='{'){
					      printf("少了{ %s\n",objsybla);
					     exit(-1);
					   }
					
				 }else {
					  printf("0220错误在 %s\n",objsybla);
					 exit(-1);
				 }
				 
				 if(sort->length==2)
				     pop_heap=1;
				 else if(sort->length==3){
					   pop_heap=2;
					   
					   if(booltype){
					   
					   
					  char  * value=(char * ) getarray(sort,0);
					   
					   int     rebei= returnIndex('=',value);
					   
				
					   
					    // char * txt=divideStr(ps,rebei,1);
				         // rebei= returnIndex('=',txt);
				      char * forbein=divideStr(value,rebei,0);

        //    printf("============6666=======%s \n",forbein);
           

                                    struct parameter * paraname =( struct parameter *)malloc(sizeof( struct parameter));
  					   paraname->parametername=forbein;
					     char  * name=malloc(5);
		                  sprintf(name,"int");			   
					       paraname->type=name;
					    paraname->typem=INT;
						
						    name=malloc(5);
		                  sprintf(name,"0");
						  paraname->value=name;
                                                                                          
                                                                                                 add(sp->MethodStruct->paraname,paraname);
						  setData(storageCode,paraname);




				       char * forend=divideStr(value,rebei+1,1);
				  
				  
           


                     
					   int forendsizes=	strlen(forend);
                                                            //    printf("=================== %s \n",forend);
					
				    if(!standardINT(forend)){
				      printf("赋值错误 %s \n",ps);
                                                                 exit(-1);
				
	 }
				   


				  
                                                                   LOADStr(storageCode,AX,forbein);
			                    MOVS(storageCode,AX,forend);
				      MOVTS(storageCode,forbein,AX);
			   
					   
					   }else{ //做判断查找

   char  * value=(char * ) getarray(sort,0);
   if(FORDORN(value)){
   int     rei= returnIndex('(',value);
     value=divideStr(value,rei+1,1);
    }


                                                                             
					        

					   int     rebei= returnIndex('=',value);
					   
				
					   
					    // char * txt=divideStr(ps,rebei,1);
				         // rebei= returnIndex('=',txt);
  

				      char * forbein=divideStr(value,rebei,0);

                                                                  char * forend=divideStr(value,rebei+1,1);
				  
				  
           


                     
					   int forendsizes=	strlen(forend);
                                                          //      printf("=================== %s \n",forend);
					
				    if(!standardINT(forend)){
				      printf("赋值错误 %s \n",ps);
                                                                 exit(-1);
				
	    }


                                                                      LOADStr(storageCode,AX,forbein);
			                    MOVS(storageCode,AX,forend);
				      MOVTS(storageCode,forbein,AX);
			   







}
					   
				 }else{
	                  printf("错误在%s\n",objsybla);
					 exit(-1);
					  }						  
				 
			  }else{
					 printf("120错误在%s\n",objsybla);
					 exit(-1);
				 }
			   
				   }else{


				


					  int indexRe= returnIndex('=',objsybla);
					    char * forbein=NULL;
						  char * forend=NULL;
char * expe=NULL;
					   if(indexRe!=0){
					   
					  //   char *   txt=divideStr(objsybla,indexRe,1);
					     forbein=divideStr(objsybla,indexRe,0);
				        forend=divideStr(objsybla,indexRe+1,1);
					   expe=objsybla;
					   
					   
					   
					   }else{
					   
					   
					   
					   i++;
					        p=(struct Structpost * )getarray( list,i);
		                 char  * value  =p->step;
   expe=value;
					 // =(char * ) getarray(list,i);
					   
					    int     rebei= returnIndex('=',value);
					//    char  *  txt=divideStr(objsybla,rebei,1);
					  forbein=divideStr(value,rebei,0);
				              forend=divideStr(value,rebei+1,1);
					   
					   
					   
					   }
					   


                        //add()
                           if(booltype!=1){		  
                          int bindex=compareName(sp->MethodStruct->paraname,forbein);
                          if(bindex==0){
                         printf("找不到该 %s \n", forbein);
                          exit(-1);
					 }

   	 struct parameter * 	paraname =(struct parameter *)getarray(sp->MethodStruct->paraname,bindex-1);
					 
                     if(!compareNames(paraname->type,"int")){
                       printf("创建类型错误 %s \n",forbein);
                      exit(-1);                 
					 }			


}else{
					   
					   struct parameter * paraname =( struct parameter *)malloc(sizeof( struct parameter));
  					   paraname->parametername=forbein;
					     char  * name=malloc(5);
		                  sprintf(name,"int");			   
					       paraname->type=name;
					    paraname->typem=INT;
						
						    name=malloc(5);
		                  sprintf(name,"0");
						  paraname->value=name;
  add(sp->MethodStruct->paraname,paraname);
						  setData(storageCode,paraname);
					   
				   }



                     
					   int forendsizes=	strlen(forend);
					if(forend[forendsizes-1]!=';'){
						printf("少了 ; %s \n", expe);
                      exit(-1);
						
					}
				   forend[forendsizes-1]='\0';
				    if(!standardINT(forend)){
				      printf("赋值错误 %s %s \n", expe,forend);
                      exit(-1);
					 }
				   
				  
                     LOADStr(storageCode,AX,forbein);
			         MOVS(storageCode,AX,forend);
				     MOVTS(storageCode,forbein,AX);
					   
					   




                               }
			   
			   
			     //   printf("======================sort=====2==\n");

			   
			   struct  instruct *in=(struct  instruct *)malloc(sizeof(struct  instruct));
			   if(!in){
			    printf("内存不足\n");
                 exit(-1);				
			   }
			   
			int     forendsize  =strlen(objsybla);
			
			
			     if(pop_heap==0){
			     if(objsybla[ forendsize-1]!=';'){
					 	printf("少了 ; %s \n",ps);
                      exit(-1);
					 
				 }
				  


	if(booltype!=0){
						   i++;
					        p=(struct Structpost * )getarray( list,i);
                                                 char * code= p->step;
                                   int colen=strlen(code); 
                                           if(code[colen-1]!=';'){
	 	printf("少了 ; %s \n",ps);
                      exit(-1);
					 
                      }
                        code[colen-1]='\0';

                     
//  printf("666666666------%d  \n",strlen(code));
 
		                                                        in->code=code;
                                           

						
						
					}else{
						   objsybla[ forendsize-1]='\0';
				    in->code=objsybla;
						
					}
					




// printf("======================sort=====255624bchysb==\n");
				 }else{
					
					    if( pop_heap==1){
					  in->code=(char * ) getarray(sort,0);
				       
//  printf("======================sort=====8==\n");
                                                                             }else if(pop_heap==2){
						  in->code=(char * ) getarray(sort,1);
						//  printf("======================sort=====6==\n");
					  }else{
						

//  printf("======================sort=====5==\n");
							   i++;
					        p=(struct Structpost * )getarray( list,i);
		                   in->code= p->step;
					  }


					  
				 }


 char * nameo=(char *)malloc(20);  
		 
	
		 
		 
		sprintf(nameo,"if@%d\0",forid);
		forid++;

		setIFs(storageCode,nameo);
                               free(nameo);



				     //    printf("======================sort=====4==\n");
			        isolate(in,sp->MethodStruct->paraname,0);
   //   printf("======================sort=====10==\n");
			   	      prinfgf(in->parameter,in->oper,storageCode,sp->MethodStruct->paraname);
    //  printf("======================sort=====10==\n");
			       //  free(in->obj);
                                                         free(in);

			        char * increase=NULL;
				    if(pop_heap==1)
			          increase= getarray(sort,1);
				   else if(pop_heap==2){
			           increase= getarray(sort,2);
				   }else{
//      printf("======================sort=====11==\n");
					    i++;
					    p=(struct Structpost * )getarray( list,i);
		                                                      increase=p->step;
					   int oprts=strlen(increase);
					  
					  	  if(increase[oprts-1]=='{'){
					 //     printf("======================sort=====12==\n");
					     if(increase[oprts-2]!=')'){
				         printf("少了) %s\n",increase);
						 exit(-1);
				
					  }
				  } else if(increase[oprts-1]==')'){
   //   printf("======================sort=====14==\n");
					    i++;
					    p=(struct Structpost * )getarray( list,i);
		               char * pou=p->step;
					  // oprts=strlen(pou);
					   if(pou[0]!='{'){
						 printf("少了{ %s\n",pou);
						 exit(-1);
					   }
					
				 }else{
				            printf("错误在%s\n",increase);
					 exit(-1);
					 
				 }
				 
					  
					   
				   }

     // printf("======================sort=====16==\n");
			   
			    if(cIncude('+',increase)||cIncude('-',increase)){
				//      printf("======================sort=====12==\n");
					   if(cIncude('+',increase)){
				
					   	   if(cCount('+',increase)==2){
					   	    //     printf("======================sort=====12==\n");
					        int pasce = returnIndex('+',increase);
					       char * bsd=divideStr(increase,pasce,0);
					        //      printf("================%s======sort=====12==\n",bsd);
                        int bools=compareName(sp->MethodStruct->paraname,bsd);
					       //     printf("================%d======sort=====12==\n",bools);
					      if(bools==0){
							 printf("找不到该变量 错误 %s \n",increase);
							   exit(-1);
							 }
					   
					                                               codename=bsd;
								 inc=1;
							//   LOADStr(storageCode,AX,bsd);
							 //  MICODE(storageCode,INC,AX);
							   //MOVTS(storageCode,bsd,AX);
					       //  printf("=============1w2=========sort=====12==\n");
					          //    free(bsd);
					   
					    //    printf("=========d====1w2=========sort=====12==\n");
						   }else{
					  printf("错误在 %s\n",increase);
				      exit(-1);
					   
					   }
						   
						   
					   }else{
						   
						     if(cCount('-',increase)==2){
					   
					   
					   
					      int pasce = returnIndex('-',increase);
					      char * bsd=divideStr(increase,pasce,0);
					     
                        int bools=compareName(sp->MethodStruct->paraname,bsd);
					   
					      if(bools==0){
							 printf("找不到该变量 错误 %s \n",increase);
							   exit(-1);
							 }
					           LOADStr(storageCode,AX,bsd);
							 //  MICODE(storageCode,DIN,AX);
							//   MOVTS(storageCode,bsd,AX);
					            //  free(bsd);
					   
					    codename=bsd;
								 din=1;
					   
					   
					   
					   
					   
						   }else{
							    printf("错误在 %s\n",increase);
				                 exit(-1);
					   
							   
						   }
						   
						   
						   
					   }
					
					   
				   }
				   
				   
			//   operationCODE(storageCode,JPM);
 
					
			//   free(sort->obj);
//   printf("=========d==ddhh=======sort=====12==\n");
			   free(sort);
			   
			   fori=1;
			   
			   			   	continue;

			   
			  
			  
			  























}else if(methodISMost(ps)){
		   		//   printf("===============methodISMost============\n"); 		   
		      int pasce=returnIndex('(',ps);

	    char * being=divideStr(ps,pasce,0);

	char * b;
						int mindu=0;
				if(cIncude('=',being)){
					int runs=returnIndex('=',being);
				       b=divideStr(being,runs,0);
					int bindex=compareName(sp->MethodStruct->paraname,b);
                     if(bindex==0){
                      printf("找不到该 %s \n",b);
                      exit(-1);
					 }
                        mindu=1;
					being=divideStr(being,runs+1,1);
					
				}


              int rei= puremethod(smethods,being);
   
			  if(rei==0){
              printf("找不到该函数\n");
                exit(-1);
			  }				  
		      
		    char * afte=divideStr(ps,pasce+1,1);

		     int siz= strlen(afte);
		     if(afte[siz-1]!=';'){
				printf("少了; 在%s \n",ps);
				exit(-1);
			}

    
           if(afte[siz-2]!=')'){
				printf("少了) 在%s \n",ps);
				exit(-1);
			}
 

		  afte[siz-1]='\0';
		  afte[siz-2]='\0';

		  if(cIncude(',',afte)){
		  //   printf("===============methodISMost=======6=====\n"); 
		


		   struct methods * modet  =(struct methods *)getarray(smethods,rei-1);
		    int syst=compareNames(modet->name,"printf");
			struct Arraylist *  lins=splitchar(afte,',');	
		     if(syst){
		     int u;
		    for(u=0;u<lins->length;u++){
			 char * trag	=getarray(lins,u);
			     MICODE(storageCode,CALL,WP);

		       LOADStr(storageCode,AX,trag);
		       MICODE(storageCode,WP,AX);
			}
		   
		   
		   free(lins->obj);
		   free(lins);
		   
		   
	      }else{
	CALLs(storageCode,CALL,being);				

				if(modet->patansize!=lins->length){
				 printf("函数传掺多了或少了 在%s \n",ps);
				  exit(-1);
				
				}
				
				

 int u;
				struct	parameter  * partParams=modet->partParams;
				for(u=0;u<modet->patansize;u++){
					 char * trag	=getarray(lins,u);
				      int res=compareName(sp->MethodStruct->paraname,trag);
					  if(res!=0){
					       	struct parameter* para=(struct parameter* ) getarray(sp->MethodStruct->paraname,res-1);
//    printf("===============methodISMost=======8== %d==%d=\n",partParams[u].typem,para->typem); 
	int	typem=partParams[u].typem;
							if(partParams[u].typem==0){
							int sbfd=compareNames(partParams[u].type,"int");
							if(sbfd!=0)
								typem=INT;
							
							}

					      if(typem==para->typem){
 
		
                             LOADStr(storageCode,AX,trag);
		                     MICODE(storageCode,QU,AX);
							}else{ 								
					             printf("传掺的类型不正确 %s\n",trag);
					              exit(-1);
							}
					  }else{
						  
						  
						struct	parameter  * 	partParamsto =sp->partParams;
						  
						  //   printf("===============methodISMost=======9=====\n"); 
						  int r;
						  int sr=0;
						  for(r=0;r<sp->params;r++){
						    
						    sr= compareNames(partParamsto[r].parametername,trag);
						    if(sr!=0)
						      break;
						  
						  }
						  
						  if(sr!=0){
						  
	 int	typem=partParams[u].typem;
							if(partParams[u].typem==0){
							int sbfd=compareNames(partParams[u].type,"int");
							if(sbfd!=0)
								typem=INT;
							
							}
							  
							  
							   int	typemt=partParamsto[r].typem;
							if(partParamsto[r].typem==0){
							int sbfd=compareNames(partParamsto[r].type,"int");
							if(sbfd!=0)
								typemt=INT;
							
							}


						  if(typem==typemt){
							//     printf("===============methodISMost=======8=8====\n"); 
							 LOADStr(storageCode,AX,trag);
		                     MICODE(storageCode,QU,AX);
						  
						  }else{
							    
								printf("传掺的类型不正确 %s\n",trag);
					            exit(-1);
							  
						  }
						  
						  
						  }else{
                                                                                                       int	typem=partParams[u].typem;
							if(partParams[u].typem==0){
							int sbfd=compareNames(partParams[u].type,"int");
							if(sbfd!=0)
								typem=INT;
							
							}



						 if(typem==INT){
						    
						    if(standardINT(trag)){
							   LOADStr(storageCode,AX,trag);
							   MICODE(storageCode,QU,AX);
								
							}else{
						          printf("传掺的类型不正确 %s\n",trag);
					              exit(-1);
							}
						 }else{
							 
							 LOADStr(storageCode,AX,trag);
		                     MICODE(storageCode,QU,AX);
						 }
						 
						  }
						  
					  }
					
				}
				
				
				
				
			

			
				
		}





		 
		  
		  }else{
		  
		     // printf("===============methodISMost=======7====%s=\n",afte); 
		
  struct methods * modet  =(struct methods *)getarray(smethods,rei-1);
 //     printf("===============methodISMost=======8=====\n"); 
		    int syst=compareNames(modet->name,"printf");

			//分析出传掺
			//splitchar
			
		    if(syst){
		    MICODE(storageCode,CALL,WP);

		    LOADStr(storageCode,AX,afte);
		   MICODE(storageCode,WP,AX);
		   
		   
		   
		   
	      }else{


	CALLs(storageCode,CALL,being);


struct	parameter  * partParams=modet->partParams;
				 int res=compareName(sp->MethodStruct->paraname,afte);
				 if(res!=0){
				 	struct parameter* para=(struct parameter* ) getarray(sp->MethodStruct->paraname,res-1);

	                                                                                     int	typem=partParams[0].typem;
							if(partParams[0].typem==0){
							int sbfd=compareNames(partParams[0].type,"int");
							if(sbfd!=0){
								typem=INT;
                                                                                                                  }else if(compareNames(partParams[0].type,para->type)){
                                                      

                                                  typem=para->typem;
                                                                                               
                                                                                                                         }
							}


                                                                                       //     printf("===============methodISMost===%s===%d=10== %d===\n",partParams[0].type,typem,para->typem); 
					        if(typem==para->typem){
                                                                                                 
                                                                                              LOADStr(storageCode,AX,afte);
		                                                                MICODE(storageCode,QU,AX);
							}else{ 								
					             printf("传掺的类型不正确   %s\n",afte);
					              exit(-1);
							}
				
				
				 }else{
					 
					 	struct	parameter  * 	partParamsto =sp->partParams;
					   int r;
						  int sr=0;
						  for(r=0;r<sp->params;r++){
						    
						    sr= compareNames(partParamsto[r].parametername,afte);
						    if(sr!=0)
						      break;
						  
						  }
						  
						   if(sr!=0){
						  
	   int	typem=partParams[0].typem;
							if(partParams[0].typem==0){
							int sbfd=compareNames(partParams[0].type,"int");
							if(sbfd!=0){
								typem=INT;
							
							}else if(compareNames(partParams[0].type,"char")){
							typem=CHAR;
								
							}	
							}
							
							
							int	typemt=partParamsto[r].typem;
							if(partParamsto[r].typem==0){
							int sbfd=compareNames(partParamsto[r].type,"int");
							if(sbfd!=0){
								typemt=INT;
							
						    }else if(compareNames(partParams[r].type,"char")){
							typemt=CHAR;
								
						}		
							}
							   


						  if(typem==typemt){
							  
							 LOADStr(storageCode,AX,afte);
		                     MICODE(storageCode,QU,AX);
						  
						  }else{
							    
								printf("传掺的类型不正确 %s\n",afte);
					            exit(-1);
							  
						  }
						  
						  
						  }else{
							  
							     int	typem=partParams[0].typem;
							if(partParams[0].typem==0){
							int sbfd=compareNames(partParams[0].type,"int");
							if(sbfd!=0){
								typem=INT;
							
							}else if(compareNames(partParams[0].type,"char")){
							typem=CHAR;
								
							}	
							}
							  
							  
							 if(typem==INT){
						    
						    if(standardINT(afte)){
							   LOADStr(storageCode,AX,afte);
							   MICODE(storageCode,QU,AX);
								
							}else{
						          printf("传掺的类型不正确 %s\n",afte);
					              exit(-1);
							}
						 }else{
							 
							 LOADStr(storageCode,AX,afte);
		                     MICODE(storageCode,QU,AX);
						 }
							  
						  }
						  
					 
					 
				 }



				
				
				
		}




		  
		  
		  }
		 //      printf("===============methodISMost=======end=====\n"); 
		   

  if(mindu){
			    MICODE(storageCode,POP,AX);
			     MOVTS(storageCode,b,AX);
		   }


  if(eends>=1){
			    operationCODE(storageCode,END);	
				eends--;
		  }
		  
		  
		    if(iends>=1){
			    operationCODE(storageCode,END);	
				iends--;
		    }
		   


		   
		   }




                             else{
				   
				
		//   printf("===============else========d=====%d=  %d====\n",list->length,i+1);





if(i+1<list->length){
struct   Structpost * po=(struct Structpost * )getarray( list,i+1);
			   int toes=findcontents(sp->MethodStruct->paraname,ps,po->step,storageCode);
			      //   printf("===============else==1===b=====%d========\n",toes);
			   if(toes==-1){
				   printf("错误在 %s\n",po->step);
				   exit(-1);
			   }else if(toes==1){
 //  printf("===============else==2================\n");
			    i++;
			   	continue;
			   
			   }else{
				  //   printf("===============else==3================\n");
				   if(cIncude('=',ps)){
					    int inp=returnIndex('=',ps);
					    char * before=divideStr(ps,inp,0);
						 char * afte=divideStr(ps,inp+1,1);
	//   printf("===============else==4================\n");	
						int bools=compareName(sp->MethodStruct->paraname,before);
                                	


						if(bools!=0){
						//  printf("===============else==5================\n");
						struct parameter* para=(struct parameter* )getarray( sp->MethodStruct->paraname,bools-1);
				       		
if(para->typem==0){
								int sbfd=compareNames(para->type,"int");
							  if(sbfd){	
								para->typem=INT;
								
							  }else {
							   printf("==============\n");
							  
							  }
							}


				        if(para->typem==INT){
				
				
					   if(cIncude('+',afte)||cIncude('-',afte)||cIncude('*',afte)||cIncude('/',afte)){
						   

						  //afte[stn-1]=';';
						//  afte[stn]='\0';


                                  //     printf("===============else==66========%s========\n",afte);

	                                                            struct Arraylist *  linst	     =FindExpressionV(afte);
						   // printf("===============else==888========%s========\n",afte);
						   setfiguregot(linst,sp->MethodStruct->paraname,sp->partParams,sp->params,storageCode,before,1);
						   
						   











						   
					   }else{//  printf("===============else==6================\n");	
						 int stn=strlen(afte);
						   if(afte[stn-2]==';'||afte[stn-1]==';'||afte[stn-3]==';'){
						    if(afte[stn-2]==';')
						        afte[stn-2]='\0';
						    else  if(afte[stn-1]==';')
								  afte[stn-1]='\0';
							  else
								   afte[stn-3]='\0';
						   }else{
							   printf("少了;在 %s \n",afte);
							   exit(-1);
							   
						   }
						   
						   
						   if(standardINT(afte)){
							   MOVS(storageCode,AX,afte);
							   MOVTS(storageCode,before,AX);
							   
						   }else{
							 bools=compareName(sp->MethodStruct->paraname,afte);
                              if(bools==0){
							 printf("赋值错误 %s \n",afte);
							   exit(-1);
							  }
							  
							   LOADStr(storageCode,AX,afte);
                                                                                                                 //   printf("===========smov\n");
							   MOVTS(storageCode,before,AX);
          //printf("=======end====smov\n");
						   }
						   
						   
						  // bools=compareName(sp->MethodStruct->paraname,afte);
                          // if()				


				
					   }
					   
					   
					   
						}else{
							

                                 
  int stn=strlen(afte);
						   if(afte[stn-2]==';'||afte[stn-1]==';'||afte[stn-3]==';'){
						    if(afte[stn-2]==';')
						        afte[stn-2]='\0';
						    else  if(afte[stn-1]==';')
								  afte[stn-1]='\0';
							  else
								   afte[stn-3]='\0';
						   }else{
							   printf("少了;在 %s \n",afte);
							   exit(-1);
							   
						   }



							   //  printf("===============else==7================\n");
				
							
							LOADStr(storageCode,AX,afte);
							MOVTS(storageCode,before,AX);
							
							
							
						}
						
						}else{
							
					     printf("找不到该变量 %s\n",before);
				         exit(-1);
						}
						
						free(before);
						free(afte);
					   


	    if(eends>=1){
			    operationCODE(storageCode,END);	
				eends--;
		  }
		  
		  
		    if(iends>=1){
			    operationCODE(storageCode,END);	
				iends--;
		    }


				   }else if(cIncude('+',ps)||cIncude('-',ps)){
					   
					

   if(cIncude('+',ps)){
					   
					   	   if(cCount('+',ps)==2){
					   
					      int pasce = returnIndex('+',ps);
					      char * bsd=divideStr(ps,pasce,0);
					     
                        int bools=compareName(sp->MethodStruct->paraname,bsd);
					   
					      if(bools==0){
							 printf("找不到该变量 错误 %s \n",ps);
							   exit(-1);
							 }
					   
					   
							   LOADStr(storageCode,AX,bsd);
							   MICODE(storageCode,INC,AX);
							   MOVTS(storageCode,bsd,AX);
					   
					              free(bsd);
					   
					   
						   }else{
					  printf("错误在   %s\n",ps);
				      exit(-1);
					   
							   
						   }
						   
						   
					   }else{
						   
						     if(cCount('-',ps)==2){
					   
					   
					   
					      int pasce = returnIndex('-',ps);
					      char * bsd=divideStr(ps,pasce,0);
					     
                        int bools=compareName(sp->MethodStruct->paraname,bsd);
					   
					      if(bools==0){
							 printf("找不到该变量 错误 %s \n",ps);
							   exit(-1);
							 }
					           LOADStr(storageCode,AX,bsd);
							   MICODE(storageCode,DIN,AX);
							   MOVTS(storageCode,bsd,AX);
					              free(bsd);
					   
					   
					   
					   
					   
					   
					   
						   }else{
							    printf("错误在 %s\n",ps);
				                 exit(-1);
					   
							   
						   }
						   
						   
						   
					   }
					   
   

	    if(eends>=1){
			    operationCODE(storageCode,END);	
				eends--;
		  }
		  
		  
		    if(iends>=1){
			    operationCODE(storageCode,END);	
				iends--;
		    }




				   }else{
					   
					   
					     
					   if(econf>=1){
					   if(cIncude('}',ps)){
					     operationCODE(storageCode,END);
                          econf--;		
	continue;						  
					   }else{
					   printf("错误在 0 %s\n",ps);
				      exit(-1);
					   
					   }
					   
					   }
					   
					   
					      
					   if(iconfi>=1){
					if(cIncude('}',ps)){
					     operationCODE(storageCode,END);		
                                                                         iconfi--;		
	                                                    continue;							 
                        							 
					   }else{
					   printf("错误在 1  %d %s\n",strlen(ps),ps);
				      exit(-1);
					   
					   }
					   
					   }






       if(fori){
                                                                        if(codename!=NULL){
                                                                            if(din){
din--;
                                                                                                                  LOADStr(storageCode,AX,codename);
							   MICODE(storageCode,DIN,AX);
							  MOVTS(storageCode,codename,AX);
 
                                                                         }else if(inc){

inc--;
                                                                                                                  LOADStr(storageCode,AX,codename);
							   MICODE(storageCode,INC,AX);
							  MOVTS(storageCode,codename,AX);
                                                                                                                   
                                            
                                               }    
                                  char * nameo=(char *)malloc(20);  
		 
	
		 
		 
		sprintf(nameo,"if@%d\0",forid-1);

JPMs(storageCode,JPM,nameo);
free(nameo);
                                                                            
                                                                         }else{
                                                                             printf("内部代码\n");
				      exit(-1);
                                                                                   }

fori--;
 	continue;

                                                                             }

					   
					  printf("错误在------ %s\n",ps);
				   exit(-1);
					   
				   }


				  
				   
			   }











	   
		   }else{

 
					   if(econf>=1){
					   if(cIncude('}',ps)){
					     operationCODE(storageCode,END);
                          econf--;		
	continue;						  
					   }else{
					   printf("错误在 %s\n",ps);
				      exit(-1);
					   
					   }
					   
					   }

				 

                                                                                     if(iconfi>=1){
					   if(cIncude('}',ps)){
					     operationCODE(storageCode,END);		
                                                                                           iconfi--;		
	                                                                         continue;							 
                       							 
					   }else{
					   printf("错误在 %s\n",ps);
				      exit(-1);
					   
					   }
					   
					   }
  

                                                                      if(fori){
                                                                        if(codename!=NULL){
                                                                            if(din){
din--;
                                                                                                                  LOADStr(storageCode,AX,codename);
							   MICODE(storageCode,DIN,AX);
							  MOVTS(storageCode,codename,AX);
 
                                                                         }else if(inc){

inc--;
                                                                                                                  LOADStr(storageCode,AX,codename);
							   MICODE(storageCode,INC,AX);
							  MOVTS(storageCode,codename,AX);
                                                                                                                   
                                            
                                               }    
                                  char * nameo=(char *)malloc(20);  
		 
	
		 
		 
		sprintf(nameo,"if@%d\0",forid-1);

JPMs(storageCode,JPM,nameo);
free(nameo);
                                                                            
                                                                         }else{
                                                                             printf("内部代码\n");
				      exit(-1);
                                                                                   }

fori--;
 	continue;

                                                                             }

				     printf("错误在  000    %s\n",ps);
				      exit(-1);
					   
				   
				   
			   }


}

	   }
                   
///printf("===========--%d ----------===%d\n",econf,iconfi);
   if(iconfi>=1||econf>=1){
		   
	   printf("少了}在 %s \n",sp->MethodName);
               exit(-1);
	   }
	   

//printf("===================================\n");

//printf("===================================\n");

//printf("===================================\n");
/*
    for(i=0;i<storageCode->length;i++){
		
		char * codes=getarray(storageCode,i);
		
		printf("%s \n",codes);
		
		
	}*/


//printf("===================================\n");
//printf("===================================\n");





              return storageCode;

}















struct Arraylist *  excreteStructs(struct Arraylist * list,struct symbolMethod * sp,struct Arraylist * mothd){

	//int size=list->length;

//	vector<vector<Structpost>> lismm;//
	
struct Arraylist * 	lismm = testje(list,sp->code);

int size=lismm->length,i;
	///for(i=0;i<size;i++ ){
	struct	Arraylist *  p=(struct  Arraylist * )  getarray(lismm,0);
			struct	Arraylist *  ps   =teanIF(p);
		struct	Arraylist *diso=centre(p,sp,mothd,ps);
 char * code=(char *)malloc(10);
 sprintf(code,"\n\n\n\n\n");
                                add(diso,code);
;

		/*if(re==-6){
			printf(" %s 方法\n",sp->MethodName);
			exit(-1);
		}*/


	//}

//printf("----------------end==============\n");
return diso;


}






















