_DWORD *__thiscall sub_4317D0(_DWORD *this)
{
  _DWORD *v1; // edx
  _DWORD *result; // eax
  int v3; // ecx

  this[1935] = 1133679739;
  this[1936] = 1133679739;
  v1 = this + 1945;
  result = this + 1941;
  v3 = 4;
  do
  {
    *(result - 4) = 1133679739;
    *result = 0;
    *v1 = 1133679739;
    v1[1] = 1133679739;
    v1[2] = 1133679739;
    result[16] = 1125842944;
    ++result;
    v1 += 3;
    --v3;
  }
  while ( v3 );
  return result;
}
