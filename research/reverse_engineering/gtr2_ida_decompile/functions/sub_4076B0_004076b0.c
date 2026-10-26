char __thiscall sub_4076B0(void *this, char *String1, int a3)
{
  int v3; // ebx
  _DWORD *v4; // edi
  _DWORD *v5; // esi
  int v7; // esi
  int *v8; // eax
  int v9; // [esp+0h] [ebp-540h]
  char v10; // [esp+Dh] [ebp-533h]
  char v11; // [esp+Eh] [ebp-532h]
  char v12; // [esp+Fh] [ebp-531h]
  int v13; // [esp+10h] [ebp-530h] BYREF
  float v14; // [esp+14h] [ebp-52Ch] BYREF
  int v15; // [esp+18h] [ebp-528h] BYREF
  int v16; // [esp+1Ch] [ebp-524h] BYREF
  int v17; // [esp+20h] [ebp-520h] BYREF
  int v18; // [esp+24h] [ebp-51Ch]
  float v19; // [esp+28h] [ebp-518h] BYREF
  float v20; // [esp+2Ch] [ebp-514h] BYREF
  float v21; // [esp+30h] [ebp-510h] BYREF
  _BYTE v22[4]; // [esp+34h] [ebp-50Ch] BYREF
  _BYTE v23[4]; // [esp+38h] [ebp-508h] BYREF
  _BYTE v24[4]; // [esp+3Ch] [ebp-504h] BYREF
  char v25[256]; // [esp+40h] [ebp-500h] BYREF
  char v26[253]; // [esp+140h] [ebp-400h] BYREF
  __int16 v27; // [esp+23Dh] [ebp-303h]
  char v28; // [esp+23Fh] [ebp-301h]
  char ArgList[253]; // [esp+240h] [ebp-300h] BYREF
  __int16 v30; // [esp+33Dh] [ebp-203h]
  char v31; // [esp+33Fh] [ebp-201h]
  char String[253]; // [esp+340h] [ebp-200h] BYREF
  __int16 v33; // [esp+43Dh] [ebp-103h]
  char v34; // [esp+43Fh] [ebp-101h]
  char Format[256]; // [esp+440h] [ebp-100h] BYREF

  v13 = (int)this;
  if ( !_stricmp(String1, "SPECTATOR")
    && (!byte_B71920
     || !dword_B71734
     || (unsigned __int8)sub_4735A0(&dword_B6CBA8)
     && (unsigned __int8)sub_473630(&dword_B6CBA8)
     && (unsigned __int8)sub_4735E0(&dword_B6CBA8)) )
  {
    return 0;
  }
  memset(ArgList, 0, sizeof(ArgList));
  v30 = 0;
  v31 = 0;
  memset(v26, 0, sizeof(v26));
  v27 = 0;
  v28 = 0;
  memset(String, 0, sizeof(String));
  v3 = 0;
  v33 = 0;
  v34 = 0;
  v18 = 0;
  v12 = 0;
  v10 = 0;
  v11 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0.0;
  while ( sub_5DF750(a3) != 1 )
  {
    sub_5DF240("MOTIONS", String, 0, 0, 0, 0, 0, 0, 0);
    sub_5DF240("MESHFILE", ArgList, 0, 0, 0, 0, 0, 0, 0);
    sub_5DF240("ACTORFILE", v26, 0, 0, 0, 0, 0, 0, 0);
    if ( sub_5DF240("ONGROUND", v25, 0, 0, 0, 0, 0, 0, 0) && !_stricmp(v25, "true") )
      v12 = 1;
    if ( sub_5DF240("AUTOROTATE", v25, 0, 0, 0, 0, 0, 0, 0) )
    {
      if ( !_stricmp(v25, "along") )
      {
        v18 = 1;
      }
      else if ( !_stricmp(v25, "towards") )
      {
        v18 = 2;
      }
    }
    if ( sub_5DF630(&off_6F1B20, &v15, &v16, &v17, 0) )
      v10 = 1;
    if ( sub_5DF630(&off_6F1B1C, &v14, 0, 0, 0) )
      v11 = 1;
  }
  if ( !v26[0] || !ArgList[0] )
    return 1;
  v4 = *(_DWORD **)(v13 + 8);
  v5 = (_DWORD *)*v4;
  if ( (_DWORD *)*v4 != v4 )
  {
    while ( !sub_4075C0((const char **)v5[2], String) )
    {
      v5 = (_DWORD *)*v5;
      if ( v5 == v4 )
        goto LABEL_28;
    }
    v3 = v5[2] + 16;
  }
LABEL_28:
  if ( sub_5DCC60((int)&v13, (int)String1, (char)ArgList, 0, 16) )
  {
    sub_5D8CB0(0, Format);
    if ( (unsigned __int8)sub_5612D0(
                            (int)byte_FAE910,
                            2,
                            "\\Dev\\Src\\Copperhead\\App\\Source\\AnimationLoader.cpp",
                            192) )
      sub_561210((int)byte_FAE910, Format, v9);
    return 0;
  }
  sub_5DD0A0(1, 0);
  if ( v10 )
  {
    sub_5DA610(v22, v23, v24, &v19, &v20, &v21);
    sub_5DB2B0(v15, v16, v17, v19, v20, v21);
  }
  v7 = sub_408C30(v26, v13, String1, v3);
  if ( !v7 )
    return 0;
  if ( !v10 )
  {
    if ( !v11 )
      goto LABEL_43;
    v8 = (int *)sub_4095D0(v22, v9);
    v15 = *v8;
    v16 = v8[1];
    v17 = v8[2];
  }
  if ( !v11 )
    v14 = sub_409310(v7);
  if ( v12 )
    sub_409A10(&v15, LODWORD(v14));
  else
    (*(void (__thiscall **)(int, int *, float))(*(_DWORD *)v7 + 16))(v7, &v15, COERCE_FLOAT(LODWORD(v14)));
LABEL_43:
  if ( v18 == 1 )
  {
    sub_4097C0(v7);
  }
  else if ( v18 == 2 )
  {
    sub_409640(v7);
    return 1;
  }
  return 1;
}
