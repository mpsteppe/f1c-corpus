_DWORD *__thiscall sub_5D0F90(_DWORD *this, int a2, char a3, char a4, int a5)
{
  if ( a5 )
  {
    *this = &unk_5F75E4;
    this[10] = 0;
    this[1] = &std::basic_ios<unsigned short>::`vftable';
  }
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::basic_ostream<unsigned short>::`vftable';
  if ( a4 )
    std::basic_ios<unsigned short>::init((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)), a2, a3);
  return this;
}
