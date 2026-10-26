int __thiscall sub_5D3136(void *this)
{
  bool v1; // zf
  int result; // eax

  v1 = *((_DWORD *)this + 2) == 0;
  *(_DWORD *)this = &exception::`vftable';
  if ( !v1 )
    return sub_5BE8AE(*((void **)this + 1));
  return result;
}
