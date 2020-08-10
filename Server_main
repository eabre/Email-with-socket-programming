#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>


FILE *fp;
FILE *dosya;
FILE *fp_2;

int main()
{

    //variables
    char texter[2048]={0};
    char texter_temp[2048]={0};
    int count =0;
    char command[1024]="ip r first.txt";
    char command_second[1024]="ip r > second.txt";
    char command_2[1024];
    char mail_basics[1024]="curl --ssl-reqd \
                        --url 'smtps://smtp.gmail.com:465' \
                        --user 'barann.tanrverdi@gmail.com:Ozlem1972' \
                        --mail-from 'barann.tanrverdi@gmail.com' \
                        --mail-rcpt 'barann.tanrverdi@gmail.com' \
                        --upload-file dosya.txt";
    char command_from_client[256];
    int server_socket;
    int client_socket;



    //socket programming configuration
    struct sockaddr_in server_address;
    server_address.sin_family =AF_INET;
    server_address.sin_port =htons(9002);
    server_address.sin_addr.s_addr= htonl(INADDR_ANY);

    //creating a socket
    server_socket = socket(AF_INET,SOCK_STREAM,0);

    //server connections
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(server_socket, 5);
    client_socket = accept(server_socket, NULL, NULL);


    //receiving password and control
    recv(client_socket, &command_from_client, sizeof (command_from_client),0 );
    if(!strcmp(command_from_client,"1998"))
    {

            memset(command_2, 0, sizeof(command_2));

            send(client_socket, "access successful", sizeof("access successful"), 0);
            bzero((char *) &command_from_client, sizeof(command_from_client));
                                //30 sec. control; if there is no difference, the system won't send nothing
                                while(1)
                                {
                                        // first ip info
                                        system(command);
                                        fp= fopen("first.txt","r");
                                        while (1)
                                        {


                                                texter[count]= fgetc(fp);
                                                count++;
                                                if(feof(fp))
                                                {
                                                break;
                                                }
                                        }
                                        count= 0;
                                        if(fp == NULL)
                                        {
                                                printf("Could not find first.txt\n");

                                                return -1;
                                        }
                                        fseek(fp, 0, SEEK_SET);
                                        fclose(fp);

                                        printf("************************loading...***********************\n\n\n");
                                        sleep(10);
                                        printf("***************sending a new ip was finished*************");


                                        //second ip info
                                        system(command_second);
                                        fp_2 = fopen("second.txt","r");
                                        if(fp_2 == NULL)
                                        {
                                                printf("Could not find second.txt\n");
                                                return -1;
                                        }
                                        while (1)
                                        {

                                                texter_temp[count]= fgetc(fp_2);

                                                count++;
                                                if(feof(fp_2))
                                                {
                                                        break;
                                                }
                                        }
                                        count= 0;

                                        fseek(fp_2, 0, SEEK_SET);
                                        fclose(fp_2);
                                        printf("\nFIRST\n\n%s\nSECOND\n\n%s",texter, texter_temp);
                                        sleep(5);
                                                //comparing ips
                                                if(strcmp(texter,texter_temp) == 0)
                                                {
                                                                printf("***********************************same ip****************************************");
                                                                sleep(5);
                                                }
                                                else
                                                {
                                                                strcat(command_2,"From: \"Mail Bot\" <barann.tanrverdi@gmail.com>\n");
                                                                strcat(command_2,"To: \"Myself\" <barann.tanrverdi@gmail.com>\n");
                                                                strcat(command_2,"Subject: This is a test\n");
                                                                printf("\n command 2 is %s \n",command_2);
                                                                dosya = fopen("dosya.txt","w");
                                                                fprintf(dosya,"%s \n\n\n\n%s", command_2, texter);
                                                                fclose(dosya);
                                                                system(mail_basics);
                                                                memset(command_2, 0, sizeof(command_2));
                                                                printf("***********************************new ip was sent*************************************");
                                                                sleep(5);
                                                }
                                        memset(texter, 0, sizeof(texter));
                                        memset(texter_temp, 0, sizeof(texter_temp));
                                }

    }
    else
    {
            send(client_socket, "wrong password", sizeof("wrong password"), 0);
            exit(1);
    }
    send(client_socket, "proccess finished", sizeof("proccess finished"), 0);
    close(server_socket);
    return 0;
}
