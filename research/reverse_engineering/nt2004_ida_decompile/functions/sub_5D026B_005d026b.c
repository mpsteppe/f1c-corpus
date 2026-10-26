void __thiscall sub_5D026B(void *this)
{
  void *v2; // edi

  *(_DWORD *)this = &off_5F755C;
  if ( *((_BYTE *)this + 72) )
    std::filebuf::close();
  v2 = (void *)*((_DWORD *)this + 17);
  if ( v2 )
  {
    std::string::_Tidy(1);
    sub_5BE8AE(v2);
  }
  std::locale::~locale((std::locale::facet **)this + 19);
  *(_DWORD *)this = &std::streambuf::`vftable';
  std::locale::~locale((std::locale::facet **)this + 13);
}
