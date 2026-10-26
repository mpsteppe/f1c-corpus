int __thiscall sub_4DBCD0(int this, const char *a2)
{
  int v2; // esi
  const char *v3; // edi
  int v4; // esi
  int v6; // ebx
  const char *v7; // eax
  const char *v8; // edx
  unsigned int v9; // eax
  char *v10; // edi
  const char *v12; // edx
  unsigned int v13; // eax
  char *v14; // edi
  _WORD *v16; // edi
  char v17; // al
  int v19; // [esp+14h] [ebp-104h] BYREF
  _BYTE v20[256]; // [esp+18h] [ebp-100h] BYREF

  v2 = *(_DWORD *)(this + 760);
  memset(v20, 0, sizeof(v20));
  v3 = a2;
  v4 = 4 * v2;
  v19 = v4;
  if ( !a2 || !strlen(a2) )
    return -1;
  if ( v4 > 0 )
  {
    v6 = v4;
    while ( 1 )
    {
      v7 = "*";
      if ( v4 > 4 )
        v7 = CommandLine;
      v8 = v7;
      v9 = strlen(v7) + 1;
      v10 = (char *)&v19 + 3;
      while ( *++v10 )
        ;
      qmemcpy(v10, v8, v9);
      if ( !--v6 )
        break;
      v4 = v19;
    }
    v3 = a2;
  }
  v12 = v3;
  v13 = strlen(v3) + 1;
  v14 = (char *)&v19 + 3;
  while ( *++v14 )
    ;
  qmemcpy(v14, v12, v13);
  v16 = (_WORD *)((char *)&v19 + 3);
  do
  {
    v17 = *((_BYTE *)v16 + 1);
    v16 = (_WORD *)((char *)v16 + 1);
  }
  while ( v17 );
  *v16 = 10;
  if ( *(_BYTE *)(this + 766) )
  {
    if ( *(_DWORD *)(this + 188) )
      (*(void (**)(int, const char *, ...))(*(_DWORD *)(this + 184) + 32))(this + 184, "%s", v20);
  }
  return 0;
}
