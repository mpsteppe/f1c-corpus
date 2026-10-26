// f1c  0x00593dd3  size=72
int __cdecl sub_593DD3(int a1)
{
  int result; // eax

  result = (int)HeapAlloc(hHeap, 0, 0x140u);
  lpMem = (LPVOID)result;
  if ( result )
  {
    dword_8D48F4 = 0;
    dword_8D48F8 = 0;
    dword_8D48F0 = result;
    dword_8D4900 = a1;
    dword_8D48E8 = 16;
    return 1;
  }
  return result;
}
