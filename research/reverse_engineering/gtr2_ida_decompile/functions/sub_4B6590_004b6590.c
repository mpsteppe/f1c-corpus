int __thiscall sub_4B6590(_DWORD *this, const char *a2)
{
  unsigned int v3; // eax
  const char *v4; // esi
  char *v5; // edi
  char *v7; // edi
  int v9; // eax
  char *i; // eax
  unsigned int v11; // eax
  char *v12; // edi
  _DWORD *v14; // edi
  int v15; // esi
  _DWORD *v16; // [esp+8h] [ebp-124h] BYREF
  char FileName[15]; // [esp+Ch] [ebp-120h] BYREF
  char v18; // [esp+1Bh] [ebp-111h] BYREF
  char v19[15]; // [esp+1Ch] [ebp-110h] BYREF
  char v20; // [esp+2Bh] [ebp-101h] BYREF
  _BYTE v21[256]; // [esp+2Ch] [ebp-100h] BYREF

  v16 = this;
  if ( !a2 )
    return sub_4E37B0(0);
  v3 = strlen(a2);
  v4 = &a2[v3];
  if ( &a2[v3] > a2 )
  {
    while ( *v4 != 92 )
    {
      if ( --v4 <= a2 )
        goto LABEL_8;
    }
    ++v4;
  }
LABEL_8:
  sub_630FE0(FileName, v4, 3);
  FileName[3] = 0;
  sub_630FE0(v19, v4, 3);
  v19[3] = 0;
  v5 = (char *)&v16 + 3;
  while ( *++v5 )
    ;
  strcpy(v5, "Info.jpg");
  v7 = &v18;
  while ( *++v7 )
    ;
  strcpy(v7, "hs.txt");
  sub_630FE0(byte_B6DB18, a2, 255);
  byte_B6DC17[0] = 0;
  v9 = strlen(byte_B6DB18);
  if ( v9 > 0 )
  {
    for ( i = (char *)&unk_B6DB17 + v9; i >= byte_B6DB18; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  sub_630FE0(v21, byte_B6DB18, 255);
  v21[255] = 0;
  strcat(byte_B6DB18, FileName);
  v11 = strlen(v19) + 1;
  v12 = &v20;
  while ( *++v12 )
    ;
  qmemcpy(v12, v19, v11);
  sub_630FE0(&unk_B6D6B8, byte_B6DB18, 255);
  v14 = v16;
  byte_B6D7B7 = 0;
  v15 = sub_4E0080(v16[12], byte_B6DB18, 0, 0, 1, 0, 0, 0, 0);
  sub_4E37B0(v15);
  if ( v15 )
    sub_615860(a2);
  else
    sub_615860(WindowName);
  return sub_4B6470(v14, FileName);
}
