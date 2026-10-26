std::locale::_Locimp *__thiscall std::locale::_Locimp::_Locimp(std::locale::_Locimp *this, int a2)
{
  size_t v3; // eax

  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &std::locale::facet::`vftable';
  *((_BYTE *)this + 20) = a2;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_BYTE *)this + 24) = HIBYTE(a2);
  std::string::_Tidy((_DWORD *)this + 6, 0);
  v3 = strlen(asc_5FE194);
  std::string::assign((int)this + 24, asc_5FE194, v3);
  *(_DWORD *)this = &off_5F76D8;
  return this;
}
