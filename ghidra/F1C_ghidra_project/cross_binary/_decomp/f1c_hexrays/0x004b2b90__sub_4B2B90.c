// f1c  0x004b2b90  size=95
void __thiscall sub_4B2B90(int this, float a2)
{
  if ( a2 > 0.75 )
  {
    if ( a2 >= 0.85000002 )
    {
      if ( a2 >= 0.94999999 )
        *(_DWORD *)(this + 15) |= 3u;
      else
        *(_DWORD *)(this + 15) = *(_DWORD *)(this + 15) & 0xFFFFFFFC | 2;
    }
    else
    {
      *(_DWORD *)(this + 15) = *(_DWORD *)(this + 15) & 0xFFFFFFFC | 1;
    }
  }
  else
  {
    *(_DWORD *)(this + 15) &= 0xFFFFFFFC;
  }
}
