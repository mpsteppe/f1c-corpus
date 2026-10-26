_DWORD *__thiscall sub_444560(_DWORD *this)
{
  int v1; // edx
  int v2; // eax
  int v3; // edx
  _DWORD *result; // eax
  int v5; // edx
  const void *v6; // esi
  void *v7; // edi

  v1 = this[1987];
  this[1984] = this[1986];
  v2 = this[2105];
  this[1985] = v1;
  v3 = this[2106];
  this[2103] = v2;
  this[2104] = v3;
  result = this + 210;
  v5 = 4;
  do
  {
    *result = result[2];
    result[1] = result[3];
    result[4] = result[6];
    result[5] = result[7];
    v6 = result + 22;
    v7 = result + 14;
    result += 314;
    --v5;
    qmemcpy(v7, v6, 0x20u);
  }
  while ( v5 );
  return result;
}
