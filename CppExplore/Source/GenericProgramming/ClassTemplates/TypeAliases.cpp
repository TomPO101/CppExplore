#include <vector>
#include <list>

template<typename T>
class Klass
{
public:
    void Add(const T el)
    {
        container.push_back(el);
    }

private:
    T container;
};

// This is called a TypeDef
typedef std::vector<int> IntVec;

// This is called a Alias Declaration
using IntList = std::list<int>;

// A common term for both methods is Type Alias Declaration
// So each new name is called a Type Alias


// Alias Templates

// Not you cannot use typdef(TypeDef) with this only using (Alias Declaration)

// Can only be defined in the global namespace and class declarations

template<typename T>
using VariableList = std::list<T>;

int main()
{
    // Use Typedef
    Klass<IntVec> kls;

    // Use Alias Declaration
    Klass<IntList> kls1;

    // Use Alias Template
    Klass<VariableList<int>> kls2;
    Klass<VariableList<char>> kls3;
}