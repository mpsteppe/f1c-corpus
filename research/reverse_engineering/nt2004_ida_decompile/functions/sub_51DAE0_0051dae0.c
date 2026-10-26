void __thiscall sub_51DAE0(int this, int a2)
{
  double v2; // st7
  double v4; // st6
  int v5; // eax
  double v6; // st5
  double v8; // st4
  double v9; // st3
  int v10; // ecx
  int v11; // edx
  double v12; // st2
  double v13; // st1
  double v14; // st7
  float v15; // [esp+4h] [ebp-24h]
  float v16; // [esp+8h] [ebp-20h]
  int v17; // [esp+Ch] [ebp-1Ch]
  int v18; // [esp+10h] [ebp-18h] BYREF
  float v19; // [esp+14h] [ebp-14h]
  float v20; // [esp+18h] [ebp-10h]
  int v21; // [esp+1Ch] [ebp-Ch]
  float v22; // [esp+20h] [ebp-8h]
  float v23; // [esp+24h] [ebp-4h]
  float v24; // [esp+2Ch] [ebp+4h]
  float v25; // [esp+2Ch] [ebp+4h]

  v2 = 0.0;
  v4 = 0.0;
  v5 = *(_DWORD *)(this + 16500);
  v6 = 0.0;
  *(float *)&v18 = 0.0;
  v8 = 0.0;
  v15 = 0.0;
  v19 = 0.0;
  v20 = 0.0;
  if ( v5 )
  {
    v9 = 0.5;
  }
  else
  {
    if ( a2 == 22 )
    {
      sub_51D8D0((char *)this);
      v2 = (float)0.0;
      v4 = v2;
      v6 = *(float *)&v18;
      v8 = v19;
    }
    v9 = 0.82999998;
  }
  v10 = this + 17924;
  v11 = 4;
  do
  {
    if ( *(_DWORD *)v10 && *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v10 + 84) + 48) == a2 && v9 > *(float *)(v10 - 152) )
    {
      v24 = (v9 - *(float *)(v10 - 152)) * *(float *)(v10 - 156) * 0.00012207031;
      if ( v24 > (double)v15 )
        v15 = (v9 - *(float *)(v10 - 152)) * *(float *)(v10 - 156) * 0.00012207031;
      if ( v24 > 0.0 )
      {
        v2 = v2 + v24;
        v4 = v4 + (1.05 - *(float *)(v10 - 152) * 0.25 + *(float *)(v10 - 160) * 0.001953125) * v24;
        v12 = v24 * *(float *)(v10 - 220);
        v13 = v24 * *(float *)(v10 - 216);
        v23 = v24 * *(float *)(v10 - 212);
        v6 = v6 + v12;
        v8 = v8 + v13;
        v20 = v23 + v20;
      }
    }
    v10 += 248;
    --v11;
  }
  while ( v11 );
  v19 = v8;
  *(float *)&v18 = v6;
  if ( v15 > 0.001 )
  {
    v14 = 1.0 / v2;
    *(float *)&v21 = *(float *)&v18 * v14;
    v18 = v21;
    v22 = v19 * v14;
    v19 = v22;
    v23 = v14 * v20;
    v20 = v23;
    if ( v15 <= 1.0 )
      v25 = v15;
    else
      v25 = 1.0;
    v16 = v4;
    *(float *)&v17 = v16 * v14;
    sub_5260E0(a2, 2, v25, v17, (int)&v18);
  }
}
