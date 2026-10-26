int __thiscall sub_644E91(void *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8, unsigned int a9, int a10)
{
  int result; // eax
  int v11; // esi

  if ( !a2 || !a10 )
    return -2005530516;
  v11 = a7;
  if ( a7 == -1 )
    v11 = 0;
  result = sub_6449B5(
             (int)this,
             a2,
             (unsigned int *)&a3,
             (unsigned int *)&a4,
             (unsigned int *)&a5,
             &a6,
             v11,
             &a8,
             a9,
             4);
  if ( result >= 0 )
  {
    result = (*(int (__stdcall **)(int, int, int, int, int, unsigned int, int, unsigned int, int, _DWORD))(*(_DWORD *)a2 + 96))(
               a2,
               a3,
               a4,
               a5,
               a6,
               v11 & 0xFFE07FFF,
               a8,
               a9,
               a10,
               0);
    if ( result >= 0 )
      return 0;
  }
  return result;
}
