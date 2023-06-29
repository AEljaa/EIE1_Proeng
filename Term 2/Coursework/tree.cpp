#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

/// this is just the pre-declaration of both structured data types
/// in order to allow usage in member data fields
struct TreeNode;
struct EdgeNode;

typedef std::string tree_t;

struct EdgeNode{
    TreeNode* subtree; //the pointer of the subtree(next vegtable) it points to
    EdgeNode* next; //Goes to the next edgenode that is connected to the next sub tree/vegtable
};

struct TreeNode{
    tree_t val; //The vegtable we want/ are curently on
    EdgeNode* subtree_l; //this is a pointer to a linked list not a tree (the connections between subtrees) pointer to edgenode that connects  the subtrees
};

TreeNode* allocate_tree_node(tree_t e){
    TreeNode* tmp = new TreeNode;
    tmp->val = e;
    tmp->subtree_l = NULL;
    return tmp;
}

EdgeNode* cons_edge_node(TreeNode* t, EdgeNode* subtree_l){//(tmp,main tree subtree)
    EdgeNode* tmp = new EdgeNode;
    tmp->subtree = t;
    tmp->next = subtree_l;
    return tmp;//returns a subtree_l
}

void print_tree(TreeNode* t){
    if(t != NULL){
        EdgeNode* it = t->subtree_l;
        while(it != NULL){
            print_tree(it->subtree);
            it = it->next;
        }
        std::cout << t->val << std::endl;
    }
}

TreeNode* build_tree_root(tree_t e){
    return allocate_tree_node(e);
}

/// this function looks for the node containg the value e
/// within the tree (whose root is) t
/// and it returns the address of the node if found
/// and NULL otherwise
TreeNode* find_node(tree_t e, TreeNode* t){
    // ALWAYS use nullptr over NULL in pointer-based applications, as it cannot be implicitly converted to non-pointer types like int, unlike NULL (https://stackoverflow.com/a/20509811)
    if (t == nullptr)
        return t;

    // Note: t cannot be nullptr at this point
    if (t->val == e)
        return t;

    // I think it's nicer to use a for loop rather than a while loop (which was used in print_tree) to simply iterate over the tree, as the EdgeNode* iterator `it` used to iterate through the tree is only used within the context of the loop, and has a regular increment operation that you want to perform at the end of each step whilst iterating through the loop. Using a for loop allows you to ensure `it` only exists within the scope of the for-loop (in general we want to declare variables in the deepest possible scope to keep the namespace uncluttered), and ensure that the iterator is incremented appropriately at each step of the iteration.
    for (auto it = t->subtree_l; it != nullptr; it = it->next)
    {
        auto res = find_node(e, it->subtree);
        if (res != nullptr)
            return res;
    }
    return nullptr;
}


/// this functions adds to the tree (whose root is) t
/// a node with value d as a child of the node with value s
/// (see also how this function is called in the main)
void add_tree_node(tree_t s, tree_t d, TreeNode* t){

        TreeNode *subtree,*tree_root;//two trees one that has the subtree we want to link to (d) and the other is the main tree root we link from (t)
        tree_root=find_node(s,t);//tree_root pointer will store its address in the tree_root if it already exits. If the subtree s isnt found in the tree, returns null(as done in func), then the function has pointer next = NULL as we want or just stores the tree pointer.

        subtree = allocate_tree_node(d); //certian this correct we make a new subtree we need to use to link to main tree same as when bulding the root in main,now we got to link this to the main root tree
        //feed allocated tree we made and edgenode from the vegtable/tree ndoe we found in find_node into the cons edge node func
        tree_root->subtree_l= cons_edge_node(subtree, tree_root->subtree_l);//we construct an edge node where the edgenode*subtree pointer points to the treenode val we are passign through(the new one we jsut made) as the subtree param and the edgenode pointer *next points to the current edgenode (making a chian of edgenodes) or it points to NULL if there isn't already the value/vegtable in the tree.

    /// TODO: complete this function
    
    /// within this function you must (meaningfully) use 
    /// function find_node
}

/// this function returns the number of nodes in the tree (whose root is) t
/// (see also example of expected output below)
int count_nodes(TreeNode* t){
    // if tree is empty return 0 since wwe do recursion;
    if(t==NULL){
        //when we reach null (carrot) we return 0 final node
        return 0;
    }
    else{
        //in all other cases when the tree is not null we are on a subtree node
        // initially count is 1 since tree not NULL we start at root tree/at beginning
        int count=1;
        EdgeNode* it = t->subtree_l;
        while(it != NULL){
            //we move to the next sub tree and increase count by 1 if not null(same implemetation as the provided print func) add all the counts together (ie the number of nodes) aslong as it is not null (it will only be null when we get to carrot therefore end of tree)
            count+=count_nodes(it->subtree);
            //loop through all edgenodes/ travel along the edgenodes as is done in the print func
            it = it->next;
        }
        return count;
    }

    /// TODO: complete this function
}

/// this function returns the number of leaf nodes in the tree (whose root is) t
/// (see also example of expected output below)
int count_leaf_nodes(TreeNode* t){
    if(t==NULL){
        //if the tree is at the end (null) return 0
        return 0;
    }

    if(t->subtree_l==NULL){
        //if the sub tree of the tree node we are currently on points to null then increase count by 1 we are on a leaf( leaf subtrees_l point to null by defeault)
        return 1;
    }
    //initally count is 0 since tree is not null/not on a leaf not possibel to start on a leaf at the beginning
    int count=0;
    //it has the sub tree of the bigger root tree (same implemetation of the printing func)
    EdgeNode* it = t->subtree_l;
    //while we don't hit a null
    while(it != NULL){
        //recursive we alrady set the requiremnets above therefore we can make this recursive to simplify
        count+= count_leaf_nodes(it->subtree);
        //it becimes the next value and still is in the whiel loop therefore all count values add up to check all subtrees whiel it is not NULL
        it = it->next;

    }
    return count;

    /// TODO: complete this function
}

/// this function deallocates *all* the memory (dynamically) allocated for the tree
/// this will include instances of the structured data type TreeNode
/// and instances of the structured data type EdgeNode
void deallocate_tree(TreeNode* t) {
    if (t != NULL ) {
        EdgeNode *it = t->subtree_l;
        while (it != NULL) {
            //recursive like the print func
            deallocate_tree(it->subtree);

            //jump to next edgenode to delete next sub tree and also the edgenode associated with that sub tree
            it = it->next;

        }
        // delte the starting root tree and sicne we let it= the next sub tree and we do thsi recursvily,we constantly delte all the sub trees.
        delete t;
        //deelte the current edgenode that we are currently withouth harming our loop,if we dont do thsi then we'd never dealloacte the edgenode memoy
        delete it;
    }
}
int main(){

    std::string filename;
    std::cin >> filename;

    std::ifstream infile;
    infile.open(filename);

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return(EXIT_FAILURE);
    }

    std::string s1, s2;
    infile >> s1;

    TreeNode* t1;
    t1 = build_tree_root(s1);

    while(infile >> s1 >> s2){
        add_tree_node(s1, s2, t1);
    }
    /// we could have infile.close(); here but in this case we are ok with infile being closed
    /// by the std::ifstream destructor when infile goes out of scope (at the end of the main)

    print_tree(t1);

    std::cout << "node count: " << count_nodes(t1) << std::endl;
    std::cout << "leaf node count: " << count_leaf_nodes(t1) << std::endl;

    deallocate_tree(t1);

}