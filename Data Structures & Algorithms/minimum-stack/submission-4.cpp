class MinStack {
public:
    stack<long> st;
    
    int curMin;
    MinStack() {

    }
    
    void push(int val) {
        if(st.size() == 0){
            curMin = val;
            st.push(0);
        }else{
            st.push(val - curMin);
            cout<<"pushed: " << val-curMin << endl;
            if(val < curMin)
            {
                cout<<"CurMin: " << val<<endl;
                curMin = val;
            }
        }
        
       
    }
    
    void pop() {
        long top = st.top();
        cout<< "top: " << top << endl;
        if(top < 0){
            curMin = curMin - top;
            cout<< "updated curMin: " << curMin << endl;
        }
        st.pop();
    }
    
    long top() {
       if(st.top() >= 0 ) return st.top() + curMin;
       return curMin;
    }
    
    int getMin() {
        return curMin;
    }
};
