/* 
 * http://leetcode.com/2010/09/serializationdeserialization-of-binary.html
 */

#ifndef	 __TREE_H__
#define	 __TREE_H__

#include <iostream>
#include <vector>
#include <string>
#include <queue>

#include <fstream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;


const char cSentinel = '#';
const char cSep = ',';

struct TreeNode {
    int val = 0;
    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode(int x) : val(x) {}
};

TreeNode *deserialBTree(string str);

TreeNode *initTree(vector<int> num) {
    if ( !num.size() ) {
        return NULL;
    }

    TreeNode *root = new TreeNode(num[0]);
    TreeNode **list = new TreeNode*[num.size()];
    list[0] = root;

    for (int i = 1; i < num.size(); ++i) {
        if ( num[i] >= 0 ) {
            TreeNode *tree = new TreeNode(num[i]);
            int p = (i+1)/2 - 1;

            if ( i&1 ) {
                list[p]->left = tree;
            } else {
                list[p]->right = tree;
            }

            list[i] = tree;
        }
    }

    delete[] list;
    return root;
}

void serializeBTreeRec(TreeNode *root, string &str) {
    if ( !root ) {
        str = str + cSentinel + cSep;
    } else {
        str = str + to_string(root->val) + cSep;
        serializeBTreeRec(root->left, str);
        serializeBTreeRec(root->right, str);
    }
}

// serialize binary tree
string serialBTree(TreeNode *root) {
    string res;
    queue<TreeNode*> treeQue;
    
    if (!root) {
        return res;
    }

    treeQue.push(root);

    while( !treeQue.empty() ) {
        TreeNode *node = treeQue.front();
        treeQue.pop();

        if ( node ) {
            res = res + to_string(node->val) + cSep;
            treeQue.push(node->left);
            treeQue.push(node->right);
        } else {
            res = res + cSentinel + cSep;
        }
    }

    if ( !res.empty() ) {
        res.erase(res.size()-1);
    }

    return res;
}

TreeNode *deserialBTree(string str) {
    istringstream iss(str);
    string token;

    if ( str.empty() ) {
        return NULL;
    }

    getline(iss, token, cSep);
    TreeNode *root = new TreeNode(stoi(token));
    queue<TreeNode*> treeQue;
    treeQue.push(root);
    bool inLeft = true;
    //cout << "Token: " << token <<endl;
    while( getline(iss, token, cSep) ) {
        if ( !token.empty() && !treeQue.empty() ) {
            //cout << "Token: " << token <<endl;
            TreeNode *par = treeQue.front();
            if ( !inLeft ) {
                treeQue.pop();
            }

            if ( token[0] != cSentinel ) {
                int value = stoi(token);
                TreeNode *node = new TreeNode(value);
                treeQue.push(node);

                if ( inLeft ) {
                    par->left = node;
                } else {
                    par->right = node;
                }
            }
            inLeft = !inLeft;
        }
    }

    return root;
}


/* 
 * Pretty print the binary tree.
 */

// Find the maximum height of the binary tree
int maxHeight(TreeNode *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convert an integer value to string
string intToString(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
  deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {  
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
  deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->val) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<TreeNode*>& nodesQueue, ostream& out) {
  deque<TreeNode*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->val) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
// printPretty(root, 1, 0, cout);
void printPretty(TreeNode *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<TreeNode*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      TreeNode *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

#endif
