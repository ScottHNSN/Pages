#ifndef POWNERTREE_H
#define POWNERTREE_H
#include <vector>
//small bintree class
template <typename NodeType>
class PNode { /* >>> Binary tree Nodes Class for easy lookup of pagetrees & more <<< */
public:
    PNode(PNode* NodeParentptr = nullptr, NodeType* NodeContent = nullptr, std::vector<PNode*>* siblinglist = nullptr) {
        if (NodeParent != nullptr) {
            ChildOrRoot = 1;
            NodeParent = NodeParentptr;
            Siblings = siblinglist;
            GenKey(NodeParentptr, keyX, keyY);
        } else {
            ChildOrRoot = 0;
            GenKey(nullptr);
        }
    content = NodeContent;
    }
    void GenKey(PNode* parent, int* X, int* Y) {
        if (parent = (nullptr)) {
            *X = 0;
            *Y = 0;
        }
        else {
            *X = parent->KeyY + 1;
            *Y = parent->Siblings->size() + 1;
        }
    }
    PNode* AddChild(NodeType* ChildContent) {
        PNode* childptr = new PNode<NodeType>(this, &ChildContent, Children);
        Children->push_back(childptr);
        return childptr;
    }
    PNode* GetParent(bool Force = 0) {
        if (ChildOrRoot == 1) {
            return NodeParent;
        } else if (ChildOrRoot == 0 && Force == 1) {
            return NodeParent; // do NOT do this
        } else if (ChildOrRoot == 1 && Force == 0) {
            static_assert(false, "Node is root!");
        }
    }
    PNode* AddSibling(NodeType *NodeContent) { // adds sibling to the tree with same parent, adds it to shared

        PNode* brotherbuffer = new PNode;
        Siblings->push_back(brotherbuffer);
        return brotherbuffer;
    }
private:
    int keyX;
    int keyY;
    bool ChildOrRoot; // 0 = root 1 = ChildOrRoot
    PNode* NodeParent;
    NodeType* content;
    std::vector<PNode*>* Siblings = nullptr;
    std::vector<PNode*>* Children = nullptr;
};

#endif // POWNERTREE_H

