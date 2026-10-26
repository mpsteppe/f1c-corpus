int __thiscall sub_4BB810(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int result; // eax
  int v8; // [esp-Ch] [ebp-14h]
  int v9; // [esp-8h] [ebp-10h]

  StructResetReinitializer();
  this[12] = 0;
  if ( dword_7C56A4 == 7 )
  {
    this[3] = 2;
    this[24] = 0;
  }
  else
  {
    this[3] = 0;
    this[24] = 1;
  }
  v2 = dword_8ACF8C;
  if ( dword_8ACF8C >= 128 )
    v2 = 128;
  this[34] = v2;
  v3 = OperatorNewNhMallocWrapper(4 * v2);
  v9 = 4 * this[34];
  this[35] = v3;
  v4 = OperatorNewNhMallocWrapper(v9);
  v8 = this[34];
  this[36] = v4;
  v5 = OperatorNewNhMallocWrapper(v8);
  v6 = this[34];
  this[37] = v5;
  result = 0;
  this[38] = 0;
  if ( v6 > 0 )
  {
    do
    {
      *(_DWORD *)(this[35] + 4 * result) = -1082130432;
      *(_DWORD *)(this[36] + 4 * result) = -1082130432;
      *(_BYTE *)(result + this[37]) = 0;
      ++result;
    }
    while ( result < this[34] );
  }
  return result;
}

