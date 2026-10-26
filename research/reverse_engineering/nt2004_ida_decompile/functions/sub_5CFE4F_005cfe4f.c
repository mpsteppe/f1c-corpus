_DWORD *__thiscall sub_5CFE4F(_DWORD *this, int a2, char a3, char a4, int a5)
{
  if ( a5 )
  {
    *this = &unk_5F7548;
    this[10] = 0;
    this[1] = &std::ios::`vftable';
  }
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::ostream::`vftable';
  if ( a4 )
    std::ios::init((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)), a2, a3);
  return this;
}
