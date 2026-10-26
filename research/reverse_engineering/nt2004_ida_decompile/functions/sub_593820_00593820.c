char __thiscall sub_593820(int this, float a2, float a3, int a4)
{
  int v4; // eax
  double v5; // st7
  double v6; // st6
  long double v7; // st6
  long double v8; // st7
  long double v9; // st7
  long double v10; // st6
  long double v11; // st7
  long double v12; // st6
  char result; // al
  float v14; // [esp+4h] [ebp-8h]
  float v15; // [esp+8h] [ebp-4h]
  float v16; // [esp+10h] [ebp+4h]
  float v17; // [esp+10h] [ebp+4h]
  float v18; // [esp+14h] [ebp+8h]
  float v19; // [esp+18h] [ebp+Ch]

  LOWORD(v4) = a4;
  if ( !a4 )
    v4 = *(_DWORD *)(this + 128);
  switch ( v4 & 0xC5 )
  {
    case 1:
      if ( (v4 & 0x100) == 0 )
      {
        if ( (v4 & 0x200) == 0 )
          goto LABEL_14;
        v5 = a2 / *(float *)(this + 116);
        goto LABEL_15;
      }
      v5 = a3;
      v6 = (double)dword_7E8CEC / (double)dword_7E8CE8 * (a3 * *(float *)(this + 116));
      break;
    case 4:
      if ( (v4 & 0x100) == 0 )
      {
        v5 = (double)dword_7E8CEC / (double)dword_7E8CE8 * *(float *)(this + 116) * a2;
        goto LABEL_15;
      }
      v5 = a3;
      v6 = a3 / ((double)dword_7E8CEC / (double)dword_7E8CE8 / *(float *)(this + 116));
      break;
    case 0x40:
    case 0x80:
LABEL_14:
      v5 = a3;
      goto LABEL_15;
    default:
      if ( (v4 & 0x100) != 0 )
      {
        v5 = a3;
        v6 = 1.244 * a3 / ((double)dword_7E8CEC / (double)dword_7E8CE8 / *(float *)(this + 116));
      }
      else
      {
        v5 = a2 * 0.80385852;
LABEL_15:
        v6 = a2;
      }
      break;
  }
  *(float *)(this + 108) = v6;
  *(float *)(this + 112) = v5;
  v7 = v6 * 0.5;
  v16 = v7;
  v14 = tan(v7);
  *(float *)(this + 28) = v14;
  v8 = v5 * 0.5;
  v18 = v8;
  v15 = tan(v8);
  *(float *)(this + 32) = v15;
  v9 = sin(v16);
  v10 = cos(v16);
  v19 = sin(v18);
  v17 = cos(v18);
  *(float *)(this + 12) = (double)*(int *)(this + 84) * 0.5 / v14;
  *(float *)(this + 16) = (double)*(int *)(this + 88) * 0.5 / v15;
  *(_DWORD *)(this + 236) = 0;
  *(_DWORD *)(this + 240) = 0;
  *(_DWORD *)(this + 244) = -1082130432;
  *(float *)(this + 248) = -*(float *)(this + 8);
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 224) = 0;
  *(_DWORD *)(this + 228) = 1065353216;
  *(_DWORD *)(this + 232) = *(_DWORD *)(this + 4);
  *(float *)(this + 156) = -v10;
  *(float *)(this + 164) = v9;
  *(_DWORD *)(this + 160) = 0;
  *(_DWORD *)(this + 168) = 0;
  *(float *)(this + 172) = v10;
  *(_DWORD *)(this + 176) = 0;
  *(_DWORD *)(this + 184) = 0;
  *(float *)(this + 180) = v9;
  *(float *)(this + 192) = v17;
  *(_DWORD *)(this + 188) = 0;
  *(float *)(this + 196) = v19;
  *(_DWORD *)(this + 200) = 0;
  *(float *)(this + 208) = -v17;
  *(_DWORD *)(this + 204) = 0;
  *(_DWORD *)(this + 216) = 0;
  *(float *)(this + 212) = v19;
  v11 = tan(*(float *)(this + 108) * 0.5) * *(float *)(this + 8);
  v12 = tan(*(float *)(this + 112) * 0.5) * *(float *)(this + 8);
  result = *(_BYTE *)(this + 128);
  *(float *)(this + 120) = sqrt(v12 * v12 + v11 * v11);
  if ( (result & 0x10) != 0 )
    *(float *)(this + 12) = -*(float *)(this + 12);
  return result;
}
