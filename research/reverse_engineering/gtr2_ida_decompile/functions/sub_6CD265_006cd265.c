int __thiscall sub_6CD265(_DWORD *this, int a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // edx
  int result; // eax
  int v6; // esi
  int v7; // eax
  int v8; // edx

  v3 = this[1];
  v4 = *(_DWORD **)(*(_DWORD *)(v3 + 20) + 4 * a3);
  result = *(_DWORD *)(*(_DWORD *)(v3 + 16) + 4 * v4[1]);
  v6 = a2;
  if ( (*(_BYTE *)(result + 4) & 0x20) == 0 && v4[23] )
  {
    v7 = this[9];
    if ( v7 )
    {
      *(_DWORD *)(v7 + 4 * (*(_DWORD *)(this[7] + 4 * a2) + *(_DWORD *)(this[8] + 4 * a2))) = a3;
      v6 = a2;
    }
    result = this[7] + 4 * v6;
    ++*(_DWORD *)result;
  }
  v8 = v4[5];
  if ( v8 != -1 )
    return sub_6CD1F0(this, v6, v8);
  return result;
}
