/*--------------------------------------------------------------------------------*\
 | MIT License                                                                    |
 |                                                                                |
 | Copyright (c) 2017 Gustavo Takachi Toyota                                      |
 |                                                                                |
 | Permission is hereby granted, free of charge, to any person obtaining a copy   |
 | of this software and associated documentation files (the "Software"), to deal  |
 | in the Software without restriction, including without limitation the rights   |
 | to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      |
 | copies of the Software, and to permit persons to whom the Software is          |
 | furnished to do so, subject to the following conditions:                       |
 |                                                                                |
 | The above copyright notice and this permission notice shall be included in all |
 | copies or substantial portions of the Software.                                |
 |                                                                                |
 | THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     |
 | IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       |
 | FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    |
 | AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         |
 | LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  |
 | OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  |
 | SOFTWARE.                                                                      |
\*--------------------------------------------------------------------------------*/

#ifndef OPTIONAL
#define OPTIONAL

#include <memory>

template <typename Type>
class optional {
public:
    optional() {
    }
    optional(const optional<Type> &value) {
        if (value.exists())
            pointer.reset(new Type(*value));
        else
            pointer.reset();
    }
    optional(const Type &value) {
        pointer.reset(new Type(value));
    }

    // Functions
    void clear() {
        pointer.reset();
    }
    bool exists() const {
        return pointer != NULL;
    }

    // Operators
    Type &operator =(const optional<Type> &value) {
        if (value.exists())
            pointer.reset(new Type(*value));
        else
            pointer.reset();

        return *pointer;
    }

    Type &operator *() {
        return *pointer;
    }
    const Type &operator *() const {
        return *pointer;
    }

    Type *operator ->() {
        return pointer.get();
    }
    const Type *operator ->() const {
        return pointer.get();
    }
private:
    std::unique_ptr<Type> pointer;
};

#endif