_DWORD *__thiscall sub_524520(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // ecx

  *this = 0;
  this[16] = 0;
  result = this + 2;
  v2 = 5;
  do
  {
    *(result - 1) = 0;
    *result = 0;
    result[1] = 0;
    result += 3;
    --v2;
  }
  while ( v2 );
  return result;
}
