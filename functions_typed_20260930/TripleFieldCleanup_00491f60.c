int __thiscall sub_491F60(int *this)
{
  int v2; // ecx

  v2 = *this;
  if ( v2 )
    StreamFileTypeCheckWithDispatch(v2);
  if ( this[1] )
    FileCloseWithLock(this[1]);
  if ( this[2] )
    FileCloseWithLock(this[2]);
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  return 0;
}

