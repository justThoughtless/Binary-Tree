//
// Created by lemme on 6/7/20.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H

namespace tree{
    template<typename k,typename v>
    struct node
    {
    public:
        node();
        node(k key,v value);

        ~node();
        void set_parent(node<k,v>* n);
        void set_left(node<k,v>* n);
        void set_right(node<k,v>* n);

        node<k,v>* get_parent();
        node<k,v>* get_left();
        node<k,v>* get_right();
        k get_key();
        v get_value();

        bool is_left();
        bool is_right();

    private:
        node<k,v> *left,*right,*parent;
        k Key;
        v Value;
    };
}


#endif //UNTITLED_NODE_H
