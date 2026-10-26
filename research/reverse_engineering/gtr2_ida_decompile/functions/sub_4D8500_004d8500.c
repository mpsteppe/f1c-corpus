int __thiscall sub_4D8500(int this)
{
  int v2; // eax
  _DWORD *v3; // ebx
  const CHAR *v4; // eax
  const CHAR *v5; // eax
  const CHAR *v6; // eax
  CHAR *v7; // eax
  int v8; // edx
  CHAR v9; // cl
  const char *v10; // eax
  const char *v11; // edx
  unsigned int v12; // eax
  char *v13; // edi
  int v15; // eax
  int v16; // eax
  const CHAR *v17; // eax
  const char *v18; // eax
  _BYTE v20[61]; // [esp+2Ch] [ebp-340h] BYREF
  __int16 v21; // [esp+69h] [ebp-303h]
  char v22; // [esp+6Bh] [ebp-301h] BYREF
  _BYTE v23[768]; // [esp+6Ch] [ebp-300h] BYREF

  v2 = *(_DWORD *)(this + 268);
  v3 = (_DWORD *)(this + 268);
  if ( v2 )
  {
    sub_5F5280(v2);
    *v3 = 0;
    sub_4B77F0((int *)(this + 84));
    sub_615860(WindowName);
  }
  v4 = *(const CHAR **)(this + 160);
  if ( !v4 )
    v4 = WindowName;
  *(_DWORD *)(this + 296) = sub_5F5190(dword_FB1CE0, v3, v4, 0, 0);
  v5 = *(const CHAR **)(this + 160);
  if ( !v5 )
    v5 = WindowName;
  sub_615860(v5);
  if ( !*(_DWORD *)(this + 296) )
    goto LABEL_31;
  v6 = *(const CHAR **)(this + 160);
  if ( !v6 )
    v6 = WindowName;
  sub_615860(v6);
  v7 = (CHAR *)dword_91CA98;
  if ( !dword_91CA98 )
    v7 = (CHAR *)WindowName;
  v8 = v23 - v7;
  do
  {
    v9 = *v7;
    v7[v8] = *v7;
    ++v7;
  }
  while ( v9 );
  v10 = *(const char **)(this + 160);
  if ( !v10 )
    v10 = WindowName;
  v11 = v10;
  v12 = strlen(v10) + 1;
  v13 = &v22;
  while ( *++v13 )
    ;
  qmemcpy(v13, v11, v12);
  v15 = sub_5F5190(dword_FB1CE0, v3, v23, 0, 0);
  *(_DWORD *)(this + 296) = v15;
  if ( !v15 )
  {
LABEL_31:
    if ( (unsigned __int8)sub_4D3C00() )
    {
      if ( *(int *)(this + 96) > 0 )
      {
        v16 = *(_DWORD *)(this + 84);
        if ( v16 )
        {
          if ( *(_DWORD *)v16 )
          {
            *(_BYTE *)(*(_DWORD *)v16 + 12) = 1;
            sub_615860("binkASurf");
            sub_4E3350(550, 550);
          }
        }
      }
    }
  }
  memset(v20, 0, sizeof(v20));
  v21 = 0;
  v22 = 0;
  v17 = *(const CHAR **)(this + 168);
  if ( !v17 )
    v17 = WindowName;
  sub_630FE0(v20, v17, 63);
  v22 = 0;
  v18 = (const char *)sub_6331DF(v20, CommandLine);
  if ( v18 )
    *(float *)(this + 292) = atof(v18);
  return 0;
}
