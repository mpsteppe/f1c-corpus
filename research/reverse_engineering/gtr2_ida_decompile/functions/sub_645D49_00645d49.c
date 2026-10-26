int __stdcall sub_645D49(LPCWCH lpWideCharStr, int a2, int a3, char ArgList, int a5, int a6, int *a7, int a8, int *a9)
{
  int v11[6]; // [esp+Ch] [ebp-370h] BYREF
  _BYTE v12[664]; // [esp+24h] [ebp-358h] BYREF
  _BYTE v13[184]; // [esp+2BCh] [ebp-C0h] BYREF
  int v14; // [esp+374h] [ebp-8h] BYREF
  int v15; // [esp+378h] [ebp-4h] BYREF
  int v16; // [esp+39Ch] [ebp+20h]

  v15 = 0;
  v14 = 0;
  sub_65BC9B(v11);
  if ( a7 )
    *a7 = 0;
  if ( a9 )
    *a9 = 0;
  if ( (a6 & 0xFFFFF9C0) != 0 )
  {
    v16 = -2005530516;
  }
  else
  {
    v16 = sub_65D0F5((int)v11, lpWideCharStr, 0, a2, a3);
    if ( v16 >= 0 )
    {
      sub_662314(v13);
      v16 = sub_673378((int)v11, 0, ArgList, 0, a5, a6 | 0x100, (int)&v15, (int)&v14);
      if ( v16 >= 0 )
      {
        sub_663D19(v13);
        if ( sub_65D7E1(v12) )
        {
          v16 = -2005529767;
        }
        else
        {
          if ( a7 )
          {
            *a7 = v15;
            v15 = 0;
          }
          if ( a9 )
          {
            *a9 = v14;
            v14 = 0;
          }
        }
      }
      else
      {
        sub_663D19(v13);
      }
    }
  }
  if ( a8 )
    sub_65D773(a8);
  if ( v14 )
  {
    (*(void (__cdecl **)(int))(*(_DWORD *)v14 + 8))(v14);
    v14 = 0;
  }
  if ( v15 )
  {
    (*(void (__cdecl **)(int))(*(_DWORD *)v15 + 8))(v15);
    v15 = 0;
  }
  sub_65BD88(v11);
  return v16;
}
