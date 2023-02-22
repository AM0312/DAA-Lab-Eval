#include <bits/stdc++.h>
using namespace std;

class treeNode{
public:
	char data;
	int freq;
	treeNode *left, *right;
	treeNode(char data,int freq){
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare {
	bool operator()(treeNode* l, treeNode* r){
		return (l->freq > r->freq);
	}
};

void printCodes(struct treeNode* root, string str){
	if (!root) return;
	if (root->data != '$') cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int size){
	treeNode *left, *right, *top;
	priority_queue<treeNode*, vector<treeNode*>, compare> minHeap;

	for (int i = 0; i < size; ++i) minHeap.push(new treeNode(data[i], freq[i]));
	while (minHeap.size() != 1){
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new treeNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	printCodes(minHeap.top(), "");
}

int main(){
	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HuffmanCodes(arr, freq, size);
}
