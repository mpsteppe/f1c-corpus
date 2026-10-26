int __thiscall std::filebuf::pbackfail(int this, int a2)
{
  unsigned int v3; // eax
  int v4; // ebx
  int v6; // edi
  unsigned int v7; // ebx

  v3 = **(_DWORD **)(this + 28);
  if ( v3 && **(_DWORD **)(this + 12) < v3 )
  {
    v4 = a2;
    if ( a2 == -1 || *(unsigned __int8 *)(v3 - 1) == a2 )
    {
      std::streambuf::_Gndec(this);
      return a2 != -1 ? a2 : 0;
    }
  }
  else
  {
    v4 = a2;
  }
  if ( *(_DWORD *)(this + 80) && v4 != -1 )
  {
    if ( *(_DWORD *)(this + 56) )
    {
      v6 = *(_DWORD *)(this + 68);
      v7 = *(_DWORD *)(v6 + 8);
      if ( v7 )
      {
        std::string::_Freeze(*(_DWORD *)(this + 68));
        if ( std::_Ungetc(*(const char **)(v6 + 4), *(FILE **)(this + 80), v7) )
        {
          std::string::erase(0, -1);
          *(_DWORD *)(this + 64) = *(_DWORD *)(this + 60);
          return a2;
        }
      }
    }
    else if ( ungetc((unsigned __int8)v4, *(FILE **)(this + 80)) != -1 )
    {
      return v4;
    }
  }
  return -1;
}
