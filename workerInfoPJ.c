#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
struct Worker
{
    
    char name[50];
    int age;
    char mail[50];
    char pass[50];
};
struct Worker info[SIZE];
void userinfo();
void loginForm();
int mailValidation(char vmail[50]);
int mylenstr(char lenmail[50]);
void recordDataToFile();
void uerAction();
void printData();
int main(){
    userinfo();
    printData();
    loginForm();
    
    



    return 0;
}
void userinfo(){
    
    int rev=0;
    for(int i=0;i<SIZE;i++){
    printf("Enter your name ");
    scanf(" %[^\n]",&info[i].name);
    printf("Enter your age ");
    scanf("%d",&info[i].age);
    
    do{
    printf("Enter your mail ");
    scanf(" %[^\n]",&info[i].mail);
    rev=mailValidation(info[i].mail);
    }while (rev==1);
    
    
    printf("Enter your pass ");
    scanf(" %[^\n]",&info[i].pass); 
}

   
}

void loginForm(){
    int value=0;
    int efound,pfound;
    char lemail[50];
    char lpass[50];
    int echeckCount=0;
    int pcheckCount=0;
    
    printf("This is Login Form!!\n");
    do{
    printf("Enter your email ");
    scanf(" %[^\n]",&lemail);
    value=mailValidation(lemail);
    }while(value==1);
    mailValidation(lemail);
    printf("Enter your pass ");
    scanf(" %[^\n]",&lpass);
    int e_length=mylenstr(lemail);
    
    
    
        for (int i = 0; i < SIZE; i++)
        {
            int info_elength=mylenstr(info[i].mail);
        
        if(e_length==info_elength){
            for(int ii=0;ii<e_length;ii++){
                if(lemail[ii]==info[i].mail[ii]){
                    echeckCount++;
                }
            }
        }
        if(echeckCount==e_length){
            efound=i;
        }
        
        }
      ///printf("efound%d",efound);
        int p_lenght=mylenstr(lpass);
         int info_passlength=mylenstr(info[efound].pass);
        if (p_lenght==info_passlength)
        {
            for(int i=0;i<p_lenght;i++){
                if(lpass[i]==info[efound].pass[i])
                pcheckCount++;
            }
            if(p_lenght==pcheckCount){
            pfound=efound;
            }
        }
        
        //printf("pfound%d",pfound);
        if(efound==pfound){
            printf("Welcome Sir -%s\n",info[efound].name);
            uerAction();
        }else{
            printf("Enter Validate email and password!!\n");
            loginForm();
        }
        
        
    }

int mylenstr(char lenmail[50]){
        int count=0;
        for (int i = 0; i < 50; i++)
        {
            if (lenmail[i]=='\0')
             {
                break;
            }else{
                    count++;
                }
        }
        return count;
}
int mailValidation(char vmail[50]){
    int flag=0,length=0,validateValue=0;
    char lemail[50];
    int vmaillength=mylenstr(vmail);
    for(int i=0;i<vmaillength;i++){
        if(vmail[i+1]=='@' && vmail[i+7]=='.'){
            flag=1;
            length=i+7;
        }
    }
    if (flag!=1 && (vmaillength-length)!=4)
    {
        printf("Your mail is nor Correct. Please enter correct mail format!!\n");
        validateValue=1;
    }
    
    return validateValue;
}

void recordDataToFile(){
    FILE *fptr=fopen("workerInfo.txt","w");
    if(fptr==NULL){
        printf("Error to Open Worker Infomation File!!\n");
    }else{
        for(int i=0;i<SIZE;i++){
        fprintf(fptr,"%d %s %d %s %s%c",i+1,info[i].name,info[i].age,info[i].mail,info[i].pass,'\n');
        }
        printf("Record Worker's Data to file Successfully\n");
    }
    fclose(fptr);
}
void uerAction(){
    int action=0;
    printf("Press 1 to Main Menu \n");
    printf("Press 2 to Save data to File \n");
    printf("Press 3 to Exit \n");
    scanf(" %d",&action);
    if(action==1){
        loginForm();
    }else if(action==2){
        recordDataToFile();
    }else if(action==3){
        exit(0);
    }else{
        uerAction();
    }
}


void printData(){
     printf("Your information List from workerInfo File\n");
    for(int i=0;i<SIZE;i++){
        printf("Id-%d Name-%s Age-%d Mail-%s Password-%s\n",i+1,info[i].name,info[i].age,info[i].mail,info[i].pass);
    }
}