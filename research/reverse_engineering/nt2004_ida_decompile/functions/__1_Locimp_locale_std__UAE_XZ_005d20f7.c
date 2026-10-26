void __thiscall std::locale::_Locimp::~_Locimp(std::locale::_Locimp *this)
{
  int v2; // edi
  std::locale::facet *v3; // ecx
  struct std::locale::facet *v4; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-10h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  *(_DWORD *)this = &off_5F76D8;
  v6 = 1;
  std::_Lockit::_Lockit((std::_Lockit *)v5);
  v2 = *((_DWORD *)this + 3);
  LOBYTE(v6) = 2;
  while ( v2 )
  {
    --v2;
    v3 = *(std::locale::facet **)(*((_DWORD *)this + 2) + 4 * v2);
    if ( v3 )
    {
      v4 = std::locale::facet::_Decref(v3);
      if ( v4 )
        (**(void (__thiscall ***)(struct std::locale::facet *, int))v4)(v4, 1);
    }
  }
  sub_5C1B88(*((LPVOID *)this + 2));
  LOBYTE(v6) = 1;
  std::_Lockit::~_Lockit((std::_Lockit *)v5);
  LOBYTE(v6) = 0;
  std::string::_Tidy((_DWORD *)this + 6, 1);
  *(_DWORD *)this = &std::locale::facet::`vftable';
}
