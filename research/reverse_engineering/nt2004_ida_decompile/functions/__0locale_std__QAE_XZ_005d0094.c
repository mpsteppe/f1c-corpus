std::locale *__thiscall std::locale::locale(std::locale *this)
{
  _BYTE v3[4]; // [esp+4h] [ebp-4h] BYREF

  *(_DWORD *)this = std::locale::_Init();
  std::_Lockit::_Lockit((std::_Lockit *)v3);
  std::locale::facet::_Incref(dword_7FF900);
  std::_Lockit::~_Lockit((std::_Lockit *)v3);
  return this;
}
