struct std::locale::_Locimp *__cdecl std::locale::_Init()
{
  std::locale::_Locimp *v0; // ecx
  std::locale::facet *v1; // eax
  size_t v2; // eax
  std::locale::facet *v3; // esi
  _BYTE v5[4]; // [esp+8h] [ebp-10h] BYREF
  int v6; // [esp+14h] [ebp-4h]

  std::_Lockit::_Lockit((std::_Lockit *)v5);
  v6 = 0;
  if ( !dword_7FF900 )
  {
    v0 = (std::locale::_Locimp *)operator new(0x28u);
    LOBYTE(v6) = 1;
    if ( v0 )
      v1 = (std::locale::facet *)std::locale::_Locimp::_Locimp(v0, 0);
    else
      v1 = 0;
    LOBYTE(v6) = 0;
    dword_7FF900 = v1;
    atexit(sub_5D1FFB);
    *((_DWORD *)dword_7FF900 + 4) = 63;
    v2 = strlen(aC_0);
    std::string::assign((int)dword_7FF900 + 24, aC_0, v2);
    dword_7FF8FC = (int)dword_7FF900;
    std::locale::facet::_Incref(dword_7FF900);
    if ( &dword_7FF8F8 )
      dword_7FF8F8 = dword_7FF8FC;
  }
  v3 = dword_7FF900;
  v6 = -1;
  std::_Lockit::~_Lockit((std::_Lockit *)v5);
  return v3;
}
