//
// Created by bob on 11/15/19.
//

#pragma once

#include <stdexcept>
#include <cstdint>

template <typename TreeType>
struct TreeNode {
    TreeType
        datum;
    int32_t
        count,
        height;
    TreeNode<TreeType>
        *left,*right;
};

template <class TreeType>
class SortedLinearList {
public:
    SortedLinearList() { root = nullptr; }
    ~SortedLinearList() { prvClear(root); }

    void clear() { prvClear(root); root = nullptr; }
    bool isEmpty() { return root == nullptr; }

    //-----------------------------------------------------------------------------
    //  int32_t size()
    //      return number of nodes in the tree
    //
    //  returns
    //      the number of nodes in the tree
    //

    int32_t size() {

        // no tree? no nodes.
        if (root == nullptr)
            return 0;

        // get node count from root
        return root->count;
    }

    //-----------------------------------------------------------------------------
    //  int32_t height()
    //      return height of the tree
    //
    //  returns
    //      the height of the tree
    //
    //  note
    //  - height is number of edges from root to farthest leaf
    //

    int32_t height() {

        // no tree? height is -1 by default
        if (root == nullptr)
            return -1;

        // get height from root
        return root->height;
    }

    //-----------------------------------------------------------------------------
    //  int32_t search(TreeType key)
    //      search for node in tree
    //
    //  parameter
    //      key - key to find
    //
    //  returns
    //      rank of key (position in sorted order) if found
    //
    //  throws
    //      domain_error if key is not in the list
    //

    int32_t search(TreeType key) {
        TreeNode<TreeType>
            *node = root;
        int32_t
            pos = 0;

        // walk down the tree from the top
        while (node != nullptr)
            // is this the key?
            if (node->datum == key) {
                if (node->left != nullptr)      // update the rank with leftCount
                    pos += node->left->count;
                return pos;                     // return the rank

                // is the key smaller than node's value?
            } else if (key < node->datum)
                node = node->left;              // walk to the left

                // is the key larger than the node's value?
            else {
                pos++;                          // update skipped, add leftCount+1
                if (node->left != nullptr)
                    pos += node->left->count;
                node = node->right;             // walk to the right
            }

        // if we fall out of the loop, the key wasn't in the tree. throw an error.
        throw std::domain_error("Key ["+std::to_string(key)+"] not found");
    }

    //-----------------------------------------------------------------------------
    //  TreeType &operator[](int32_t pos)
    //      find the element at the given rank
    //
    //  parameter
    //      pos - rank to locate
    //
    //  returns
    //      element at the given rank
    //
    //  throws
    //      out_of_range if pos < 0 or pos >= tree size
    //

    TreeType &operator[](int32_t pos) {
        TreeNode<TreeType>
            *node;
        int32_t
            leftCount,
            skipped;

        // make sure pos is valid, or the loop could fall out of the tree
        if (root == nullptr || pos < 0 || pos >= root->count)
            throw std::domain_error("Index " + std::to_string(pos) + " is out of range");

        // start at root, with initial skipped and leftCount values
        node = root;
        leftCount = skipped = 0;
        if (node->left != nullptr)
            leftCount = node->left->count;

        // walk down the tree
        while (true) {
            // current node rank is skipped+leftCount; is that the right rank?
            if (skipped + leftCount == pos)
                return node->datum;                 // yes, stop and return

                // is the rank too high?
            else if (skipped + leftCount > pos)
                node = node->left;                  // yes, go left

                // is the rank too low?
            else {
                skipped += leftCount + 1;           // yes, adjust skipped
                node = node->right;                 // and go right
            }

            // if we go left or right, update leftCount
            leftCount = 0;
            if (node->left != nullptr)
                leftCount = node->left->count;
        }
    }

    void traverse(void (*fp)(TreeType &)) { prvTraverse(root,fp); }

    //-----------------------------------------------------------------------------
    //  void insert(TreeType val)
    //      insert a value into the list
    //
    //  parameter
    //      val - value to be inserted
    //

    void insert(TreeType val) {
        TreeNode<TreeType>
            *newNode;

        // create and populate a new node
        newNode = new TreeNode<TreeType>;
        newNode->datum = val;
        newNode->left = newNode->right = nullptr;
        newNode->count = 1;
        newNode->height = 0;

        // recursively insert it into the tree
        root = prvInsert(root,newNode);
    }

    //-----------------------------------------------------------------------------
    //  void remove(TreeType key)
    //      remove a value from the list
    //
    //  parameter
    //      key - value to be removed
    //
    //  throws
    //      domain_error if key is not in the list
    //

    void remove(TreeType key) {

        // recursively detach the key node from the tree
        root = prvRemove(root,key);

        // if the key was found, ntbd will be set and detached from the tree;
        // delete the node
        //if (ntbd != nullptr)
            delete ntbd;
    }

private:
    //-----------------------------------------------------------------------------
    //  void prvClear(TreeNode<TreeType> *r)
    //      remove r and both subtrees via postorder traversal
    //
    //  parameter
    //      r - root of subtree being deleted
    //

    void prvClear(TreeNode<TreeType> *r) {

        // if r is null, nothing to do
        if (r != nullptr) {
            prvClear(r->left);      // delete the subtrees first
            prvClear(r->right);
            delete r;               // then delete r
        }
    }

    //-----------------------------------------------------------------------------
    //  void prvTraverse(TreeNode<TreeType> *r,
    //        void (*fp)(TreeType &))
    //      traverse the list, calling fp() with each value in sorted order
    //
    //  parameters
    //       r - root of subtree to traverse
    //      fp - function to call with datum passed to it
    //

    void prvTraverse(TreeNode<TreeType> *r,void (*fp)(TreeType &)) {

        // no tree? no work.
        if (r != nullptr) {
            prvTraverse(r->left,fp);    // recursively traverse to the left
            (*fp)(r->datum);            // pass datum to function
            prvTraverse(r->right,fp);   // recursively traverse to the right
        }
    }

    //-----------------------------------------------------------------------------
    //  TreeNode<TreeType> *prvInsert(
    //          TreeNode<TreeType> *r,TreeNode<TreeType> *newNode)
    //      recursively add a new node to the given (sub)tree
    //
    //  parameters
    //            r - root of subtree that will contain newNode
    //      newNode - new node being inserted
    //
    //  returns
    //      root of the resulting tree... newNode if r is null, r otherwise
    //

    TreeNode<TreeType> *prvInsert(TreeNode<TreeType> *r,TreeNode<TreeType> *newNode) {

        // if current tree doesn't exist, then the new tree is just the new node
        if (r == nullptr)
            return newNode;

        // recursively insert to the left or right
        // attach what is returned as the left or right child
        if (newNode->datum < r->datum)
            r->left = prvInsert(r->left,newNode);
        else
            r->right = prvInsert(r->right,newNode);

        // update node count and tree height
        prvAdjust(r);

        // return root of tree
        return r;
    }

    //-----------------------------------------------------------------------------
    //  TreeNode<TreeType> *prvRemove(TreeNode<TreeType> *r,
    //                                  const TreeType &key)
    //      recursively remove a value from the tree
    //
    //  parameters
    //        r - root of (sub)tree to remove from
    //      key - value being removed
    //
    //  returns
    //      root of resulting tree after removal
    //
    //  throws
    //      domain_error if key isn't in the tree
    //

    TreeNode<TreeType> *prvRemove(TreeNode<TreeType> *r,const TreeType &key) {
        TreeNode<TreeType>
            *tmpNode;
        TreeType
            tmp;

        // no tree? that's a problem, throw an error
        if (r == nullptr)
            throw std::domain_error("Key ["+std::to_string(key)+"] not found");

        // is the key smaller?
        if (key < r->datum) {
            r->left = prvRemove(r->left, key);      // yes, recurse to the left

            // is the key larger?
        } else if (key > r->datum) {
            r->right = prvRemove(r->right,key);     // yes, recurse to the right

            // do we have a match?
        } else {

            ntbd = r;                               // remember the node

            // no left child?
            if (r->left == nullptr) {

                // no right child either?
                if (r->right == nullptr)
                    return nullptr;                 // deleting a leaf, return null
                else
                    return r->right;                // only a right child, return it
            } else {
                // no right child?
                if (r->right == nullptr)
                    return r->left;                 // only a left child, return it
                else {
                    // choose taller subtree to swap into
                    if (r->left->height > r->right->height) {
                        // find largest node in left subtree
                        for (tmpNode = r->left; tmpNode->right != nullptr;
                             tmpNode = tmpNode->right);

                        // swap ntbd and largest node in left subtree
                        tmp = r->datum;
                        r->datum = tmpNode->datum;
                        tmpNode->datum = tmp;

                        // recursively remove to the left
                        r->left = prvRemove(r->left,key);

                    } else {

                        // find smallest node in right subtree
                        for (tmpNode = r->right; tmpNode->left != nullptr;
                             tmpNode = tmpNode->left);

                        // swap ntbd and smallest node in right subtree
                        tmp = r->datum;
                        r->datum = tmpNode->datum;
                        tmpNode->datum = tmp;

                        // recursively remove to the right
                        r->right = prvRemove(r->right,key);
                    }
                }
            }
        }

        // adjust count and height information for new root
        prvAdjust(r);

        // return the root of the resulting tree
        return r;
    }

    //-----------------------------------------------------------------------------
    //  void prvAdjust(TreeNode<TreeType> *r)
    //      compute node count and height of tree rooted at r
    //
    //  parameter
    //      r - root of tree whose sizes are being determined
    //

    void prvAdjust(TreeNode<TreeType> *r) {

        // assume tree is just a leaf
        r->count = 1;
        r->height = 0;

        // if there's a left child, factor it in
        if (r->left != nullptr) {
            r->count += r->left->count;
            r->height = 1 + r->left->height;
        }

        // if there's a right child, factor it in also
        if (r->right != nullptr) {
            r->count += r->right->count;
            if (1 + r->right->height > r->height)
                r->height = 1 + r->right->height;
        }
    }

    TreeNode<TreeType>
        *root,
        *ntbd;
};
