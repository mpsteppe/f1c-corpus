char __thiscall sub_50B100(int this)
{
  int v2; // eax
  _BYTE *i; // edx
  int v4; // edx
  int j; // eax

  if ( *(_DWORD *)(this + 1556) && !*(_BYTE *)(this + 1620) )
    return 1;
  if ( !*(_DWORD *)(this + 1624) || *(_BYTE *)(this + 1688) )
  {
    v2 = 0;
    for ( i = (_BYTE *)(this + 404); *i; i += 304 )
    {
      if ( ++v2 >= 4 )
      {
        v4 = 0;
        for ( j = this + 1692; !*(_DWORD *)j || *(_BYTE *)(j + 64); j += 68 )
        {
          if ( ++v4 >= 12 )
            return 0;
        }
        return 1;
      }
    }
  }
  return 1;
}
