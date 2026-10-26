int __stdcall sub_645B85(LPCWCH lpWideCharStr, int a2, int a3, int a4, _DWORD *a5, int a6)
{
  int v6; // ebx
  int v8[6]; // [esp+Ch] [ebp-334h] BYREF
  _BYTE v9[664]; // [esp+24h] [ebp-31Ch] BYREF
  _BYTE v10[128]; // [esp+2BCh] [ebp-84h] BYREF
  int v11; // [esp+33Ch] [ebp-4h] BYREF

  v11 = 0;
  sub_65BC9B(v8);
  if ( a5 )
    *a5 = 0;
  if ( (a4 & 0xFFFFFFFC) != 0 )
  {
    v6 = -2005530516;
  }
  else
  {
    v6 = sub_65D0F5((int)v8, lpWideCharStr, 0, a2, a3);
    if ( v6 >= 0 )
    {
      sub_65EC4C(v10);
      v6 = sub_661E5C(v10, v8, a4, 0, &v11);
      sub_661299(v10);
      if ( v6 >= 0 )
      {
        if ( sub_65D7E1(v9) )
        {
          v6 = -2005529767;
        }
        else if ( a5 )
        {
          *a5 = v11;
          v11 = 0;
        }
      }
    }
  }
  if ( a6 )
    sub_65D773(a6);
  if ( v11 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v11 + 8))(v11);
    v11 = 0;
  }
  sub_65BD88(v8);
  return v6;
}
