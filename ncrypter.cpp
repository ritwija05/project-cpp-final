#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
//-----------------function declaration--------------------------
void encrypt();
void decrypt();
void banner();


//----------------global variable declaration--------------------
char str[30];//string for input and output
int i,num=0;
int ConvLimit=0;
int key;

//----------------main program------------------
int main() {
  int opt;
  cout<<"Choose an option\n "
      <<"[1]Encrypt\n"
      <<"[2]Decrypt\n"
      <<"[0]Exit\n"
      <<"OPTION >>> ";
  cin>>opt;
  if (opt==1)
      encrypt();
  else if (opt==2)
      decrypt();
  else if (opt==0){
      system("clear");
      exit(0);
            }
  else {
      cout<<"\t\t\t\t\tInvalid option please try again !!!";
      main();}
  return 0;
}


void encrypt(){  //encrypt function
    cout<<"Enter text to Encrypt : ";

	for (i=0;i<250;i++)
		{
	           str[i]=getchar();
               if (i !=0 && str[i] == '\n')//stops reading when press ENTER
                    break;
		}
    ConvLimit = strlen(str);
    //cout<<;  //--DEBUG PURPOSE
    str[ConvLimit]='\0';
    str[0]='\0';
    str[ConvLimit-1]='\0';
    cout<<"Encrypted Text is :: ";
	for(i=1;i<(ConvLimit-1);i++){
      //-----------------
      if (str[i]=='\0')//used for removing occational segmentation faults
          break;
     //-----------------
     key=i%4;
     //-----------------
      num=str[i]; //letter to ASCII
      switch (key) {
          case 0 :num++;
                  break;
          case 1 :num +=2;
                  break;
          case 2 :num += 3;
                  break;
          case 3 :num+= 4;
                break;
      } //converting to next charecter
      str[i]=num;//ASCII to letter
      cout<<str[i];//print new letter
  //-------------------
    }
    cout<<endl<<'\a';
	main();
}


void decrypt(){//decrypt function same as encrypt
    cout<<"Enter text to Decrypt : ";
	for (i=0;i<250;i++)
	{
		str[i]=getchar();
		if (i !=0 && str[i] == '\n')
				break;
	}
    ConvLimit = strlen(str);
    str[ConvLimit]='\0';
    str[ConvLimit-1]='\0';
    str[0]='\0';
    cout<<"Decrypted text is :: ";

    for(i=1;i<(ConvLimit-1);i++){
//-------------------
        if (str[i]=='\0')
	       break;
//-------------------
    key=i % 4;
//-------------------
    num=str[i];
    switch (key) {
        case 0 :num--;
                break;
        case 1 :num -=2;
                break;
        case 2 :num -= 3;
                break;
        case 3 :num -= 4;
              break;
    }
    str[i]=num;
    cout<<str[i];
//-------------------
  }
    cout<<endl<<'\a';
	main();
}

