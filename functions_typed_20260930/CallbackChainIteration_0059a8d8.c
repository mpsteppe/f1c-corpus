int __thiscall sub_59A8D8(_DWORD *this, int a2)
{
  int **i; // esi
  int result; // eax

  for ( i = (int **)this[7]; i; i = (int **)*i )
    result = ((int (__cdecl *)(int, _DWORD *, int *))i[2])(a2, this, i[1]);
  return result;
}

