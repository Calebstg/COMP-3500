#include <dirent.h>
#include <stdio.h>

void alphabetlettercount(char *path, char *filetowrite, long alphabetfreq[])
{
    DIR *d;//to open a directory
    struct dirent *dir;//to get a file or sub-directory in particular directory

    char extension[5];//will store last 4 characters of extrected file name for extension checking
    char fullPath[50];//to hold full path (path + extrected name of .txt file)
    FILE *fp;//file pointer variable
    int len=0; //to hold the length of current file name with extension example abcd.txt have length 8
    int character;//to get the character from file......................later on same variable will be used to hold the corresponding variable with respect to posigion in alphabetfreq array
    int position=-1;//to hold position in alphabetfreq array, so we can find on what position we need to increment the frequency on its occurence.
    int i;//loop counter

    d = opendir(path);//open directory

    if(d)//check if directory is open
    {
        while ((dir = readdir(d)) != NULL)//get file or sub-directory till exixt
        {
            //to get extension of extrected file name
            len=strlen(dir->d_name)-1;
            extension[0]=(dir->d_name)[len-3];
            extension[1]=(dir->d_name)[len-2];
            extension[2]=(dir->d_name)[len-1];
            extension[3]=(dir->d_name)[len];
            extension[4]='\0';//to terminate the char array as string
            if(strcmp(extension,".txt")==0)//check extension
            {
                //create a full path of found .txt file
                strcpy(fullPath,path);
                strcat(fullPath,dir->d_name);

                fp=fopen(fullPath,"r");//open the file
                if(fp)//check if file is open or not
                {
                    while((character=fgetc(fp))!=EOF)//get characters from file
                    {
                        position=-1;//initially set position to -1 which is an invalid position

                        if(character<='Z'&&character>='A')// if A<=character<=Z
                        {
                            position=(int)character-65;//if character is 'A' then its position in alphabetfreq array should be 0; ASC II value of 'A' is 65 and A(65)- 65 =0 so we found the actual position .
                        }
                        else if(character<='z'&&character>='a')// if a<=character<=a
                        {
                            position=(int)character-97+26;//if character is 'a' then its position in alphabetfreq array should be 26; ASC II value of 'a' is 97 and a(97)- 97 + 26 =26 so we found the actual position .
                        }
                        else if(character=='.')// for '.'
                        {
                            position=52;
                        }
                        else if(character==',')// for ','
                        {
                            position=53;
                        }
                        else if(character==':')// for ':'
                        {
                            position=54;
                        }
                        else if(character==';')// for ';'
                        {
                            position=55;
                        }
                        else if(character=='!')// for '!'
                        {
                            position=56;
                        }
                        else
                        {
                            //skip;
                        }

                        if(position!=-1)// check if position is invalid or not
                        {
                            alphabetfreq[position]++;// if not then increment the frequency of founf character position.
                        }
                    }
                }
                fclose(fp);//close current found .txt file
            }
        }
        closedir(d);//close the directory

        fp=fopen(filetowrite,"w");//open the output file
        if(fp) //check if file is open
        {
            character=-1;//initially set character to -1

            for(i=0;i<57;i++)//to get character according to alphabetfreq array position (0...25 is A...Z, 26...51 is A...Z, 52 is '.', 53 is ',', 54 is ':', 55 is ';', 56 is '!')
            {
                if(i<=25&&i>=0)
                {
                    character=i+65;
                }
                else if(i<=51&&i>=26)
                {
                    character=i-26+97;
                }
                else if(i==52)
                {
                    character='.';
                }
                else if(i==53)
                {
                    character=',';
                }
                else if(i==54)
                {
                    character=':';
                }
                else if(i==55)
                {
                    character=';';
                }
                else if(i==56)
                {
                    character='!';
                }

                fprintf(fp,"%c -> %ld\n",character,alphabetfreq[i]);//store the resultant frequency with corresponding character in output file
            }
            fclose(fp);//close the file
        }
        else
        {
            printf("\nUnable to open output file...!!!\n");
        }
    }
    else
    {
        printf("\nDirectory Not Found...!!!\n");
    }
}

int main(void)
{
    int i;
    char path[30];
    char fileToWrite[50];
    long alphabetfreq[57];

    strcpy(path,"C:/Users/Caleb/Desktop/");//copy path or take it from user
    strcpy(fileToWrite,"C:/Users/Caleb/Desktop/fileToWrite.txt");//copy output file name or take it from user

    for(i=0;i<57;i++)//initializ the frequency of each acceptable character to 0 in alphabetfreq array
    {
        alphabetfreq[i]=0;
    }

    alphabetlettercount(path,fileToWrite,alphabetfreq);// call function

//check output file after execution of program .

    return(0);
}