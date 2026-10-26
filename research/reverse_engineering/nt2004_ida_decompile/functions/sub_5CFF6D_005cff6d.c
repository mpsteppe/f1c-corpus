_DWORD *__thiscall sub_5CFF6D(_DWORD *this, int a2, char a3, int a4)
{
  if ( a4 )
  {
    *this = &unk_5F7550;
    this[11] = 0;
    this[2] = &std::ios::`vftable';
  }
  this[1] = 0;
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::istream::`vftable';
  std::ios::init((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)), a2, a3);
  return this;
}
