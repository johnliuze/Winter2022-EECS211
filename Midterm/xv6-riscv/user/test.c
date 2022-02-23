#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

long long cal(long long n)
{
	long long i, j;
	long long res;
	res = 1;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			res += 1;
			res *= -1;
		}
	}
	return res;
}

int child(void)
{
	int i, pid;
	long long a;
	for(i=0; i<5; ++i){
		if((pid = fork()) == 0){
			a = cal(50000);
			printf("Grandchild. %d\n", a);
			break;
		}
		else{
			a = cal(10000);
			printf("Child. %d\n", a);
		}
	}
	for(i=0; i<5; ++i){
		wait(0);
	}
	exit(0);
}

int main(void)
{
	int n, pid, a, i;
	n = 2;
	for(i=0; i<n; ++i){
		if((pid = fork()) == 0){
			child();
			break;
		}
		else{
			a = cal(5000);
		}
	}
	printf("Parent. %d\n", a);
	exit(0);
}
