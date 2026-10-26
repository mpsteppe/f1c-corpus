int __thiscall sub_566BD0(int *this, int a2, int a3)
{
  if ( this[4] )
    return BufferFillWithTimeout(*this, a2, a3);
  else
    return FileReadWrapperWithLock(a2, 1, a3, *this);
}

