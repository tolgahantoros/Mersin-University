#include <iostream>
#include <cstdlib>
#define MAX_TREE_HT 100
using namespace std;
struct minstacknode {
	char data;
	unsigned period;
	struct minstacknode *left, *right;
};
struct minstack {
	unsigned size;
	unsigned capacity;
	struct minstacknode** array;
};
struct minstacknode* newNode(char data, unsigned period)
{
	struct minstacknode* temp
		= (struct minstacknode*)malloc
(sizeof(struct minstacknode));

	temp->left = temp->right = NULL;
	temp->data = data;
	temp->period = period;

	return temp;
}
struct minstack* createminstack(unsigned capacity)

{

	struct minstack* minStack
		= (struct minstack*)malloc(sizeof(struct minstack));
	minStack->size = 0;

	minStack->capacity = capacity;

	minStack->array
		= (struct minstacknode**)malloc(minStack->
capacity * sizeof(struct minstacknode*));
	return minStack;
}
void changeminstacknode(struct minstacknode** a,
					struct minstacknode** b)

{

	struct minstacknode* inter = *a;
	*a = *b;
	*b = inter;
}

void minpile(struct minstack* minStack, int addax)

{

	int smallest = addax;
	int left = 2 * addax + 1;
	int right = 2 * addax + 2;

	if (left < minStack->size && minStack->array[left]->
period < minStack->array[smallest]->period)
		smallest = left;

	if (right < minStack->size && minStack->array[right]->
period < minStack->array[smallest]->period)
		smallest = right;

	if (smallest != addax) {
		changeminstacknode(&minStack->array[smallest],
						&minStack->array[addax]);
		minpile(minStack, smallest);
	}
}
int sizeone(struct minstack* minStack)
{

	return (minStack->size == 1);
}
struct minstacknode* extractMin(struct minstack* minStack)

{

	struct minstacknode* temp = minStack->array[0];
	minStack->array[0]
		= minStack->array[minStack->size - 1];

	--minStack->size;
	minpile(minStack, 0);

	return temp;
}
void insertMinStack(struct minstack* minStack,
				struct minstacknode* minStacknode)

{

	++minStack->size;
	int i = minStack->size - 1;

	while (i && minStacknode->period< minStack->array[(i - 1) / 2]->period) {

		minStack->array[i] = minStack->array[(i - 1) / 2];
		i = (i - 1) / 2;
	}

	minStack->array[i] = minStacknode;
}
void buildMinStack(struct minstack* minStack)

{

	int n = minStack->size - 1;
	int i;

	for (i = (n - 1) / 2; i >= 0; --i)
		minpile(minStack, i);
}
void prtarr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		cout<< arr[i];

	cout<<"\n";
}
int isLeaf(struct minstacknode* root)

{

	return !(root->left) && !(root->right);
}

struct minstack* createAndBuildMinStack(char data[], int period[], int size)

{

	struct minstack* minStack = createminstack(size);

	for (int i = 0; i < size; ++i)
		minStack->array[i] = newNode(data[i], period[i]);

	minStack->size = size;
	buildMinStack(minStack);

	return minStack;
}
struct minstacknode* buildHuffmanTree(char data[], int period[], int size)

{
	struct minstacknode *left, *right, *top;
	struct minstack* minStack = createAndBuildMinStack(data, period, size);
	while (!sizeone(minStack)) {
		left = extractMin(minStack);
		right = extractMin(minStack);

		top = newNode('&', left->period + right->period);

		top->left = left;
		top->right = right;

		insertMinStack(minStack, top);
	}
	return extractMin(minStack);
}
void printCodes(struct minstacknode* root, int arr[], int top)

{
	if (root->left) {

		arr[top] = 0;
		printCodes(root->left, arr, top + 1);
	}
	if (root->right) {

		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (isLeaf(root)) {

		cout<< root->data <<":";
		prtarr(arr, top);
	}
}
void HuffmanCodes(char data[], int period[], int size)

{
	struct minstacknode* root
		= buildHuffmanTree(data, period, size);
	int arr[MAX_TREE_HT], top = 0;

	printCodes(root, arr, top);
}
int main()
{

	char arr[] ="%tolgahantoros%";
	int period[] = { 2,4,8,16,32,64 };

	int size = sizeof(arr) / sizeof(arr[0]);

	HuffmanCodes(arr, period, size);

	return 0;
}

