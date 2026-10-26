int __thiscall sub_65DCB5(_DWORD *this, unsigned int a2, int a3)
{
  int result; // eax
  char v5; // cl
  int v6; // ecx
  int v7; // edx

  result = sub_65D5D6((int)this, a2, &a2);
  if ( result >= 0 )
  {
    v5 = a3;
    if ( a3 == 255 )
    {
      v6 = 4 * a2;
      *(_DWORD *)(4 * a2 + this[7]) &= 0x20u;
      *(_DWORD *)(this[7] + v6) |= 1u;
    }
    else if ( a3 == 16 )
    {
      *(_DWORD *)(this[7] + 4 * a2) |= 0x10u;
    }
    else
    {
      v7 = 4 * a2;
      *(_DWORD *)(v7 + this[7]) &= 0xFFFFFFF0;
      *(_DWORD *)(this[7] + v7) |= v5 & 0xF;
    }
  }
  return result;
}
