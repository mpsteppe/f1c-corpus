int __thiscall sub_4DC0C0(int this)
{
  bool v2; // zf
  int v3; // eax
  void *v4; // eax
  void *v5; // eax
  void *v6; // eax
  int v7; // ecx
  int v8; // eax
  int result; // eax
  unsigned int v10; // [esp-Ch] [ebp-14h]
  unsigned int v11; // [esp-8h] [ebp-10h]

  sub_4DC3F0(this);
  *(_DWORD *)(this + 12) = 0;
  *(_DWORD *)(this + 20) = 0;
  *(_DWORD *)(this + 24) = -1082130432;
  *(_DWORD *)(this + 28) = -1082130432;
  *(_DWORD *)(this + 32) = -1082130432;
  *(_DWORD *)(this + 56) = 0;
  *(_DWORD *)(this + 60) = 0;
  *(_DWORD *)(this + 64) = 0;
  v2 = dword_75CBB0 == 7;
  *(_DWORD *)(this + 16) = 0;
  if ( v2 )
  {
    *(_DWORD *)(this + 8) = 3;
    *(_DWORD *)(this + 116) = 0;
    *(_BYTE *)(this + 36) = 1;
  }
  else
  {
    *(_DWORD *)(this + 8) = 5;
    *(_DWORD *)(this + 116) = 1;
  }
  *(_DWORD *)(this + 120) = 0;
  *(_DWORD *)(this + 124) = -1082130432;
  *(_DWORD *)(this + 128) = -1082130432;
  *(_DWORD *)(this + 132) = -1082130432;
  *(_DWORD *)(this + 136) = -1082130432;
  *(_DWORD *)(this + 140) = -1082130432;
  *(_DWORD *)(this + 144) = -1082130432;
  memset((void *)(this + 332), 0xFFu, 0x28u);
  *(_DWORD *)(this + 148) = -1082130432;
  *(_DWORD *)(this + 152) = 0;
  v3 = dword_7D74B8;
  if ( dword_7D74B8 >= 1000 )
    v3 = 1000;
  *(_DWORD *)(this + 156) = v3;
  v4 = operator new(4 * v3);
  v11 = 4 * *(_DWORD *)(this + 156);
  *(_DWORD *)(this + 160) = v4;
  v5 = operator new(v11);
  v10 = *(_DWORD *)(this + 156);
  *(_DWORD *)(this + 164) = v5;
  v6 = operator new(v10);
  v7 = *(_DWORD *)(this + 156);
  *(_DWORD *)(this + 168) = v6;
  v8 = 0;
  *(_DWORD *)(this + 172) = 0;
  *(_DWORD *)(this + 176) = 0;
  *(_DWORD *)(this + 180) = 0;
  if ( v7 > 0 )
  {
    do
    {
      *(_DWORD *)(*(_DWORD *)(this + 160) + 4 * v8) = -1082130432;
      *(_DWORD *)(*(_DWORD *)(this + 164) + 4 * v8) = -1082130432;
      *(_BYTE *)(v8 + *(_DWORD *)(this + 168)) = 0;
      ++v8;
    }
    while ( v8 < *(_DWORD *)(this + 156) );
  }
  result = -8388609;
  *(_DWORD *)(this + 280) = 0;
  *(_BYTE *)(this + 284) = 0;
  *(_DWORD *)(this + 288) = 0;
  *(_DWORD *)(this + 292) = 0;
  *(_DWORD *)(this + 296) = 0;
  *(_DWORD *)(this + 300) = 0;
  *(_BYTE *)(this + 285) = 1;
  *(_DWORD *)(this + 304) = -8388609;
  *(_DWORD *)(this + 308) = 0x7FFFFFFF;
  *(_DWORD *)(this + 312) = -8388609;
  *(_DWORD *)(this + 328) = -2;
  return result;
}
