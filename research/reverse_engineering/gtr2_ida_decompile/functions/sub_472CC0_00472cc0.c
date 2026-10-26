void __thiscall sub_472CC0(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // ebx
  int v5; // edi
  double v6; // st7
  int v7; // eax
  bool v8; // cc
  int v9; // [esp+10h] [ebp-18h]
  int v10; // [esp+14h] [ebp-14h]
  int v11; // [esp+18h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-Ch]
  int v13; // [esp+20h] [ebp-8h] BYREF
  int v14; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD *)(this + 804);
  v10 = 0;
  *(_BYTE *)(this + 808) = 0;
  v12 = v2;
  sub_567E80(&v13, 0);
  v3 = 0;
  v14 = (unsigned __int64)((double)dword_903EBC * 0.035);
  v11 = 0;
  v9 = 0;
  while ( 1 )
  {
    v4 = (v3 + v12) % 8;
    v5 = 92 * v4 + this;
    if ( *(float *)(v5 + 152) > 0.0 )
      break;
LABEL_9:
    v11 = ++v3;
    if ( v3 >= 8 )
      return;
  }
  sub_5688F0(v5 + 68, v13 / 2, v9, *(float *)(v5 + 148), 2, -1.0, -1.0, 0, 0);
  v6 = *(float *)(v5 + 152) - dbl_FB1D08;
  *(float *)(v5 + 152) = v6;
  if ( v6 > 0.0 )
  {
    *(_BYTE *)(this + 808) = 1;
  }
  else
  {
    *(_BYTE *)(v5 + 68) = 0;
    *(_DWORD *)(v5 + 148) = -1;
    *(_DWORD *)(v5 + 152) = -1082130432;
    *(_DWORD *)(v5 + 156) = 3;
    v7 = *(_DWORD *)(this + 804);
    if ( v4 == v7 )
      *(_DWORD *)(this + 804) = (v7 + 1) % 8;
  }
  v8 = ++v10 < 4;
  v9 += v14;
  if ( v8 )
  {
    v3 = v11;
    goto LABEL_9;
  }
}
