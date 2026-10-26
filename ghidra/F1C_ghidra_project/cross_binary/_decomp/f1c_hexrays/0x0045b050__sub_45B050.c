// f1c  0x0045b050  size=419
int __thiscall sub_45B050(int this)
{
  double v1; // st7
  double v2; // st6
  long double v3; // st5
  double v5; // st4
  unsigned __int8 v6; // c0
  unsigned __int8 v7; // c2
  int v8; // edi
  long double v9; // st5
  double v10; // st7
  int v11; // ebx
  double v12; // st6
  double v13; // st7
  double v14; // st6
  double v15; // st7
  double v16; // st6
  double v17; // st7
  double v18; // st7
  double v19; // st6
  double v20; // st7
  double v21; // st6
  double v22; // st7
  double v23; // st6
  float v24; // edx
  int v25; // eax
  int result; // eax
  float v27; // [esp+Ch] [ebp-24h]
  double v28; // [esp+10h] [ebp-20h] BYREF
  int v29; // [esp+18h] [ebp-18h]
  int v30; // [esp+1Ch] [ebp-14h]
  float v31; // [esp+20h] [ebp-10h]
  int v32; // [esp+24h] [ebp-Ch]

  v28 = *(double *)(this + 264) * -1.0;
  v1 = *(double *)(this + 272) * -1.0;
  v2 = *(double *)(this + 280) * -1.0;
  v3 = sqrt(v2 * v2 + v1 * v1);
  v5 = *(double *)(this + 792);
  if ( v6 | v7 )
    v5 = -v5;
  *(float *)(this + 96) = v5;
  v8 = this + 100;
  if ( v3 == 0.0 )
  {
    *(_DWORD *)(this + 104) = 0;
    *(float *)v8 = *(double *)(this + 800);
  }
  else
  {
    v9 = *(double *)(this + 800) / v3;
    *(float *)v8 = v9 * v1;
    *(float *)(this + 104) = v9 * v2;
  }
  v10 = -*(float *)v8;
  v11 = 1;
  v12 = *(float *)(this + 104);
  v27 = v5;
  *(float *)(this + 108) = v27;
  *(float *)(this + 112) = v12;
  *(float *)(this + 116) = v10;
  v13 = -*(float *)(this + 104);
  v14 = -*(float *)v8;
  *(float *)(this + 120) = *(float *)(this + 96);
  *(float *)(this + 124) = v14;
  *(float *)(this + 128) = v13;
  v15 = *(float *)v8;
  v16 = -*(float *)(this + 104);
  *(float *)(this + 132) = *(float *)(this + 96);
  *(float *)(this + 136) = v16;
  *(float *)(this + 140) = v15;
  v17 = *(float *)(this + 96);
  *(_DWORD *)(this + 148) = 0;
  *(_DWORD *)(this + 152) = 0;
  *(float *)(this + 144) = v17;
  v18 = *(float *)(this + 104);
  v19 = *(float *)v8;
  *(float *)(this + 156) = -*(float *)(this + 96);
  *(float *)(this + 160) = v19;
  *(float *)(this + 164) = v18;
  v20 = *(float *)(this + 116);
  v21 = *(float *)(this + 112);
  *(float *)(this + 168) = *(float *)(this + 156);
  *(float *)(this + 172) = v21;
  *(float *)(this + 176) = v20;
  v22 = *(float *)(this + 140);
  v23 = *(float *)(this + 136);
  *(float *)(this + 180) = *(float *)(this + 156);
  *(float *)(this + 184) = v23;
  *(float *)(this + 188) = v22;
  do
  {
    v24 = *(float *)v8;
    v25 = *(_DWORD *)(v8 + 4);
    v30 = *(_DWORD *)(v8 - 4);
    v28 = 0.0;
    v29 = 0;
    v31 = v24;
    v32 = v25;
    result = sub_54FA00(&v28, v11++);
    v8 += 12;
  }
  while ( v11 <= 8 );
  return result;
}
