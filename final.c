#include <stdio.h>
typedef struct hole
{
	float  x,y,z,r;
}Hole;
int countC ;

float height[100];

float totalVol=0;
float totalHeight=0;

void CircleInput(Hole ho[10000]);
void HeightInZ(Hole ho[10000],int divide,float one,int numberofHole);

int main()
{

	int numberofHole,divide ;
	float ActualCheeseVol, oneCheeseVol;
	float cheeseVol = 1000000000000000;
	Hole Ho[10000];
	
	scanf("%d ", &numberofHole);
	scanf("%d", &divide);

	for(int i =0 ; i < numberofHole;i++) CircleInput(&Ho[i]);	
	ActualCheeseVol =  cheeseVol -totalVol;
	oneCheeseVol = ActualCheeseVol/divide;

	HeightInZ(Ho,divide,oneCheeseVol,numberofHole);
	for(int j =0 ; j< divide ; j++)
	{
		printf("%.9f \n",height[j]/1000);
	}
}	

//Gets the information of the hole
void  CircleInput(Hole ho[10000])
{
	float x,y,z,r;	
	float vol;
	scanf("%f %f %f %f", &r ,&x,&y ,&z);

			ho[countC].x = x ;
			ho[countC].y = y ;
			ho[countC].z = z ;
			ho[countC].r = r ;	
	vol = r*r*r*3.14*4.00/3.00;	
	totalVol+=vol;	
}

//calculate the height
void  HeightInZ(Hole ho[10000], int divide,float  one,int num)
{
	float vol;
	float totalVol =0;
	float h=0;
	float r[10000],z[10000];	
        double sphere[10000];
	double totalsphere=0;
	double cz[10000],cr[10000];
	int calcount=0;
	int countH=0;
	//각 구의 반지름과 z좌표값을 입력해준다. 
	for(int i  =0 ; i< num; i++)
	{
		cr[i] = ho[i].r;
		cz[i] = ho[i].z;
	}
	//구 부피 계산 과정
	while(countH<divide){	
			for(int j =0; j < num; j ++)
			{	
					if((cz[j]+cr[j])>=h&&(cz[j]-cr[j])<=h)
					{
						r[calcount]= cr[j];
						z[calcount] =cz[j];
						calcount++;
					}
					else if ((cz[j]+cr[j])<h)
					{
						r[calcount] = cr[j];
						z[calcount] = cz[j];
						calcount++;
					}
			}
			for(int i =0 ; i< calcount; i++)
			{
				if(h>r[i]+z[i])
					sphere[i] = 3.14*r[i]*r[i]*r[i]/3.00*4.00;
				else
					sphere[i] = 3.14*(r[i]*r[i]*(h-z[i])-1.00/3.00*(h-z[i])*(h-z[i])*(h-z[i]) + r[i]*r[i]*r[i]-1.00/3.00*r[i]*r[i]*r[i]);
					
			totalsphere= totalsphere+sphere[i];		
			}
				vol= h*100000*100000 - totalsphere ;	
					if(vol>=(one*(countH+1)))
					{
						if((divide-1) == countH)
							height[countH] = 100000- totalHeight;
						else 
						{	
							height[countH]=h-totalHeight;	
							totalHeight += height[countH];
						}	
							countH++;		
					}
					else 
					{
						h+=25;
					}
						totalsphere = 0;	
						calcount=0;
			}

}
