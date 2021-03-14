//O(n^2)
#include<iostream>

using namespace std;

int maximum(int a, int b){
    if(a>b){
        return b;
    }else{
        return a;
    }
}

int maximum(int a, int b, int c){
    if(a>=b && a>=c){
        return a;
    }else if(b>=a && b>=c){
        return b;
    }else{
        return c;
    }
}

int maxSumOfTables(int a[], int starting , int mid , int ending){

    int sum = 0;
    int left_sum = 0;
    int tempStartleft = 0;
    int tempEndleft = 0;

    //Elements of the left sub table
    for(int i = mid; i >= starting; i--){//we start from the end of that subarray and move forwards the start
        sum = sum + a[i];
        if(sum > left_sum){
            left_sum = sum;
            //tempEndleft=i;
            //tempStartleft=i+1;
        }
    }

    //Elements of the Right sub table
    int right_sum = 0;
    int tempStartright = 0;
    int tempEndright = 0;
    sum=0;
    for(int i=mid+1; i<=ending; i++){//start from the first element of the subarray and move towards the end
        sum=sum+a[i];
        if(sum>right_sum){
            right_sum=sum;
            //tempEndright=i;
            //tempStartright=i-1;
        }
    }

    return left_sum + right_sum;
}



int maxSubArraySum(int a[],int starting,int ending){

    if(starting == ending){
        return a[starting];
    }

    int mid=(starting+ending)/2;

    //return the max number of the left subtable, the right subtable and the between
    return maximum(maxSubArraySum(a , starting , mid),
                   maxSubArraySum(a , mid+1 , ending),
                   maxSumOfTables(a , starting ,mid , ending));

}


int main(){
    int a[]= {-9 , 5, -4, 7, 10,-2};

    int lenght = sizeof(a)/sizeof(int);
    int max_sum = maxSubArraySum(a, 0, lenght-1);


    cout<<"The table with length:"<<lenght<<" has max sequence sum:"<<max_sum<<endl;
    return 0;

}
