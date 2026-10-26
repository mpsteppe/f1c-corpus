int sub_495160()
{
  const CHAR *v1; // eax
  int v2; // eax
  int v3; // ebp
  int v4; // eax
  int v5; // esi
  int v6; // eax
  _BYTE *v7; // eax
  int v8; // edi
  int v9; // [esp+20h] [ebp-168h]
  _BYTE v10[28]; // [esp+24h] [ebp-164h] BYREF
  _BYTE v11[56]; // [esp+40h] [ebp-148h] BYREF
  _BYTE v12[253]; // [esp+78h] [ebp-110h] BYREF
  __int16 v13; // [esp+175h] [ebp-13h]
  char v14; // [esp+177h] [ebp-11h]
  int v15; // [esp+184h] [ebp-4h]

  if ( !(unsigned __int8)sub_54B750(&unk_BE27B0) )
    return sub_4CE020(WindowName);
  sub_617030(v11);
  v15 = 1;
  v1 = *(const CHAR **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v1 = WindowName;
  sub_615860(v1);
  v2 = sub_54B350(&unk_BE27B0);
  sub_615A50(v2);
  sub_616F90(WindowName, 0);
  sub_53DA30(v10);
  LOBYTE(v15) = 2;
  v3 = 0;
  sub_53D830(v10);
  v4 = sub_616930("Game Filter");
  sub_53D850(v10, v4);
  v5 = sub_5A6E90(v10);
  memset(v12, 0, sizeof(v12));
  v13 = 0;
  v9 = v5;
  v14 = 0;
  v6 = sub_54B310(&unk_BE27B0);
  sub_630FE0(v12, v6, 255);
  v14 = 0;
  v7 = &v12[strlen(v12)];
  if ( v7 > v12 )
  {
    while ( *v7 != 46 )
    {
      if ( --v7 <= v12 )
        goto LABEL_10;
    }
    *v7 = 0;
  }
LABEL_10:
  v8 = 0;
  if ( v5 > 0 )
  {
    do
    {
      v3 = sub_53A9E0(v10, v8);
      if ( !strcmp((const char *)(v3 + 4), v12) )
        break;
      ++v8;
    }
    while ( v8 < v9 );
  }
  sub_53A2B0((int)v12, 255, "VenueName", (char *)(v3 + 260));
  sub_4CE020(v12);
  LOBYTE(v15) = 1;
  sub_53DAA0(v10);
  v15 = -1;
  return sub_617060(v11);
}
