class node{
   private:
     int value;
     node *next;
   public:
     node();
     void set(int);
     void insert(node *);
     void insert(int);
     void print();
     void print_evens();
};
