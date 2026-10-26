int __thiscall sub_489970(int this, int a2)
{
  char *v3; // eax
  int v4; // edi
  _BYTE *v5; // edx
  char v6; // cl
  char *v7; // eax
  int v8; // esi
  int v9; // edx
  char v10; // cl
  _BYTE v12[77]; // [esp+8h] [ebp-50h] BYREF
  __int16 v13; // [esp+55h] [ebp-3h]
  char v14; // [esp+57h] [ebp-1h]

  v12[0] = byte_5EA438[0];
  memset(&v12[1], 0, 0x4Cu);
  v13 = 0;
  v14 = 0;
  v3 = UIScreenTextAccessor((_DWORD *)this);
  if ( !v3 )
    return 0;
  v4 = this + 225;
  *(_BYTE *)(this + 225) = 0;
  v5 = (_BYTE *)(v12 - v3);
  do
  {
    v6 = *v3;
    v3[(_DWORD)v5] = *v3;
    ++v3;
  }
  while ( v6 );
  v7 = (char *)sub_5897CA(v12, &word_5C692C);
  v8 = a2;
  if ( a2 > 0 )
  {
    do
    {
      v7 = (char *)sub_5897CA(0, &word_5C692C);
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
