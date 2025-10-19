class queue
{
private:
    int* head;
    int* tail;
    const int coef = 2;
    int max_size;
    int* start_array_mem;
    int* end_array_mem;

public:
    int* get_head();

    int* get_tail();

    int get_max_size();

    queue(int initialSize);

    ~queue();

    queue& operator=(const queue& from);

    void allocate_new_array();

    void push_to_head(int value);

    void push_to_tail(int value);

    void print_array_with_capacity();

    int pop_from_head();

    int pop_from_tail();
};
