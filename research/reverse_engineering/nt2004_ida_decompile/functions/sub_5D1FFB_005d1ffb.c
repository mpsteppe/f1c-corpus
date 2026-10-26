void __thiscall sub_5D1FFB(void *this)
{
  struct std::locale::facet *v1; // eax
  void *v2; // [esp+0h] [ebp-10h] BYREF
  int v3; // [esp+Ch] [ebp-4h]

  v2 = this;
  std::_Lockit::_Lockit((std::_Lockit *)&v2);
  v3 = 0;
  if ( dword_7FF900 )
  {
    v1 = std::locale::facet::_Decref(dword_7FF900);
    if ( v1 )
      (**(void (__thiscall ***)(struct std::locale::facet *, int))v1)(v1, 1);
  }
  v3 = -1;
  std::_Lockit::~_Lockit((std::_Lockit *)&v2);
}
