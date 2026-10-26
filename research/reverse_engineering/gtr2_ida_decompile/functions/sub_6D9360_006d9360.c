int __stdcall sub_6D9360(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // eax
  int v3; // eax
  int result; // eax
  int v5; // eax

  v1 = (_DWORD *)a1[85];
  (*(void (__stdcall **)(_DWORD *))(a1[93] + 8))(a1);
  v2 = v1[5];
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( !v3 )
    {
      result = v1[6] + 1;
      v1[5] = 2;
      v1[6] = result;
      return result;
    }
    if ( v3 == 1 )
    {
      if ( a1[46] )
      {
        ++v1[8];
        result = v1[6] + 1;
        v1[5] = 1;
        v1[6] = result;
        return result;
      }
      goto LABEL_8;
    }
  }
  else
  {
    v5 = a1[46];
    v1[5] = 2;
    if ( !v5 )
LABEL_8:
      ++v1[8];
  }
  result = v1[6] + 1;
  v1[6] = result;
  return result;
}
