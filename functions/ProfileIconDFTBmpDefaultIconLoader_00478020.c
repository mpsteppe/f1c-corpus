char *__thiscall ProfileIconDFTBmpDefaultIconLoader(char *this)
{
  const char *v2; // eax
  int v3; // eax

  v2 = (const char *)*((_DWORD *)this + 86);
  if ( !v2 )
    v2 = byte_5EA438;
  v3 = sub_497AD0(*((_DWORD **)this + 16), v2, 0);
  if ( !v3 )
    v3 = sub_497AD0(*((_DWORD **)this + 16), aProfileiconDft, 0);
  ObjectFieldInitWithIndirectLookup((_DWORD *)this + 73, v3);
  if ( *((_DWORD *)this + 81) )
  {
    (*(void (__thiscall **)(char *, int))(*(_DWORD *)this + 60))(this, 1);
    return this + 292;
  }
  else
  {
    (*(void (__thiscall **)(char *, _DWORD))(*(_DWORD *)this + 60))(this, 0);
    return 0;
  }
}
