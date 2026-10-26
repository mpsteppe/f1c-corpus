char *__stdcall sub_496D40(char *Str, int a2)
{
  unsigned int v2; // kr00_4
  __int32 v3; // esi
  int v4; // eax
  const char *v5; // eax
  char v6; // cl
  const char *v7; // ecx
  char *v8; // esi
  char *result; // eax
  char *v10[5]; // [esp+0h] [ebp-114h] BYREF
  _BYTE v11[256]; // [esp+14h] [ebp-100h] BYREF

  v4 = sub_539FE0(&unk_BE1CE0);
  sub_630FE0(v11, v4, 255);
  v11[255] = 0;
  v5 = v11;
  if ( v11[0] == 32 )
  {
    do
      v6 = *++v5;
    while ( v6 == 32 );
  }
  v7 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v7 = WindowName;
  v8 = Str;
  sub_41D810(Str, a2 - 1, "%s%s.tga", v7, v5);
  for ( result = strchr(Str, 58); result; result = strrchr(v8, 58) )
  {
    *result = 0;
    v10[2] = result + 1;
    v10[1] = v8;
    v10[0] = v8;
    v2 = __readeflags();
    v3 = loc_662122 + dword_16C6C84;
    __writeeflags(v2);
    v8 = (char *)_InterlockedExchange((volatile __int32 *)v10, v3);
    sub_41D810(v8, a2 - 1, v10[0]);
  }
  return result;
}
