void __thiscall std::locale::facet::_Incref(std::locale::facet *this)
{
  int v2; // eax
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)v3);
  v2 = *((_DWORD *)this + 1);
  if ( v2 != -1 )
    *((_DWORD *)this + 1) = v2 + 1;
  std::_Lockit::~_Lockit((std::_Lockit *)v3);
}
