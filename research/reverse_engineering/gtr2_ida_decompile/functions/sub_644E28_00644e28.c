int __thiscall sub_644E28(void *this, int a2, int a3, int a4, int a5, int a6, unsigned int a7, int a8)
{
  int result; // eax
  int v9; // esi

  if ( !a2 || !a8 )
    return -2005530516;
  v9 = a5;
  if ( a5 == -1 )
    v9 = 0;
  result = sub_644D91(this, a2, (unsigned int *)&a3, &a4, v9, &a6, a7);
  if ( result >= 0 )
  {
    result = (*(int (__stdcall **)(int, int, int, unsigned int, int, unsigned int, int, _DWORD))(*(_DWORD *)a2 + 100))(
               a2,
               a3,
               a4,
               v9 & 0xFFE07FFF,
               a6,
               a7,
               a8,
               0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
