int __thiscall sub_5E3450(_DWORD *this, _DWORD *a2, int a3)
{
  int v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int v7; // eax

  if ( a3 >= this[64] )
    return 0;
  v4 = sub_5E8220(99);
  v5 = (_DWORD *)sub_5E80D0(a3 + v4);
  v6 = v5;
  if ( v5[1] == 1 )
  {
    v7 = *v5;
    if ( (*v6 & 0x44000) == 0 )
      return v6[55];
    if ( v6[56] )
    {
      if ( byte_FB2740 )
      {
        sub_5F4CF0(v6[55], 0, 0, 0);
        *(_DWORD *)v6[55] &= ~0x100u;
      }
      return v6[55];
    }
    if ( (v7 & 0x4000) != 0 )
    {
      if ( this[275] )
        return sub_606D40(2);
      return v6[55];
    }
    return 0;
  }
  if ( !a2 || (*a2 & 0x100000) != 0 )
    return v5[55];
  else
    return v5[55] + 216 * *(_DWORD *)(v5[19] + 4 * abs32(a2[23]));
}
