int __thiscall sub_4F2AE0(_DWORD *this)
{
  int v1; // edx
  int v2; // esi
  int v3; // esi
  int v4; // edi
  int v5; // esi

  v1 = this[26];
  v2 = this[24];
  this[26] = v1 + 1;
  if ( v1 + 1 >= v2 )
    this[26] = 0;
  v3 = this[25];
  v4 = *(_DWORD *)(v3 + 108 * v1 + 4);
  v5 = 108 * v1 + v3;
  if ( v4 < 0 )
  {
    *(_DWORD *)(v5 + 4) = this[27];
    *(_DWORD *)(this[28] + 4 * this[27]++) = 108 * v1 + this[25];
    sub_5B0910(v1);
  }
  return v5;
}
