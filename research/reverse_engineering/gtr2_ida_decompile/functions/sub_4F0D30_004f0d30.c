void __thiscall sub_4F0D30(int this, int a2)
{
  double v3; // st7
  double v4; // st6
  double v5; // st6
  double v6; // st6
  double v7; // st6
  double v8; // st6
  double v9; // st6
  double v10; // st6
  double v11; // st6
  double v12; // st6
  int v13; // eax
  double v14; // st6
  double v15; // st7
  float v16; // [esp+4h] [ebp+4h]
  float v17; // [esp+4h] [ebp+4h]
  float v18; // [esp+4h] [ebp+4h]
  float v19; // [esp+4h] [ebp+4h]

  v3 = *(float *)(a2 + 68) + *(float *)a2;
  *(_DWORD *)(this + 28) = 1203982208;
  *(_DWORD *)(this + 32) = 1203982208;
  *(_DWORD *)(this + 36) = 1203982208;
  *(_DWORD *)(this + 40) = 1203982208;
  *(_DWORD *)(this + 44) = 1203982208;
  *(_DWORD *)(this + 48) = 1203982208;
  *(_DWORD *)(this + 52) = 1203982208;
  *(_DWORD *)(this + 56) = 1203982208;
  *(_DWORD *)(this + 60) = 1203982208;
  *(_DWORD *)(this + 64) = 1203982208;
  *(_DWORD *)(this + 68) = 1203982208;
  *(_DWORD *)(this + 72) = 1203982208;
  *(_DWORD *)(this + 76) = 1203982208;
  *(_DWORD *)(this + 80) = 1203982208;
  *(_DWORD *)(this + 84) = 1203982208;
  *(_DWORD *)(this + 88) = 1203982208;
  *(_DWORD *)(this + 92) = 1203982208;
  *(_DWORD *)(this + 96) = 1203982208;
  *(_DWORD *)(this + 100) = 1203982208;
  *(_DWORD *)(this + 104) = 1203982208;
  *(_DWORD *)(this + 108) = 1203982208;
  *(_DWORD *)(this + 112) = 1203982208;
  *(_DWORD *)(this + 116) = 1203982208;
  *(_DWORD *)(this + 120) = 1203982208;
  *(_DWORD *)(this + 124) = 1203982208;
  *(_DWORD *)(this + 128) = 1203982208;
  *(_DWORD *)(this + 132) = 1203982208;
  *(_DWORD *)(this + 136) = 1203982208;
  *(_DWORD *)(this + 140) = 1203982208;
  *(_DWORD *)(this + 144) = 1203982208;
  *(_DWORD *)(this + 148) = 1203982208;
  *(_DWORD *)(this + 152) = 1203982208;
  *(_DWORD *)(this + 156) = 1203982208;
  *(_DWORD *)(this + 160) = 1203982208;
  *(_DWORD *)(this + 164) = 1203982208;
  if ( *(_BYTE *)(a2 + 44) )
  {
    *(float *)(this + 88) = *(float *)(a2 + 48) + *(float *)(a2 + 52);
    *(float *)(this + 92) = *(float *)(a2 + 48) + *(float *)(a2 + 52);
    *(_DWORD *)(this + 188) = *(_DWORD *)(a2 + 60);
    *(_DWORD *)(this + 192) = *(_DWORD *)(a2 + 60);
    v16 = *(float *)(a2 + 64) + *(float *)(a2 + 56) + *(float *)(this + 88) + *(float *)(a2 + 60);
    if ( v3 < v16 )
      v3 = v16;
  }
  else if ( *(_BYTE *)(a2 + 5) )
  {
    *(_DWORD *)(this + 96) = *(_DWORD *)a2;
  }
  if ( *(_BYTE *)(a2 + 4) )
  {
    if ( *(_BYTE *)(a2 + 5) )
    {
      if ( *(float *)(a2 + 8) >= (double)*(float *)(a2 + 12) )
        v4 = *(float *)(a2 + 12);
      else
        v4 = *(float *)(a2 + 8);
      *(float *)(this + 72) = v4;
      *(float *)(this + 64) = v4;
      *(_DWORD *)(this + 100) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(this + 112) = *(_DWORD *)(a2 + 12);
      if ( *(float *)(a2 + 8) <= (double)*(float *)(a2 + 12) )
        v5 = *(float *)(a2 + 12);
      else
        v5 = *(float *)(a2 + 8);
      v6 = v5 + *(float *)(a2 + 36) + *(float *)(a2 + 32);
      *(float *)(this + 68) = v6;
      *(float *)(this + 76) = v6;
      v17 = v6 + *(float *)(a2 + 40);
      if ( v3 < v17 )
        v3 = v17;
      *(_DWORD *)(this + 16) = 3;
    }
    else
    {
      if ( *(float *)(a2 + 8) >= (double)*(float *)(a2 + 12) )
        v7 = *(float *)(a2 + 12);
      else
        v7 = *(float *)(a2 + 8);
      *(float *)(this + 64) = v7;
      *(_DWORD *)(this + 104) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(this + 116) = *(_DWORD *)(a2 + 12);
      if ( *(float *)(a2 + 8) <= (double)*(float *)(a2 + 12) )
        v8 = *(float *)(a2 + 12);
      else
        v8 = *(float *)(a2 + 8);
      v9 = v8 + *(float *)(a2 + 36) + *(float *)(a2 + 32);
      *(float *)(this + 68) = v9;
      v18 = v9 + *(float *)(a2 + 40);
      if ( v3 < v18 )
        v3 = v18;
      *(_DWORD *)(this + 16) = 1;
    }
  }
  else if ( *(_BYTE *)(a2 + 5) )
  {
    if ( *(float *)(a2 + 8) >= (double)*(float *)(a2 + 12) )
      v10 = *(float *)(a2 + 12);
    else
      v10 = *(float *)(a2 + 8);
    *(float *)(this + 72) = v10;
    *(_DWORD *)(this + 108) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(this + 120) = *(_DWORD *)(a2 + 12);
    if ( *(float *)(a2 + 8) <= (double)*(float *)(a2 + 12) )
      v11 = *(float *)(a2 + 12);
    else
      v11 = *(float *)(a2 + 8);
    v12 = v11 + *(float *)(a2 + 36) + *(float *)(a2 + 32);
    *(float *)(this + 76) = v12;
    v19 = v12 + *(float *)(a2 + 40);
    if ( v3 < v19 )
      v3 = v19;
    *(_DWORD *)(this + 16) = 2;
  }
  else
  {
    *(_DWORD *)(this + 16) = 0;
  }
  v13 = *(_DWORD *)(this + 64);
  *(float *)(this + 172) = (*(float *)(a2 + 20) + 1.0) * 0.5;
  *(float *)(this + 176) = (*(float *)(a2 + 16) + 1.0) * 0.5;
  *(float *)(this + 180) = (*(float *)(a2 + 28) + 1.0) * 0.5;
  v14 = *(float *)(a2 + 24);
  *(_DWORD *)(this + 80) = 0;
  *(float *)(this + 184) = (v14 + 1.0) * 0.5;
  *(float *)(this + 84) = v3 - 3.5999999;
  if ( v13 == 1203982208 )
  {
    *(_DWORD *)(this + 64) = 0;
    v15 = v3 - *(float *)(a2 + 40) - 1.0;
    if ( v15 < 0.0 )
      v15 = 0.0;
    *(float *)(this + 68) = v15;
  }
}
