class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;
        for(int i=0; i<n; i++){
            if(operations[i] == "C" && !st.empty()) st.pop();
            else if( operations[i] == "D" && !st.empty() ){
                st.push(st.top()*2);  
            }
            else if(operations[i]=="+"){
                if(st.size()>=2){
                    int a = st.top(); st.pop();
                    int b = st.top();
                    st.push(a);
                    st.push(a+b);
                }
            }
            else st.push(stoi(operations[i]));
        }
        int sum=0;
        while(!st.empty()){
            sum+= st.top();
            st.pop();
        }
        return sum;
    }
};
