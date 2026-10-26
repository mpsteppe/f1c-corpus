int __thiscall sub_5AF100(int this, char *Str)
{
  char *v3; // eax
  char *v4; // edx
  char v5; // cl
  int v6; // edi
  int v7; // edx
  const char *i; // ebp
  int v10; // esi
  int v12; // [esp+14h] [ebp-104h]
  char String[256]; // [esp+18h] [ebp-100h] BYREF

  strcpy(String, Str);
  if ( strrchr(Str, 92) )
  {
    v3 = strrchr(Str, 92) + 1;
    v4 = (char *)(String - v3);
    do
    {
      v5 = *v3;
      v3[(_DWORD)v4] = *v3;
      ++v3;
    }
    while ( v5 );
  }
  _strupr(String);
  v6 = 0;
  v12 = *(_DWORD *)(this + 280);
  if ( v12 <= 0 )
    return -2;
  v7 = *(_DWORD *)(this + 296);
  for ( i = (const char *)(v7 + 20); strcmp(String, i); i += 256 )
  {
    ++v6;
    v7 += 256;
    if ( v6 >= v12 )
      return -2;
  }
  v10 = *(_DWORD *)(this + 284);
  *(_DWORD *)(this + 292) = v6;
  fseek(*(FILE **)(this + 16), v10 + *(_DWORD *)(v7 + 4), 0);
  return 0;
}
