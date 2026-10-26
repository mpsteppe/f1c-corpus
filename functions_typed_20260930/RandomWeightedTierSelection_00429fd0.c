int __thiscall sub_429FD0(_DWORD *this)
{
  int v2; // edi
  bool v3; // zf
  signed int v4; // eax
  int v5; // ebp
  int i; // esi
  char *v7; // eax

  if ( flt_8AFEE8 < 0.15000001 )
  {
    v2 = this[4451];
    goto LABEL_17;
  }
  if ( flt_8AFEE8 < 0.2 )
  {
    v4 = RandLCGRandomNumberGenerator(this) & 0x80000001;
    v3 = v4 == 0;
    if ( v4 < 0 )
      v3 = (((_BYTE)v4 - 1) | 0xFFFFFFFE) == -1;
    if ( !v3 )
    {
      v2 = this[4451];
      goto LABEL_17;
    }
    goto LABEL_9;
  }
  if ( flt_8AFEE8 < 0.5 )
  {
LABEL_9:
    v2 = 4;
    goto LABEL_17;
  }
  if ( flt_8AFEE8 >= 0.55000001 )
  {
    if ( flt_8AFEE8 >= 0.80000001 )
    {
      if ( flt_8AFEE8 >= 0.85000002 )
        v2 = 6;
      else
        v2 = 6 - (RandLCGRandomNumberGenerator(this) % 2 != 0);
    }
    else
    {
      v2 = 5;
    }
  }
  else
  {
    v2 = (RandLCGRandomNumberGenerator(this) % 2 != 0) + 4;
  }
LABEL_17:
  v5 = 0;
  for ( i = 0; i < *(_DWORD *)(this[3678] + 16); ++i )
  {
    v7 = *(char **)CompoundIndexLookup(i);
    if ( !v7 )
      v7 = &byte_5EA438;
    if ( v2 == TireCompoundNameIDMapping(v7) )
      v5 = i;
  }
  return v5;
}

