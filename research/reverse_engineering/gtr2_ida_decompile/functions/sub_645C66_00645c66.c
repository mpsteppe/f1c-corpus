int __stdcall sub_645C66(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  int v7; // edi
  _BYTE v9[24]; // [esp+Ch] [ebp-334h] BYREF
  _BYTE v10[664]; // [esp+24h] [ebp-31Ch] BYREF
  _BYTE v11[128]; // [esp+2BCh] [ebp-84h] BYREF
  int v12; // [esp+33Ch] [ebp-4h] BYREF

  v12 = 0;
  sub_65BC9B(v9);
  if ( a6 )
    *a6 = 0;
  if ( (a5 & 0xFFFFFFFC) != 0 )
  {
    v7 = -2005530516;
  }
  else
  {
    v7 = sub_65D173(a1, a2, a3, a4);
    if ( v7 >= 0 )
    {
      sub_65EC4C(v11);
      v7 = sub_661E5C(v11, v9, a5, 0, &v12);
      sub_661299(v11);
      if ( v7 >= 0 )
      {
        if ( sub_65D7E1(v10) )
        {
          v7 = -2005529767;
        }
        else if ( a6 )
        {
          *a6 = v12;
          v12 = 0;
        }
      }
    }
  }
  if ( a7 )
    sub_65D773(a7);
  if ( v12 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v12 + 8))(v12);
    v12 = 0;
  }
  sub_65BD88(v9);
  return v7;
}
