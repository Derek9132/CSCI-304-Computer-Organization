#include <stdlib.h>
#include <stdio.h>
/*
.pos 0
Init:
    irmovl Stack, %ebp
    irmovl Stack, %esp
    call main
    halt
*/

int array[7] = {5, 12, 3, 4, 6, 2, -1};
/*
.align 4
array: .long 0x5
       .long 0xc
       .long 0x3 should become 0x6
Done:  .long 0xFFFFFFFF
*/

void main (){
    //subl $20, %esp <--- allocate space for 5 local variables
	int *ptr = array; //irmovl array, %eax | %eax should be set to array, element of array(%eax) will be returned
	while (*ptr != -1){ //jne while_1 | Previous ALU Operation:
		int local = *ptr; //mrmovl %eax,%ebx | move value at ptr into local(%ebx)
		int factor = 1; //irmovl $1, %ecx | move 1 into factor(%ecx)
		while (local != 0){ //jne while_2 | Previous ALU Operation:
			//factor = factor * local;
			int l_local = local; //rrmovl %ecx, %edx | move local into l_local
			int l_factor = factor; //rrmovl %ebx, %edi | move factor into l_factor
			while (l_local > 1){ //jg while_3 | Previous ALU Operation:
				factor = factor + l_factor; //addl %edi, %ecx
				l_local--; //irmovl $4, %esi | subl %esi, %edi
			}
			local--; //irmovl $4, %esi | subl %esi, %ebx
		}

		ptr++; //irmovl $1, %esi | addl %esi, %eax
		printf("%d\n", factor);
	}
}

/*==============================================================================================================================================

int fac(int n) //irmovl $4, %edx, pushl %edx, call fac
{
    //set up %esp and %ebp
    //subl $8, %esp
    int x = 1; //irmovl $1, %eax
    int result = 1; //irmovl $1, %ebx
    while (x != n + 1) //irmovl $4, %ecx | addl %ecx, %edx | jne while
    {
        result = multiply(result, x); //call multiply:
                                      //mrmovl %ebx, %esi | pushl %esi
                                      //mrmovl %eax, %edi | pushl %edi
                                      //call multiply
        x++; //irmovl $4, %ecx | addl %ecx, %eax

    }
    return result;
}

int multiply(int y, int z) //x stored in %eax, result stored in %ebx
{
  //set up %esp and %ebp
  //subl $8, %esp
    int start = 0; //irmovl $0, %ebx
    int res = 0; //irmovl $0, %eax
    while (start != z) //jne while
    {
        res += y; //%addl
        start++; //irmovl $1, %edx | addl %edx, %ebx
    }
    return res;
}

int main() { //Set up %esp and %ebp

  int z = fac(4); //irmovl $4, %edx, pushl %edx, call fac
  return 0;
}


/*Office hours
lab3p1.s -
each line in IA32 corresponds to one or more lines in y86 (example: subl and addl takes 2 registers so they will require 2 lines)
L2 outermost loop
L3
*/
