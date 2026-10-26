int __cdecl __sbh_heap_init(int a1)
{
  int result; // eax

  result = (int)HeapAlloc(hHeap, 0, 0x140u);
  lpMem = (LPVOID)result;
  if ( result )
  {
    dword_8003B4 = 0;
    dword_8003B8 = 0;
    dword_8003B0 = result;
    dword_8003C0 = a1;
    dword_8003A8 = 16;
    return 1;
  }
  return result;
}
