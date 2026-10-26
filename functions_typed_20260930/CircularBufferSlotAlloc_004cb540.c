int __thiscall sub_4CB540(_DWORD *this)
{
  int v1; // edx
  int v2; // esi
  int v3; // esi
  int v4; // edi
  int v5; // esi

  v1 = this[24];
  v2 = this[22];
  this[24] = v1 + 1;
  if ( v1 + 1 >= v2 )
    this[24] = 0;
  v3 = this[23];
  v4 = *(_DWORD *)(v3 + 108 * v1 + 4);
  v5 = 108 * v1 + v3;
  if ( v4 < 0 )
  {
    *(_DWORD *)(v5 + 4) = this[25];
    *(_DWORD *)(this[26] + 4 * this[25]++) = 108 * v1 + this[23];
    sub_558A30(v1);
  }
  return v5;
}

