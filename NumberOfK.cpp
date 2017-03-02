class Solution {
public:
	int GetNumberOfK(vector<int> data ,int k){
		int lower = getLower(data,k);
		int upper = getUpper(data,k);
		return upper - lower + 1;
	}
	//获取k第一次出现的下标
	int getLower(vector<int> data,int k){
		int start = 0,end = data.size()-1;
		int mid = (start + end)/2;
		while(start <= end){
			if(data[mid] < k){
				start = mid + 1;
			}else{
				end = mid - 1;
			}
			mid = (start + end)/2;
		}
		return start;
	}
	//获取k最后一次出现的下标
	int getUpper(vector<int> data,int k){
		int start = 0,end = data.size()-1;
		int mid = (start + end)/2;
		while(start <= end){ 
			if(data[mid] <= k){
				start = mid + 1;
			}else{
				end = mid - 1;
			}
			mid = (start + end)/2;
		}
		return end;
	}
};
