#include<bits/stdc++.h>
using namespace std;

int largestArea(int arr[],int n)
{
	int curArea,max_area=INT_MIN;
	stack<int> s;
	
	int topelement,i=0;
	
	while(i<n)
	{
			//if current element is bigger than top we push it
			if(s.empty()||arr[s.top()]<=arr[i])
				s.push(i++);
			else{
				// we find the area with top element as minimum
				topelement=arr[s.top()];
				s.pop();
				//here i is the right index and s.top is the left index
				curArea=arr[topelement]*(s.empty()?i:i-s.top()-1);
				
				max_area=max(curArea,max_area);
				}
				
	}
	
	//now in case the stack is not empty
	while(!s.empty())
	{
			topelement=s.top();
			s.pop();
			curArea=arr[topelement]*(s.empty()?i:i-s.top()-1);
			max_area=max(curArea,max_area);
			
	}
	return max_area;
	}


int main(){
	
	int hist[] = {6, 2, 5, 4, 5, 1, 6}; 
    int n = sizeof(hist)/sizeof(hist[0]); 
    cout << "Maximum area is " << largestArea(hist, n); 
return 0;	}
