#include <vector>
#include <list>

template<typename T, typename cont = std::vector<T>>
class Klass
{
public:
    void Add(const T el);

private:
    cont container;
};

// External member fucniton definitions must still be declared with the template arguments
// But you cant define the default template parameters value again
template<typename T, typename cont>
void Klass<T, cont>::Add(const T el)
{
    container.push_back(el);
}

int main()
{
    Klass<int, char> kls; // Compiles fine becuase of partial template usage
    //kls.Add(4); // Produces a compile error to do with char not working with .push_back

    // Override the default template param with list 
    Klass<int, std::list<int>> kls1;
    kls1.Add(4); // Compiles fine becuase std::list works with .push_back
}