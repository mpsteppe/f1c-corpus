void *__thiscall sub_4B1D90(_DWORD *this, int a2, int a3, int a4, int a5, int a6, char a7)
{
  StringCopyWithBufferRealloc(a2);
  this[8] = a5;
  this[6] = a3;
  this[7] = a4;
  if ( a6 )
    StringCopyWithBufferRealloc(a6);
  if ( a7 )
    this[5] = a3;
  return ShortComputation_1b70(this);
}

