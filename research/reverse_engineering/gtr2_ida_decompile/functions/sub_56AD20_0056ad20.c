char __thiscall sub_56AD20(int this)
{
  int v2; // eax
  _BYTE *i; // edx
  int v4; // edx
  int j; // eax

  if ( *(_DWORD *)(this + 1648) && !*(_BYTE *)(this + 1712) || *(_DWORD *)(this + 1716) && !*(_BYTE *)(this + 1780) )
    return 1;
  v2 = 0;
  for ( i = (_BYTE *)(this + 528); *i; i += 296 )
  {
    if ( ++v2 >= 4 )
    {
      v4 = 0;
      for ( j = this + 1784; !*(_DWORD *)j || *(_BYTE *)(j + 64); j += 68 )
      {
        if ( ++v4 >= 8 )
          return 0;
      }
      return 1;
    }
  }
  return 1;
}
