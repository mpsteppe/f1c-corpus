char __thiscall sub_4D4D20(_DWORD *this)
{
  const char *v1; // eax
  const CHAR *v3; // eax
  const CHAR *v4; // eax
  int *v6; // eax
  int v7; // eax
  const CHAR *v8; // eax
  _BYTE v9[256]; // [esp+4h] [ebp-100h] BYREF

  v1 = dword_75ACF4;
  if ( !dword_75ACF4 )
    v1 = WindowName;
  if ( !_stricmp(v1, WindowName) )
    return 0;
  sub_4DED90();
  v3 = dword_75ACF4;
  if ( !dword_75ACF4 )
    v3 = WindowName;
  if ( !sub_5DEB30(&dword_B6E198, v3, 0) )
  {
    if ( dword_B6E198 )
    {
      if ( *(int *)(dword_B6E198 + 400) > 0 && (v6 = *(int **)(dword_B6E198 + 388)) != 0 )
        v7 = *v6;
      else
        v7 = 0;
      this[67] = v7;
      v8 = dword_75ACF4;
      if ( !dword_75ACF4 )
        v8 = WindowName;
      sub_615860(v8);
    }
    if ( this[67] )
    {
      sub_5E51D0(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
      sub_5E5190(0);
    }
    (*(void (__thiscall **)(_DWORD *))(*this + 168))(this);
    return 0;
  }
  sub_5D8CB0(0, v9);
  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\O_BaseGz.cpp", 8758) )
  {
    LOBYTE(v4) = (_BYTE)dword_75ACF4;
    if ( !dword_75ACF4 )
      v4 = WindowName;
    sub_561210((int)byte_FAE910, "CUBE error loading scene file %s: %s", (char)v4);
  }
  return 1;
}
