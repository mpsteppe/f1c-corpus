_DWORD *__thiscall sub_5CFEB9(_DWORD *this, int a2, int a3)
{
  if ( a3 )
  {
    *this = &unk_5F7548;
    this[10] = 0;
    this[1] = &std::ios::`vftable';
  }
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::ostream::`vftable';
  std::ios_base::_Addstd((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)));
  return this;
}
