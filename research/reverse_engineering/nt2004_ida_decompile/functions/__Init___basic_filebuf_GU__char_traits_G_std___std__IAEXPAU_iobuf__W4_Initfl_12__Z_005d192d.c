int __thiscall std::basic_filebuf<unsigned short>::_Init(int this, int a2, int a3)
{
  int result; // eax

  *(_BYTE *)(this + 72) = a3 == 1;
  if ( !a3 )
  {
    std::locale::~locale((std::locale::facet **)(this + 76));
    if ( this != -76 )
      std::locale::locale((std::locale *)(this + 76));
    *(_DWORD *)(this + 68) = 0;
  }
  unknown_libname_188((_DWORD *)this);
  *(_DWORD *)(this + 80) = a2;
  *(_DWORD *)(this + 64) = dword_801520;
  result = dword_801520;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = result;
  return result;
}
