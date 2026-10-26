void __thiscall sub_5537E0(int this, int a2)
{
  int v3; // ecx
  int v4; // ebx
  int v5; // ecx
  int v6; // ebx

  *(_DWORD *)(this + 216) = *(_DWORD *)a2;
  *(float *)(this + 220) = dbl_FB1D18 - (*(float *)(a2 + 12) - *(float *)(a2 + 4));
  *(float *)(this + 224) = *(float *)(a2 + 8) - *(float *)(a2 + 12) + dbl_FB1D18;
  *(_DWORD *)(this + 228) = *(_DWORD *)(a2 + 16);
  *(_DWORD *)(this + 232) = *(_DWORD *)(a2 + 20);
  *(_DWORD *)(this + 268) = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(this + 476) = *(_DWORD *)(a2 + 44);
  sub_552890();
  v3 = *(_DWORD *)(this + 316);
  v4 = *(_DWORD *)(a2 + 36);
  *(_DWORD *)(this + 312) = v4;
  if ( v3 )
    sub_5E37F0(v4, 0, 0);
  if ( *(_DWORD *)(this + 320) )
    sub_5E37F0(v4, 0, 0);
  v5 = *(_DWORD *)(this + 304);
  v6 = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(this + 300) = v6;
  if ( v5 )
    sub_5E37F0(v6, 0, 0);
  if ( *(_DWORD *)(this + 308) )
    sub_5E37F0(v6, 0, 0);
  *(_DWORD *)(this + 348) = *(_DWORD *)(a2 + 28);
  *(_DWORD *)(this + 352) = *(_DWORD *)(a2 + 32);
  *(_BYTE *)(this + 472) = *(_BYTE *)(a2 + 1836);
  *(_BYTE *)(this + 473) = *(_BYTE *)(a2 + 1837);
  *(_BYTE *)(this + 474) = *(_BYTE *)(a2 + 1838);
  sub_553180(a2, 0);
}
