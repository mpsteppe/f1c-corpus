int *__thiscall sub_599495(int *this)
{
  if ( !this[20] || FileCloseWithLock(this[20]) )
    return 0;
  ObjectInitializationWithBufferBoundsSetup(0, 2);
  return this;
}

