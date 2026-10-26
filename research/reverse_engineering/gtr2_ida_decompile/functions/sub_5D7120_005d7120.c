_DWORD *__thiscall sub_5D7120(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  _DWORD *v3; // edx
  int v4; // ecx

  result = this + 2;
  v3 = (_DWORD *)(a2 + 32);
  v4 = 4;
  do
  {
    *(v3 - 8) = *(result - 1);
    *(v3 - 4) = *result;
    *v3 = result[1];
    v3[4] = result[2];
    result += 4;
    ++v3;
    --v4;
  }
  while ( v4 );
  return result;
}
