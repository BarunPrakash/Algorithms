#include <stdio.h>
#include <string.h>
#include<iostream>
#include<stdbool.h>
using namespace std;
#include<stdint.h>
#include <bits/stdc++.h>
/**************************************************/
#define MaxSize 128
#define key     1
#define on      1
#define off     0
/*********************************************************
 *Defined Hash Table
 *
 *
 */
bool DefinedHashTable[MaxSize][key];
/***************************************************************************
 * Hash Designed problems
 * This is designed by Barun
 * Date 23 April 2018
 * objective: To   sovle the problems into multiple time complexity .Solution should reach lowest time complexity 
 *
 *
 *
 *1.Find the array is subset of other array.
 *2.Given an array A[] and a number x, check for pair in A[] with sum as x
 *3.Find four elements a, b, c and d in an array such that a+b = c+d
 *4.Find the length of largest subarray with 0 sum
 *5.Print all subarrays with 0 sum
 *
 */
/********************************************************************/
  bool findSubsetArrayAintoArrayB(uint8_t *arrA,uint8_t *arrB,uint8_t sizofa ,uint8_t sizofb);
  bool findSubsetArrayAintoArrayBUsingBinarySearch(uint8_t *arrA,uint8_t *arrB,uint8_t sizofa ,uint8_t sizofb);     
  bool binarySearch(uint8_t *arr,uint8_t num ,uint8_t low,uint8_t max);
  bool findSubsetArrayAintoArrayBUsingShorted(uint8_t *arrA,uint8_t *arrB,uint8_t sizofa ,uint8_t sizofb);
  bool isItSubsetUsingSelfDefinedHashContainer(int *arrA, int *arrB, uint8_t sa, uint8_t sb);
  bool isItSubsetUsingHashMapContainer(int *arrA, int *arrB, uint8_t sa, uint8_t sb);
  bool findPairsSum(int *arr, int n) ;
  void printPairsSum(int *arr,int as,int sum);
  int maxLenOfZeroSum(int *arr, int sz);



  /***********************************************************************/


bool findSubsetArrayAintoArrayB(uint8_t *arrA,uint8_t *arrB,uint8_t sizofa ,uint8_t sizofb)     //Time complexity  O(M*N)
{
	uint8_t countA=0,countB=0,countFlag=0;
	for( ;countB<sizofb;countB++)
	{
		for( countA=0;countA<sizofa;countA++)
			{
               if(arrA[countA]==arrB[countB])
               {
            	   countFlag++;
            	  // printf("%d",countFlag);
            	   break;

               }

			}
		if(countFlag ==sizofb)
		{
			return true;
		}


	}

	return false;
}

/***************************************************************************
 * Implement using Binary search O(log N)*M
 *
 *
 */

bool findSubsetArrayAintoArrayBUsingBinarySearch(uint8_t *arrA,uint8_t *arrB,uint8_t sizofa ,uint8_t sizofb)     //Time complexity  O(M*N)
{
	uint8_t countB=0,countFlag=0;
	for( ;countB<sizofb;countB++)
	{
		if(binarySearch(arrA,arrB[countB],0,10-1))
		{
			countFlag++;
		}

		if(countFlag ==sizofb)
		{
			return true;
		}

	}


	return false;
}
bool binarySearch(uint8_t *arr,uint8_t num ,uint8_t low,uint8_t max)
{
	uint8_t mid =low +( max- low)/2;
	if(max>=low)
	{
    	if(arr[mid]==num)
    	{
    		return true;
    	}
    	if(num<arr[mid])
    	{
    		return binarySearch(arr,num,low,mid-1);
    	}
	    if(num>arr[mid])
	    {
	    	return binarySearch(arr,num,mid+1,max);
	    }
	}
	return false;



}

/*********************************************************************
 *
 *
 * short two array into and find existing subarray.Ex using inbuilt STL
 * O(logM +logM)
 *

bool findSubsetArrayAintoArrayBUsingShorted(int arrA[],int arrB[],int sizofa ,int sizofb)     //Time complexity  O(M*N)
{
	uint8_t countB=0,countA=0,countFlag=0;
	short(arrA,arrA+sizofa);
	short(arrB,arrB+sizofb);


}*/
bool isItSubset(int arr1[], int arr2[], int siza, int sizb)
{
    int i = 0, j = 0;

    if (siza < sizb)
       return 0;

    sort(arr1, arr1 + siza);
    sort(arr2, arr2 + sizb);
    while (i < sizb && j < siza )
    {
        if( arr1[j] <arr2[i] )
            j++;
        else if( arr1[j] == arr2[i] )
        {
            j++;
            i++;
        }
        else if( arr1[j] > arr2[i] )
            return  false;
    }

    return  (i == sizb)? true : false;
}
/****************************************************************************
 * Implement  using Hash
 * linear approach using hash O(N) ,only for subarray.
 	It has been sloved inbuilt Hash table in c+=
 	uinorder_map
 	It can be solved by using Map container O(logn)
 */

bool isItSubsetUsingHashContainer(int *arrA, int *arrB, uint8_t sa, uint8_t sb)
{
#if off
  uint8_t ia,count=0;
	unordered_map<int,bool> arrANode;

	for(ia=0;ia<sa;ia++)
	{
		arrANode.insert(make_pair(arrA[ia],true));
	}
	for(ia=0;ia<sb;ia++)
	{
		if(arrANode.find(arrB[sa])==arrANode.end())
		{

		}
		else
		{
			count++;
			printf("%d",count);
		}
	}

	return(count==sb)? true:false;
#endif
}
/************************************************************************
 * Imlimenting using Self defined hash function
 *  O(N) ,Movig index subarray
 	It is lowest solution
 	O(1),It ia implimented through defined hash Table.
 */
bool isItSubsetUsingSelfDefinedHashContainer(int *arrA, int *arrB, uint8_t sa, uint8_t sb)
{

	uint8_t ia,count=0;


	for(ia=0;ia<sa;ia++)
	{
		DefinedHashTable[arrA[ia]][key]=true;

	}
	for(ia=0;ia<sb;ia++)
	{
		if( DefinedHashTable[arrB[ia]][key]==true)
		{
				count++;
			//	printf("%d",count);
		}

	}

	return(count==sb)? true:false;

}
/*
	Implimenting through Map container 
	O(logn)

*/
bool isItSubsetUsingHashMapContainer(int *arrA, int *arrB, uint8_t sa, uint8_t sb)
{
#if off
  uint8_t ia,count=0;
	map<int,bool> arrANode;

	for(ia=0;ia<sa;ia++)
	{
		arrANode.insert(make_pair(arrA[ia],true));
	}
	for(ia=0;ia<sb;ia++)
	{
		if(arrANode.find(arrB[sa])==arrANode.end())
		{

		}
		else
		{
			count++;
			printf("%d",count);
		}
	}

	return(count==sb)? true:false;
#endif
}

/***************************************************
	find sum pair
*/

void printPairsSum(int *arr,int as,int sum)
{
    unordered_set<int> s;
    int temp =0;
    for(int index=0;index<as;index++)
    {
        temp =sum -arr[index];
        if(temp>=0&&s.find(temp)!=s.end())
        cout<< "sum"<<sum<<"is("<<arr[index]<<","<<temp<<")"<<endl;
        s.insert(arr[index]);
    }
    
}
/******************************************************/

bool findPairsSum(int *arr, int n) 
{ 
    
    map<int, pair<int, int> > Hash; 
  
    
    for (int i = 0; i < n; ++i) 
    { 
        for (int j = i + 1; j < n; ++j) 
        { 
       
            int sum = arr[i] + arr[j]; 
            if (Hash.find(sum) == Hash.end()) 
                Hash[sum] = make_pair(i, j); 
  
            else 
            { 
                // Find previous pair 
                pair<int, int> pp = Hash[sum];r
  
          
                cout << "(" << arr[pp.first] << ", " << arr[pp.second] 
                     << ") and (" << arr[i] << ", " << arr[j] << ")n"; 
                return true; 
            } 
        } 
    } 
  
    cout << "No pairs found"; 
    return false; 
} 

/**************************************************************************/

int maxLenOfZeroSum(int *arr, int sz) 
{ 
    int max_len = 0; 
  
    
    for (int i = 0; i < sz; i++) 
    { 
         
        int curr_sum = 0; 
  
    
        for (int j = i; j < sz; j++) 
        { 
            curr_sum += arr[j]; 
  
            
            if (curr_sum == 0) 
               max_len = max(max_len, j-i+1); 
        } 
    } 
    return max_len; 
} 
int main()
{
	int arry[10] ={3,4,5,6,7,8,67,5,8,11};
	int arrys[3]={3,6,8};
	printf("%d",isItSubsetUsingSelfDefinedHashContainer(arry,arrys,10,3));

    return 0;
