_DWORD *__thiscall sub_4D0410(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v3; // esi
  _BYTE *v4; // edi
  int v5; // edx
  int v6; // ecx
  bool v7; // cl
  int v8; // edx
  bool v9; // cl
  int v10; // ecx
  int v11; // esi
  bool v12; // dl
  int v13; // edx

  result = this;
  this[1] &= 0xFFFC0000;
  v3 = 0;
  v4 = (_BYTE *)(a2 + 404);
  do
  {
    v5 = *v4 == 0;
    v4 += 304;
    v6 = (v5 << v3++) | result[1];
    result[1] = v6;
  }
  while ( v3 <= 3 );
  v7 = *(_DWORD *)(a2 + 1556) && !*(_BYTE *)(a2 + 1620);
  v8 = (16 * v7) | result[1];
  result[1] = v8;
  v9 = *(_DWORD *)(a2 + 1624) && !*(_BYTE *)(a2 + 1688);
  result[1] = v8 | (32 * v9);
  v10 = 6;
  v11 = a2 + 1692;
  do
  {
    v12 = *(_DWORD *)v11 && !*(_BYTE *)(v11 + 64);
    v13 = v12 << v10;
    v11 += 68;
    ++v10;
    result[1] |= v13;
  }
  while ( v10 < 18 );
  return result;
}
