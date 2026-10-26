void __thiscall std::ios_base::_Addstd(std::ios_base *this)
{
  int v2; // eax
  std::ios_base *v3; // ecx
  unsigned int v4; // eax
  _BYTE v5[4]; // [esp+4h] [ebp-4h] BYREF

  std::_Lockit::_Lockit((std::_Lockit *)v5);
  if ( *((_DWORD *)this + 9) < 8u )
  {
    do
    {
      v2 = *((_DWORD *)this + 9);
      v3 = (std::ios_base *)dword_7FF8C8[v2];
      if ( !v3 )
        break;
      if ( v3 == this )
        break;
      v4 = v2 + 1;
      *((_DWORD *)this + 9) = v4;
    }
    while ( v4 < 8 );
  }
  dword_7FF8C8[*((_DWORD *)this + 9)] = (int)this;
  ++byte_7FF8EC[*((_DWORD *)this + 9)];
  std::_Lockit::~_Lockit((std::_Lockit *)v5);
}
