_DWORD *__thiscall StructZeroInit_6bc0(_DWORD *this)
{
  _DWORD *result; // eax
  _DWORD *v2; // edx
  int v3; // ecx

  result = this;
  *this = 0;
  this[16] = 0;
  v2 = this + 2;
  v3 = 5;
  do
  {
    *(v2 - 1) = 0;
    *v2 = 0;
    v2[1] = 0;
    v2 += 3;
    --v3;
  }
  while ( v3 );
  return result;
}
