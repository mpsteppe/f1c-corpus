_DWORD *__thiscall sub_4412F0(_DWORD *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // edx
  _DWORD *result; // eax
  int v5; // edx
  const void *v6; // esi
  void *v7; // edi

  v1 = this[1818];
  this[1815] = this[1817];
  v2 = this[1936];
  this[1816] = v1;
  v3 = this[1937];
  this[1934] = v2;
  this[1935] = v3;
  result = this + 206;
  v5 = 4;
  do
  {
    *result = result[2];
    result[1] = result[3];
    result[4] = result[6];
    result[5] = result[7];
    v6 = result + 22;
    v7 = result + 14;
    result += 281;
    --v5;
    qmemcpy(v7, v6, 0x20u);
  }
  while ( v5 );
  return result;
}
