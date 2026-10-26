_DWORD *__thiscall sub_5205D0(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // edx
  int v3; // ecx

  result = this;
  v2 = this + 4;
  v3 = 6;
  do
  {
    *(v2 - 4) = 0;
    *(v2 - 3) = 0;
    *(v2 - 2) = 0;
    *(v2 - 1) = 0;
    *v2 = 0;
    v2[1] = 0;
    v2 += 6;
    --v3;
  }
  while ( v3 );
  result[36] = 0;
  result[37] = 0;
  result[38] = 0;
  result[39] = 0;
  result[40] = 0;
  result[41] = 0;
  return result;
}
