

class BitCell{
    private:
        int _value;
    public:
        BitCell(int value = 0){this->_value = value;}
        int compare(int key, int mask);
        int write(int key, int mask);
};