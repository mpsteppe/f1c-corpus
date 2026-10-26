void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  *(_DWORD *)this = &off_712568;
  if ( !*((_DWORD *)this + 67) )
  {
    *((_DWORD *)this + 67) = 0;
    sub_4DA470((char *)this + 272);
  }
}
