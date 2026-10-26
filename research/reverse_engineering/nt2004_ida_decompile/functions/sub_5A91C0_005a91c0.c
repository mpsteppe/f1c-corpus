int __stdcall sub_5A91C0(const char *a1)
{
  char v1; // al
  char *v2; // edi
  int v3; // edi
  char Str[256]; // [esp+0h] [ebp-100h] BYREF

  strcpy(Str, a1);
  _strupr(Str);
  if ( !strstr(Str, aBik_1) )
  {
    v1 = aBik_1[4];
    v2 = &Str[strlen(Str)];
    *(_DWORD *)v2 = *(_DWORD *)aBik_1;
    v2[4] = v1;
  }
  v3 = dword_7E5D58;
  if ( !dword_7E5D58 )
    return 0;
  while ( strcmp((const char *)(v3 + 12), Str) )
  {
    v3 = *(_DWORD *)(v3 + 280);
    if ( !v3 )
      return 0;
  }
  return v3;
}
