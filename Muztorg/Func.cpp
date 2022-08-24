#include "Func.h"

System::String^ Convert_string_to_String(string& os, System::String^ s)
{
	s = gcnew System::String(os.c_str());
	return s;
}

string& Convert_String_to_string(System::String^ s)
{
	string os;
	using namespace System::Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
	return os;
}

System::String^ Convert_string_to_String(string& os)
{
	System::String^ s = gcnew System::String(os.c_str());
	return s;
}

string BillPathCreator(int Sale_ID)
{
	string BILL_DEFAUL_PATH = "_bill.txt";
	string result;
	result = "Sale_id_" + to_string(Sale_ID) + BILL_DEFAUL_PATH;

	return result;
}

string& Convert_String_to_string(System::String^ s, string& os)
{
	using namespace System::Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
	return os;
}