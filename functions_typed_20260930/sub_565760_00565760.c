BOOL __thiscall sub_565760(int this, int a2, int a3, int a4, int a5, int a6)
{
  BOOL result; // eax

  if ( !sub_565400((char *)this, a2) )
    return 0;
  if ( a6 )
    return StrlenFormatCallWrapper(*(_DWORD *)(this + 384), "(%d,%d,%d,%d)", a3, a4, a5, a6) == 4;
  if ( a5 )
    return StrlenFormatCallWrapper(*(_DWORD *)(this + 384), "(%d,%d,%d)", a3, a4, a5) == 3;
  if ( a4 )
    return StrlenFormatCallWrapper(*(_DWORD *)(this + 384), "(%d,%d)", a3, a4) == 2;
  if ( !a3 )
    return 0;
  result = StrlenFormatCallWrapper(*(_DWORD *)(this + 384), "(%d)", a3) == 1;
  if ( !result )
    return StrlenFormatCallWrapper(*(_DWORD *)(this + 384), "%d", a3) == 1;
  return result;
}

