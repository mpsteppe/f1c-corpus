_DWORD *__thiscall sub_5D1064(_DWORD *this, int a2, char a3, int a4)
{
  if ( a4 )
  {
    *this = &unk_5F75EC;
    this[11] = 0;
    this[2] = &std::basic_ios<unsigned short>::`vftable';
  }
  this[1] = 0;
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::basic_istream<unsigned short>::`vftable';
  std::basic_ios<unsigned short>::init((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)), a2, a3);
  return this;
}
