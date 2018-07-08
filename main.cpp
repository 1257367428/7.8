#include <cstdlib>
#include<stdio.h>
struct student
{
    int numbers;
    char name[20];
    char sex[20];
    int dateofbirt;
    char class1[20];
    char phoneNo[20];
    int judge1;
    int judge2;
    int judge3;
    int judge4;
    int judge5;
    int score;
};
int main()
{
    struct student s[1000];               //定义结构数组
    FILE *fp1,*fp2;                 //俩个文件指针
    int i=0,j;
    fp1 =fopen("/Users/S20171105117/Desktop/studentdata.csv","r");          //读取文件
    if(fp1==NULL)//文件为空
    {
        printf("找不到文件\n");
        exit(-1);
    }
    else
    {
     //   fscanf(fp1,"%*[^\n]%*c");            //换行
        while(!feof(fp1))
        {
            fscanf(fp1,"%d,%[^,],%[^,],%[^,],%d,%d,%d,%d,%d",&s[i].numbers,s[i].name,s[i].sex,&s[i].dateofbirt,s[i].class1,s[i].phoneNo,&s[i].judge1,&s[i].judge2,&s[i].judge3,&s[i].judge4,&s[i].judge5);
            fscanf(fp1,",",s[i].name);

            i++;
            
        }
        
        j=i;
        
        for(i=0;i<j;i++)
        {
            printf("%d",s[i].numbers);
            printf("%s",s[i].name);
            printf("%s",s[i].sex);
            printf("%d",s[i].dateofbirt);
            printf("%s",s[i].class1);
            printf("%s",s[i].phoneNo);
            printf("%d",s[i].judge1);
            printf("%d",s[i].judge2);
            printf("%d",s[i].judge3);
            printf("%d",s[i].judge4);
            printf("%d\n",s[i].judge5);
        }
        fclose(fp1);              //关闭文件
    }
    
    j=i;
    int max[100],min[100];
    for(i=0;i<j;i++)
    {
        max[i]=min[i]=s[i].judge1;//最大值给第一个数
    }
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2>max[i])
            max[i]=s[i].judge2;
        if(s[i].judge3>max[i])
            max[i]=s[i].judge3;
        if(s[i].judge4>max[i])
            max[i]=s[i].judge4;
        if(s[i].judge5>max[i])
            max[i]=s[i].judge5;
    }
    j=i;
    for(i=0;i<j;i++)
    {
        if(s[i].judge2<min[i])
            min[i]=s[i].judge2;
        if(s[i].judge3<min[i])
            min[i]=s[i].judge3;
        if(s[i].judge4<min[i])
            min[i]=s[i].judge4;
        if(s[i].judge5<min[i])
            min[i]=s[i].judge5;
    }               //最值
    j=i;
    for(i=0;i<j;i++)
    {
        s[i].score=(s[i].judge1+s[i].judge2+s[i].judge3+s[i].judge4+s[i].judge5-max[i]-min[i])/3;       //平均值
    }
    j=i;
    i=0;
    fp2=fopen("/Users/S20171105117/Desktop/student1.csv","w");         //写入文件
    fprintf(fp2,"numbers,");
    fprintf(fp2,"name,");
    fprintf(fp2,"sex,");
    fprintf(fp2,"dateofbirth,");
    fprintf(fp2,"class,");
    fprintf(fp2,"phoneNo,");
    fprintf(fp2,"judge1,");
    fprintf(fp2,"judge2,");
    fprintf(fp2,"judge3,");
    fprintf(fp2,"judge4,");
    fprintf(fp2,"judge5,");
    fprintf(fp2,"score\n");
    while(i<j)
    {
        fprintf(fp2,"%d,",s[i].numbers);
        fprintf(fp2,"%s,",s[i].name);
        fprintf(fp2,"%s,",s[i].sex);
        fprintf(fp2,"%d,",s[i].dateofbirt);
        fprintf(fp2,"%s,",s[i].class1);
        fprintf(fp2,"%s,",s[i].phoneNo);
        fprintf(fp2,"%d,",s[i].judge1);
        fprintf(fp2,"%d,",s[i].judge2);
        fprintf(fp2,"%d,",s[i].judge3);
        fprintf(fp2,"%d,",s[i].judge4);
        fprintf(fp2,"%d,",s[i].judge5);
        fprintf(fp2,"%d\n",s[i].score);
        i++;
    }
    fclose(fp2);               //关闭文件
    return 0;
}
