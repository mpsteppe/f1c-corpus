__int16 __thiscall std::basic_filebuf<unsigned short>::pbackfail(int this, int Character)
{
  unsigned int v3; // eax
  wint_t v4; // di
  int v5; // eax
  bool v6; // zf
  int v7; // edi
  unsigned int v8; // ebx

  v3 = **(_DWORD **)(this + 28);
  if ( v3 && **(_DWORD **)(this + 12) < v3 )
  {
    v4 = Character;
    if ( (_WORD)Character == 0xFFFF || *(_WORD *)(v3 - 2) == (_WORD)Character )
    {
      std::basic_streambuf<unsigned short>::_Gndec(this);
      return (_WORD)Character != 0xFFFF ? Character : 0;
    }
  }
  else
  {
    v4 = Character;
  }
  if ( !*(_DWORD *)(this + 80) || v4 == 0xFFFF )
  {
LABEL_15:
    LOWORD(v5) = -1;
    return v5;
  }
  if ( *(_DWORD *)(this + 56) )
  {
    v7 = *(_DWORD *)(this + 68);
    v8 = *(_DWORD *)(v7 + 8);
    if ( v8 )
    {
      std::string::_Freeze(*(_DWORD **)(this + 68));
      if ( std::_Ungetc(*(const char **)(v7 + 4), *(FILE **)(this + 80), v8) )
      {
        std::string::erase(*(_DWORD **)(this + 68), 0, 0xFFFFFFFF);
        *(_DWORD *)(this + 64) = *(_DWORD *)(this + 60);
        LOWORD(v5) = Character;
        return v5;
      }
    }
    goto LABEL_15;
  }
  v6 = ungetwc(v4, *(FILE **)(this + 80)) == 0xFFFF;
  LOWORD(v5) = v4;
  if ( v6 )
    LOWORD(v5) = -1;
  return v5;
}
