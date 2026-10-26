void __thiscall sub_5D132B(void *this)
{
  _DWORD *v2; // edi

  *(_DWORD *)this = &off_5F75F8;
  if ( *((_BYTE *)this + 72) )
    std::basic_filebuf<unsigned short>::close();
  v2 = (_DWORD *)*((_DWORD *)this + 17);
  if ( v2 )
  {
    std::string::_Tidy(v2, 1);
    sub_5BE8AE(v2);
  }
  std::locale::~locale((std::locale::facet **)this + 19);
  *(_DWORD *)this = &std::basic_streambuf<unsigned short>::`vftable';
  std::locale::~locale((std::locale::facet **)this + 13);
}
