_DWORD *__thiscall sub_5D0FFA(_DWORD *this, int a2, int a3)
{
  if ( a3 )
  {
    *this = &unk_5F75E4;
    this[10] = 0;
    this[1] = &std::basic_ios<unsigned short>::`vftable';
  }
  *(_DWORD *)((char *)this + *(_DWORD *)(*this + 4)) = &std::basic_ostream<unsigned short>::`vftable';
  std::ios_base::_Addstd((std::ios_base *)((char *)this + *(_DWORD *)(*this + 4)));
  return this;
}
