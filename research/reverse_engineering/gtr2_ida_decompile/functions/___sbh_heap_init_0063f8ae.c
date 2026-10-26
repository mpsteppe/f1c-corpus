int __cdecl __sbh_heap_init(int a1)
{
  int result; // eax

  result = (int)HeapAlloc(hHeap, 0, 0x140u);
  lpMem = (LPVOID)result;
  if ( result )
  {
    dword_FBB4A0 = 0;
    dword_FBB4A4 = 0;
    dword_FBB4B0 = result;
    dword_FBB4AC = a1;
    dword_FBB4B4 = 16;
    return 1;
  }
  return result;
}
