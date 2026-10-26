_DWORD *__thiscall sub_5D10CC(_DWORD *this, int a2, int a3)
{
  if ( a3 )
  {
    *this = &unk_5F75EC;
    this[11] = 0;
    this[2] = &std::basic_ios<unsigned short>::`vftable';
  }
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::basic_istream<unsigned short>::`vftable';
  std::ios_base::_Addstd((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)));
  return this;
}
