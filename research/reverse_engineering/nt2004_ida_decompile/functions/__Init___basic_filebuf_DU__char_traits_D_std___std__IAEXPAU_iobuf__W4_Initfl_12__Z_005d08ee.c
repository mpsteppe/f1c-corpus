int __thiscall std::filebuf::_Init(int this, int a2, int a3)
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
  unknown_libname_188(this);
  if ( a2 && !*(_BYTE *)(this + 72) )
  {
    *(_DWORD *)(this + 28) = a2;
    *(_DWORD *)(this + 12) = a2 + 8;
    *(_DWORD *)(this + 16) = a2 + 8;
    *(_DWORD *)(this + 32) = a2;
    *(_DWORD *)(this + 44) = a2 + 4;
    *(_DWORD *)(this + 48) = a2 + 4;
  }
  *(_DWORD *)(this + 80) = a2;
  *(_DWORD *)(this + 64) = dword_801528;
  result = dword_801528;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = result;
  return result;
}
