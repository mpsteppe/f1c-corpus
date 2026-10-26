// f1c  0x00516990  size=28
int __cdecl sub_516990(int a1)
{
  int result; // eax

  result = (**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 274);
  *(_BYTE *)(result + 273) = 0;
  return result;
}
