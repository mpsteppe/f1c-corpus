int __cdecl _initptd(int a1)
{
  int result; // eax

  result = a1;
  *(_DWORD *)(a1 + 80) = &unk_6264D8;
  *(_DWORD *)(a1 + 20) = 1;
  return result;
}
