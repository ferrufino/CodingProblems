#include <iostream>
using namespace std;
#include <vector>

struct node {
    int val;
    node  *next = NULL;
    
    node(int e){
        val = e;
    }
    
};


node* addTwoLinkedLists(node *l1, node *l2){

  int len1 = 0, len2 = 0;
  vector<int> vec1;
  vector<int> vec2;

  while(l1){
    vec1.push_back(l1->val); 
    l1 = l1->next; 
  }

  while(l2){
    vec2.push_back(l2->val); 
    l2 = l2->next; 
  }
  
  len1 = vec1.size();
  len2 = vec2.size();

  node *head, *p;
  int carry = 0;  
  int sum = 0;

  for(int i = len1-1, j = len2-1; i>=0 || j>=0 || carry > 0; i--, j--){
      
   sum = carry;
   if(i>= 0){
      sum+= vec1[i]; 
   }
   
   if(j>=0){
      sum+= vec2[j]; 
   }

   carry = sum/10;
   p = new node(sum%10);
   p->next = head;
   head = p; 
  }

  return head;
}



int main(){
    
    node* l1 = new node(7);
    node* l2 = new node(2);
    node* l3 = new node(4);
    node* l4 = new node(3);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    
    
    node* k1 = new node(5);
    node* k2 = new node(6);
    node* k3 = new node(4);
    
    k1->next = k2;
    k2->next = k3;
   
    node *ans = addTwoLinkedLists(l1, k1);
    while(ans){
      cout<<ans->val<<" "; 
      ans = ans->next;
    }
}
