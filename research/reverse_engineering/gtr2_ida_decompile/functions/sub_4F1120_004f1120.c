float *__thiscall sub_4F1120(float *this, float a2)
{
  int v2; // edx
  float *result; // eax

  v2 = 2;
  result = this + 8;
  do
  {
    if ( v2 != 17 && v2 != 18 && *((_DWORD *)result - 1) != 1203982208 )
      *(result - 1) = a2 + *(result - 1);
    if ( v2 != 16 && v2 != 17 && *(_DWORD *)result != 1203982208 )
      *result = a2 + *result;
    if ( v2 != 15 && v2 != 16 && *((_DWORD *)result + 1) != 1203982208 )
      result[1] = a2 + result[1];
    if ( v2 != 14 && v2 != 15 && *((_DWORD *)result + 2) != 1203982208 )
      result[2] = a2 + result[2];
    if ( v2 != 13 && v2 != 14 && *((_DWORD *)result + 3) != 1203982208 )
      result[3] = a2 + result[3];
    if ( v2 != 12 && v2 != 13 && *((_DWORD *)result + 4) != 1203982208 )
      result[4] = a2 + result[4];
    if ( v2 != 11 && v2 != 12 && *((_DWORD *)result + 5) != 1203982208 )
      result[5] = a2 + result[5];
    v2 += 7;
    result += 7;
  }
  while ( v2 - 2 < 35 );
  this[47] = a2 + this[47];
  this[48] = a2 + this[48];
  return result;
}
