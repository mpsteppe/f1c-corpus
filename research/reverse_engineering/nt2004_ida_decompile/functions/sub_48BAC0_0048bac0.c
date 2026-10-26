int __thiscall sub_48BAC0(_DWORD *this)
{
  CHAR *v1; // eax
  char *v3; // eax
  int v4; // esi
  const char *v5; // ecx
  bool v6; // zf
  int v7; // ecx
  char *v8; // eax
  char *v9; // eax
  const char *v10; // edi
  int v11; // eax
  char String2[253]; // [esp+8h] [ebp-100h] BYREF
  __int16 v14; // [esp+105h] [ebp-3h]
  char v15; // [esp+107h] [ebp-1h]

  v1 = dword_7665D8;
  if ( !dword_7665D8 )
    v1 = &byte_629120;
  sub_578600(v1);
  v3 = dword_7665D8;
  if ( !dword_7665D8 )
    v3 = &byte_629120;
  sub_4E7690(v3);
  v4 = sub_4E7760(&unk_7D6A50);
  if ( v4 )
  {
    String2[0] = byte_629120;
    memset(&String2[1], 0, 0xFCu);
    v5 = *(const char **)v4;
    v6 = *(_DWORD *)v4 == 0;
    v14 = 0;
    v15 = 0;
    if ( v6 )
      v5 = &byte_629120;
    strcpy(String2, v5);
    v7 = strlen(String2);
    if ( v7 > 0 )
    {
      v8 = &String2[v7];
      while ( v8 >= String2 )
      {
        if ( *v8 == 92 )
          break;
        *v8 = 0;
        if ( v8 > String2 )
          --v8;
      }
    }
    strcat(String2, (const char *)(v4 + 1164));
    v9 = &String2[strlen(String2)];
    if ( v9 > String2 )
    {
      while ( *v9 != 46 )
      {
        if ( --v9 <= String2 )
          goto LABEL_19;
      }
      *v9 = 0;
    }
LABEL_19:
    v10 = (const char *)this[42];
    if ( !v10 )
      v10 = &byte_629120;
    strcat(String2, v10);
    v11 = sub_4AD970(String2, 0, 0, 1);
    if ( v11 || (v11 = sub_4AD970(off_600F2C, 0, 0, 1)) != 0 )
      sub_4B0AC0(v11);
  }
  return 0;
}
