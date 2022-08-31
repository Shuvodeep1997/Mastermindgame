#include <cstdio>
#include <iostream>
#include <vector>
#include<string.h>
#include<cmath>
#include<ctime>
using namespace std;
#include "togasat.hpp"

const char clrs[10]={'R','B','G','Y','O','P','W','K','\0'};

vector<vector<int> > vec;

int* matches(string res,string fin,int* arr)
{
	int c=0,i,j;
	char str1[100];
	char str2[100];
	strcpy(str1,res.c_str());
	strcpy(str2,fin.c_str());
	//cout<<str1[3];
	//int l=strlen(res);
	for(i=0;i<4;i++)
	{
		if(str1[i]==str2[i])		//str1->codemaker
		{
			//cout<<str1[i];
			//cout<<endl;
			c++;
			//cout<<"c value:"<<c;
			//cout<<endl;
		}
	}
	arr[1]=c;
	c=0;
	for (i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(str1[i]==str2[j] && i!=j)
				c++;
		}
	}
	arr[2]=c;
//	for(i=1;i<=3;i++)
//		cout<<arr[i];
//	cout<<endl;
	return arr;
}

std::vector<int> findSAT(){
    togasat::Solver solver;
    for(int i=0; i< vec.size(); i++){
        solver.addClause(vec[i]);
    }
    solver.solve();
    return solver.assigns;
    //solver.printAnswer();
    //cout<<"truth value: "<<solver.assigns[2]<<endl;
}


int get_var_number(int pos,char clr)
{
	int i,index;
	for(i=0;i<strlen(clrs);i++)
		if(clrs[i]==clr)
			return i*4+pos;
	return -1;
}

void get_color(int *pos, char *clr, int var_no){
	*clr = clrs[(var_no-1)/4];
	*pos = (var_no-1)%4+1;
}

int main(void)
{    
	 togasat::Solver solver;
    std::vector<int> clause;
// 1-R1,2-R2,3-R3,4-R4,5-B1,6-B2,7-B3,8-B4,9-G1,10-G2,11-G3,12-G4,13-Y1,14-Y2,15-Y3,16-Y4,17-O1,18-O2,19-O3,20-O4,21-P1,22-P2,23-P3,24-P4,25-W1,26-W2,27-W3,28-W4,29-K1,30-K2,31-K3,32-K4
    int i,j;
    
    clause.clear();
    for(i=1;i<=32;i=i+4)
    {
    	clause.push_back(i);
    	
	}
	vec.push_back(clause);
    //solver.addClause(clause);
    
    clause.clear();
    for(i=2;i<=32;i=i+4)
    {
    	clause.push_back(i);
	}
	vec.push_back(clause);
    //solver.addClause(clause);
    
    clause.clear();
    for(i=3;i<=32;i=i+4)
    {
    	clause.push_back(i);
	}
	vec.push_back(clause);
    //solver.addClause(clause);
    
    clause.clear();
    for(i=4;i<=32;i=i+4)
    {
    	clause.push_back(i);
	}
	vec.push_back(clause);
    //solver.addClause(clause);
   
   	for(i=1;i<=4;i++)
   	{
   		for(j=1;j<=4;j++)
		   if(i!=j)
		   {
		    	clause.clear();
				clause.push_back(-i);
				clause.push_back(-j);
				vec.push_back(clause);
    			//solver.addClause(clause);
	//			findSAT();	
		   }	
	}
   
   for(i=5;i<=8;i++)
   {
   	for(j=5;j<=8;j++)
   		if(i!=j)
   		{
   			//cout<<"i value and j value : "<<i<<","<<j<<endl;
			clause.clear();
    		clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    	//	solver.addClause(clause);
    //		findSAT();
    	}
	}
    
   for(i=9;i<=12;i++)
   {
   	for(j=9;j<=12;j++)
   		if(i!=j)
   		{
			clause.clear();
    		clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    //		findSAT();
    	//	solver.addClause(clause);
    		
    	}
	}
	
	for(i=13;i<=16;i++)
   {
   	for(j=13;j<=16;j++)
   		if(i!=j)
   		{
			clause.clear();
    		clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    	//	solver.addClause(clause);
    		
    //		findSAT();
    	}
	}
	
	for(i=17;i<=20;i++)
   {
   	for(j=17;j<=20;j++)
   		if(i!=j)
   		{
			clause.clear();
    		clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    	//	solver.addClause(clause);
    //		findSAT();
    	}
	}
	
   for(i=21;i<=24;i++)
   {
   	for(j=21;j<=24;j++)
   		if(i!=j)
   		{
			clause.clear();
    		clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    	//	solver.addClause(clause);
    //		findSAT();
    	}
	}
	
   for(i=25;i<=28;i++)
   {
   	for(j=25;j<=28;j++)
   		if(i!=j)
   		{
   			//cout<<"i value and j value : "<<i<<j<<endl;
			clause.clear();
    		clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    	//	solver.addClause(clause);
    	//	findSAT();
    	}
	}
	
	
   for(i=29;i<=32;i++)
   {
   	for(j=29;j<=32;j++)
   		if(i!=j)
   		{
			clause.clear();
    		clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    	//	solver.addClause(clause);
    	//	findSAT();
    	}
	}
    
    for(i=1;i<=28;i++)
    {
    	for(j=i+4;j<=32;j=j+4)
    	{
			clause.clear();
	    	clause.push_back(-i);
    		clause.push_back(-j);
    		vec.push_back(clause);
    	//	solver.addClause(clause);
    	//	findSAT();
    	}
	}
	srand(time(0));
	const char ch[10]={'R','B','G','Y','O','P','W','K','\0'};
	char ch1[10]={'R','B','G','Y','O','P','W','K'};
	string actual="";
	random_shuffle(ch1, ch1+8);
	for(i=0;i<4;i++)
	{
		
		actual+=ch1[i];
	}
	cout<<"guess is: "<<actual<<endl;
    string guess="RGYW";
    char choice;
    int c1,c2,c3,c4,f1,f2,f3,f4,l;
    int varnumarr[4];
    int bw[3];
    for(i=1;i<=100;i++)
    {
    	cout<<"itteration " <<i<<": "<<guess<<endl;
    	matches(guess,actual,bw);
    	for(j=0;j<4;j++)
    		varnumarr[j]=get_var_number(j+1,guess[j]);
    	cout<<"Black : "<<bw[1]<<" white : "<<bw[2]<<endl;
    	cout<<varnumarr[0]<<", "<<varnumarr[1]<<", "<<varnumarr[2]<<", "<<varnumarr[3]<<endl;
    	switch(bw[1])
    	{
    		case 0:
    			clause.clear();
				clause.push_back(-varnumarr[0]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.push_back(-varnumarr[1]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.push_back(-varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[1]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[2]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[1]);
//				clause.push_back(-varnumarr[2]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[1]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[2]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
    			break;
    			
    		case 1:

				cout<<"enter switch case:"<<endl;
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[1]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[2]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[1]);
//				clause.push_back(-varnumarr[2]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[1]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[2]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[2]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				break;   	
			case 2:
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);	
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[2]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[2]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				break;	
			case 3:
				clause.clear();
				cout<<"Hi"<<endl;
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				cout<<"bye"<<endl;
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[3]);
				vec.push_back(clause);
			//	solver.addClause(clause);
				clause.clear();
				cout<<"bye"<<endl;
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[2]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				
				break;
			case 4: 
				cout<<"wins!!";
				return 0;
		}
		
		if(bw[1]==0 && bw[2]==0)
		{
			f1=floor(varnumarr[0]/4)*4;
			c1=ceil(varnumarr[0]/4)*4;
			
			for(l=f1+1;l<=c1;l++)
			{
				clause.clear();
				clause.push_back(-l);
		//		solver.addClause(clause);
				vec.push_back(clause);
			}
			
			f2=floor(varnumarr[1]/4)*4;
			c2=ceil(varnumarr[1]/4)*4;
			for(l=f2+1;l<=c2;l++)
			{
				clause.clear();
				clause.push_back(-l);
		//		solver.addClause(clause);
				vec.push_back(clause);
			}			
			
			f3=floor(varnumarr[2]/4)*4;
			c3=ceil(varnumarr[2]/4)*4;
			for(l=f3+1;l<=c3;l++)
			{
				clause.clear();
				clause.push_back(-l);
		//		solver.addClause(clause);
				vec.push_back(clause);
			}

			f4=floor(varnumarr[3]/4)*4;
			c4=ceil(varnumarr[3]/4)*4;
			for(l=f4+1;l<=c4;l++)
			{
				clause.clear();
				clause.push_back(-l);
		//		solver.addClause(clause);
				vec.push_back(clause);
			}			
		}
		if(bw[1]==1 && bw[2]==1)
		{
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
		//		solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
				f1=floor((varnumarr[0]-0.1)/4)*4;
				c1=f1+4;
				cout<<"Floor value and ceil value"<<f1<<" , "<<c1<<endl;
				for(l=f1+1;l<=c1;l++)
				if(l!=varnumarr[0])
				{
					//clause.clear();
					clause.push_back(l);
					//solver.addClause(clause);
				}
				
				f2=floor((varnumarr[1]-0.1)/4)*4;
				c2=f2+4;
				cout<<"Floor value and ceil value"<<f2<<" , "<<c2<<endl;
				for(l=f2+1;l<=c2;l++)
				if(l!=varnumarr[1])
				{
					//clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}			
			
				f3=floor((varnumarr[2]-0.1)/4)*4;
				c3=f3+4;
				cout<<"Floor value and ceil value"<<f3<<" , "<<c3<<endl;
				for(l=f3+1;l<=c3;l++)
				if(l!=varnumarr[2])
				{
				//	clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}
				//solver.addClause(clause);
				vec.push_back(clause);
				
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[3]);
				f1=floor((varnumarr[0]-0.1)/4)*4;
				c1=f1+4;
				cout<<"Floor value and ceil value"<<f1<<" , "<<c1<<endl;
				for(l=f1+1;l<=c1;l++)
				if(l!=varnumarr[0])
				{
					//clause.clear();
					clause.push_back(l);
					//solver.addClause(clause);
				}
				
				f2=floor((varnumarr[1]-0.1)/4)*4;
				c2=f2+4;
				for(l=f2+1;l<=c2;l++)
				if(l!=varnumarr[1])
				{
					//clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}			
			
				f4=floor((varnumarr[3]-0.1)/4)*4;
				c4=f4+4;
				for(l=f4+1;l<=c4;l++)
				if(l!=varnumarr[3])
				{
				//	clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}
				//solver.addClause(clause);
				vec.push_back(clause);
				
				//------------------------------------------------
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
				f1=floor((varnumarr[0]-0.1)/4)*4;
				c1=f1+4;
				for(l=f1+1;l<=c1;l++)
				if(l!=varnumarr[0])
				{
					//clause.clear();
					clause.push_back(l);
					//solver.addClause(clause);
				}
				
				f3=floor((varnumarr[2]-0.1)/4)*4;
				c3=f3+4;
				for(l=f3+1;l<=c3;l++)
				if(l!=varnumarr[2])
				{
					//clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}			
			
				f4=floor((varnumarr[3]-0.1)/4)*4;
				c4=f4+4;
				for(l=f4+1;l<=c4;l++)
				if(l!=varnumarr[3])
				{
				//	clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}
			//	solver.addClause(clause);
				vec.push_back(clause);

				//----------------------------------------------
				clause.clear();
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
				f2=floor((varnumarr[1]-0.1)/4)*4;
				c2=f2+4;
				for(l=f2+1;l<=c2;l++)
				if(l!=varnumarr[1])
				{
					//clause.clear();
					clause.push_back(l);
					//solver.addClause(clause);
				}
				
				f3=floor((varnumarr[2]-0.1)/4)*4;
				c3=f3+4;
				for(l=f3+1;l<=c3;l++)
				if(l!=varnumarr[2])
				{
					//clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}			
			
				f4=floor((varnumarr[3]-0.1)/4)*4;
				c4=f4+4;
				for(l=f4+1;l<=c4;l++)
				if(l!=varnumarr[3])
				{
				//	clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}
				//solver.addClause(clause);			
				vec.push_back(clause);
				
				//-----------------------------------------
				
				clause.clear();
				f1=floor((varnumarr[0]-0.1)/4)*4;
				c1=f1+4;
			
				for(l=f1+1;l<=c1;l++)
				if(l!=varnumarr[0])
				{
					clause.push_back(l);
				//	solver.addClause(clause);
				}

				f2=floor((varnumarr[1]-0.1)/4)*4;
				c2=f2+4;
				for(l=f2+1;l<=c2;l++)
				if(l!=varnumarr[1])
				{
				//	clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}			
			
				f3=floor((varnumarr[2]-0.1)/4)*4;
				c3=f3+4;
				for(l=f3+1;l<=c3;l++)
				if(l!=varnumarr[2])
				{
				//	clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}

				f4=floor((varnumarr[3]-0.1)/4)*4;
				c4=f4+4;
				for(l=f4+1;l<=c4;l++)
				if(l!=varnumarr[3])
				{
				//	clause.clear();
					clause.push_back(l);
				//	solver.addClause(clause);
				}
				//solver.addClause(clause);							
				vec.push_back(clause);
				
			
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[1]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
						
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[3]);
		//		solver.addClause(clause);
				vec.push_back(clause);
						
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[2]);
		//		solver.addClause(clause);
				vec.push_back(clause);
						
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[3]);
		//		solver.addClause(clause);
				vec.push_back(clause);
				
				clause.push_back(-varnumarr[2]);
				clause.push_back(-varnumarr[3]);
		//		solver.addClause(clause);
				vec.push_back(clause);
								
				
				
		}
		if(bw[2]==2 && bw[1]==1)
		{
				cout<<"loop comes and varnum"<<varnumarr[0]<<endl;
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[1]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[2]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[0]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[1]);
//				clause.push_back(-varnumarr[2]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[1]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(-varnumarr[2]);
//				clause.push_back(-varnumarr[3]);
//				solver.addClause(clause);
//				clause.clear();
//				clause.push_back(varnumarr[0]);
//				clause.push_back(varnumarr[1]);
//				clause.push_back(varnumarr[2]);
//				clause.push_back(varnumarr[3]);
//				solver.addClause(clause);
				
		}
		if(bw[1]==0 && bw[2]==4)
		{
		
			f1=floor((varnumarr[0]-0.1)/4)*4;
			c1=f1+4;
			f2=floor((varnumarr[1]-0.1)/4)*4;
			c2=f2+4;
			f3=floor((varnumarr[2]-0.1)/4)*4;
			c3=f3+4;
			f4=floor((varnumarr[3]-0.1)/4)*4;
			c4=f4+4;
			for(l=1;l<=32;l++)
				if(!((l>f1 && l<=c1)|| (l>f2 && l<=c2) || (l>f3 && l<=c3) || (l>f4 && l<=c4)))
				{
					clause.clear();
					clause.push_back(-l);
				//	solver.addClause(clause);
					vec.push_back(clause);
				}
			
			
		}
		if(bw[1]==2 && bw[2]==2)
		{
		
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);	
				vec.push_back(clause);
				
				clause.clear();
				clause.push_back(-varnumarr[0]);
				clause.push_back(-varnumarr[2]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				
				clause.clear();
				clause.push_back(varnumarr[0]);
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				
				clause.clear();
				clause.push_back(-varnumarr[1]);
				clause.push_back(-varnumarr[2]);
				clause.push_back(-varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
				clause.clear();
				clause.push_back(varnumarr[1]);
				clause.push_back(varnumarr[2]);
				clause.push_back(varnumarr[3]);
			//	solver.addClause(clause);
				vec.push_back(clause);
	
		}
		//togasat::lbool status = solver.solve(); 
		std::vector<int> assigns=findSAT();
		//cout<<"status = "<<status<<endl;
		cout<<"assigns: "<<endl;
		for(j=0;j<32;j++)
		{
			cout<<j<< " -> "<<assigns[j]<<endl;
		}
		cout<< endl;
		int pos;
		char clr;
		for(j=31;j>=0;j--)
			if(assigns[j]==0)
			{
				get_color(&pos, &clr, j+1);
				guess[pos-1]=clr;
			}
	}
}
