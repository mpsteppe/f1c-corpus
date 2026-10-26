int __thiscall sub_4F8D80(int this)
{
  _DWORD *v2; // eax
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // edx

  sub_414B10((_DWORD *)this);
  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 208) = 0;
  *(_DWORD *)(this + 216) = 0;
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 228) = 0;
  *(_DWORD *)(this + 232) = 0;
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = 0;
  *(_DWORD *)(this + 248) = 0;
  v2 = (_DWORD *)(this + 360);
  v3 = 48;
  do
  {
    *v2 = -2;
    v2[1] = -1082130432;
    v2 += 2;
    --v3;
  }
  while ( v3 );
  sub_4F7CC0((_DWORD *)(this + 360));
  v4 = (_DWORD *)(this + 748);
  v5 = 48;
  do
  {
    *v4 = -2;
    v4[1] = -1082130432;
    v4 += 2;
    --v5;
  }
  while ( v5 );
  sub_4F7CC0((_DWORD *)(this + 748));
  sub_4F7ED0((_DWORD *)(this + 356));
  *(_DWORD *)(this + 144) = 0x7FFFFFFF;
  *(_DWORD *)(this + 148) = 0;
  *(_DWORD *)(this + 152) = 0;
  *(_DWORD *)(this + 156) = 1065353216;
  *(_BYTE *)(this + 160) = 0;
  *(_DWORD *)(this + 180) = 0;
  *(_DWORD *)(this + 184) = 0;
  *(_BYTE *)(this + 164) = 0;
  *(_DWORD *)(this + 176) = 0;
  *(_BYTE *)(this + 188) = 0;
  *(_BYTE *)(this + 189) = 0;
  *(_BYTE *)(this + 163) = 0;
  *(_DWORD *)(this + 260) = 0;
  *(_DWORD *)(this + 264) = 0;
  *(_DWORD *)(this + 268) = 0;
  *(_DWORD *)(this + 272) = 0;
  *(_DWORD *)(this + 276) = 0;
  *(_DWORD *)(this + 280) = 0;
  *(_DWORD *)(this + 284) = 5;
  *(_DWORD *)(this + 292) = 0;
  *(_DWORD *)(this + 296) = 0;
  *(_DWORD *)(this + 300) = 0;
  memset((void *)(this + 304), 0xFFu, 0x30u);
  sub_4F7ED0((_DWORD *)(this + 356));
  *(_DWORD *)(this + 1200) = 0;
  *(_DWORD *)(this + 1204) = 0;
  *(_DWORD *)(this + 1208) = 0;
  *(_DWORD *)(this + 1212) = 0;
  *(_DWORD *)(this + 1216) = 0;
  *(_DWORD *)(this + 1220) = 0;
  return this;
}
