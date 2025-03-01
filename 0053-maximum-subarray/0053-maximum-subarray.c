int maxSubArray(int* nums, int numsSize) {
    int current=0;
    int maxi=nums[0];
    for(int i=0;i<numsSize;i++){
        current+=nums[i];
        if(current>maxi){
            maxi=current;
        }
        if(current<0){
            current=0;
        }
    }
    return maxi;
}