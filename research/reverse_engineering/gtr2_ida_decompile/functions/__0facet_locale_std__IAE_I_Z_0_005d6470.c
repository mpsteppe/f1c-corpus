std::locale::facet *__thiscall std::locale::facet::facet(std::locale::facet *this, unsigned int a2)
{
  std::locale::facet *result; // eax

  result = this;
  *(_DWORD *)this = &off_72B614;
  *((_DWORD *)this + 1) = a2;
  return result;
}
