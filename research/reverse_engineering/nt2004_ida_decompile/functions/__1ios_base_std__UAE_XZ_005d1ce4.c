void __thiscall std::ios_base::~ios_base(std::ios_base *this)
{
  int v2; // eax

  *(_DWORD *)this = &off_5F76CC;
  v2 = *((_DWORD *)this + 9);
  if ( !v2 || (--byte_7FF8EC[v2], byte_7FF8EC[*((_DWORD *)this + 9)] <= 0) )
    std::ios_base::_Tidy(this);
  std::locale::~locale((std::locale::facet **)this + 8);
}
