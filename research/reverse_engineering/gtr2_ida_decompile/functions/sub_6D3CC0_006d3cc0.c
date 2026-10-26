unsigned int __stdcall sub_6D3CC0(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  unsigned int *v4; // esi
  unsigned int result; // eax
  _DWORD *v6; // ebx
  bool v7; // zf
  unsigned int v8; // ecx

  v4 = (unsigned int *)a1[86];
  result = v4[2];
  if ( result < a1[62] )
  {
    v6 = v4 + 3;
    do
    {
      v7 = *v6 == 8;
      if ( *v6 < 8u )
      {
        result = (*(int (__stdcall **)(_DWORD *, int, _DWORD *, int, unsigned int *, unsigned int *, int))(a1[87] + 4))(
                   a1,
                   a2,
                   a3,
                   a4,
                   v4 + 6,
                   v4 + 3,
                   8);
        v7 = *v6 == 8;
      }
      if ( !v7 )
        break;
      v7 = (*(int (__stdcall **)(_DWORD *, unsigned int *))(a1[88] + 4))(a1, v4 + 6) == 0;
      result = v4[4];
      if ( v7 )
      {
        if ( !result )
        {
          result = (unsigned int)a3;
          --*a3;
          v4[4] = 1;
        }
        return result;
      }
      if ( result )
      {
        ++*a3;
        v4[4] = 0;
      }
      v8 = a1[62];
      result = v4[2] + 1;
      *v6 = 0;
      v4[2] = result;
    }
    while ( result < v8 );
  }
  return result;
}
