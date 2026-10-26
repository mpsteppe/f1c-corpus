_DWORD *__thiscall sub_50C9A0(_DWORD *this, int a2)
{
  _DWORD *result; // eax
  int v3; // ecx

  this[848] = a2;
  result = this + 127;
  v3 = 4;
  do
  {
    *result = -1;
    result += 76;
    --v3;
  }
  while ( v3 );
  return result;
}
