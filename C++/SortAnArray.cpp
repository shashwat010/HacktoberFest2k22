class Solution {
public:
    void merge(vector<int>&arr,int l,int mid,int r){
        if(l>=r)    return;
        vector<int>a(mid-l+1);
        vector<int>b(r-mid);
        for(int i=l;i<=mid;i++)     a[i-l] = arr[i];
        for(int i=mid+1;i<=r;i++)     b[i-mid-1] = arr[i];
        int x=0;
        int y=0;
        int i = l;
        while(x<a.size() && y<b.size()){
            if(a[x]<=b[y]){
                arr[i]=a[x];
                x++;
            }
            else{
                arr[i]=b[y];
                y++;
            }
            i++;
        }
        while(x<a.size()){
            arr[i]=a[x];
            x++;
            i++;
        }
        while(y<b.size()){
            arr[i]=b[y];
            y++;
            i++;
        }
    }
    void mergeSort(vector<int>&arr,int l, int r){
        if(l<r){
            int mid = (l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
    vector<int> sortArray1(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
    
    void countSort(vector<int> &arr, int n){
		int mx = INT_MIN;
		for(int i=0;i<n;i++)	mx = max(mx,arr[i]);
		vector<int> count(mx+1);
		for(int i=0;i<n;i++)	count[arr[i]]++;
		for(int i=1;i<=mx;i++)	count[i]+=count[i-1];
		
		int output[n];
		for(int i=n-1;i>=0;i--){
			output[--count[arr[i]]] = arr[i];
		}
		for(int i=0;i<n;i++)	arr[i] = output[i];
	}
    
    vector<int> sortArray(vector<int>& nums) {
        countSort(nums, nums.size());
        return nums;
    }
};
