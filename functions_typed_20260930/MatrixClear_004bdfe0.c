_DWORD *__thiscall sub_4BDFE0(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // esi
  int v3; // edx

  result = this + 1;
  v2 = 8;
  do
  {
    v3 = 8;
    do
    {
      *result = 0;
      result += 9;
      --v3;
    }
    while ( v3 );
    --v2;
  }
  while ( v2 );
  this[577] = 0;
  return result;
}

