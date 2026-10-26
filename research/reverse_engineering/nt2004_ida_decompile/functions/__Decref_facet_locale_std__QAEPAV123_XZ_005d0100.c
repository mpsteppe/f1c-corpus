struct std::locale::facet *__thiscall std::locale::facet::_Decref(std::locale::facet *this)
{
  int v2; // eax
  std::locale::facet *v3; // esi
  _BYTE v5[4]; // [esp+8h] [ebp-4h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)v5);
  v2 = *((_DWORD *)this + 1);
  if ( v2 && v2 != -1 )
    *((_DWORD *)this + 1) = v2 - 1;
  v3 = *((_DWORD *)this + 1) == 0 ? this : 0;
  std::_Lockit::~_Lockit((std::_Lockit *)v5);
  return v3;
}
