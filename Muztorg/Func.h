#pragma once
#include "Types.hpp"

string& Convert_String_to_string(System::String^ s, string& os);
System::String^ Convert_string_to_String(string& os, System::String^ s);
string& Convert_String_to_string(System::String^ s);
System::String^ Convert_string_to_String(string& os);
string BillPathCreator(int Sale_ID);