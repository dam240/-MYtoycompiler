#include "uril.h"
#include "sybla.h"
#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ops.h"



int  FORDORN(char * p){
 //   printf("=======FORDORN========\n");
	int size=strlen(p),i;
	   if(size<5)
		return 0;
	
	
      if(p[0]!='f')
	  return 0;
	
	   if(p[1]!='o')
	  return 0;
	
     if(p[2]!='r')
	  return 0;
	 

	 if(p[3]!='(')
	  return 0;
//     printf("=======FORDORN====end====\n");
	 return 1;
	
}


void setDatas( struct Arraylist *  storageCode, 	struct parameter p){
	
	  char * code=(char *)malloc(100);
      sprintf(code,"%d,%s,%s \r\n", p.typem, p.parametername,p.value);

	  add(storageCode,code);

}


void JPMs( struct Arraylist *  storageCode ,OPER ope,char * po){
char * code=(char *)malloc(50);

 sprintf(code,"%d,%s  \r\n", ope, po);
 add(storageCode,code);

}	

void CALLs( struct Arraylist *  storageCode,OPER registers,char * code){
	
  char * codes=(char *)malloc(50);
 sprintf(codes,"%d,%s  \r\n",registers,code);
  add(storageCode,codes);
//add(storageCode,"\n");
}	


int methodISMost(char  * p){
	
	int size=strlen(p),i;
	int b,e,h;
	for(i=0;i<size;i++){
		
		if(p[i]==')'){
			b=1;
			
			
		}else if(p[i]=='('){
			
			e=1;
			
	
       	}else if(p[i]==';'){
			
			h=1;
		}
	
		
	}
	
	if(b==e&&h==b&&b==1){
		
	 return 1;
	}	
	
	
	return 0;
}




char * getschar(int b,int e,char * p){
	
	char * ps=malloc((e-b)+1);
	int i,size=strlen(p),j=0;
	
	for(i=b;i<e;i++){
	  ps[j]=p[i];
            //  printf("%c",ps[j]);
j++;
	}
	ps[j]='\0';
	//printf("getschar====%s\n",ps);
	
	return  ps;
	
}




int cCount(char c,char * p){
	
	int size=strlen(p);
   int i,count=0;
     
	for(i=0;i<size;i++){
		if(p[i]==c)
		count++;

	}
	return count;


}


struct Arraylist *  splitchar(char  * p,char c){
		//printf("replace===============\n");
	struct Arraylist * list;
	 list=inif();
	int s=strlen(p);
	int i,j=0;
	int size=cCount(c,p);
	int * INTS=(int *)malloc(size*sizeof(int));
	for(i=0;i<s;i++){
		if(p[i]==c){
			INTS[j]=i;
		   j++;
		}
		
	}
	//printf("replace========%s=======%d\n",p,size);
	int b=0;
	
	for(i=0;i<size;i++){
//printf("replace=========%d==%d===\n",b,INTS[i]);	
          char * ps=getschar(b,INTS[i],p);

          b=INTS[i]+1;
//printf("replace=====%s=====%d==%d===\n",ps,b,INTS[i]);	
		
		 add(list,ps);
	}
	char * ps=getschar(b,s,p);
    add(list,ps);
		//printf("replace=====%s==========\n",ps);	
	free(INTS);
	
		//printf("replace=====end==========\n");	
	return list;
}


























void MOVS( struct Arraylist *  storageCode,OPER registers,char * cos){
char * code=(char *)malloc(50);

 sprintf(code,"%d,%d,%s \r\n", MOV, registers,cos);
 add(storageCode,code);

}	

void MOVTS( struct Arraylist *  storageCode,char * cos,OPER registers){
char * code=(char *)malloc(50);

 sprintf(code,"%d,%s,%d  \r\n", MOV,cos,registers);
 add(storageCode,code);

}	


void LOADM( struct Arraylist *  storageCode,OPER registers,char * code){
//	printf("LOADM============\n");
  char * codes=(char *)malloc(50);

 sprintf(codes,"%d,%d,%d \r\n", LOAD, registers,code);
  add(storageCode,codes);

//printf("%s \n",codes);
 
}	

void operationCODE( struct Arraylist *  storageCode,OPER registers){
//printf("operationCODE============\n");
char * code=(char *)malloc(50);

 sprintf(code,"%d \r\n", registers);
 add(storageCode,code);

//printf("%s \n",code);
}	


void MOVI( struct Arraylist *  storageCode,OPER registers,OPER  code){
//printf("MOVI============\n");
char * codes=(char *)malloc(50);

 sprintf(codes,"%d,%d,#%d  \r\n", LOAD, registers,code);
 add(storageCode,codes);
//  add(storageCode,"\n");

}	


void setIFs(struct Arraylist *  storageCode,char * name){
	  char * code=(char *)malloc(50);

	    sprintf(code,"%s#: \r\n",name);
	 add(storageCode,code);

}

void MI( struct Arraylist *  storageCode ,OPER ope,OPER registers,OPER  code){
	//printf("MI============\n");
char * codes=(char *)malloc(50);

 sprintf(codes,"%d,%d,%d  \r\n", ope, registers,code);
//printf("%s \n",codes);
 add(storageCode,codes);

}	


void MICODE( struct Arraylist *  storageCode ,OPER ope,OPER registers){
//  printf("MICODE============\n");
char * codes=(char *)malloc(50);

 sprintf(codes,"%d,%d  \r\n", ope, registers);
 add(storageCode,codes);

//  add(storageCode,"\n");
//printf("%s \n",codes);
}	


void LOADStr( struct Arraylist *  storageCode,OPER registers,char * code){

  char * codes=(char *)malloc(50);

 sprintf(codes,"%d,%d,#%s  \r\n", LOAD, registers,code);
 add(storageCode,codes);

 // add(storageCode,"\n");
//printf("%s \n",codes);

}	
void setData( struct Arraylist *  storageCode,struct parameter * p){
	
	  char * codes=(char *)malloc(100);
             sprintf(codes,"%d,%s,%s \r\n", p->typem, p->parametername,p->value);
	  add(storageCode,codes);
         //  add(storageCode,"\n");
//printf("%s \n",codes);
}


void setMethodesn(struct Arraylist *  storageCode,char * name){
	  char * code=(char *)malloc(50);

	    sprintf(code,"%s:  \r\n",name);
	add(storageCode,code);
	//add(storageCode,"\n");
}

int findcontent(struct Arraylist *  op,struct Structpost * p){
	
	//printf("findcontent=======%d======\n",op->length);
	int i;
	
	for(i=0;i<op->length;i++){
		
	        struct parameter * para=	(struct parameter *)getarray(op,i);
		
 
	  // printf("%d %d \n",para->ip,p->index);
/*if(para->ip==p->index+1){
	 	p->vail=1;
		return i;
		}*/
		
	}
//printf("findcontent======end=======\n");

	return -1;
}



int cIncude(char c,char * p){
	
	int size=strlen(p),i;


	for( i=0;i<size;i++){
		if(p[i]==c)
		 return 1;

	}
	return 0;
}


char * returnsCH(char * code,int b,int e){
	//printf("returnsCH======== %d===%d======\n",b,e);
	char * t=(char *)malloc(20);
	 if(!t){
		 exit(-1);
	 }
	  int j=0,i;
         
	 for(i=b;i<e;i++,j++){
		 t[j]=code[i];
	 }

	 t[j]='\0';
	 return t;
}



int compareNames(char * name,char * name2){
	//printf("compareNames====================%s \n",name2);

	int size=strlen(name2);
	if(strlen(name)<size)
		return 0;
	int s=0,i;

	for( i=0;i<size;i++){
		
		if(name2[i]==name[i]){
	
			s++;
		}else
		{
			return 0;
		}

	}

	if(s==size){
		//printf("compareNames   emds \n");
		return 1;
	}

	return 0;

}







int standardINT(char * p){

	int size=strlen(p);
	if(p[size-1]=='\n'||p[size-1]=='\0'){
		size=size-1;
			//printf("=====sss====standardINT======%s=%d\n",p,size);
	}
	//printf("=========standardINT======%s=%d\n",p,size);
	if(size==1)
		if(p[0]>=48&&p[0]<=57){
		//printf("==\n");
			return 1;
		}else{
			printf("\n");
		}
	int count=0,i;

	for(i=0;i<size;i++){
			
		
		if(p[i]>=48&&p[i]<=57){
			//printf("=sss\n");
			count++;
		}else
		{//printf("==---sss\n");
			return 0;
		}


	}


	if(count==size){
		return 1;

	}else
		return 0;

}




struct Arraylist * listmod=NULL;
struct Arraylist * keyso(){
//  printf("================keyso===========\n");
  
if(!listmod){
	 listmod=inif();
	
char * p=(char * )malloc(sizeof(char)*10);
if(!p)
	exit(-1);
p="int";

add(listmod,p);
 p=(char * )malloc(sizeof(char)*10);
if(!p)
	exit(-1);

p="char";

add(listmod,p);
}
          //  printf("==============end ==========ok\n");
	return listmod;
}


int returnIndex(char c,char * p){
	
	int size=strlen(p),i;


	for( i=0;i<size;i++){
		if(p[i]==c)
		 return i;

	}
	return 0;


}






int opirn(struct Arraylist * list,char * p){
	//printf("=opirn==\n");
	int size=list->length;
	int lens=strlen(p);
int i,j;
			
	for(i=0;i<size;i++){
		char * ps=(char *)getarray(list,i);
		int len=strlen(ps);
	
		int o=0;
		if(lens>=len){
		for(j=0;j<len;j++){
			if(ps[j]==p[j]){
				o++;
printf(" ");
				//printf("  --  %c",p[j]);
			}else{
printf(" ");
			//printf("  -- break   %s \n",p);
				break;
			}
		}
      

		}else
			printf(" ");
		//printf("\n");

		if(o==len){
printf(" ");
					//printf("opirn=======retirn====\n");

			return 1;
		}
	  
		
		
		}


	return 0;

}







void  strutcMthod(struct symbolMethod * ps){
	int size=ps->code->length;

	 struct Arraylist *  list=ps->code;
	ps->MethodStruct=(struct StructSymbol *)malloc(sizeof(struct StructSymbol));
	if(!ps->MethodStruct){
		printf("内存\n");
                exit(EXIT_FAILURE);
	}
          /*	
		 	
    for(int i=0;i<size;i++){
		char * p=(char *) getarray(list,i);
	  int re=treHead(p);
	  if(re==0)
		  printf("if --for");
	  else{
	        printf("其他");
	  }
	}
*/




}


void strutcMthodechan(struct symbolMethod * ps){ //拆分局部变量和装载信息
	//int size=ps->code.size();
      //       printf("-----------------dhh----------\n");
	  ps->MethodStruct->paraname=inif();
//          printf("============================modffff===============\n");
	 struct Arraylist *  list=ps->code;
	//printf("-======strutcMthodechan=======");



	// sd ssd;
	 int size=list->length;
	 int i,j;
	// printf("=====================%d===============  \n",size);
    for(i=0;i<size;i++){
		char * p= (char * )getarray(list,i);
		// printf("=====================%d======== %s=======  \n",i,p);

		if(p[0]=='\n'){
			continue;
		}


		int r=opirn(keyso(),p);
			
		if(r==1){
	
				char * pss=p;

			 p=(char * )getarray(list,i+1);
			if(ReturnMoPart(p)){
				//printf("-------ReturnMoPart ,,,-======;\n");
				//vector<int> nub	=dot(',',p);
				int s=strlen(p);

			   //int lens=	nub.size();
			   int y=0,o=0;

			      char  * ui=(char  *)malloc(20);
			      for( j=0;j<s;j++){
				
					  if(p[j]==','){
						   ui[y]='\0';
						   //int sh=strlen(ui);
						int ni=   returnIndex('=',ui);
						   if(ni>0){
							   	// printf("-------push_back vlee==0-======;\n");
							   int sh=strlen(ui);
							   int r=0;
							struct     parameter * top=(struct parameter *)malloc(sizeof(struct parameter));
							   char * tx=( char *)malloc(20);
							   for(;r<ni;r++){
								   tx[r]=ui[r];
							   }
							    tx[r]='\0';
							   top->type=pss;
							   top->parametername=tx;
							   top->ip=i;
							    tx=( char *)malloc(20);
								int ii;
							   for(ii=0;r<sh;r++,ii++){
								   tx[ii]=ui[r];
							   }
							     tx[ii]='\0';
								// printf("top------------%s\n",tx);
								 top->value=tx;
									free(ui);
									add(ps->MethodStruct->paraname,top); 

						   }else{
							   	// printf("-------push_back vlee==null-======;\n");
							 struct  parameter * top=(struct parameter *)malloc(sizeof(struct parameter));
							   top->type=pss;
							   top->ip=i;
							   top->parametername=ui;
							   top->value=NULL;
				
							   add(ps->MethodStruct->paraname,top); 
						   }

						ui=(char  *)malloc(20);

						   y=0;
					  }else{
                      ui[y]=p[j];
					   y++;
					  }

						 
				 }
				  
				  if(ui[y-1]==';'){
					  	  ui[y]='\0';
					  int ni=   returnIndex('=',ui);
					  if(ni>0){

						  	 int sh=strlen(ui);
							   int r=0;
							   struct  parameter * top=( struct parameter *)malloc(sizeof(struct parameter));
							   char * tx=( char *)malloc(20);
							   for(;r<ni;r++){
								   tx[r]=ui[r];
							   }
							   
							   
							//   printf("====================sssss    %s\n",tx);
							   top->type=pss;
							   top->parametername=tx;
							      top->ip=i;
							    tx=( char *)malloc(20);
								int coidn=0;int ii=0;
							   for(;r<sh;r++,ii++){
								   tx[ii]=ui[r];
							   }
						 

							      tx[ii-1]='\0';
								 top->value=tx;
								 free(ui);
								 	// printf("1top-------------%s\n",tx);
								   // ps->MethodStruct.paraname.push_back(top);
								 add(ps->MethodStruct->paraname,top); 
						   	// printf("--else-----push_back vlee==null-======;\n");
					  }else{
						   ui[y-1]='\0';
                     struct parameter * top=(struct parameter *)malloc(sizeof(struct parameter));
							   top->type=pss;
							   top->parametername=ui;
							   top->value=NULL;
							      top->ip=i;
							//   ps->MethodStruct.paraname.push_back(top);
								  add(ps->MethodStruct->paraname,top); 
							     	// printf("--else-----push_back vlee==null-======;\n");
					  }




				
				  }else{

					   printf("在%s 少了;号\n",pss);
					   exit(-1);
				  }


				 	// printf("-------push_back ui2-======;\n");

			}else{
				//printf("------- -======;\n");
				int s=strlen(p);
				 if(p[s-1]==';'){
				//printf("------=============- -======;\n");
				           int ni=   returnIndex('=',p);
					  if(ni>0){
						//  printf("------=============- -======; %s\n",p);
						  		  int sh=strlen(p);
							   int r=0;
							    struct parameter * top=(struct parameter *)malloc(sizeof(struct parameter));
							   char * tx=( char *)malloc(20);
							   for(;r<ni;r++){
								   tx[r]=p[r];
							   }
							    tx[r]='\0';
							   top->type=pss;
							   top->parametername=tx;
							       top->ip=i;
							    tx=( char *)malloc(20);
								int ii=0;
							   for(;r<sh;r++,ii++){
								   tx[ii]=p[r];
							   }
							 
							    tx[ii-1]='\0';
							  
								 top->value=tx;




								// free(ui);
								 	// printf("2top-----%s\n",tx);
								 add(ps->MethodStruct->paraname,top); 
								   // ps->MethodStruct.paraname.push_back(top);
						   	// printf("--else-----push_back vlee==null-======;\n");
					  }else{
                     struct  parameter * top=(struct parameter *)malloc(sizeof(struct parameter));
							   top->type=pss;
							   top->parametername=p;
							   top->value=NULL;
							      top->ip=i;
								  add(ps->MethodStruct->paraname,top); 
							  // ps->MethodStruct.paraname.push_back(top);
							 //   printf("--else-----push_back vlee==null-======;\n");
					  }


					// printf("-------push_back-======;\n");
				 }else{

					




					 printf("在%s  错误少了;\n",p);
					 exit(-1);
				 }


			}
		//	ps->MethodStruct.paraname.push_back(listp);
			
		}else if(ps->MethodStruct->paraname->length>0){
			//ps->MethodStruct.paraname.size();
		  struct Arraylist *  listp=ps->MethodStruct->paraname;

		  int s=	listp->length;
		//	printf(" -----------------------------%d-----------\n",s);
			for(j=0;j<s;j++){
		//	printfcopde(listp[j]);
			
				struct parameter * od= (struct parameter * )getarray(listp,j);
			//printf(" 等几条指令= %d   type=%s    name %s \n ",od->ip,od->type,od->parametername);
			
			}


			// if()
		}


	}








}







void  verifyType(struct symbolMethod * sp,int type){
	//printf("=============verifyType==============\n");
	 struct Arraylist *list= sp->MethodStruct->paraname;
	 int size=list->length,i;
	for(i=0;i<size;i++){
		
	struct	parameter * ob=(struct parameter *)getarray(list,i);
		if(compareNames(ob->type,"int")){
ob->typem=INT;
			if(ob->value!=NULL)
			if(standardINT(ob->value)){
				///	printf("=============verifyType==============111111\n");

				ob->typem=INT;
			}else{
				 	//printf("%s\n",ob->value);
				if(type==1){

					if(strlen(ob->value)>=2){

					
						if(ob->value[0]=='='&&ob->value[1]!='='){
						ob->value=	returnsCH(ob->value,1,strlen(ob->value));
				           if(standardINT(ob->value)){
						   ob->typem=INT;

							//printf(" ====== %d   -----sss   %d\n", ob->typem,INT);
						   }else{
							   	printf("该变量 %s 值 %s错误\n",ob->parametername,ob->value);
								exit(-1);						 
						   }

						}else
						{
								printf("该变量 %s 值 %s错误\n",ob->parametername,ob->value);
								exit(-1);
						}

					





					}else{
					
                                                                              if(ob->value==NULL){

                                                                     char * mp=(char *)malloc(10);
                                                                                   *mp="0\0";
					   ob->value=mp;
					}if(ob->value[0]=';'){

	                                                                  char * mp=(char *)malloc(10);
                                                                                   *mp="0\0";
					   ob->value=mp;
   
					}else if(ob->value[0]=='='){

					printf("该变量 %s 语法 %s错误\n",ob->parametername,ob->value);
					}

				}



			     



              





				}else if(type==2){

				
				printf("该变量 %s 值 %s错误\n",ob->parametername,ob->value);
				exit(-1);

				}
			}


		}else if(compareNames(ob->type,"char")){

			ob->typem=CHAR;
		}else{
			printf("找不到该类型 %s\n",ob->type);
				exit(-1);

		}

	}
//	sp->MethodStruct.paraname=list;

}





int findcontents(struct Arraylist *  op,char * top,char  * p, struct Arraylist *  storageCode){
	//printf("findcontents==========================\n");
   struct Arraylist * key=	keyso();
		int i,j;
		int bools=0;
		
	for(i=0;i<key->length;i++){
		char * ch=(char *)getarray(key,i);
		int s=strlen(ch);
		int count=0;
		
		for(j=0;j<s;j++){
			if(ch[j]==top[j]){
				count++;
			}
			
		}
		
		if(s==count){
			bools=1;
			break;
		}
		
		
		
	}
	
		//printf("findcontents=======c===================\n");

	
	if(bools){
		
		int re=cIncude(',',p);
		if(re==0){
		 int in=returnIndex('=',p);
 if(in!=0){
		 char * before=divideStr(p,in,0);
	// printf("findcontents=======c= %s==================\n",before);
    	for(i=0;i<op->length;i++){
		
	   struct parameter * para=	(struct parameter *)getarray(op,i);
        if(compareNames(before,para->parametername)){
		  setData(storageCode,para);
		return 1;
		}

	  }



		 }else{
			 int rets=compareName(op,p);
			if(rets!=0){
					// printf("findcontents=======c=ooo==================\n");
				
				  struct parameter * para=	(struct parameter *)getarray(op,rets-1);
				  
				if(compareNames(para->type,"int")){
				   

     if(para->typem==0)
				   para->typem=90001;

				      if(para->value==NULL){
				      char * txt=(char *)malloc(10);
						*txt="0";
						para->value=txt;
						setData(storageCode,para);
						 return 1;
					  }else{
				
                      		if(compareNames(para->value,"null")){		
						    free(para->value);
						       char * txt=(char *)malloc(10);
						    *txt="0";
						     para->value=txt;
						      setData(storageCode,para);
						     return 1;

							 }else if(compareNames(para->value,"")){
								 
								  free(para->value);
						       char * txt=(char *)malloc(10);
						    *txt="0";
						     para->value=txt;
						      setData(storageCode,para);
						     return 1;
								 
							 }else{
								 
							setData(storageCode,para);
		                      return 1;
								 
							 }
						  
					  }
				
				
				
				}else{
					
  if(para->typem==0)
				   para->typem=90002;
				   

					if(para->value==NULL){
						char * txt=(char *)malloc(10);
						*txt="null\0";
						para->value=txt;
						setData(storageCode,para);
						 return 1;
					}
					
					
					
				}
				
				
				
				
				
				
			}
			 
			 
			 
			 
		 }
		





//printf("findcontents=======c=d==================\n");

		
		}else{
		
		 struct Arraylist * list=splitchar(p,',');
// printf("---------------%d----------\n",list->length);
		int   count=0;
			for(i=0;i<list->length;i++){
				char * ps=getarray(list,i);
if(cIncude('=',ps)){
				 int in=returnIndex('=',ps);
				
				 char * before=divideStr(ps,in,0);
				 for(j=0;j<op->length;j++){

					   struct parameter * para=	(struct parameter *)getarray(op,j);
					
	 if(j+1==op->length){

						int ms= strlen(before);

						if(before[ms-1]==';'){
                 
								before[ms-1]='\0';
						}else if(before[ms-2]==';'){

								before[ms-2]='\0';
						}else if(before[ms-3]==';'){

							before[ms-3]='\0';
						}
							
						
					 }

  //    printf("---------------%s----------\n",before);
	         	 if(compareNames(before,para->parametername)){
                 //       printf("---------------%s------s----\n",before);
		              setData(storageCode,para);
					  count++;
	                  break;
				 }	
					
				}
			
}else{
				
				 if(i+1==list->length){
					int sim=strlen(ps);
					//printf("i+1==list->length===========%d\n",sim);
					 if(ps[sim-1]==';')
						 ps[sim-1]='\0';
					else if(ps[sim-2]==';')
						 ps[sim-2]='\0';
					
				 }
				
						//printf("i+1==list->length===========%s\n",ps);
			

	
			 for(j=0;j<op->length;j++){
					   struct parameter * para=	(struct parameter *)getarray(op,j);
				//	// printf("------------parameter---%s----------\n",ps);
					
	         	    if(compareNames(ps,para->parametername)){
					// printf("---------------%s----------\n",ps);
		              setData(storageCode,para);
					  count++;
	                  break;
				 }	
					
				}
			
					
					
					
					
				}
				 
				
				
			}
			
			if(count==list->length){
				
				return 1;
			}
			
			
			//printf("----------------------------ssss\n");
			
			
		}
	
	return -1;
	
	}else
	    return 0;
	 
	
	
	
		
		//printf("findcontents=======end===================\n");
	
}





int puremethod(struct Arraylist *  smethods ,char  * name){

     int i;
    for(i=0;i<smethods->length;i++){
     struct methods * ps =(struct methods *)getarray( smethods,i);
	if(compareNames(ps->name,name)){

       return i+1;

  	}
	}

  return 0;

}	




void setfiguregot(struct Arraylist * list,struct Arraylist * para,struct parameter  * partParams,int psize,struct Arraylist *  storageCode,char * b,int t){
		//printf("==================setfiguregot======\n");
	int i;
	int lfte=0,r=0,ib=0;
	for(i=0;i<list->length;i++){
		 lfte=0; 
                                r=0;
                               ib=0;
	  struct  expressionV * value=( struct  expressionV *)getarray(list,i);
 //  printf("========setfiguregot======%s= %s \n",value->left,value->right);
	  int bools=compareName(para,value->left);
	  if(bools!=0){
		    LOADStr(storageCode,AX,value->left);
			lfte=1;
	  }else{
		  int j,bo=0;
		  for(j=0;j<psize;j++){
			  
			 
			   if( compareNames(value->left,partParams[j].parametername)){
			      bo=1;
			     break;
			   }
		  }
		  
		  if(bo){
			  LOADStr(storageCode,AX,value->left);
		  }else{
			  if(standardINT(value->left)){
			   LOADStr(storageCode,AX,value->left);
			  }else{
			  printf("该类型不能当做数算 %s\n",value->left);
			  exit(-1);
			  }
		  }
		  
		  
		  
		  
	  }
	  
	  
	  
	  
	   bools=compareName(para,value->right);
	  
	   if(bools!=0){
		    LOADStr(storageCode,BX,value->right);
			r=1;
	  }else{
		  int j,bo=0;
		  for(j=0;j<psize;j++){
			  
			   if( compareNames(value->right,partParams[j].parametername)){
			      bo=1;
			     break;
			   }
		  }
		  
		  if(bo){
			  LOADStr(storageCode,BX,value->right);
		  }else{
			  if(standardINT(value->right)){
			   LOADStr(storageCode,BX,value->right);
			  }else{
			  printf("该类型不能当做数算 %s\n",value->right);
			  exit(-1);
			  }
		  }
		  
		  
		  
		  
	  }
	  
	  
	  if(lfte){
		  MI(storageCode,value->opem,AX,BX);
		  MOVTS(storageCode,value->left,AX);
		
	  }else if(r){
		    MI(storageCode,value->opem,AX,BX);
		    MOVTS(storageCode,value->right,AX);
			
	  }else{
		 
                                    if(t){
			   
			printf("不可以没有变量组成 %s\n",value->right);
			exit(-1);
			   
		    } 
		   
		    MI(storageCode,value->opem,AX,BX);

			//MI(storageCode,value->opem,AX,BX);
		    //MI(storageCode,MOV,DX,AX);
	  }
	  
	  
	  
	  
	
	}
	

	
	 if(t)
	  MOVTS(storageCode,b,AX);
	
	
	
	//printf("==================setfiguregot===end=\n");
	
	
	
}





int sybalSubsection(char * p,int index,int type){
// printf("===============sybalSubsection =============\n");
	int b=0;
	int e=strlen(p);
		int i;
	if(type==1){
		b=index+1;
		
		
	for(i=b;i<e;i++){
	 
	 if(p[i]=='+'){
		return i;
		}
		
	  if(p[i]=='-'){
			return i;
		}
		
	  if(p[i]=='*'){
			return i;
		}
		
	  if(p[i]=='/'){
			return i;
		}
		
		
	   if(p[i]==';'){
		 if(i+1==e)
			return i; 
		else{
			printf("少了; 在%s \n",p);
			exit(-1);
		}
		
	   }
		
		
		
	}
// printf("===============sybalSubsection ======1=======\n");
	}else{
		e=index;
	
	      //printf("%d \n",e);
	for(i=e;i>=0;i--){
	     //  printf("%d \n",i);
	 if(p[i]=='+'){
                   
		return i;
		}
		
	  if(p[i]=='-'){
			return i;
		}
		
	  if(p[i]=='*'){
			return i;
		}
		
	  if(p[i]=='/'){
			return i;
		}
		
		
		// printf("===============sybalSubsection ======2=======\n");
	}
	// printf("===============sybalSubsection ===end==========\n");
	return 0;
	
	
		
	}
	

	
	
	
	return -1;
	
	
	
	
}








struct Arraylist *    subsection (struct Arraylist * los,char * p,int type){
   struct Arraylist *  list;
	list=inif();
	  int i;
// printf("===============subsection =============\n");
	  for(i=0;i<los->length;i++){
                struct  Vsort * v  =getarray(los,i);
                int b=   sybalSubsection(p,v->index-1,0);
// printf("===============subsection ======1=======\n");
                int e=   sybalSubsection(p,v->index,1);
//printf("subsection=========%d==%d==%d\n",v->index,b,e);
				// printf("===============subsection ===2==========\n");
				if(e==-1){
					printf("缺少 ; %s \n",p);
					exit(-1);
				}
				
                               if(b!=0)
                                b=b+1;
		 char * before=getschar(b,v->index,p);
		 char * later =getschar(v->index+1,e,p);     
      struct  expressionV * value=(  struct  expressionV *)malloc(sizeof(  struct  expressionV * ));
			if(!value)
				exit(-1);
				
				value->left=before;
				value->right=later;
				value->ip=v->ip;
			if(type==1){
             value->opem=ADD;
			}else if(type==2){
                value->opem=SUB;
			}else if(type==3){
                value->opem=SURP;
			}else{
            value->opem=DIVD;
			}				
				add(list,value);
			
       }			
	
	return list;
	
}















struct Arraylist *   FindExpressionV(char * p){
 
	struct Arraylist *  list;
	list=inif();
	
	int size=strlen(p);
	int i;
	struct Arraylist *  adds,*sub,*surp,*divd;

	adds=inif();
	sub=inif();
    surp=inif();
	divd=inif();
   int index=1;

// printf("===============FindExpressionV=============\n");
	for(i=0;i<size;i++){
		
		if(p[i]=='+'){
			struct  Vsort * v=(struct  Vsort *)malloc(sizeof(struct  Vsort));
			v->index=i;
			v->ip=index;
			index++;
			add(adds,v);
		}
		
		
	  if(p[i]=='-'){
			struct  Vsort * v=(struct  Vsort *)malloc(sizeof(struct  Vsort));
			v->index=i;
			v->ip=index;
			index++;
			add(sub,v);
		}
		
	   if(p[i]=='*'){
		  struct  Vsort * v=(struct  Vsort *)malloc(sizeof(struct  Vsort));
			v->index=i;
			v->ip=index;
			index++;
			add(surp,v);
		}
		
		if(p[i]=='/'){
			struct  Vsort * v=(struct  Vsort *)malloc(sizeof(struct  Vsort));
			v->index=i;
			v->ip=index;
			index++;
			add(divd,v);
		}	
		
		
	}
	// printf("===============FindExpressionV===1==========\n");
	//=b*2/a*b;
	//2/a
   // b*a
	//a*b
	
       	struct Arraylist *  f;
		f=inif();
	struct Arraylist *  a=   subsection(adds,p,1);
	struct Arraylist *  b=  	subsection(sub,p,2);
		struct Arraylist *  c=  subsection(surp,p,3);
	struct Arraylist *  d=    subsection(divd,p,0);
	
	if(d->length!=0){
		for(i=0;i<d->length;i++){
	   struct  expressionV * value=( struct  expressionV *)getarray(d,i);
		add(f,value);
		}
	}
	
	
	if(c->length!=0){
		for(i=0;i<c->length;i++){
	   struct  expressionV * value=( struct  expressionV *)getarray(c,i);
		add(f,value);
		}
	}
	
		if(b->length!=0){
		for(i=0;i<b->length;i++){
	   struct  expressionV * value=( struct  expressionV *)getarray(b,i);
		add(f,value);
		}
	}
	
		if(a->length!=0){
		for(i=0;i<a->length;i++){
	   struct  expressionV * value=( struct  expressionV *)getarray(a,i);
		add(f,value);
		}
	}
//	 printf("===============FindExpressionV======8=======\n");
	     /* 
          if(d){
   if(d->obj)
               free(d->obj);
	free(d);
}	

    if(c){
             if(c->obj)
	free(c->obj);
	free(c);
	}
	if(b){
   if(b->obj)
                  if(b->obj)
	free(b->obj);
	free(b);
	}
  if(a){
                 if(a->obj)
	free(a->obj);
	free(a);
	}

         if(adds!=NULL){
                 if(adds->obj!=NULL)
	free(adds->obj);
	free(adds);}
	if(sub!=NULL){
 if(sub->obj!=NULL)
	  free(sub->obj);
	free(sub);}*/
/*
if(surp!=NULL){
   if(surp->obj!=NULL)
	free(surp->obj);
	free(surp);}*/
/*
 if(divd!=NULL){
   if(divd->obj!=NULL)
             free(divd->obj);
	free(divd);

}*/
	// printf("===============FindExpressionV===end==========\n");
	return f;
	
}




struct Arraylist * returntype(){
  
struct Arraylist * list=NULL;
list=inif();

char * q=(char * )malloc(10);
if(!q)
exit(-1);

 sprintf(q,"int\0");
add(list,q);

q=(char * )malloc(10);
if(!q)
exit(-1);
 sprintf(q,"char\0");

add(list,q);

 q=(char * )malloc(10);
if(!q)
	exit(-1);
 sprintf(q,"void\0");
add(list,q);


	return list;
}



int  verifyReType(struct Arraylist * lin,char * p){
	
	int i;
	for(i=0;i<lin->length;i++){
		char * ob=(char *)getarray(lin,i);
                              
		if(compareNames(ob,p)){
		   return 1;
		}
	}
	
	
	return 0;
	
	
}

