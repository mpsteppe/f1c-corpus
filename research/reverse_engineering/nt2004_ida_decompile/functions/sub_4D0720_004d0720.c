void __thiscall sub_4D0720(int this, float a2)
{
  __int16 v2; // dx

  *(_BYTE *)(this + 13) &= 0xFCu;
  v2 = *(_WORD *)(this + 12);
  if ( a2 <= 0.93000001 )
  {
    if ( a2 <= 0.79000002 )
    {
      if ( a2 > 0.64999998 )
        *(_WORD *)(this + 12) = v2 | 0x100;
    }
    else
    {
      *(_WORD *)(this + 12) = v2 | 0x200;
    }
  }
  else
  {
    *(_WORD *)(this + 12) = v2 | 0x300;
  }
}
