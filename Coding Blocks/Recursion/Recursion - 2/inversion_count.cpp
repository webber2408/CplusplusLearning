#include<iostream>
#include<vector>
using namespace std;

int get_split_inversion_count(vector<int> &nums, int l, int mid, int r){
    int n1 = mid-l+1, n2 = r-mid, inversion_count = 0;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
        L[i] = nums[l+i];
    for(int i=0; i<n2; i++)
        R[i] = nums[mid+1+i];

    int p1 = 0, p2 = 0, k = l;
    while(p1<n1 && p2<n2){
        if(L[p1] <= R[p2])
            nums[k++] = L[p1++];
        else{
            inversion_count++;
            nums[k++] = R[p2++];
        }
    }

    while(p1<n1)
        nums[k++] = L[p1++];
    while(p2<n2)
        nums[k++] = R[p2++];

    return inversion_count;
}

int count_inversions(vector<int> &nums, int l, int r){
    static int inversion_count = 0;
    if(l>=r) return 0;
    int mid = (l+r)/2;
    // cout<<"mid"<<mid<<" "<<endl;
    int left_count = count_inversions(nums, l, mid);
    int right_count = count_inversions(nums, mid+1, r);
    int split_count = get_split_inversion_count(nums, l, mid, r);
    // cout<<split_count<<" ";
    inversion_count = left_count + right_count + split_count;
    return inversion_count;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }

    int ans = count_inversions(nums, 0, n-1);
    
    cout<<ans<<endl;

    return 0;
}