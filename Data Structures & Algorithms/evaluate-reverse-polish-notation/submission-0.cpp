class Solution {
public:
    int performArthimetic(int a, int b, string str){
        if(str=="+") return a+b;
        if(str=="-") return a-b;
        if(str=="*") return a*b;
        if(str=="/") return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            string str = tokens[i];
            if(str == "+" || str == "-" || str == "*" || str == "/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                int x = performArthimetic(a,b,str);
                st.push(x);
            }else{
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
