int __stdcall sub_645E7A(int a1, int a2, int a3, int a4, char ArgList, int a6, int a7, int *a8, int a9, int *a10)
{
  int v12[6]; // [esp+Ch] [ebp-370h] BYREF
  _BYTE v13[664]; // [esp+24h] [ebp-358h] BYREF
  _BYTE v14[184]; // [esp+2BCh] [ebp-C0h] BYREF
  int v15; // [esp+374h] [ebp-8h] BYREF
  int v16; // [esp+378h] [ebp-4h] BYREF
  int v17; // [esp+3A0h] [ebp+24h]

  v16 = 0;
  v15 = 0;
  sub_65BC9B(v12);
  if ( a8 )
    *a8 = 0;
  if ( a10 )
    *a10 = 0;
  if ( (a7 & 0xFFFFF9C0) != 0 )
  {
    v17 = -2005530516;
  }
  else
  {
    v17 = sub_65D173(a1, a2, a3, a4);
    if ( v17 >= 0 )
    {
      sub_662314(v14);
      v17 = sub_673378((int)v12, 0, ArgList, 0, a6, a7 | 0x100, (int)&v16, (int)&v15);
      if ( v17 >= 0 )
      {
        sub_663D19(v14);
        if ( sub_65D7E1(v13) )
        {
          v17 = -2005529767;
        }
        else
        {
          if ( a8 )
          {
            *a8 = v16;
            v16 = 0;
          }
          if ( a10 )
          {
            *a10 = v15;
            v15 = 0;
          }
        }
      }
      else
      {
        sub_663D19(v14);
      }
    }
  }
  if ( a9 )
    sub_65D773(a9);
  if ( v15 )
  {
    (*(void (__cdecl **)(int))(*(_DWORD *)v15 + 8))(v15);
    v15 = 0;
  }
  if ( v16 )
  {
    (*(void (__cdecl **)(int))(*(_DWORD *)v16 + 8))(v16);
    v16 = 0;
  }
  sub_65BD88(v12);
  return v17;
}
