_DWORD *__thiscall sub_536160(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // esi
  unsigned int v3; // ecx
  unsigned int v4; // edx
  int v5; // ecx
  int v6; // ecx
  unsigned int v7; // edi

  result = this;
  v2 = this[7];
  v3 = this[4];
  v4 = *(_DWORD *)(v2 + 20);
  if ( v4 > v3 )
    v4 = v3;
  if ( v4 )
  {
    qmemcpy((void *)result[3], *(const void **)(v2 + 16), v4);
    v5 = result[7];
    result[3] += v4;
    *(_DWORD *)(v5 + 16) += v4;
    v6 = result[7];
    v7 = result[4] - v4;
    result[5] += v4;
    result[4] = v7;
    *(_DWORD *)(v6 + 20) -= v4;
    result = (_DWORD *)result[7];
    if ( !result[5] )
      result[4] = result[2];
  }
  return result;
}
