int *__thiscall sub_59A44C(int *this)
{
  if ( !this[20] || FileCloseWithLock(this[20]) )
    return 0;
  ObjectInitWithBufferDataPointerAssignment(0, 2);
  return this;
}

