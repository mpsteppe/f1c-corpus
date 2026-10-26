// f1c  0x008d8000  size=190
int start()
{
  HMODULE LibraryA; // eax
  HMODULE v1; // eax
  BOOL (__stdcall *IsDebuggerPresent)(); // eax
  int result; // eax

  dword_5C7530 = (int)LocalAlloc(0x40u, 0x7D0u);
  LibraryA = LoadLibraryA("oph.dll");
  if ( LibraryA )
  {
    hModule = LibraryA;
    start_0 = GetProcAddress(LibraryA, "start");
    port = (int)GetProcAddress(hModule, "port");
    dword_5C752C = (int)GetProcAddress(hModule, "ip");
    start_0();
  }
  v1 = LoadLibraryA("steeringwheel.dll");
  if ( v1 )
  {
    dword_5C7534 = (int)v1;
    start_1 = (int)GetProcAddress(v1, "start");
    ((void (*)(void))start_1)();
  }
  IsDebuggerPresent = (BOOL (__stdcall *)())GetModuleHandleA("KERNEL32");
  if ( IsDebuggerPresent )
  {
    IsDebuggerPresent = GetProcAddress((HMODULE)IsDebuggerPresent, "IsDebuggerPresent");
    dword_5C753C = IsDebuggerPresent;
  }
  result = IsDebuggerPresent();
  if ( !result )
    return sub_58A19E();
  return result;
}
