// f1c  0x004966e0  size=109
void __thiscall sub_4966E0(_DWORD *this, int a2)
{
  int v3; // eax

  if ( a2 )
  {
    v3 = sub_587C03(16);
    if ( v3 )
    {
      *(_DWORD *)v3 = a2;
      *(_DWORD *)(v3 + 4) = 0;
      *(_DWORD *)(v3 + 8) = 0;
      *(_BYTE *)(v3 + 12) = 0;
    }
    else
    {
      v3 = 0;
    }
    if ( this[1591] )
    {
      *(_DWORD *)(this[1592] + 4) = v3;
      *(_DWORD *)(v3 + 8) = this[1592];
    }
    else
    {
      this[1591] = v3;
      this[1593] = v3;
    }
    this[1592] = v3;
    ++this[1594];
  }
}
