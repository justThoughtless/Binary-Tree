//
// Created by lemme on 6/7/20.
//

#ifndef UNTITLED_BTREE_H
#define UNTITLED_BTREE_H

#include "node.h"
#include<vector>

namespace tree{
    template<typename k,typename v>
    class btree
    {
    public:
        btree();
        ~btree();
        bool insert_node(k new_key,v value);
        v delete_node(k key);
        v get_value(k key);
        std::vector<v> inordervector();
        int size();
    private:
        node<k,v>* root;
        node<k,v>* get_node(k key);
        std::vector<node<k,v>*> __inordervector(node<k,v>* n);
        void set_root(node<k,v>* n);
    };

}


#endif //UNTITLED_BTREE_H
