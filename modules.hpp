

class BitCell{
    private:
        int _value;
    public:
        BitCell(int value = 0);
        int compare(int key, int mask);
        int write(int key, int mask);
};