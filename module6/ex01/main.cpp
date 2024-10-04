#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.text = "Hello, world!";

    uintptr_t raw = Serializer::serialize(&data);
    Data* deserializedData = Serializer::deserialize(raw);

    std::cout << "Original Data: " << &data << "\n";
    std::cout << "Deserialized Data: " << deserializedData << "\n";

    std::cout << "Data number: " << deserializedData->number << "\n";
    std::cout << "Data text: " << deserializedData->text << "\n";

    if (&data == deserializedData)
    {
        std::cout << "Serialization and deserialization successful!" << std::endl;
    }
    else
    {
        std::cout << "Serialization and deserialization failed!" << std::endl;
    }

    return 0;
}
