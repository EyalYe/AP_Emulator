

class BitCell{
    private:
        int _value;
    public:
        BitCell(int value);
        int getValue();
        void setValue(int value);
        void flip();
        void print();
};