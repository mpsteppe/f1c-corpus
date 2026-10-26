int __thiscall sub_46B7A0(int this, int a2)
{
  char *v2; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // eax
  double v7; // st7
  double v8; // st7
  double v9; // st7
  int v10; // eax
  int v11; // edx
  int result; // eax

  v2 = *(char **)(a2 + 4);
  if ( !v2 )
    v2 = (char *)off_16C9A68;
  sub_615860(v2);
  if ( a2 != -12 )
  {
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  }
  if ( a2 != -24 )
  {
    *(_DWORD *)(this + 24) = *(_DWORD *)(a2 + 24);
    *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 28);
    *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 32);
  }
  v4 = *(_DWORD *)(a2 + 48);
  *(float *)(this + 52) = *(float *)(a2 + 52);
  *(_DWORD *)(this + 48) = v4;
  v5 = *(_DWORD *)(a2 + 56);
  *(float *)(this + 60) = *(float *)(a2 + 60);
  *(_DWORD *)(this + 56) = v5;
  v6 = *(_DWORD *)(a2 + 64);
  *(float *)(this + 68) = *(float *)(a2 + 68);
  *(_DWORD *)(this + 64) = v6;
  v7 = *(float *)(a2 + 72);
  if ( *(_BYTE *)(a2 + 124) )
    v7 = v7 + v7;
  *(float *)(this + 72) = v7;
  v8 = *(float *)(a2 + 80);
  *(_DWORD *)(this + 76) = *(_DWORD *)(a2 + 76);
  *(float *)(this + 80) = v8;
  v9 = *(float *)(a2 + 88);
  *(_DWORD *)(this + 84) = *(_DWORD *)(a2 + 84);
  *(float *)(this + 88) = v9;
  *(_DWORD *)(this + 92) = *(_DWORD *)(a2 + 92);
  *(_BYTE *)(this + 96) = *(_BYTE *)(a2 + 96);
  v10 = *(_DWORD *)(a2 + 108);
  v11 = *(_DWORD *)(a2 + 100);
  *(_DWORD *)(this + 104) = *(_DWORD *)(a2 + 104);
  *(_DWORD *)(this + 108) = v10;
  *(_DWORD *)(this + 100) = v11;
  *(_DWORD *)(this + 112) = *(_DWORD *)(a2 + 112);
  *(_DWORD *)(this + 116) = *(_DWORD *)(a2 + 116);
  *(_DWORD *)(this + 120) = *(_DWORD *)(a2 + 120);
  *(_DWORD *)(this + 132) = *(_DWORD *)(a2 + 132);
  *(_DWORD *)(this + 136) = *(_DWORD *)(a2 + 136);
  *(_DWORD *)(this + 140) = *(_DWORD *)(a2 + 140);
  *(_DWORD *)(this + 144) = *(_DWORD *)(a2 + 144);
  *(_DWORD *)(this + 148) = *(_DWORD *)(a2 + 148);
  *(_DWORD *)(this + 152) = *(_DWORD *)(a2 + 152);
  *(_DWORD *)(this + 156) = *(_DWORD *)(a2 + 156);
  *(_DWORD *)(this + 160) = *(_DWORD *)(a2 + 160);
  *(_DWORD *)(this + 164) = *(_DWORD *)(a2 + 164);
  *(_DWORD *)(this + 168) = *(_DWORD *)(a2 + 168);
  *(_DWORD *)(this + 172) = *(_DWORD *)(a2 + 172);
  *(_DWORD *)(this + 176) = *(_DWORD *)(a2 + 176);
  *(_DWORD *)(this + 180) = *(_DWORD *)(a2 + 180);
  *(_DWORD *)(this + 184) = *(_DWORD *)(a2 + 184);
  *(_DWORD *)(this + 188) = *(_DWORD *)(a2 + 188);
  *(_DWORD *)(this + 192) = *(_DWORD *)(a2 + 192);
  *(_DWORD *)(this + 196) = *(_DWORD *)(a2 + 196);
  result = this;
  *(_DWORD *)(this + 200) = *(_DWORD *)(a2 + 200);
  return result;
}
