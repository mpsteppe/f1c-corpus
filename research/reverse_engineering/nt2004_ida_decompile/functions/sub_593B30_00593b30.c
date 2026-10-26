void __thiscall sub_593B30(int this, float a2, float a3, float a4, float a5, int a6)
{
  double v7; // st7
  double v8; // st6
  double v9; // st6
  double v10; // st7
  int v11; // edi
  int v12; // ecx
  double v13; // st7
  double v14; // st6
  double v15; // st7
  int v16; // [esp+Ch] [ebp+4h]
  int v17; // [esp+14h] [ebp+Ch]
  float v18; // [esp+14h] [ebp+Ch]
  int v19; // [esp+18h] [ebp+10h]
  float v20; // [esp+1Ch] [ebp+14h]
  int v21; // [esp+1Ch] [ebp+14h]

  if ( a6 )
  {
    v7 = 1.0;
    v20 = 1.0;
    if ( a4 >= 0.0 )
      *(_DWORD *)(this + 84) = (__int64)a4;
    else
      *(_DWORD *)(this + 84) = 0;
    goto LABEL_4;
  }
  v7 = (double)dword_7E8CE8;
  v20 = (float)dword_7E8CEC;
  if ( a4 <= 1.0 )
    a4 = a4 * v7;
  if ( a5 <= 1.0 )
    a5 = v20 * a5;
  if ( a4 <= v7 )
  {
    if ( a4 < 0.0 )
    {
      *(_DWORD *)(this + 84) = 0;
      goto LABEL_17;
    }
    v8 = a4;
  }
  else
  {
    v8 = v7;
  }
  *(_DWORD *)(this + 84) = (__int64)v8;
LABEL_17:
  if ( a5 > (double)v20 )
  {
    v9 = v20;
    goto LABEL_20;
  }
LABEL_4:
  if ( a5 < 0.0 )
  {
    *(_DWORD *)(this + 88) = 0;
    goto LABEL_21;
  }
  v9 = a5;
LABEL_20:
  *(_DWORD *)(this + 88) = (__int64)v9;
LABEL_21:
  if ( a2 <= 1.0 )
    a2 = v7 * a2;
  v10 = a3;
  if ( a3 <= 1.0 )
    v10 = v10 * v20;
  v11 = (__int64)a2;
  *(_DWORD *)(this + 104) = v11;
  v16 = *(_DWORD *)(this + 84);
  v17 = v11 + (v16 >> 1);
  *(_DWORD *)(this + 92) = v17;
  v21 = *(_DWORD *)(this + 88);
  *(float *)(this + 20) = (float)v17;
  *(_DWORD *)(this + 100) = (__int64)v10;
  v19 = (v21 >> 1) + (__int64)v10;
  v12 = *(_DWORD *)(this + 128);
  *(_DWORD *)(this + 96) = v19;
  *(float *)(this + 24) = (float)v19;
  v13 = (double)v16;
  v18 = 0.5 * v13 / *(float *)(this + 28);
  *(float *)(this + 12) = v18;
  v14 = (double)v21;
  *(float *)(this + 16) = 0.5 * v14 / *(float *)(this + 32);
  v15 = v13 / v14;
  *(float *)(this + 116) = v15;
  if ( (v12 & 0xC5) == 0 && v15 >= 1.323333333333333 && v15 <= 1.343333333333333 )
    *(_DWORD *)(this + 128) = v12 & 0xFFFFFF3A;
  if ( (*(_BYTE *)(this + 128) & 0x10) != 0 )
    *(float *)(this + 12) = -v18;
}
