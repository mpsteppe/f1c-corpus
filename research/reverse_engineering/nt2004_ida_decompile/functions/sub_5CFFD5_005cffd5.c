_DWORD *__thiscall sub_5CFFD5(_DWORD *this, int a2, int a3)
{
  if ( a3 )
  {
    *this = &unk_5F7550;
    this[11] = 0;
    this[2] = &std::ios::`vftable';
  }
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::istream::`vftable';
  std::ios_base::_Addstd((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)));
  return this;
}
