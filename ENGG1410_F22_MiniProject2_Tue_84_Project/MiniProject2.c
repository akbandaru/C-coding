#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
    }

    void swapInt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    }

void bubleSort(float array[], int indexAry[], int n){
    int k,l;
    for(k = 0; k < n-1; k++){
        for(l = 0; l < n-k-1;l++) {
            if (array[l] > array[l+1]) {
                swap(&array[l], &array[l+1]);
                swapInt(&indexAry[l], &indexAry[l+1]);
                //swapChar(nameArray[l], nameArray[l+1]);
            }
        }
    }
}

char *readLine(FILE *fp, char *buffer) {
   
    size_t buff_len = 80;
    buffer = malloc(sizeof(char) * buff_len);
    if (!buffer) {
        return NULL;
    }
    if(fgets(buffer, buff_len, fp) == NULL) {
        return NULL;
    }
    
     return buffer;
}

struct our_user
{
    char user[30];
    int time;
    float altitude;
    float longitude;
    float latitude;

};

struct other_user
{
    char name[30];
    int time1;
    float altitude1;
    float longitude1;
    float latitude1;

};


int main (int argc, char *argv[])
{

    int i,j,user_num,y;
    float alt_dif,lat_dif,long_dif,mag,a,b,c;
    a = 0;
    b = 0;
    c = 0;
    lat_dif = 0;
    long_dif = 0;
    alt_dif = 0;
    float our_homie[3];
    char mainUserName[30];
    int mainUserTime;
    float mainUserAlt, mainUserLong, mainUserLat;

    struct our_user main_user;
    char *fileName ;

    if (argc == 2) {
        fileName = argv[1];
    } else {
        printf("Please provide the sample user details");
    }

    FILE *file = fopen (fileName, "r");

    if (file != NULL) {
        char *s = readLine(file, 0);
        //printf("\n Readline string %s", s);
        sscanf(s, "%d", &user_num);
        //free(s);
        s = readLine(file, 0);
        //printf("\n Readline string %s", s);
        //strcpy(main_user.user, s);
        sscanf(s, "%s", &mainUserName);
        s = readLine(file, 0);
        sscanf(s, "%d", &mainUserTime);
        s = readLine(file, 0);
        sscanf(s, "%f", &mainUserAlt);
         s = readLine(file, 0);
        sscanf(s, "%f", &mainUserLong);
         s = readLine(file, 0);
        sscanf(s, "%f", &mainUserLat);
  
    

        printf("\n number of users :%d", user_num);
        
        strcpy(main_user.user,mainUserName);
        main_user.time = mainUserTime;
        main_user.altitude = mainUserAlt;
        main_user.longitude = mainUserLong;
        main_user.latitude = mainUserLat;
        printf("\n%s", main_user.user);
        printf("\n%d",main_user.time);
        printf("\n%f",main_user.altitude);
        printf("\n%f",main_user.longitude);
        printf("\n%f",main_user.latitude);
        our_homie[0] = main_user.altitude;
        our_homie[1] = main_user.longitude;
        our_homie[2] = main_user.latitude;

        // printf("Enter the number of user: ");
        // scanf("%d",&user_num);
        float GPS[user_num];
        int indexArry[user_num];
        // float alt[user_num];
        // float lon[user_num];
        // float lat[user_num];
        struct other_user record[user_num];
        
        for(i = 0; i < user_num; i++){
            s = readLine(file, 0);
            sscanf(s, "%s",&record[i].name);
            s = readLine(file, 0);
            sscanf(s, "%d",&record[i].time1);
            s = readLine(file, 0);
            sscanf(s, "%f",&record[i].altitude1);
            s = readLine(file, 0);
            sscanf(s, "%f",&record[i].longitude1);
            s = readLine(file, 0);
            sscanf(s, "%f",&record[i].latitude1);

            printf("\nRecord of Students: %s",record[i].name);
            printf("\nTime: %d ",record[i].time1);
            printf("\nAltitude: %f ",record[i].altitude1);
            printf("\nLongitude: %f ",record[i].longitude1);
            printf("\nLatitude: %f ",record[i].latitude1);
            
            /*alt[i] = record[i].altitude1;
            lon[i] = record[i].longitude1;
            lat[i] = record[i].latitude1;
            printf("%f %f %f \n",alt[i],lon[i],lat[i]);*/
        }
     

    for(j = 0;j < user_num;j++){
        struct our_user main_user;
        //alt_dif = our_homie[0] - alt[j];
        //lat_dif = our_homie[2] - lat[j];
        //long_dif = our_homie[1] - lon[j];

        alt_dif = our_homie[0] - record[j].altitude1;
        lat_dif = our_homie[2] - record[j].latitude1;
        long_dif = our_homie[1] - record[j].longitude1;

        a = pow(alt_dif,2);
        b = pow(lat_dif,2);
        c = pow(long_dif,2);

        mag = a + b + c;
        indexArry[j] = j;
        GPS[j] = pow(mag,0.5);
        
        printf("\n%s - %f",record[indexArry[j]].name, GPS[j]);
    }


    bubleSort(GPS, indexArry, user_num);
    printf("\n********************* Positions Sorting *******************************");
    printf("\n********************Sorting Index - Other User Name - Time - Magnitude*****************");
    for(y = 0; y < user_num;y++){
        printf("\n%d - %s - %d - %f",y+1, record[indexArry[y]].name, record[indexArry[y]].time1, GPS[y]);
    }
     }

    fclose(file);
    return 0;
}