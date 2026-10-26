char __thiscall sub_4D1670(int *this)
{
  int v1; // edx
  int v3; // ecx
  unsigned int v4; // eax
  int v5; // ebp
  int *v6; // edi
  char result; // al
  int v8; // ecx
  int v9; // esi
  _BYTE v10[52]; // [esp+Ch] [ebp-34h] BYREF

  v1 = dword_5C329C;
  memset(v10, 0, sizeof(v10));
  v3 = 0;
  if ( dword_5C329C > 0 )
  {
    do
    {
      v4 = *(_DWORD *)(dword_7C54F0[v3] + 18596);
      if ( v4 < 0x34 )
        v10[v4] = 1;
      ++v3;
    }
    while ( v3 < v1 );
  }
  v5 = 0;
  v6 = this + 160;
  do
  {
    result = v10[v5];
    v8 = *(v6 - 52);
    v9 = *v6;
    if ( result )
    {
      if ( v8 )
        result = FlagFieldBitManipulation(0, 0, 1, 0);
      if ( v9 )
        result = FlagFieldBitManipulation(1, 1, 1, 0);
    }
    else
    {
      if ( v8 )
        result = FlagFieldBitManipulation(1, 1, 1, 0);
      if ( v9 )
        result = FlagFieldBitManipulation(0, 0, 1, 0);
    }
    ++v5;
    ++v6;
  }
  while ( v5 < 52 );
  return result;
}

