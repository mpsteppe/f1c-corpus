_DWORD *__thiscall sub_431920(_DWORD *this)
{
  _DWORD *v1; // eax
  int v2; // esi
  int v3; // edx
  _DWORD *result; // eax
  int v5; // ecx

  v1 = this + 50;
  v2 = 4;
  do
  {
    v3 = 11;
    do
    {
      *v1 = *(v1 - 1);
      v1 += 16;
      --v3;
    }
    while ( v3 );
    --v2;
  }
  while ( v2 );
  result = this + 754;
  v5 = 55;
  do
  {
    *result = *(result - 1);
    result += 16;
    --v5;
  }
  while ( v5 );
  return result;
}
