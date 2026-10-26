void *__thiscall sub_4B1C20(_BYTE *this, int a2, char a3, char a4, char a5, int a6, char a7)
{
  StringCopyWithBufferRealloc(a2);
  this[21] = a3;
  this[22] = a4;
  this[23] = a5;
  if ( a6 )
    StringCopyWithBufferRealloc(a6);
  if ( a7 )
    this[20] = a3;
  return ShortComputation_1b70(this);
}

