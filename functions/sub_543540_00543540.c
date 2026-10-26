_DWORD *__thiscall sub_543540(_DWORD *this, int *a2, int *a3, int *a4, _DWORD *a5)
{
  int v5; // edx
  int v6; // edx
  _DWORD *result; // eax
  int v8; // edx
  int v9; // ecx

  if ( *a2 < 0 )
  {
    *a4 += *a2;
    *a2 = 0;
  }
  v5 = this[7];
  if ( *a2 + *a4 > v5 )
    *a4 = v5 - *a2;
  v6 = *a4;
  if ( *a4 >= this[7] )
    v6 = this[7];
  *a4 = v6;
  result = a5;
  if ( *a3 < 0 )
  {
    *a5 += *a3;
    *a3 = 0;
  }
  v8 = this[8];
  if ( *a3 + *a5 > v8 )
    *a5 = v8 - *a3;
  v9 = this[8];
  if ( *a5 >= v9 )
    *a5 = v9;
  else
    *a5 = *a5;
  return result;
}
