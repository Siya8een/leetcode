//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMidElement(stack<int> &st,const int &target,int index)
    {
        if(st.empty()) return ;
        int ele = st.top();
        st.pop();
        deleteMidElement(st,target,index-1);
        if(index!=target) st.push(ele);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int mid = (sizeOfStack+1)/2;
        deleteMidElement(s,mid-1,sizeOfStack-1); //-1s for considering 0 based indexing 
    }
};
    

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends