//#include <QCoreApplication>
#include "tree.h"

int main()
{
    tree<string> root;
    root.add_content(string("root"));
    tree<string> a,b,c,d,e,f,g,h;
    a.add_content(string("a "));
    b.add_content(string("b "));
    c.add_content(string("c "));
    d.add_content(string("d "));
    e.add_content(string("e "));
    f.add_content(string("f0"));
    f.add_content(string("f2"));
    f.add_content(string("f3"));
    f.add_content(string("f5"));
    g.add_content(string("g" ));
    h.add_content(string("h" ));

    root.append_child(a);
    root.append_child(b);
    root.append_child(c);
    root.append_child(f);
    a.append_child(d);
    d.append_child(h);
    d.append_child(g);
    b.append_child(e);


    root.traverse(0 );

    d.move_to(&root);
    root.traverse(0);

    root.remove_child(a);
    root.traverse(0);

    f.pop_content();
    f.del_content(1);
    root.traverse(0);
/*
    tree<int> root;
    root.add_content(0);
    tree<int> a,b,c,d,e,f,g,h;
    a.add_content(1);
    b.add_content(2);
    c.add_content(3);
    d.add_content(4);
    e.add_content(5);
    f.add_content(10);
    f.add_content(12);
    f.add_content(13);
    f.add_content(15);
    g.add_content(21);
    h.add_content(32);

    root.append_child(a);
    root.append_child(b);
    root.append_child(c);
    root.append_child(f);
    a.append_child(d);
    d.append_child(h);
    d.append_child(g);
    b.append_child(e);

    root.traverse(0 );

    d.move_to(&root);
    root.traverse(0);

    root.remove_child(a);
    root.traverse(0);

    f.pop_content();
    f.del_content(1);
    root.traverse(0);

   */
    return 0;
}
