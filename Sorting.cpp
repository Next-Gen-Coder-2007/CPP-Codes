#include <iostream>
#include <vector>
using namespace std;

vector<int> Bubble(vector<int> nums){
    int n = nums.size();
    for(int i = 0;i < n - 1;i++){
        int flag = 0;
        for(int j = 0;j < n - i - 1;j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }

    return nums;
}

vector<int> Insertion(vector<int> nums){
    for(int i = 1;i < nums.size();i++){
        int j = i - 1;
        int x = nums[i];
        while(j > -1 && nums[j] > x){
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = x;
    }
    return nums;
}

vector<int> Selection(vector<int> nums){
    for(int i = 0;i < nums.size();i++){
        int k = i;
        for(int j = i + 1;j < nums.size();j++){
            if(nums[j] < nums[k]){
                k = j;
            }
        }
        swap(nums[i], nums[k]);
    }
    return nums;
}

int partition(vector<int>& nums, int l, int h){
    int pivot = nums[l];
    int i = l, j = h;
    do{
        do{
            i++;
        }while(nums[i] <= pivot);
        
        do{
            j--;
        }while(nums[j] > pivot);

        if(i < j){
            swap(nums[i], nums[j]);
        }
    }while(i < j);

    swap(nums[l], nums[j]);
    return j;
}

void QuickSort(vector<int>& nums, int l, int h){
    if(l < h){
        int j = partition(nums, l, h);
        QuickSort(nums, l, j);
        QuickSort(nums, j+1, h);
    }
}

vector<int> QuickSort(vector<int> nums){
    QuickSort(nums, 0, nums.size());
    return nums;
}

void Merge(vector<int>& nums, int l, int mid, int h){
    int i = l, j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= h){
        if(nums[i] < nums[j]){
            temp.push_back(nums[i++]);
        }else{
            temp.push_back(nums[j++]);
        }
    }
    while(i <= mid){
        temp.push_back(nums[i++]);
    }
    while(j <= h){
        temp.push_back(nums[j++]);
    }

    for(int k = 0; k < temp.size(); k++){
        nums[l + k] = temp[k];
    }
}

vector<int> IMergeSort(vector<int> nums){
    int p, l, h, mid;

    for(p = 2; p <= nums.size(); p = p * 2){
        for(int i = 0; i + p - 1 < nums.size(); i = i + p){
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;

            Merge(nums, l, mid, h);
        }
    }

    if(p / 2 < nums.size()){
        Merge(nums, 0, p / 2 - 1, nums.size() - 1);
    }

    return nums;
}

void RMergeSort(vector<int>& nums, int l, int h){
    if(l < h){
        int mid = (l + h) / 2;
        RMergeSort(nums, l, mid);
        RMergeSort(nums, mid + 1, h);
        Merge(nums, l, mid, h);
    }
}

vector<int> RMergeSort(vector<int> nums){
    RMergeSort(nums, 0, nums.size() - 1);
    return nums;
}

void Display(vector<int> nums){
    cout << "[";
    for(auto n : nums){
        cout << n << " ";
    }
    cout << "]" << endl;
}

int main(){
    vector<int> nums = {8, 5, 7, 3, 2};

    Display(nums);

    Display(Bubble(nums));
    Display(Insertion(nums));
    Display(Selection(nums));
    Display(QuickSort(nums));
    Display(IMergeSort(nums));
    Display(RMergeSort(nums));

    return 0;
}