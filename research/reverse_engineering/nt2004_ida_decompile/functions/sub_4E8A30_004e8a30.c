int sub_4E8A30()
{
  int v0; // esi
  char *v1; // eax
  char v2; // cl
  char *v3; // eax
  char v4; // cl
  int v5; // ecx
  char *i; // eax
  int v7; // ecx
  char *j; // eax
  int result; // eax
  char *v10; // ecx
  char *v11; // eax
  char *v12; // edx
  char v13; // cl
  char *v14; // edi
  char v15; // cl
  char v16[64]; // [esp+8h] [ebp-C0h] BYREF
  char v17[128]; // [esp+48h] [ebp-80h] BYREF

  v0 = 400 * dword_7D6B54 + dword_7D6B58;
  v1 = (char *)(v0 + 260);
  do
  {
    v2 = *v1;
    byte_7D6A60[(_DWORD)v1 - 260 - v0] = *v1;
    ++v1;
  }
  while ( v2 );
  v3 = (char *)(v0 + 4);
  do
  {
    v4 = *v3;
    v17[(_DWORD)v3 - 4 - v0] = *v3;
    ++v3;
  }
  while ( v4 );
  sprintf(&byte_7D6AB0, "%s.SCN", v17);
  sprintf(byte_7D6B00, "%s.AIW", v17);
  sub_578600(&byte_7D6AB0);
  sub_578600(byte_7D6A60);
  if ( _access(byte_7D6B00, 0) != -1 )
    return sub_578600(byte_7D6B00);
  v5 = strlen(byte_7D6B00);
  if ( v5 > 0 )
  {
    for ( i = (char *)&unk_7D6AFF + v5; i >= byte_7D6B00; *i-- = 0 )
    {
      if ( *i == 92 )
        break;
    }
  }
  if ( byte_7D6AFE[strlen(byte_7D6B00) + 1] == 92 )
    byte_7D6AFE[strlen(byte_7D6B00) + 1] = 0;
  v7 = strlen(byte_7D6B00);
  if ( v7 > 0 )
  {
    for ( j = (char *)&unk_7D6AFF + v7; j >= byte_7D6B00; *j-- = 0 )
    {
      if ( *j == 92 )
        break;
    }
  }
  if ( byte_7D6AFE[strlen(byte_7D6B00) + 1] == 92 )
    byte_7D6AFE[strlen(byte_7D6B00) + 1] = 0;
  result = 0;
  v10 = &byte_7D6B00[strlen(byte_7D6B00)];
  if ( v10 > byte_7D6B00 )
  {
    while ( *v10 != 92 )
    {
      if ( --v10 <= byte_7D6B00 )
        goto LABEL_23;
    }
    ++v10;
  }
LABEL_23:
  if ( v10 )
  {
    v11 = v10;
    v12 = (char *)(v16 - v10);
    do
    {
      v13 = *v11;
      v11[(_DWORD)v12] = *v11;
      ++v11;
    }
    while ( v13 );
    *(_WORD *)&byte_7D6B00[strlen(byte_7D6B00)] = *(_WORD *)word_5FB9F4;
    strcat(byte_7D6B00, v16);
    v14 = &byte_7D6B00[strlen(byte_7D6B00) + 1];
    v15 = byte_610EAC;
    *(_DWORD *)--v14 = dword_610EA8;
    v14[4] = v15;
    _access(byte_7D6B00, 0);
    return sub_578600(byte_7D6B00);
  }
  return result;
}
