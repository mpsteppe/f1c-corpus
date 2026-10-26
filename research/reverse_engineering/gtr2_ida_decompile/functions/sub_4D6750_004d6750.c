int __thiscall sub_4D6750(_DWORD *this, char *String1)
{
  int v3; // esi
  const char *v4; // eax
  void (__thiscall ***v6)(_DWORD, int); // eax

  if ( !String1 )
    return -1;
  v3 = this[36];
  if ( v3 )
  {
    while ( 1 )
    {
      v4 = *(const char **)(v3 + 160);
      if ( !v4 )
        v4 = WindowName;
      if ( !_stricmp(String1, v4) )
        break;
      v3 = *(_DWORD *)(v3 + 140);
      if ( !v3 )
        return 0;
    }
    v6 = (void (__thiscall ***)(_DWORD, int))sub_4CD3E0(this, v3);
    if ( v6 )
      (**v6)(v6, 1);
    sub_4D4060(this, 1, 0);
  }
  return 0;
}
