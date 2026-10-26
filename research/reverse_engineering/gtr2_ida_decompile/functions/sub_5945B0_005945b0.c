void __thiscall sub_5945B0(_DWORD *this, int a2)
{
  int v3; // esi
  double v4; // st7
  float *v5; // ebx
  int v6; // ecx
  int v7; // eax
  char i; // bl

  v3 = this[15];
  if ( v3 )
  {
    v4 = dbl_FB1D18;
    v5 = (float *)(a2 + 24);
    *(float *)(a2 + 4) = *(float *)v3 - dbl_FB1D18;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(this[15] + 8);
    *(_DWORD *)(a2 + 8) = *(_DWORD *)(this[15] + 4);
    v6 = 1;
    do
    {
      if ( v6 < 144 )
      {
        *(v5 - 2) = *(float *)v3 - v4;
        *v5 = *(float *)(v3 + 8);
        *(v5 - 1) = *(float *)(v3 + 4);
      }
      if ( v4 < *(float *)v3 )
      {
        ++v6;
        v5 += 3;
      }
      v3 = *(_DWORD *)(v3 + 12);
    }
    while ( v3 );
    if ( v6 <= 144 )
      *(_BYTE *)a2 = v6;
    else
      *(_BYTE *)a2 = -112;
    v7 = this[15];
    for ( i = 0; v7; ++i )
      v7 = *(_DWORD *)(v7 + 12);
    *(_BYTE *)(a2 + 1) = v6 - i;
    *(_DWORD *)(a2 + 1748) = this[13];
    *(_DWORD *)(a2 + 1732) = this[9];
    *(_DWORD *)(a2 + 1744) = this[12];
    *(_DWORD *)(a2 + 1740) = this[11];
    *(_DWORD *)(a2 + 1736) = this[10];
    *(_DWORD *)(a2 + 1752) = this[14];
  }
}
