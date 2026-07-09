class Solution {
public:
    void merge(vector<int>&arr, int low, int mid, int high){

        vector<int>temp;
        int left=low;
        int right=mid+1;

        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                temp.push_back(arr[left]);
                left++;
            }else{
                temp.push_back(arr[right]);
                right++;
            }
        }
        // Copy the remaning elements from left Subarray
        while(left<=mid){
            temp.push_back(arr[left]);
            left++;
        }
        // Copy the remaning elements from right Subarray
        while(right<=high){
            temp.push_back(arr[right]);
            right++;
        }
        // Copy the elements to original array and keep in mind original array starting index starts from low.
        for(int i=0; i<temp.size(); i++){
            arr[low++]=temp[i];
        }
    }

    void mergeSort(vector<int>&arr, int low, int high){

        if(low>=high) return;
        int mid=low + (high-low)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);

    }

    vector<int> sortArray(vector<int>& nums) {

        int low=0;
        int high=nums.size()-1;
        mergeSort(nums,low,high);
        return nums; 
    }
};
