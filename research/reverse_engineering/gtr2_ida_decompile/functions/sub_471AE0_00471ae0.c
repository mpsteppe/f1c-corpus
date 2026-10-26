int __thiscall sub_471AE0(int this)
{
  double v2; // st7
  double v3; // st6
  long double v4; // st5
  double v6; // st4
  unsigned __int8 v7; // c0
  unsigned __int8 v8; // c2
  int v9; // edi
  long double v10; // st5
  double v11; // st7
  int v12; // ebx
  double v13; // st6
  double v14; // st7
  double v15; // st6
  double v16; // st7
  double v17; // st6
  double v18; // st7
  double v19; // st6
  double v20; // st7
  double v21; // st6
  double v22; // st7
  double v23; // st6
  int v24; // ecx
  float v25; // eax
  int v26; // ecx
  int result; // eax
  float v28; // [esp+Ch] [ebp-24h]
  int v29[2]; // [esp+10h] [ebp-20h] BYREF
  int v30; // [esp+18h] [ebp-18h]
  int v31; // [esp+1Ch] [ebp-14h]
  float v32; // [esp+20h] [ebp-10h]
  int v33; // [esp+24h] [ebp-Ch]

  *(double *)v29 = *(double *)(this + 280) * -1.0;
  v2 = *(double *)(this + 288) * -1.0;
  v3 = *(double *)(this + 296) * -1.0;
  v4 = sqrt(v3 * v3 + v2 * v2);
  v6 = *(double *)(this + 808);
  if ( v7 | v8 )
    v6 = -v6;
  *(float *)(this + 104) = v6;
  v9 = this + 108;
  if ( v4 == 0.0 )
  {
    *(_DWORD *)(this + 112) = 0;
    *(float *)v9 = *(double *)(this + 816);
  }
  else
  {
    v10 = *(double *)(this + 816) / v4;
    *(float *)v9 = v10 * v2;
    *(float *)(this + 112) = v10 * v3;
  }
  v11 = -*(float *)v9;
  v12 = 1;
  v13 = *(float *)(this + 112);
  v28 = v6;
  *(float *)(this + 116) = v28;
  *(float *)(this + 120) = v13;
  *(float *)(this + 124) = v11;
  v14 = -*(float *)(this + 112);
  v15 = *(float *)v9;
  *(_DWORD *)(this + 128) = *(_DWORD *)(this + 104);
  *(float *)(this + 132) = -v15;
  *(float *)(this + 136) = v14;
  v16 = *(float *)v9;
  v17 = *(float *)(this + 112);
  *(_DWORD *)(this + 140) = *(_DWORD *)(this + 104);
  *(float *)(this + 144) = -v17;
  *(float *)(this + 148) = v16;
  *(_DWORD *)(this + 152) = *(_DWORD *)(this + 104);
  *(_DWORD *)(this + 156) = 0;
  *(_DWORD *)(this + 160) = 0;
  v18 = *(float *)(this + 112);
  v19 = *(float *)v9;
  *(float *)(this + 164) = -*(float *)(this + 104);
  *(float *)(this + 168) = v19;
  *(float *)(this + 172) = v18;
  v20 = *(float *)(this + 124);
  v21 = *(float *)(this + 120);
  *(_DWORD *)(this + 176) = *(_DWORD *)(this + 164);
  *(float *)(this + 180) = v21;
  *(float *)(this + 184) = v20;
  v22 = *(float *)(this + 148);
  v23 = *(float *)(this + 144);
  *(_DWORD *)(this + 188) = *(_DWORD *)(this + 164);
  *(float *)(this + 192) = v23;
  *(float *)(this + 196) = v22;
  do
  {
    v24 = *(_DWORD *)(v9 + 4);
    v25 = *(float *)v9;
    v31 = *(_DWORD *)(v9 - 4);
    v33 = v24;
    v26 = *(_DWORD *)(this + 216);
    v29[0] = 0;
    v29[1] = 0;
    v30 = 0;
    v32 = v25;
    result = sub_5ED900(v26, (int)v29, v12++);
    v9 += 12;
  }
  while ( v12 <= 8 );
  return result;
}
