bool __thiscall sub_566B90(int *this)
{
  bool result; // al
  bool v3; // zf
  int v4; // ecx
  int v5; // eax
  int v6; // eax

  result = 0;
  v3 = this[4] == 0;
  v4 = *this;
  if ( v3 )
  {
    if ( v4 )
    {
      v5 = FileCloseWithLock(*this);
      *this = 0;
      return v5 == 0;
    }
  }
  else if ( v4 )
  {
    v6 = StreamFileTypeCheckWithDispatch(v4);
    *this = 0;
    return v6 == 0;
  }
  return result;
}
