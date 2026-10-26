char __thiscall sub_4692B0(_DWORD *this)
{
  int v2; // eax
  const char *v3; // edx
  const char *v4; // eax
  int v5; // eax
  char v6; // cl
  int v7; // ecx
  char *v8; // eax
  int v9; // eax
  char v10; // cl
  char v12[253]; // [esp+10h] [ebp-200h] BYREF
  __int16 v13; // [esp+10Dh] [ebp-103h]
  char v14; // [esp+10Fh] [ebp-101h]
  _BYTE v15[256]; // [esp+110h] [ebp-100h] BYREF

  v2 = sub_48D360();
  v3 = (const char *)sub_4693E0(v2);
  v12[0] = byte_5EA438[0];
  memset(&v12[1], 0, 0xFCu);
  v13 = 0;
  v14 = 0;
  v4 = (const char *)dword_5EC440;
  if ( !dword_5EC440 )
    v4 = byte_5EA438;
  sub_58815F(v15, "%s%s\\", v4, v3);
  v5 = 0;
  do
  {
    v6 = v15[v5];
    v12[v5++] = v6;
  }
  while ( v6 );
  v7 = strlen(v12);
  if ( v7 > 0 )
  {
    v8 = &v12[v7];
    while ( v8 >= v12 )
    {
      if ( *v8 == 92 )
        break;
      *v8 = 0;
      if ( v8 > v12 )
        --v8;
    }
  }
  if ( sub_423A00(byte_5EC4C0, aProfileiconBmp, byte_5EC4CC) )
  {
    v9 = 0;
    do
    {
      v10 = aProfileiconBmp[v9];
      byte_5EC4CC[v9++] = v10;
    }
    while ( v10 );
  }
  strcat(v12, byte_5EC4CC);
  sub_497C40(v12);
  sub_468EE0(this, 0);
  return 0;
}
