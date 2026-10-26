signed int sub_4E2FD0()
{
  signed int v0; // edi
  signed int result; // eax
  int i; // ebx
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  int k; // eax
  int v7; // ecx
  signed int j; // [esp+8h] [ebp-C4h]
  _DWORD v9[48]; // [esp+Ch] [ebp-C0h] BYREF

  memset(v9, 0xFFu, sizeof(v9));
  v0 = NumOfElements;
  result = 0;
  for ( i = 1; result < v0; v9[*(_DWORD *)(v3 + 25248)] = *(_DWORD *)(v3 + 24988) )
    v3 = dword_75AAD0[result++];
  for ( j = 0; j < v0; ++j )
  {
    v4 = -1;
    v5 = 999;
    for ( k = 0; k < 48; ++k )
    {
      v7 = v9[k];
      if ( v7 != -1 && v7 < v5 )
      {
        v5 = v9[k];
        v4 = k;
      }
    }
    if ( v5 != 999 && v4 != -1 )
    {
      sub_4DEB20((int *)&unk_6310CC + 6326 * v4, i);
      v0 = NumOfElements;
      v9[v4] = -1;
      ++i;
    }
    result = j + 1;
  }
  return result;
}
