char __thiscall sub_40A0D0(int this)
{
  int v2; // ecx
  const char *v3; // eax
  const char *v4; // eax
  int v6; // ecx

  if ( dword_767A9C )
  {
    if ( !*(_BYTE *)(this + 52) )
    {
      v2 = *(_DWORD *)(this + 16);
      if ( v2 )
      {
        v3 = (const char *)sub_459BA0(v2);
        if ( !_strcmpi(v3, aDrivable) )
          return 1;
        v4 = (const char *)sub_459BA0(*(_DWORD *)(this + 16));
        if ( !_strcmpi(v4, aSwingman) )
          return 1;
      }
    }
  }
  v6 = *(_DWORD *)(this + 68);
  if ( v6 )
  {
    if ( !*(_BYTE *)(this + 72) )
    {
      sub_59FFB0(0, 0, *(_DWORD *)(v6 + 28), *(_DWORD *)(v6 + 32), 0);
      *(_BYTE *)(this + 72) = 1;
    }
  }
  return 0;
}
