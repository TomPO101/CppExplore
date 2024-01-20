#include <vector>

template<typename T, typename cont = std::vector<T>>
class Klass
{
public:
    void Add(const T el);

private:
    cont container;
};

template<typename T, typename cont>
void Klass<T, cont>::Add(const T el)
{
    container.push_back(el);
}

int main()
{
    Klass<int> kls;
    kls.Add(4);
}