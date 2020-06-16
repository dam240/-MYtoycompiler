#include "befile.h"
#include "list.h"
#include "sybla.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
char  * readfile(char * filename){ 


        int r_id=open(filename,O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
	 if(r_id==-1){
            printf("找不到文件\n");       
           return NULL;
        }

	 char * index=(char *)malloc(2048);
           
      int  r=read(r_id,index,2048);


       
     if(r==-1){
    printf("clsee--> %s\n",filename);
    close(r_id);
    return NULL;
    }

    if(close(r_id)==-1){
     printf("clsee--> %s\n",filename);
     }

	 return index;


}


struct Arraylist *  pd(char * txt){

      struct Arraylist * list;
    list=inif();

	 int bin[512];
	
	 int b_cou=0;
	 int size=strlen(txt);
	  int i;
           for(i=0;i<size;i++){
		  if(txt[i]==' '||txt[i]=='\n'||txt[i]=='\r'){
			 bin[b_cou]=i;
		  b_cou++;
		  
		  }

	 }
	
	 int j=0;
	 for(i=0;i<b_cou;i++){

        //  printf("%d \n",bin[i]);
			
		int y=bin[i];
		int o=0;
		  char * ps=(char *)malloc((y-j)+1);
		  
//	printf("==================dd=================");
		 //   printf("%d \n",(y-j)+1);
		 
	     for(;j<y;j++){
		
			      if(txt[j]!=' '&&txt[j]!='\n'&&txt[j]!='\r'){

				  ps[o]=txt[j];
				  
				  o++;
				  }
					 

			  }
		  ps[o]='\0';
		  
			// 
               add(list,ps);
			 // list.push_back(ps);

		}

	  char * ps=(char *)malloc((size-j)+1);
	  int o=0;
	 for(;j<size;j++){
		 if(txt[j]!=' '&&txt[j]!='\n'&&txt[j]!='\r'){

				  ps[o]=txt[j];
				  //  printf("%c",txt[j]);
				  o++;
				  }
					 
	 }
	 // printf("%\n");

	   ps[o]='\0';
	   add(list,ps);
	 //  list.push_back(ps);
	return list;
}



int endMethds(char * p){
   int size=strlen(p),i;
   
 for(i=0;i<size;i++){
	   if(p[i]=='}'){
		   return 1;
	   }
   }
	return 0;
}

int endStructure (struct Arraylist * m,int head,int index){

      if(index<head)
                return -1;
        int re=endMethds((char *)getarray(m,index));
          if(re)
                  return index;
          else
          {         
                  re=endStructure(m,head,index-1);
                  return re;

          }

        return 0;

}


  struct Arraylist *  LOWDd( struct Arraylist *  list){
	//printf("===============LOWDd=============\n");
	//int size=;
	    struct Arraylist * lists;
		lists=inif();
		 int u=0;
	         int j,i;
		 for(i=0;i<list->length;i++){
			 char *ps=(char *)getarray(list,i);
			 		
		       	 int s= strlen(ps);
			 			
			 for(j=0;j<s;j++){
				 if(ps[j]!=' '||(j!=0&&ps[j]!='\n')||(j!=0&&ps[j]!='\r')){
					 u=1;
					 break;
				 }
			 }

			 if(u==1){
				 u=0;
				 //printf("---------------LOWDd--------ddd\n");
				 add(lists,ps);

			 }

		 }
		 
		/* size=lists.size();


		 for(i=0;i<size;i++){

			 printf("%s  \n",lists[i]);

		 }*/
		//free(list->obj);
		// free(list);

		 return lists;
}







int treHead(char * p){
	
	int size=strlen(p);
	char txes[4]="for";
	char txw[6]="while";
	char txif[3]="if";
       int i;

	for(i=0;i<size;i++){
		if(p[i]=='('&&i!=0){

			
			//printf("(  ====treHead\n");
			int count=0,j;
			while(count<3){
				int inc=0;

				int s=0;

				if(count==0)
					s=2;
				else if(count==1)
					s=3;
				else
					s=5;

			for(j=0;j<s;j++){
				if(count==0){
						//printf("%c  --- \n",p[j]);
					if(p[j]==txif[j]){
						inc++;
						//printf("%c \n",p[j]);

					}else
						break;
	
				}else if(count==1){

					if(p[j]==txes[j]){
						inc++;
						//	printf("%c \n",p[j]);
					}else
						break;

				}else if(count==2){
					if(p[j]==txw[j]){
						inc++;
						//	printf("%c \n",p[j]);
					}else
						break;
				}


			}
			
			//printf("ekswe =%d  %d\n",inc,s);

			if(inc==s){
				
				return 0;
			}


			count++;
			}



      return 1;
		}else
	     printf("\n");


	


	}


	return 2;
}





int pdthd( struct Arraylist * m,int index){
	if(index==0){
		printf("语法错误，请检查一下\n");
		    exit(-1);
	}
	int n=treHead((char *)getarray(m,index));
		// printf("pdthd()===%d\n",n);
		 if(n==1)
			 return 1;
		 else if(n==2){
			 return pdthd(m,index-1);
		 }else 
			 return 0;


	return 0;
}








 struct Arraylist * halffile( struct Arraylist * m){
	 struct Arraylist * list;
	 list=inif();
	// printf("======================being   %d   halffile \n",m->length);
	int size=m->length;
	char tx[5]="void";
	int index[50];
	int metds=0;
	int o=0,i,j,ii;
		int ub=0;
		int uend=0;
		//printf("-------------halffile---------0 \n");
	for(i=0;i<size;i++){
		char * p=(char *)getarray(m,i);
		int s=strlen(p);
		
			//printf("-------------halffile---------%d  0\n",i);
		for(j=0;j<s;j++){
			
			if(p[j]==')'){ 
				if(j+1==s){
                     //    printf("---if----------halffile-------- 0\n");
				//   printf(" uiidiudu \n");
					if(i+1!=size){
                      char * ps= (char *)getarray(m,i+1);
					   int psd=strlen(ps); 
					   // printf(" ------------------------- \n");
					   for(ii=0;ii<psd;ii++){
						   if(ps[ii]=='{'&&ii==0){
							   
							   
							  int r =treHead((char *)getarray(m,i));
							   if(r==2){
							   //printf("halffile==========if \n");

							   int n=treHead((char *)getarray(m,i-1));
							   if(n==1){
								   metds=1;

							   }else if(n==2){ //再查找
								 metds= pdthd(m,i-2);
                                 //   printf("------------fff--------=%d \n",metds);	
								   
							   }else  
								   metds=0; //是if 和

							    if(metds==1){// 是一个函数
								   index[o]=i;
								   o++;
								   
                              //  printf("if---------------------=%d \n",metds);	
								
							   }else{
							   printf(" \n");
								      //printf("metds=%d \n",metds);
							   }
								break;

							   
							   }else if(r==1){
							 metds=1;
						 }else {
							 metds=0;

					     }
						   
						   //  printf("if-------------fff--------=%d \n",metds);	
						    if(metds==1){// 是一个函数
								   index[o]=i;
								   o++;
								   
                                printf("if---------------------=%d \n",metds);	
								
							   }else{
							   
								      printf(" \n");
							   }
						   }else{
							   
							   printf("----------- \n");
						   }
					   
					   }


					}
				
				}else
				{
					// printf("halffile==========else  %d %d\n",j,s);
					if(p[j+1]=='{'){
							  // printf(" sdfffff \n");
						// printf("halffilessssdd  \n");
						 int r =treHead((char *)getarray(m,i));
					//	  printf("else r==%d \n",r);
						 if(r==2){
						  int n=treHead((char *)getarray(m,i-1));
							   if(n==1){
								   metds=1;

							   }else if(n==2){ //再查找
								 metds= pdthd(m,i-2);
                                 
							   }else  
								   metds=0; //是if 和

							
							 	//  printf(" else n==%d \n",n);

						 }else if(r==1){
							 metds=1;
						 }else 
							 metds=0;



						    if(metds==1){// 是一个函数
								   index[o]=i;
								   o++;
								   //  printf("elses---------------------=%d \n",metds);
									    break;
									
							   }else{
								   //   printf("metds=%d \n",metds);
							   }


					}


				}
			
			
			}



		  }

	
		  
	} 


  // printf("======================end   halffile \n");
   int endarry[50];
   int endcount=0;
   if(o>=1){

	for(i=1;i<o;i++){
		int c=index[i];
		char * po=(char *)getarray(m,c);
		int  re=endStructure(m,index[i-1],c);
		if(re==-1){
				printf("语法错误，请检查一下\n");
                exit(-1);
		}else if(re>1){
			//printf("------endcount-------\n");

                                                  char * isio=(char *)getarray(m,re);
                                   //   printf("%s=======%d====\n", isio,re);
			endarry[endcount]=re;
			endcount+=1;

		}
		//printf("%s %d \n",po,c);

	}

	endarry[endcount]=m->length-1;
	endcount+=1;
   
   }



//printf("==============%d ======= ===================\n",endcount);

   for(i=0;i<endcount;i++){

      int c =endarry[i];
      
//printf("%d ---000  \n",c);
	  char * po=(char *)getarray(m,c);
	 printf("%s  ------ \n",po);
	
	struct symbolMethod  * sp = FindMethdName(m,index[i],c,i==0?0:endarry[(i-1)]);
	//printf("%s------- %s---- %d \n",sp->MethodName,sp->retParam,sp->params);
	 add(list,sp);
	 //list.push_back(sp);
	   //	printf("%s------- %d \n",po,c);
   }



// printf("======================8888ddd ===================\n");


	return list;
}

