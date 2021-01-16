//Selected question
/*
C/C++ Program for Next Power of 2 ----y
C/C++ Program for Write an Efficient Method to Check if a Number is Multiple of 3
C/C++ Program for Write a C program to find the parity of an unsigned integer
C/C++ Program for Efficient way to multiply with 7
C/C++ Program for Write one line C function to find whether a no is power of two
C/C++ Program for Position of rightmost set bit
C/C++ Program for Find the Number Occurring Odd Number of Times
C/C++ Program for Check for Integer Overflow
C/C++ Program for Little and Big Endian Mystery
C/C++ Program for Write an Efficient C Program to Reverse Bits of a Number
C/C++ Program for Count set bits in an integer
C/C++ Program for Count number of bits to be flipped to convert A to B
C/C++ Program for Find the two non-repeating elements in an array of repeating elements
C/C++ Program for Rotate bits of a number
C/C++ Program for Compute the minimum or maximum of two integers without branching
C/C++ Program for Compute modulus division by a power-of-2-number
C/C++ Program for Compute the integer absolute value (abs) without branching
C/C++ Program for Find whether a given number is a power of 4 or not
C/C++ Program for Turn off the rightmost set bit
C/C++ Program for Multiply a given Integer with 3.5
C/C++ Program for Add 1 to a given number
C/C++ Program for Optimization Techniques | Set 1 (Modulus)
C/C++ Program for Next higher number with same number of set bits
C/C++ Program for Program to count number of set bits in an (big) array
C/C++ Program for A Boolean Array Puzzle
C/C++ Program for Smallest of three integers without comparison operators
C/C++ Program for Add two numbers without using arithmetic operators
C/C++ Program for Swap bits in a given number
C/C++ Program for Count total set bits in all numbers from 1 to n
C/C++ Program for Detect if two integers have opposite signs
C/C++ Program for Find the element that appears once
C/C++ Program for Binary representation of a given number
C/C++ Program for Write your own strcmp that ignores cases
C/C++ Program for Add two bit strings
C/C++ Program for Swap all odd and even bits
C/C++ Program for Find position of the only set bit
C/C++ Program for Divide and Conquer | Set 4 (Karatsuba algorithm for fast multiplication)
C/C++ Program for How to swap two numbers without using a temporary variable?
C/C++ Program for Check if a number is multiple of 9 using bitwise operators
*/

bool checkIntegerOverFlow(int  numA ,int numB ,int *ptr)
{
    *ptr =numA+numB;
    if(numA<0 && numB<0 && *ptr>0)
     return true;
      if(numA>0 && numB>0 && *ptr<0)
     return true;
     
}

uint32_t rightSetBit(uint32_t num)
{
    return(log2(num&-num)+1);
}
uint32_t bitReversalNum(uint32_t num)
{
    uint32_t revNob=0;
    uint8_t max_count= 8*sizeof(int);
    uint8_t count=0;
    for(; count<max_count;count++)
    {
        if(num&(1<<count))
        {
            revNob |=(1<<(max_count-1-count));
        }
    }
  return revNob;
}
uint32_t countSetBits(uint32_t num)
{
     uint8_t count=0;
     while(num)
     {
         count+= num&1;
         num>>=1;
     }
}

uint32_t findBitFlipped(uint32_t num A , uint32_t numB)
{
    
    return(countSetBits(numB^numB));
}
uint32_t findLeftRotation(uint32_t num ,int pos)
{
    return((num<<pos)|(num>>(32-pos)));
}
uint32_t findMax(uint32_t x  , uint32_t y)
{
    return(x^((x^y)&-(x<y))));
}
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)
// find the parity of number
bool funcToCheckParity(uint32_t num) //return 1 in case of odd parity
{
    bool parity=false;
    while(num)
    {
        parity=!parity;
        num=num&(num-1);
        
    }
    return parity;
}
//smallest or equal to pow of 2

uint32_t eqOrGreaterPowOf2(uint32_t num)
{
    
    if(num&&(!(num&(num-1))))
    {
        return num;
    }
    else
    {
        int count =false; //not good to defined in this way .
        while(num!=0)
        {
           
            count+=1;
            num>>=1;
        }
        
    return 1<<count;
    }
}
int main()
{
    printf("Barun\n:%x",findMax(2,3));
}
