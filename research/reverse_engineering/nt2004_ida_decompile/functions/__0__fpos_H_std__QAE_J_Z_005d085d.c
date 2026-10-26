_DWORD *__thiscall std::fpos<int>::fpos<int>(_DWORD *this, int a2)
{
  *this = a2;
  this[2] = 0;
  this[3] = 0;
  std::_Lockit::_Lockit((std::_Lockit *)&a2);
  this[4] = dword_80152C;
  std::_Lockit::~_Lockit((std::_Lockit *)&a2);
  return this;
}
