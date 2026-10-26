int __thiscall sub_4D5840(_DWORD *this)
{
  int result; // eax

  result = *this;
  if ( *this )
  {
    sub_587F64(result, 0, 0);
    FileReadWrapperWithLock(this + 6, 4, 1, *this);
    result = FileCloseWithLock(*this);
    *this = 0;
  }
  return result;
}
