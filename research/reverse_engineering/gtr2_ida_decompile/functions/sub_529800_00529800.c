int __thiscall sub_529800(void *this)
{
  int result; // eax
  const char *v3; // esi
  char *v4; // eax
  char *v5; // eax
  unsigned int v6; // eax
  _BYTE *v7; // edi
  _WORD *v9; // edi
  char v10; // al
  unsigned int v11; // eax
  _BYTE *v12; // edi
  _WORD *v14; // edi
  char v15; // al
  unsigned int v16; // eax
  _BYTE *v17; // edi
  char *v19; // edi
  __int16 v21; // [esp+8h] [ebp-340h] BYREF
  char v22; // [esp+Ah] [ebp-33Eh]
  char v23; // [esp+Bh] [ebp-33Dh]
  char v24; // [esp+Ch] [ebp-33Ch]
  char v25; // [esp+Dh] [ebp-33Bh]
  char v26; // [esp+Eh] [ebp-33Ah]
  char v27[11]; // [esp+10h] [ebp-338h] BYREF
  int v28; // [esp+1Bh] [ebp-32Dh]
  char v29; // [esp+1Fh] [ebp-329h]
  char Buffer[11]; // [esp+20h] [ebp-328h] BYREF
  int v31; // [esp+2Bh] [ebp-31Dh]
  char v32; // [esp+2Fh] [ebp-319h]
  char Str[133]; // [esp+30h] [ebp-318h] BYREF
  __int16 v34; // [esp+B5h] [ebp-293h]
  char v35; // [esp+B7h] [ebp-291h]
  void *v36; // [esp+B8h] [ebp-290h]
  _BYTE v37[124]; // [esp+BCh] [ebp-28Ch] BYREF
  char v38[521]; // [esp+138h] [ebp-210h] BYREF
  __int16 v39; // [esp+341h] [ebp-7h]
  char v40; // [esp+343h] [ebp-5h]

  if ( (unsigned __int8)sub_4735A0() )
  {
    if ( !dword_B71E40 )
    {
      result = dword_B71E64;
      if ( !dword_B71E64 )
      {
        *(_DWORD *)this = 0;
        *((_BYTE *)this + 5) = 1;
        return result;
      }
    }
    *(_DWORD *)this = 1;
    goto LABEL_7;
  }
  result = *(_DWORD *)this;
  if ( *(_DWORD *)this == 1 )
  {
LABEL_7:
    v3 = Path;
    memset(v38, 0, sizeof(v38));
    v39 = 0;
    v40 = 0;
    if ( !Path )
      v3 = WindowName;
    _mkdir(v3);
    strcpy(v38, v3);
    v36 = &loc_524356;
    memset(v37, 0, sizeof(v37));
    memset(&Str[8], 0, 125);
    v34 = 0;
    v35 = 0;
    sub_53A390(&unk_BE1CFD);
    v4 = sub_41D840(&byte_91CC38, &Str[128]);
    sub_630FE0(Str, v4, 127);
    Str[127] = 0;
    v5 = strstr(Str, ",");
    if ( v5 && v5 > Str )
      *v5 = 0;
    v6 = strlen(Str) + 1;
    v7 = &v37[115];
    while ( *++v7 )
      ;
    qmemcpy(v7, Str, v6);
    if ( byte_B71EE8 )
    {
      strcpy(v27, "XXXXXXXXXX");
      strcpy(Buffer, "XXXXXXXXXX");
      v28 = 0;
      v31 = 0;
      v29 = 0;
      v32 = 0;
      _strtime(v27);
      _strdate(Buffer);
      v21 = *(_WORD *)&Buffer[6];
      v22 = Buffer[0];
      v23 = Buffer[1];
      v24 = Buffer[3];
      v25 = Buffer[4];
      v26 = 0;
      v27[2] = v27[3];
      v27[3] = v27[4];
      v27[4] = 0;
      v9 = &v37[115];
      do
      {
        v10 = *((_BYTE *)v9 + 1);
        v9 = (_WORD *)((char *)v9 + 1);
      }
      while ( v10 );
      *v9 = 95;
      v11 = strlen((const char *)&v21) + 1;
      v12 = &v37[115];
      while ( *++v12 )
        ;
      qmemcpy(v12, &v21, v11);
      v14 = &v37[115];
      do
      {
        v15 = *((_BYTE *)v14 + 1);
        v14 = (_WORD *)((char *)v14 + 1);
      }
      while ( v15 );
      *v14 = 95;
      v16 = strlen(v27) + 1;
      v17 = &v37[115];
      while ( *++v17 )
        ;
      qmemcpy(v17, v27, v16);
    }
    v19 = &v37[115];
    while ( *++v19 )
      ;
    strcpy(v19, ".Vcr");
    if ( !(unsigned __int8)sub_528A30(*((int **)this + 2), (int)v19, (int)&v37[116], 1) )
      *(_DWORD *)this = 0;
    sub_527050(*((_DWORD *)this + 2));
    result = sub_520C70(*((_DWORD **)this + 2), dword_B71EAC);
    *((_BYTE *)this + 5) = 1;
    return result;
  }
  if ( result == 2 )
    *(_BYTE *)(*((_DWORD *)this + 2) + 2892960) = 1;
  *((_BYTE *)this + 5) = 1;
  return result;
}
