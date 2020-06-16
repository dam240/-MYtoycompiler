#include "sybla.h"
#include <stdio.h>
#include <stdlib.h>
#include "list.h"




int ReturnEndPart(char * p){
	int size=strlen(p);
         int i;
	for(i=0;i<size;i++){
		if(p[i]==')')
			return i;

	}
	return 0;
}


int ReturnHeadPart(char * p){
	int size=strlen(p);
	int i;
      for( i=0;i<size;i++){
		if(p[i]=='('){
			//printf("ReturnHeadPart=========%c  %d\n",p[i],i);
			return i;
		}
	}
	return 0;
}




int ReturnMoPart(char * p){
	int size=strlen(p);
        int i;
	for( i=0;i<size;i++){
		if(p[i]==',')
			return i;

	}
	return 0;
}





void setcode(struct  symbolMethod * m, struct Arraylist * p,int index,int endddd){

	//printf("============setcode==========\n");
//	if(m->code==NULL)

	char  * ps=(char *)getarray(p,index);
	int size=strlen(ps);
 int i,j;
	//printf("%s 000ss   %d\n",(char *)getarray(p,index), size);
	if(size==1&&ps[0]=='{'){
		index=index+1;

	}else if(size>1&&ps[0]=='{'){
		char * pd=(char *)malloc(size-1);
		for(i=1,j=0;i<size;i++,j++){
			pd[j]=ps[i];
		}
	      add(m->code,pd);
		 	index=index+1;
	}

	
	
	for( i=index;i<endddd;i++){
		ps=(char *)getarray(p,i);
		add(m->code,ps);
      	
	}
	//printf("============setcode======end====\n");
}








char * FindMethdNames(char * p,int end){
	  //int size=strlen(p);
	   char * name=(char *)malloc(end);
	   int i=0;
	   for(;i<end;i++){
		   name[i]=p[i];
	   }
	    name[i]='\0';
	   return name;

}






 struct symbolMethod * FindMethdName( struct Arraylist * m,int index,int endddd,int other){
	// printf("FindMethdName  =====================\n");
	char * p=(char *)getarray(m,index);
	  int size=strlen(p);
	 struct symbolMethod * ms=(struct symbolMethod *)malloc(sizeof(struct symbolMethod));
	  ms->code=inif();
	  int bin=0;
	  int scend=0;
	  int in=0,i,j;

		for(i=0;i<size;i++){
			if(p[i]=='('){
                bin=i;
				continue;
			}
			if(p[i]==')')
				scend=i;
	     }
		 
		 	// printf("FindMethdName  =====1================\n");
		 
		if(scend!=0&&bin!=0){
			ms->params=0;

			if(bin+1==scend){
					// printf("FindMethdName  =====bin+1==scend=======dddddd=========\n");
				
				
		     ms->retParam=(char *)getarray(m,index-1);
			ms->MethodName=FindMethdNames(p,bin);
			// printf(" 方法 %s \n",ms->MethodName);
			 if(scend+1==size||p[scend+1]=='\n'){
				//printf("scend====s  \n");
			 }else{
				 if(p[scend+1]=='{'){
					// printf("scend===={  %d  %d \n",scend,size);

					  if(p[scend+2]=='\0'){
						  //printf("scend===={  %d  %d \n",scend,size);
						 for(i=index+1;i<endddd; i++ ){
						       p=(char *)getarray(m,i);
							 //  printf(" %s \n",p);
							   add( ms->code,p);
							 // ms.code.push_back(p);

						 }

					  }


				 }


			 }



			}else{
				printf("等处理\n");
			}


		}else if(scend==0&&bin!=0){
						// printf("FindMethdName  =====scend==0&&bin!=0======dddddd=========\n");
			   ms->retParam=(char *)getarray(m,index-1);
			   ms->MethodName=FindMethdNames(p,bin);
			  // char * obj=p;
			         int in=0;
				   for(i=index+1;i<endddd;i++ ){
					   p=(char *)getarray(m,i);
			        int re= ReturnEndPart(p);
					if(re!=0){
						scend=re;
						in=i;
						break;
					}
				   }
				   setcode(ms,m,in,endddd);
                  //    printf("FindMethdName        =====scend==0&&bin!=0   1        \n");

				  j=index;
				  char  * arry=(char *)malloc(50);
				  int o=0;
				   while (j<endddd)
				  {
					    p =(char *)getarray(m,j);
						int ds=0;
						if(j==index){
							ds=bin;
						}else if(j+1==endddd){
							ds=0;
							size=in;
						}else{
						    ds=0;
						    size=strlen(p);
						}
					   for(i=ds;i<size;i++){
					       
						   arry[o]=p[i];
						   o++;
				       }
			            j++;
				   }

				 ms->Paramscode=arry;
				// printf(" 方法 %s \n",ms->MethodName);
				// printf("%s wwwww\n",arry);

		}else if(scend!=0&&bin==0){
				 	// printf("FindMethdName  =====scend!=0&&bin==0======dddddd=========\n");


		            int re=0;
					int in=0;
					for(i=other;i<endddd;i++){
				// printf("other  \n");
                   
                    bin= ReturnHeadPart((char *)getarray(m,i));
					//   printf("other   %d \n",bin);
					if(bin!=0){
						in=i;
						break;
					}
			}
					//printf("---dd----%d \n",m->length);
					setcode(ms,m,index+1,endddd);
//       printf("FindMethdName  =====scend!=0&&bin==0= 1        \n");

			//printf("-------%d \n",bin);
			 ms->retParam=(char *)getarray(m,in-1);
			// printf("----dddd---%s \n",getarray(m,in-1));

		    ms->MethodName=FindMethdNames((char *)getarray(m,in),bin);
			

			      j=in;
				  char  * arry;
				  int o,ui=0;

				//  printf("%d aaaa\n",index-j);
				    ms->params=index-j;
					
				struct  parameter * sp=(struct parameter *)malloc(sizeof(struct parameter)*ms->params);
				  if(sp==NULL){
					  printf("内存\n");
		              exit(EXIT_FAILURE);
				  }


				  while (j<=index)
				  {
		             arry=(char *)malloc(strlen(p));
					    p =(char *)getarray(m,j);
						int ds=0;
						if(j==in){
							ds=bin+1;
							size=strlen(p);

					
						}else if(j==index){
						  ds=0;
						  size=scend;
	//  printf("======vbvvv===%c\n",p[size]);
						    //size=strlen(p);

						}else{
						    ds=0;
						    size=strlen(p);

						}
						o=0;
					   for(i=ds;i<size;i++){
					       
						     
							   arry[o]=p[i];
							 // printf("%c" , p[i]);
							// printf("%c" , arry[o]);
							    o++;
								//  printf("%c -"  ,p[i]);



					   }
					   if(j!=in){
					   arry[o++]='\0';
					    int s=ReturnMoPart(arry);
						size=strlen(arry);

					if(s!=0){

						char * e=(char *)malloc(s+2);
							int i=0;
							int jj;
						for(jj=0;i<s;i++,jj++){
							e[jj]=arry[i];
						}
						e[i]='\0';

						//printf("%s==\n",e);
						
						//struct  parameter * ps =getarray(sp,ui);
						// ps->parametername=e;
                                                                                             sp[ui].parametername=e;
						  ui++;
						char * es=(char *)malloc((size-s)+2);
					
						for( jj=0;i<size;i++){
						
							if(arry[i]!=','){
							es[jj]=arry[i];
							jj++;
							}

							if(i+1==size)
							 es[jj]='\0';
						}
					
					    // ps =getarray(sp,ui);
						// ps->type=es;
						sp[ui].type=es;
						//printf("%s====9=\n",es);

					      }else{
                      //   struct  parameter * ps3 =getarray(sp,ui);
						// ps3->parametername=arry;
							  sp[ui].parametername=arry;

					      }


					   }else
					   {
						 // struct  parameter * ps2 =getarray(sp,ui);
						  // ps2->parametername=arry;
						    arry[o++]='\0';
						  sp[ui].type=arry;
						   // printf("%s======---------======== 00--\n",arry);
					   }
					    
					  //  printf("%d jj\n",j);

			            j++;


				   }

				
				  ms->partParams=sp;
		      	//  printf(" 方法 %s \n",ms->MethodName);
			// printf("%s ==============\n",arry);


				 // printfparameter(ms->partParams, ms->params);

				







		}

		//printf("-----ms-----------------\n");
		return ms;
}



