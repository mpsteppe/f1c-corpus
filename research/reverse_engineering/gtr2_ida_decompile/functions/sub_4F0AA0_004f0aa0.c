_DWORD *__thiscall sub_4F0AA0(_DWORD *this, int *a2, _DWORD *a3, float a4, char a5)
{
  _DWORD *result; // eax
  int v6; // edx
  int v7; // edx

  result = &this[15 * this[67] + 68];
  if ( *a2 )
  {
    if ( *a2 > 1 )
    {
      result[2] = *(result - 7);
      v6 = *(result - 5);
      result[3] = *(result - 6);
      result[4] = v6;
      result[5] = *(result - 4);
      v7 = *(result - 2);
      result[6] = *(result - 3);
      result[7] = v7;
      *((_BYTE *)result + 56) = a5;
    }
    result[8] = *a3;
    result[9] = a3[1];
    result[10] = a3[2];
    result[12] = 0;
    *((float *)result + 11) = sin(a4);
    *((float *)result + 13) = cos(a4);
    ++this[67];
    ++*a2;
  }
  else
  {
    this[15 * this[67] + 70] = *a3;
    result[3] = a3[1];
    result[4] = a3[2];
    result[6] = 0;
    *((_BYTE *)result + 56) = a5;
    *((float *)result + 5) = sin(a4);
    *((float *)result + 7) = cos(a4);
    ++*a2;
  }
  return result;
}
