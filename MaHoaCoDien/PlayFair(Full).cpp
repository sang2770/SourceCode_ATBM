#include<bits/stdc++.h>
using namespace std;
//plaintext="ACLEANFASTISB";
//key="EASTO";
//encrypted="CIHTEPCTTOKADV";

char grid[5][5]; // ma tran khoa
char keyword[26]; // cypher key
char msg[100]; // message
int mark[130],len,r,c; // cac bien


void createGrid();//tao ma tran 
void showGrid();// show ma tran
void encipher();//ma hoa 
void decipher();//giai ma
void initialize();//khoi tao
void menu()
{
    system("CLS");
    int n;
    string op[]={"1. Encipher","2. Decipher","3. Exit"};
    cout<<op[0]<<endl<<op[1]<<endl<<op[2]<<endl<<"Enter choice: ";
    cin>>n;
    if(n==1) encipher();
    else if(n==2) decipher();
    else exit(1);
}
void initialize()
{
    memset(mark,0,sizeof(mark));// lam rong mark
    system("CLS");
}
int main()
{
    menu();
    return 0;
}
void decipher()//giai ma
{
    initialize();
    createGrid();
    cout<<"Cypher text: ";
    char cypText[150]; // van ban cypher
    cin>>cypText;
    getchar(); //bo dem
    int l=strlen(cypText); //do dai chuoi

  

    cout<<"Decipher text: ";
    //bat dau giai ma
    int P,Q,R,S,f1,f2;
    char x,y;
    for(int i=0;i<l;i+=2)
    {
        x=cypText[i];
        y=cypText[i+1];
        f1=f2=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(x==grid[j][k])//lay vi tri ky tu 1
                {
                    P=j;
                    Q=k;
                    f1=1;
                }
                if(y==grid[j][k])//lay vi tri ky tu 2
                {
                    R=j;
                    S=k;
                    f2=1;
                }
                if(f1 && f2) break;
            }
             if(f1 && f2) break;
        }
        if(P==R) //giong hang
        {
            if(Q==0) cout<<grid[P][4];
            else cout<<grid[P][Q-1];
            if(S==0) cout<<grid[R][4];
            else cout<<grid[R][S-1];//lui 1 cot
        }
        else if(Q==S ) // giong cot 
        {
            if(P==0) cout<<grid[4][Q];
            else cout<<grid[P-1][Q];
            if(R==0) cout<<grid[4][S];
            else cout<<grid[R-1][S];//lui 1 hang
        }
        else //goc doi dien
        {
            cout<<grid[P][S]<<grid[R][Q];
        }
    }
    cout<<endl<<endl;
    system("PAUSE");
    menu();
}
void encipher()
{
    initialize();
    createGrid();
    cout<<"Message to cypher: ";
    gets(msg);
    int l=strlen(msg); // chieu dai msg
    char reqText[150]; //van ban giai ma encipher
    int in=0,j=0;
    for(int i=0;i<l;i++)
    {
        j=i+1;
        if(msg[i]==' ') //loai ky tu  ' '
        {
            i++;
            j++;
        }
        if(msg[j]==' ') j++; //loaiky tu ' '
        if(toupper(msg[i])=='J') msg[i]='i'; // bo qua J
        if(toupper(msg[i])==toupper(msg[j])) // nau 2 ky tu trung nhau thi them ky tu X sau ky tu dau tien
        {
            reqText[in]=toupper(msg[i]);
            reqText[in+1]='X';
            in++;
        }
        else
        {
            reqText[in]=toupper(msg[i]);
        }
        in++;
    }
    if(in%2!=0) reqText[in]='X'; // neu ky tu le thi them 'X' vao cuoi

   

    cout<<"Cypher text: ";
    //bat dau giai ma
    int P,Q,R,S,f1,f2;
    char x,y;//cap ky tu dc tach ra
    for(int i=0;i<in;i+=2)
    {
        x=reqText[i];
        y=reqText[i+1];
        f1=f2=0;
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(x==grid[j][k])//lay ky vi ky tu 1
                {
                    P=j;
                    Q=k;
                    f1=1;
                }
                if(y==grid[j][k])//lay ky vi ky tu 2
                {
                    R=j;
                    S=k;
                    f2=1;
                }
                if(f1 && f2) break;
            }
             if(f1 && f2) break;
        }
        if(P==R) //trung hang
        {
            if(Q==4) cout<<grid[P][0];
            else cout<<grid[P][Q+1];
            if(S==4) cout<<grid[R][0];
            else cout<<grid[R][S+1];//tien 1 hang
        }
        else if(Q==S ) // trung cot
        {
            if(P==4) cout<<grid[0][Q];
            else cout<<grid[P+1][Q];
            if(R==4) cout<<grid[0][S];
            else cout<<grid[R+1][S];//tien 1 cot
        }
        else //goc doi dien
        {
            cout<<grid[P][S]<<grid[R][Q];
        }
    }
    cout<<endl<<endl;
    system("PAUSE");
    menu();
}
void createGrid()
{
    cout<<"Keyword: ";
    cin>>keyword; // nhap key work
    getchar();
    len=strlen(keyword);  // kich thuoc key
    mark['J']=1; // ignore J
    r=0,c=0; //tao hang cot

    //chen khoa vao ma tran
    for(int i=0;i<len;i++)
    {
        if(!mark[toupper(keyword[i])]) // bo qua ky tu trung trong key (toupper :chuyen thanh chu hoa)
        {
            mark[toupper(keyword[i])]=1;
            grid[r][c++]=toupper(keyword[i]);
            if(c%5==0) //tang cot hang
            {
                c=0;
                r++;
            }
        }
    }

    // dien cac ky tu con lai trong bang cu cai A
    for(int i='A';i<='Z';i++)
    {
        if(mark[i]==0) // lay cac gia tri ko co trong ma tran
        {
            grid[r][c++]=i;
            mark[i]=1;
            if(c%5==0)
            {
                if(r==4 && c==5) break; //dung ma tran

                // tang cot hang
                r++;
                c=0;
            }
        }
    }
}
void showGrid()
{
    cout<<"5x5 Matrix"<<endl;
    //show grid
   for(int i=0;i<5;i++)
   {
       for(int j=0;j<5;j++)
       {
           cout<<grid[i][j]<<" ";
       }
       cout<<endl;
   }
}
