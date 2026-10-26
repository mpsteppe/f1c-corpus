int *__thiscall sub_615F10(int **this, int a2)
{
  _DWORD *v2; // esi
  int *result; // eax
  int v4; // ecx
  int v5; // edx

  (*this)[136] = a2;
  v2 = *this;
  result = sub_615DF0(**this);
  *v2 = result;
  if ( result && (v4 = result[1]) != 0 )
  {
    do
    {
      v5 = v4;
      v4 = *(_DWORD *)(v4 + 4);
    }
    while ( v4 );
    v2[1] = v5;
    v2[2] = result;
  }
  else
  {
    v2[1] = result;
    v2[2] = result;
  }
  return result;
}
