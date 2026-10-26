char __thiscall sub_4A0AB0(_DWORD *this)
{
  const char *v2; // eax
  const char *v3; // eax
  int v4; // eax

  if ( !dword_B71BC4 )
    goto LABEL_8;
  v2 = (const char *)this[42];
  if ( !v2 )
    v2 = WindowName;
  if ( !_stricmp(v2, "no") )
    goto LABEL_8;
  v3 = (const char *)this[42];
  if ( !v3 )
    v3 = WindowName;
  v4 = _stricmp(v3, off_6FE318);
  if ( !v4 )
LABEL_8:
    LOBYTE(v4) = sub_48E050((int)this);
  return v4;
}
