
template<typename T>

class vector {
    private:
    T* mData;
    size_t mCap;
    size_t mSize;
    void expandCapacity(size_t cap){ // ขยาย capacity
        T* arr = new T[cap];
        for(size_t i = 0;i < mSize;i++){
            arr[i] = mData[i];
        }
        delete[] mData;
        mData = arr;
        mCap = cap;
    };

    void CheckCapacity(size_t cap){ // check capacity ว่า User ขอเท่าไหร่
        if(cap > mCap){
            size_t newcap = (cap > mCap * 2) ? cap : mCap * 2;
            expandCapacity(newcap);
        }
    };

    public:
    typedef T* iterator;

    iterator begin(){
        return &mData[0];
    }

    iterator end(){
        return begin() + mSize;
    }

    vector() {
        mData = nullptr;
        mSize = 0;
        mCap = 0;
    }; // constructor

    ~vector(){ // destructor
         delete[] mData;
    };
    vector(const vector<T> &a){ // copy constructor
        mData = new T[a.cap()]();
        mCap = a.cap();
        mSize = a.size();
        for(size_t i = 0;i < a.size();i++){
            mData[i] = a[i];
        }
    };

    vector<T> operator=(vector<T> &other){ // assignment operator
        if(mData != other.mData){
            delete[] mData;
            mData = new T[other.cap()]();
            mCap = other.cap();
            mSize = other.size();
            for(size_t i = 0;i < other.size();i++){
                mData[i] = other[i];
            }
        }

    };

    void push_back(const T& value){
        CheckCapacity(mSize + 1);
        mData[mSize] = value;
        mSize++;
    };

    void pop_back(){
        mSize--; 
    };

    void clear(){
        mSize = 0;
    };

    void size(){
        return mSize;
    };

    iterator insert(iterator it, const T& value){
        size_t index = it - begin();
        CheckCapacity(mSize + 1);
        for(size_t i = mSize;i > index;i--){
            mData[i] = mData[i - 1];
        }
        mData[index] = value;
        mSize++;
        return begin() + index;
    };

    void erase(iterator it){
        while((it + 1) != end()){
            *it = *(it + 1);
            it++;
        }
        mSize--;
    };

    bool empty() const {
        return mSize == 0;
    }
};



template<typename T>

class stack{
    private:
    T* mData;
    size_t mCap;
    size_t mSize;
    void expandCapacity(size_t cap){ // ขยาย capacity
        T* arr = new T[cap];
        for(size_t i = 0;i < mSize;i++){
            arr[i] = mData[i];
        }
        delete[] mData;
        mData = arr;
        mCap = cap;
    };

    void CheckCapacity(size_t cap){ // check capacity ว่า User ขอเท่าไหร่
        if(cap > mCap){
            size_t newcap = (cap > mCap * 2) ? cap : mCap * 2;
            expandCapacity(newcap);
        }
    };

    public:
    stack() {
        mData = nullptr;
        mSize = 0;
        mCap = 0;
    }; // constructor

    ~stack(){ // destructor
         delete[] mData;
    };

    stack(const stack<T> &a){ // copy constructor
        mData = new T[a.cap()]();
        mCap = a.cap();
        mSize = a.size();
        for(size_t i = 0;i < a.size();i++){
            mData[i] = a[i];
        }
    };

    stack<T> operator=(stack<T> &other){ // assignment operator
        if(mData != other.mData){
            delete[] mData;
            mData = new T[other.cap()]();
            mCap = other.cap();
            mSize = other.size();
            for(size_t i = 0;i < other.size();i++){
                mData[i] = other[i];
            }
        }

    };

    const T& top() const{
        return mData[mSize - 1];
    };

    void push(const T& value){
        CheckCapacity(mSize + 1);
        mData[mSize] = value;
        mSize++;
    };

    void pop(){
        mSize--;
    };

     void size(){
        return mSize;
    };

    bool empty() const {
        return mSize == 0;
    }

};



