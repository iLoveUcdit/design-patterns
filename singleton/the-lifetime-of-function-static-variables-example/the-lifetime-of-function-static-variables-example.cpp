#include <string>
#include <iostream>

class ClassForTest {
public:
    ClassForTest(const std::string &name) : m_name(name) {
        std::cout << "Created " << m_name << std::endl;
    }
    virtual ~ClassForTest() {
        std::cout << "Destroyed " << m_name << std::endl;
    }

private:
    std::string m_name;
};

static void Check(bool skipIf) {
    if (!skipIf) {
        static ClassForTest classForTest1("in if");
    }
    static ClassForTest classForTest2("in check");
}

int main(int argc, char *argv[]) {

    Check(argc != 2);
    if (argc == 3) {
        Check(false);
    }

    return 0;
}

/*
* Test Case 1: argc = 1.
* Test Case 2: argc = 2.
* Test Case 3: argc = 3.
*/
