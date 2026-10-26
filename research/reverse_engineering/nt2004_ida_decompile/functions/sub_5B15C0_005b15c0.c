_DWORD *__thiscall sub_5B15C0(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // esi
  _DWORD *result; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int v8; // ecx
  _DWORD *i; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  int v12; // ecx

  v4 = (_DWORD *)this[2];
  result = v4;
  if ( v4 )
  {
    while ( result[5] != a2 || result[6] != a3 )
    {
      result = (_DWORD *)result[7];
      if ( !result )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    if ( v4 )
    {
      for ( i = (_DWORD *)v4[7]; i; i = (_DWORD *)i[7] )
        v4 = i;
      v10 = operator new(0x20u);
      if ( v10 )
        v11 = sub_5B12C0(v10);
      else
        v11 = 0;
      v4[7] = v11;
      sub_5B1320(v11, a2, a3);
      return (_DWORD *)v12;
    }
    else
    {
      v6 = operator new(0x20u);
      if ( v6 )
      {
        v7 = sub_5B12C0(v6);
        this[2] = v7;
        sub_5B1320(v7, a2, a3);
      }
      else
      {
        this[2] = 0;
        sub_5B1320(0, a2, a3);
      }
      return (_DWORD *)v8;
    }
  }
  return result;
}
