int __thiscall sub_677106(_DWORD *this, size_t Size)
{
  void *v3; // eax

  v3 = operator new(Size);
  this[3] = v3;
  if ( !v3 )
    return -2147024882;
  this[2] = Size;
  return 0;
}
