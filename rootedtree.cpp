
#include <iostream> 
#include <string> 

struct node 
{ 
    char data; 
    struct node* left; 
    struct node* right; 
}; 




int search(std::string arr, int strt, int end, char value); 

struct node* newNode(char data); 



  
struct node* buildTree(std::string in, std::string pre, int inStrt, int inEnd) 
{ 
    static int preIndex = 0; 
  
    if (inStrt > inEnd) 
        return NULL; 
  

    struct node* tNode = newNode(pre[preIndex++]); 

    if (inStrt == inEnd) 
        return tNode; 
  
    int inIndex = search(in, inStrt, inEnd, tNode->data); 

    tNode->left = buildTree(in, pre, inStrt, inIndex - 1); 
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd); 
  
    return tNode; 
} 


int search(std::string arr, int strt, int end, char value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            return i; 
    } 
} 
  

 struct node* newNode(char data) 
{ 
    struct node* node = new struct node; 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
  



  
  
int main() 
{ 
    std::string in, pre; 

    std::cin>> in;
    std::cin>> pre;


	char* arr=NULL;

    int len = in.length();

    struct node* root = buildTree(in, pre, 0, len - 1); 
  


    return 0;
} 