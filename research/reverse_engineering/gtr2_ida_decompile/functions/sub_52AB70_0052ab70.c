int __cdecl sub_52AB70(const char *a1, int a2, int a3)
{
  const char *v3; // ecx
  const char *v4; // ebx
  unsigned int v5; // esi
  int v6; // eax
  _BYTE v8[1024]; // [esp+Ch] [ebp-400h] BYREF

  v4 = v3;
  v5 = 0;
  v6 = strlen(v3);
  if ( v6 > 0 )
  {
    if ( !--dword_1739D2F )
      dword_1739D2F = 658;
    while ( v5 < 0x400 )
    {
      if ( v8[v5 + v4 - v8] == 92 )
        return sub_630FE0(a1, a2, a3);
      if ( (int)++v5 >= v6 )
        return _mkdir(a1);
    }
  }
  return _mkdir(a1);
}
