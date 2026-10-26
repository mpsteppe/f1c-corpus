std::locale::facet *__stdcall sub_5D1260(unsigned int a1)
{
  std::locale::facet *v1; // esi
  std::locale::facet *result; // eax

  v1 = (std::locale::facet *)operator new(8u);
  result = 0;
  if ( v1 )
  {
    std::locale::facet::facet(v1, a1);
    *(_DWORD *)v1 = &off_72B380;
    return v1;
  }
  return result;
}
