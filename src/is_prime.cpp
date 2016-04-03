#include <cstdio>
#include <cmath>


///if num is 2n or 3n, that's the easy case
///else we have to control the step
///5,7,(no 9),11,13,(no15),17,19,(no21),23,25,(no27),29,31...
///so the step is 2 in this loop and the next time it is 4
///the way to change 2 to 4 and change 4 to 2 automaticly
/// is that
///2 xor 4 == 6 so 2 xor 6 == 4 and 4 xor 6 == 2
bool isPrime_determined(int num){
    if (num <= 0) return false;
    if (num <= 3) return true;
    if (num % 2 == 0) return false;
    if (num % 3 == 0) return false;
    int sqrt_of_num = (int)(sqrt(num));
    int i;
    int step = 4;
    for (i = 5; i <= sqrt_of_num; i +=  step){
        if (num % i == 0) return false;
        step ^= 6;
    }
    return true;
}
int PowerMod(int a,int b,int c){
    //a**b%c
    if(a==0||c==1){
        return 0;
    }
    if(b==0){
        return 1;
    }
    int ans = 1;
    a = a % c;
    for(;b>0;b=b/2,a=a*a%c){
        if(b%2==1)
            ans = (ans*a) % c;
    }
    return ans;
}
/*
 * 所有底数为{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}
 * 故可以保证int情况下是对的
 * （尽管并没有什么卵用，毕竟判定大素数是超级大数应用- -）
 */
bool isPrime_MillerRabin(int num){
    if (num <= 0) return false;
    if (num <= 3) return true;
    if (num % 2 == 0) return false;
    //srand((unsigned)time(NULL));
    int candidate_a[12]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int u = num - 1;

    // num-1 = u = u' * 2^r;r>=1 would be definitely satisfied.
    int r;
    for(r=0;u%2==0;r++){
        u=u/2;
    }

    for(int i= 0; i<12;i++){
        //int a = candidate_a[rand()%12];
        int a = candidate_a[i];
        if(a==num) return true;
        int x = PowerMod(a,u,num);
        if(x==1||x==num-1){
            continue;
        }
        for(int j=0;j<r-1;j++){
            //x finally reaches u'* 2^r-1,that is sqrt(u)
            x = x*x%num;
            if(x==1){
                return false;
            }//x'=x*x%num=1,but x!=1&&x!=num-1,so that's false
            if(x==num-1){
                break;
            }//x'=num-1,so the test after would be passed
        }
        if(x!=num-1)return false;
        //if program reaches this point,x!=1,x may be num-1 or else
        //if x!=num-1 that's x go through the for-loop above,
        //so x=a^sqrt(u)%c,and x!=1,x!=num-1,so false;
    }
    return true;
}
