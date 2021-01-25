#include<iostream>
#include<conio.h>

using namespace std;
#define TRUE 1
#define FALSE  0
#define INF 10000000

int n,s,t;     //n: so dinh cua do thi, s: dinh dau, t: dinh cuoi
int truoc[100];//mang danh dau duong di
int d[100];//mang danh dau khoan cach
int Matrix[100][100];//ma tran trong so
int chuaxet[100];//mang danh dau dinh da duoc gán nhãn.

void docfile(void){
	freopen("bellman.txt","r", stdin);
 	cin>>n;
 	cout<<"So dinh : "<< n<<endl;
	cin>>s>>t;       //nhap dinh dau va dinh cuoi cua do thi

 //nhap ma tran cua do thi
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin>>Matrix[i][j];
			if (Matrix[i][j] == 0) Matrix[i][j] = INF;

  		}

 	}

}

void Ketqua(void)
{
 	cout<<"Duong di ngan nhat tu "<<(char)(s+'A'-1)<<" den "<<(char)(t + 'A' -1)<< " la: ";
 	cout<<(char)(t + 'A' - 1)<<"<=";//in dinh cuoi duoi dang char.
 	int i = truoc[t];

 	while (i != s)
	{
		cout<<(char)(i +'A' -1)<<"<=";//in ra ket qua duoi dang char.
  		i = truoc[i];
	
 	}
 	cout<<(char)(s+'A' -1);//in dinh dau duoi dang char.
 	cout<<endl<<"Do dai duong di la : "<< d[t];
}	

void Cacbuoc(void)
{

	for(int i=0;i<n;i++)
	{
		if(i!=truoc[i])
		{
			cout<<endl;
			cout<<endl<<" Khoan cach ngan nhat tu "<<(char)(s+'A'-1)<<" den "<<(char)(i +'A' -1)<<" la: ";
			//cout<<endl<<"Khoan cach cua nut"<<i<<" den "<<d[i]<<" la: ";
			cout<<d[i];
			
			int j=i;
			do
			{
				j=truoc[i];
				cout<<endl<<"Duong di: "<<(char)(s+'A'-1)<<" => "<<(char)(j +'A'-1)<<" =>"<<(char)(i +'A' -1);
			//	cout<<" <= "<<j;
			//	printf("<- %d",j);
			}while(j!=truoc[i]); 

		}
	}
}

void Bellmanford(void)
{
	int u, minp;

 //khoi tao nhan tam thoi cho cac dinh
 	for (int v = 1; v <= n; v++)
	{
  		d[v] = Matrix[s][v];
  		truoc[v] = s;
  		chuaxet[v] = FALSE;
 	}

 	truoc[s] = 0;
 	d[s] = 0;
 	chuaxet[s] = TRUE;
 	
 	//buoc lap
 	while (!chuaxet[t]) 
 	{
  		minp = INF;
  		
  		//tìm dinh u sao cho d[u] là nho nhat
  		for (int v = 1; v <= n; v++)
		{
   			if ((!chuaxet[v]) && (minp > d[v]))
			{
			   	u = v;
    			minp = d[v];

   			}

  		}

  		chuaxet[u] = TRUE;// u la dinh co nhan tam thoi nho nhat
  		if (!chuaxet[t])
		{
   			//gan nhan lai cho cac dinh
   			for(int i=1;i<=n-2;i++)     // buoc 2: lap
			{
				for(int u=1;u<=n;u++)
				{
					if(i!=s)
					{
						for(int v=1;v<=n;v++)
						{
							if((Matrix[u][v]!=INF)&&(d[u]!=INF)&&(d[v]>d[u]+Matrix[u][v]))
							{
								d[v]=d[u]+Matrix[u][v];
								truoc[v]=u;
							}
						
						}
					}
				}
			}
		}
    }
}
 	

int main(void)
{
	docfile();
	Bellmanford();
	Ketqua();
	Cacbuoc();
	getch();

}

