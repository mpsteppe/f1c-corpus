int __thiscall sub_49FB80(int this, int a2)
{
  CHAR *v3; // eax
  int v4; // edi
  char *v5; // edx
  CHAR v6; // cl
  char *v7; // eax
  int v8; // esi
  int v9; // edx
  char v10; // cl
  char String[77]; // [esp+8h] [ebp-50h] BYREF
  __int16 v13; // [esp+55h] [ebp-3h]
  char v14; // [esp+57h] [ebp-1h]

  String[0] = byte_629120;
  memset(&String[1], 0, 0x4Cu);
  v13 = 0;
  v14 = 0;
  v3 = sub_49FB30((_DWORD *)this);
  if ( !v3 )
    return 0;
  v4 = this + 269;
  *(_BYTE *)(this + 269) = 0;
  v5 = (char *)(String - v3);
  do
  {
    v6 = *v3;
    v3[(_DWORD)v5] = *v3;
    ++v3;
  }
  while ( v6 );
  v7 = strtok(String, word_6014F0);
  v8 = a2;
  if ( a2 > 0 )
  {
    do
    {
      v7 = strtok(0, word_6014F0);
      --v8;
    }
    while ( v8 );
  }
  if ( !v7 )
    return 0;
  v9 = v4 - (_DWORD)v7;
  do
  {
    v10 = *v7;
    v7[v9] = *v7;
    ++v7;
  }
  while ( v10 );
  return v4;
}
