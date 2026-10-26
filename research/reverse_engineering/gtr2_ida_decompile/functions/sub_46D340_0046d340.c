int __thiscall sub_46D340(int this, int a2)
{
  const CHAR *v2; // eax
  _DWORD *v4; // eax
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  int v11; // eax
  int v12; // edx
  double v13; // st7

  v2 = *(const CHAR **)(a2 + 4);
  if ( !v2 )
    v2 = WindowName;
  sub_615860(v2);
  if ( a2 != -12 )
  {
    *(_DWORD *)(this + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(this + 16) = *(_DWORD *)(a2 + 16);
    *(_DWORD *)(this + 20) = *(_DWORD *)(a2 + 20);
  }
  v4 = (_DWORD *)(a2 + 148);
  if ( a2 != -148 )
  {
    *(_DWORD *)(this + 24) = *v4;
    *(_DWORD *)(this + 28) = *(_DWORD *)(a2 + 152);
    *(_DWORD *)(this + 32) = *(_DWORD *)(a2 + 156);
  }
  *(_DWORD *)(this + 148) = *v4;
  *(_DWORD *)(this + 152) = *(_DWORD *)(a2 + 152);
  *(_DWORD *)(this + 156) = *(_DWORD *)(a2 + 156);
  v5 = *(_DWORD *)(a2 + 48);
  *(float *)(this + 52) = *(float *)(a2 + 52);
  *(_DWORD *)(this + 48) = v5;
  v6 = *(_DWORD *)(a2 + 56);
  *(float *)(this + 60) = *(float *)(a2 + 60);
  *(_DWORD *)(this + 56) = v6;
  v7 = *(_DWORD *)(a2 + 64);
  *(float *)(this + 68) = *(float *)(a2 + 68);
  *(_DWORD *)(this + 64) = v7;
  v8 = *(float *)(a2 + 72);
  if ( *(_BYTE *)(a2 + 124) )
    v8 = v8 + v8;
  *(float *)(this + 72) = v8;
  v9 = *(float *)(a2 + 80);
  *(_DWORD *)(this + 76) = *(_DWORD *)(a2 + 76);
  *(float *)(this + 80) = v9;
  v10 = *(float *)(a2 + 88);
  *(_DWORD *)(this + 84) = *(_DWORD *)(a2 + 84);
  *(float *)(this + 88) = v10;
  *(_DWORD *)(this + 92) = *(_DWORD *)(a2 + 92);
  *(_BYTE *)(this + 96) = *(_BYTE *)(a2 + 96);
  v11 = *(_DWORD *)(a2 + 108);
  v12 = *(_DWORD *)(a2 + 100);
  *(_DWORD *)(this + 104) = *(_DWORD *)(a2 + 104);
  *(_DWORD *)(this + 108) = v11;
  *(_DWORD *)(this + 100) = v12;
  *(_DWORD *)(this + 112) = *(_DWORD *)(a2 + 112);
  *(_DWORD *)(this + 116) = *(_DWORD *)(a2 + 116);
  *(_DWORD *)(this + 120) = *(_DWORD *)(a2 + 120);
  *(_DWORD *)(this + 128) = *(_DWORD *)(a2 + 128);
  *(_DWORD *)(this + 132) = *(_DWORD *)(a2 + 132);
  *(_DWORD *)(this + 136) = *(_DWORD *)(a2 + 136);
  v13 = *(float *)(a2 + 140);
  *(float *)(this + 140) = *(float *)(a2 + 140);
  *(float *)(this + 144) = v13 * v13;
  *(_DWORD *)(this + 168) = *(_DWORD *)(a2 + 168);
  *(_DWORD *)(this + 172) = *(_DWORD *)(a2 + 172);
  *(_DWORD *)(this + 264) = *(_DWORD *)(a2 + 264);
  *(_DWORD *)(this + 268) = *(_DWORD *)(a2 + 268);
  sub_46C620();
  return this;
}
