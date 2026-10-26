int __thiscall sub_644DB8(void *this, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8, int a9)
{
  int result; // eax
  int v10; // esi

  if ( !a2 || !a9 )
    return -2005530516;
  v10 = a6;
  if ( a6 == -1 )
    v10 = 0;
  result = sub_644D6A(this, a2, (unsigned int *)&a3, (unsigned int *)&a4, &a5, v10, &a7, a8);
  if ( result >= 0 )
  {
    result = (*(int (__stdcall **)(int, int, int, int, unsigned int, int, unsigned int, int, _DWORD))(*(_DWORD *)a2 + 92))(
               a2,
               a3,
               a4,
               a5,
               v10 & 0xFFE07FFF,
               a7,
               a8,
               a9,
               0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
