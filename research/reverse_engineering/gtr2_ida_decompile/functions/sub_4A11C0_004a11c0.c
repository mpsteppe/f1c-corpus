int sub_4A11C0()
{
  int v0; // eax
  CHAR *v1; // ecx
  char *v2; // esi
  CHAR v3; // dl
  int v4; // kr00_4
  char *i; // ecx
  const void *v6; // edx
  unsigned int v7; // eax
  char *v8; // edi
  char *v10; // edi
  char v13; // [esp+3h] [ebp-101h] BYREF
  char v14[256]; // [esp+4h] [ebp-100h] BYREF

  v0 = sub_538790(&unk_BE1CDC);
  if ( v0 )
  {
    v1 = *(CHAR **)(v0 + 8);
    if ( !v1 )
      v1 = (CHAR *)WindowName;
    v2 = (char *)(v14 - v1);
    do
    {
      v3 = *v1;
      v1[(_DWORD)v2] = *v1;
      ++v1;
    }
    while ( v3 );
    v4 = strlen(v14);
    if ( v4 > 0 )
    {
      for ( i = &v14[v4 - 1]; i >= v14; *i-- = 0 )
      {
        if ( *i == 92 )
          break;
      }
    }
    v6 = (const void *)(v0 + 1724);
    v7 = strlen((const char *)(v0 + 1724)) + 1;
    v8 = &v13;
    while ( *++v8 )
      ;
    qmemcpy(v8, v6, v7);
    v10 = &v13;
    while ( *++v10 )
      ;
    strcpy(v10, "Icon.tga");
    sub_615860(v14);
  }
  return 0;
}
