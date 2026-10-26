int __thiscall sub_5C5AC0(_DWORD *this)
{
  void *v2; // eax
  int v3; // eax

  if ( !this[2] )
  {
    v2 = operator new(0xCu);
    if ( v2 )
      v3 = unknown_libname_25(v2);
    else
      v3 = 0;
    this[2] = v3;
  }
  return this[2];
}
