void *__thiscall sub_4B1F50(_WORD *this, int a2, __int16 a3, __int16 a4, __int16 a5, int a6, char a7)
{
  StringCopyWithBufferRealloc(a2);
  this[11] = a3;
  this[12] = a4;
  this[13] = a5;
  if ( a6 )
    StringCopyWithBufferRealloc(a6);
  if ( a7 )
    this[10] = a3;
  return ShortComputation_1b70(this);
}

