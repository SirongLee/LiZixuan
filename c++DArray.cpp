#include <cstdio>
#include <iostream>

using namespace std;

class DArray{
private:
    int arr_Size;
    int arr_Max;
    double *arr_Data;

private:
    void Init();
    void Free();
    inline bool InvalidateIndex(int mIndex);

public:
    DArray();
    DArray(int mSize, int DValue = 0);
    DArray(const DArray& arr);
    DArray& operator=(const DArray& arr); 
    ~DArray();

    void Print();
    int GetSize();
    void SetSize(int mSize);
    int GetAt(int mIndex);
    void SetAt(int mIndex, int DValue);
    void PushBack(int DValue);
    void InsertAt(int mIndex, double DValue);
    void DeleteAt(int mIndex);
    double operator[](int mIndex) const;
};

void DArray::Init(){
    arr_Size = 0;
    arr_Max = 1;
    arr_Data = new double[arr_Max];
}

void DArray::Free(){
    delete []arr_Data;
}

bool DArray::InvalidateIndex(int mIndex){
	if(mIndex >= 0 && mIndex < arr_Size)
		return false;
	else
		return true;
}

DArray::DArray(){
    Init();
}

DArray::DArray(int mSize, int DValue){
    if (mSize = 0){
        Init();
    }
    else{
        arr_Size = mSize;
        arr_Max = mSize*2;
        arr_Data = new double[arr_Max];
        for(int i = 0; i < mSize; i++){
            arr_Data[i] = DValue;
        }
    }
}

DArray::DArray(const DArray& arr){
    arr_Size = arr.arr_Size;
    arr_Max = arr.arr_Max;
    arr_Data = new double[arr_Max];
    memcpy(arr_Data, arr.arr_Data, arr_Size*sizeof(double));
}

DArray& DArray::operator=(const DArray& arr){
    arr_Size = arr.arr_Size;
    arr_Max = arr.arr_Max;
    double *arr_Temp = new double[arr_Max];
    memcpy(arr_Temp, arr.arr_Data, arr_Size*sizeof(double));
    delete[] arr_Data;
    arr_Data = arr_Temp;
    return *this;
}

DArray::~DArray(){
    Free();
}

void DArray::Print()
{
	if(arr_Size == 0)
	{
		cout << "Error: The empty array can't be Printed." << endl;
		exit(0);
	}
	else
	{
		for(int i = 0; i<arr_Size; ++i)
			cout << arr_Data[i] << " ";
		cout << endl;
	}
}

int DArray::GetSize()
{
	return arr_Size;
}

void DArray::SetSize(int mSize){
    if(mSize < arr_Size){
        for (int i = mSize; i < arr_Size; i++){
            arr_Data[i] = 0;
        }
    }
    if(arr_Size <= mSize && mSize <= arr_Max){
        for (int i  = arr_Size; i < mSize; i++){
            arr_Data[i] = 0;
        }
    }
    if(mSize > arr_Max){
        arr_Max = mSize*2;
        double *temp = new double[arr_Max];
        memcpy(temp, arr_Data, arr_Size*sizeof(double));
        for (int i = arr_Size; i < mSize; i++){
            temp[i] = 0;
        }
        delete arr_Data;
        arr_Data = temp;
    }
    arr_Size = mSize;
}

int DArray::GetAt(int mIndex){
    if(InvalidateIndex(mIndex)){
        cout << "Error: the index of GetAt is invalid!" << endl;
		exit(0);
    }
    return arr_Data[mIndex];
}

void DArray::SetAt(int mIndex, int DValue){
    if(InvalidateIndex(mIndex))
	{
		cout << "Error: the index of SetAt is invalid!" << endl;
		exit(0);
	}
	else
	{
		arr_Data[mIndex] = DValue;
	}
}

void DArray::PushBack(int DValue){
    if(arr_Size < arr_Max)
	{
		arr_Data[arr_Size] = DValue;
	}
	else  
	{
		arr_Max = arr_Max*2;
		double* temp = new double[arr_Max];
		memcpy(temp, arr_Data, arr_Size*sizeof(double));
		delete[] arr_Data;
		arr_Data = temp;
		arr_Data[arr_Size] = DValue;
	}
	++arr_Size;
}

void DArray::DeleteAt(int mIndex)
{
	if(InvalidateIndex(mIndex))
	{
		cout << "Error: the index of DeleteAt is invalid." << endl;
		exit(0);
	}
	else
	{	
		for(int i = mIndex; i < arr_Size; ++i){
			arr_Data[i] = arr_Data[i+1];
        }
		arr_Data[arr_Size-1] = 0;
		--arr_Size;
	}
}

void DArray::InsertAt(int mIndex, double DValue)
{
	if(mIndex < 0 || mIndex > arr_Size){
		cout << "Error: the index of InsertAt is invalid!" << endl;
		exit(0);
	}

	if(arr_Size < arr_Max){
		for(int i = arr_Size-1; i >= mIndex; --i)
			arr_Data[i+1] = arr_Data[i];
		arr_Data[mIndex] = DValue;
	}
	else{
		arr_Max = arr_Max*2;
		double* temp = new double[arr_Max];
		memcpy(temp, arr_Data, arr_Size*sizeof(double));
		delete [] arr_Data;
		arr_Data = temp;
		for(int i = arr_Size-1; i >= mIndex; --i)
			arr_Data[i+1] = arr_Data[i];
		arr_Data[mIndex] = DValue;
	}
	++arr_Size;
}

double DArray::operator[](int mIndex) const{
	if(mIndex<0 || mIndex>=arr_Size)
	{
		cout << "Error: the index in [] is invalid!" << endl;
		exit(0);
	}
	return arr_Data[mIndex];
}

int main (){
    return 0;
}
