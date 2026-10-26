void __thiscall sub_423380(int this)
{
  double v1; // st7
  float *v2; // eax
  double v3; // st6
  long double v4; // st7
  double v5; // st7
  int v6; // eax
  double v7; // st7
  double v8; // st6
  float *v9; // eax
  long double v10; // st7
  double v11; // st7
  int v12; // eax
  unsigned __int8 v14; // c0
  unsigned __int8 v15; // c3
  float v16; // [esp+4h] [ebp-1Ch]
  float v17; // [esp+8h] [ebp-18h]
  float v18; // [esp+8h] [ebp-18h]
  float v19; // [esp+Ch] [ebp-14h]
  float v20; // [esp+10h] [ebp-10h]
  float v21; // [esp+10h] [ebp-10h]
  float v22; // [esp+14h] [ebp-Ch]

  dword_62BC10 = 0;
  flt_62BBDC = -(*(float *)(*(_DWORD *)(this + 23432) + 64) * *(float *)(this + 23880)
               - *(float *)(*(_DWORD *)(this + 23432) + 60) * *(float *)(this + 23884));
  flt_62A3B8 = *(float *)(*(_DWORD *)(this + 23432) + 64) * *(float *)(this + 23876)
             - *(float *)(*(_DWORD *)(this + 23432) + 56) * *(float *)(this + 23884);
  flt_62BBC8 = -(*(float *)(*(_DWORD *)(this + 23432) + 60) * *(float *)(this + 23876)
               - *(float *)(*(_DWORD *)(this + 23432) + 56) * *(float *)(this + 23880));
  dword_62BBC4 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 196);
  dword_62BBE0 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 200);
  dword_62BBE4 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 204);
  dword_62A394 = *(_DWORD *)(this + 17604);
  dword_62BBFC = *(_DWORD *)(this + 17608);
  dword_62BC0C = *(_DWORD *)(this + 17612);
  dword_62BC20 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 44);
  dword_62A3A0 = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 48);
  dword_62A3AC = *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 52);
  if ( *(_DWORD *)(*(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432) + 328)
    || !*(_BYTE *)(this + 24208)
    || (v1 = *(float *)&dword_62A3AC * flt_62BBC8
           + *(float *)&dword_62A3A0 * flt_62A3B8
           + *(float *)&dword_62BC20 * flt_62BBDC,
        *(float *)&dword_62BC10 = v1,
        v1 <= 0.1) )
  {
    if ( *(float *)(this + 23764) >= 15.0 )
    {
      v7 = 0.0;
      v8 = 0.0;
    }
    else
    {
      v6 = *(_DWORD *)(this + 4 * *(_DWORD *)(this + 23828) + 23432);
      v7 = *(float *)(v6 + 212) * *(float *)(this + 23912);
      v8 = *(float *)(v6 + 220) * *(float *)(this + 23912);
    }
    v9 = *(float **)(this + 4 * *(_DWORD *)(this + 23828) + 23432);
    v18 = v9[11] * *(float *)(this + 23620) + v9[49] + v7 - *(float *)(this + 17604);
    v21 = v9[13] * *(float *)(this + 23620) + v9[51] + v8 - *(float *)(this + 17612);
    v10 = (v21 * *(float *)(this + 23884) + v18 * *(float *)(this + 23876)) / sqrt(v21 * v21 + v18 * v18);
    if ( v10 >= 1.0 )
    {
      v5 = 0.0;
      goto LABEL_16;
    }
    v16 = v10;
    v11 = acos(v16);
    if ( v21 * *(float *)(this + 23876) - v18 * *(float *)(this + 23884) > 0.0 )
      v11 = -v11;
    v5 = v11 / *(float *)(this + 23960);
  }
  else
  {
    flt_62A3A4 = ((*(float *)&dword_62BC0C - *(float *)&dword_62BBE4) * flt_62BBC8
                + (*(float *)&dword_62BBFC - *(float *)&dword_62BBE0) * flt_62A3B8
                + (*(float *)&dword_62A394 - *(float *)&dword_62BBC4) * flt_62BBDC)
               / *(float *)&dword_62BC10;
    v2 = *(float **)(this + 4 * *(_DWORD *)(this + 23828) + 23432);
    v20 = flt_62A3A4 * v2[13];
    v22 = flt_62A3A4 * v2[11] + v2[49];
    v17 = v22 - *(float *)(this + 17604);
    v19 = flt_62A3A4 * v2[12] + v2[50] - *(float *)(this + 17608);
    v3 = v20 + v2[51] - *(float *)(this + 17612);
    flt_62BF54 = sqrt(v3 * v3 + v19 * v19 + v17 * v17);
    v4 = *(float *)(this + 23620) - flt_62A3A4;
    flt_62BBC0 = v4;
    v5 = atan2(v4, flt_62BF54) / (*(float *)(this + 23960) * 0.98000002);
  }
  v12 = *(_DWORD *)(this + 24020);
  if ( v12 == 3 || v12 == 1 )
    v5 = -v5;
LABEL_16:
  *(float *)(this + 23732) = v5;
  if ( v14 | v15 )
  {
    if ( v5 < -1.0 )
      *(_DWORD *)(this + 23732) = -1082130432;
  }
  else
  {
    *(_DWORD *)(this + 23732) = 1065353216;
  }
  if ( *(float *)(this + 23732) > 1.0 || *(float *)(this + 23732) < -1.0 )
    *(_DWORD *)(this + 23732) = 0;
}
