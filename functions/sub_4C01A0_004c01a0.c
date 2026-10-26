int sub_4C01A0()
{
  int v0; // edi
  int result; // eax
  int i; // ebx
  int v3; // ecx
  int v4; // esi
  int v5; // edx
  int k; // eax
  int v7; // ecx
  int j; // [esp+8h] [ebp-1A4h]
  _DWORD v9[104]; // [esp+Ch] [ebp-1A0h] BYREF

  memset(v9, 0xFFu, sizeof(v9));
  v0 = dword_5C329C;
  result = 0;
  for ( i = 1; result < v0; v9[*(_DWORD *)(v3 + 18580)] = *(_DWORD *)(v3 + 18192) )
    v3 = dword_7C54F0[result++];
  for ( j = 0; j < v0; ++j )
  {
    v4 = -1;
    v5 = 999;
    for ( k = 0; k < 104; ++k )
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
      ConditionalFieldSetter((int)&unk_5F070C + 18624 * v4, i);
      v0 = dword_5C329C;
      v9[v4] = -1;
      ++i;
    }
    result = j + 1;
  }
  return result;
}
