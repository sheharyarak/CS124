#include "parseFile.hpp"

/*this function writes the data of the node and its path to the file on a single line. It then calls itself by passing in the child nodes. It writes to the file in preorder.*/
void writeNode(BinaryTree tree, ofstream * file, string path)
{
	if(tree.empty())
		return;
	*file << tree.data() << "(" << path <<")" <<endl;
	writeNode(tree.left(), file, path + "y");
	writeNode(tree.right(), file, path + "n");
}
/*opens file and calls the writeNode function by passing in the output file and the root of the binary tree.*/
void writeTree(BinaryTree tree, string filename)
{
	ofstream *ofs = new ofstream(filename);
	writeNode(tree, ofs, "");
	ofs->close();	
}
/*This function parses line and creates a node with parsed data. and then adds child nodes. It use a '.' to determin whether it has reached a leaf node.*/
void addNode(Node *&root, ifstream *file)
{
	string line, path, data;
	int start, end, len;
	if(!getline(*file, line)) return;
	start = line.find("(") + 1;
	end = line.find(")");
	len = start - end;
	path = line.substr(end-start);
	data = line.substr(0, start - 1);
	root = new Node(data);
	if(data[data.length() - 1] == '.')
			return;
	addNode(root->left, file);
	addNode(root->right, file);
}
/*This function opens the file. and calls the addNode function by passing in a root node.*/
BinaryTree readFile(string filename){
	Node *root;
	ifstream *file = new ifstream(filename);
	addNode(root, file);
	file->close();
	BinaryTree tree(root);
	return tree;
}
