_DWORD *__thiscall sub_538020(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // edx
  int v3; // ecx

  result = this;
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  v2 = this + 8;
  v3 = 3;
  do
  {
    *(v2 - 3) = 0;
    *v2 = 0;
    v2[3] = 0;
    v2[6] = 0;
    v2[9] = 0;
    v2[12] = 0;
    v2[15] = 0;
    v2[18] = 0;
    v2[30] = 0;
    v2[33] = 0;
    v2[36] = 0;
    v2[39] = 0;
    v2[21] = 0;
    v2[24] = 0;
    v2[27] = 0;
    ++v2;
    --v3;
  }
  while ( v3 );
  return result;
}
