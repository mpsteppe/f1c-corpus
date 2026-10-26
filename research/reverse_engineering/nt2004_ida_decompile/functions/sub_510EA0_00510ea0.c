void __thiscall sub_510EA0(int this)
{
  double v2; // st7
  float *v3; // ecx
  double v4; // st7
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st6
  double v9; // st5
  int v10; // ebx
  float *v11; // edi
  int v12; // eax
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  int v17; // eax
  double v18; // st7
  double v19; // st7
  float v20; // [esp+Ch] [ebp-28h]
  float v21; // [esp+10h] [ebp-24h]
  float v22; // [esp+10h] [ebp-24h]
  float v23; // [esp+10h] [ebp-24h]
  float v24; // [esp+14h] [ebp-20h]
  float v25; // [esp+14h] [ebp-20h]
  float v26; // [esp+14h] [ebp-20h]
  float v27; // [esp+14h] [ebp-20h]
  float v28; // [esp+14h] [ebp-20h]
  float v29; // [esp+18h] [ebp-1Ch]
  float v30; // [esp+18h] [ebp-1Ch]
  float v31; // [esp+18h] [ebp-1Ch]
  float v32; // [esp+18h] [ebp-1Ch]
  float v33; // [esp+18h] [ebp-1Ch]
  _DWORD v34[3]; // [esp+1Ch] [ebp-18h] BYREF
  float v35; // [esp+28h] [ebp-Ch]

  v2 = *(float *)(this + 17588);
  v3 = (float *)(this + 17628);
  v21 = v2 * *(float *)(this + 17640);
  v24 = v2 * *(float *)(this + 17644);
  v4 = v2 * *(float *)(this + 17648);
  *v3 = v21;
  v3[1] = v24;
  v29 = v4;
  v3[2] = v29;
  *(float *)(this + 17616) = *(float *)(this + 17492) * v3[2]
                           + *(float *)(this + 17488) * v3[1]
                           + *v3 * *(float *)(this + 17484);
  *(float *)(this + 17620) = *(float *)(this + 17496) * *v3
                           + *(float *)(this + 17504) * v3[2]
                           + *(float *)(this + 17500) * v3[1];
  *(float *)(this + 17624) = *(float *)(this + 17508) * *v3
                           + *(float *)(this + 17516) * v3[2]
                           + *(float *)(this + 17512) * v3[1];
  v25 = *(float *)(this + 17476) * *(float *)(this + 17548);
  v30 = *(float *)(this + 17476) * *(float *)(this + 17552);
  *(float *)(this + 17520) = *(float *)(this + 17476) * *(float *)(this + 17544) + *(float *)(this + 17520);
  *(float *)(this + 17524) = v25 + *(float *)(this + 17524);
  *(float *)(this + 17528) = v30 + *(float *)(this + 17528);
  v26 = *(float *)(this + 17476) * *(float *)(this + 17620);
  v31 = *(float *)(this + 17476) * *(float *)(this + 17624);
  *(float *)(this + 17544) = *(float *)(this + 17476) * *(float *)(this + 17616) + *(float *)(this + 17544);
  *(float *)(this + 17548) = v26 + *(float *)(this + 17548);
  *(float *)(this + 17552) = v31 + *(float *)(this + 17552);
  v5 = *(float *)(this + 17476);
  v22 = v5 * *(float *)(this + 17568);
  *(float *)v34 = v22;
  v27 = v5 * *(float *)(this + 17572);
  *(float *)&v34[1] = v27;
  v32 = v5 * *(float *)(this + 17576);
  *(float *)&v34[2] = v32;
  sub_579930(v34, this + 17532);
  v6 = *(float *)(this + 17656) * *(float *)(this + 17668);
  v33 = *(float *)(this + 17660) * *(float *)(this + 17672);
  v35 = *(float *)(this + 17652) * *(float *)(this + 17664) * *(float *)(this + 17604);
  v7 = v6 * *(float *)(this + 17608);
  v8 = v33 * *(float *)(this + 17612);
  v9 = *(float *)(this + 17476);
  v23 = v35 * v9;
  v28 = v7 * v9;
  *(float *)(this + 17568) = v23 + *(float *)(this + 17568);
  *(float *)(this + 17572) = v28 + *(float *)(this + 17572);
  *(float *)(this + 17576) = v9 * v8 + *(float *)(this + 17576);
  *(float *)(this + 17556) = *(float *)(this + 17508) * *(float *)(this + 17552)
                           + *(float *)(this + 17496) * *(float *)(this + 17548)
                           + *(float *)(this + 17484) * *(float *)(this + 17544);
  v10 = 4;
  *(float *)(this + 17560) = *(float *)(this + 17512) * *(float *)(this + 17552)
                           + *(float *)(this + 17500) * *(float *)(this + 17548)
                           + *(float *)(this + 17488) * *(float *)(this + 17544);
  v11 = (float *)(this + 17692);
  *(float *)(this + 17564) = *(float *)(this + 17516) * *(float *)(this + 17552)
                           + *(float *)(this + 17504) * *(float *)(this + 17548)
                           + *(float *)(this + 17492) * *(float *)(this + 17544);
  do
  {
    sub_50F760(v11);
    v11 += 62;
    --v10;
  }
  while ( v10 );
  v12 = *(_DWORD *)(this + 18768);
  if ( !v12 )
  {
    v14 = *(float *)(this + 18484) + *(float *)(this + 18236);
    goto LABEL_9;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    v15 = (*(float *)(this + 18484) + *(float *)(this + 18236) + *(float *)(this + 17988) + *(float *)(this + 17740))
        * 0.25;
LABEL_10:
    *(float *)(this + 18688) = v15;
    goto LABEL_11;
  }
  if ( v13 == 1 )
  {
    v14 = *(float *)(this + 17988) + *(float *)(this + 17740);
LABEL_9:
    v15 = v14 * 0.5;
    goto LABEL_10;
  }
LABEL_11:
  v20 = -(*(float *)(this + 18788) * *(float *)(this + 18688));
  v16 = *(float *)(this + 18708);
  *(float *)(this + 18688) = v20;
  if ( v16 <= 0.0 || *(float *)(this + 18736) == 0.0 )
  {
    if ( *(float *)(this + 18736) <= 0.0
      || (v19 = *(float *)(this + 18748) * *(float *)(this + 18728) * *(float *)(this + 17476)
              + *(float *)(this + 18736),
          *(float *)(this + 18736) = v19,
          v19 < 0.0) )
    {
      *(_DWORD *)(this + 18736) = 0;
    }
  }
  else
  {
    v17 = *(_DWORD *)(this + 18828);
    if ( v17 )
    {
      if ( v17 == 1 && *(_BYTE *)(this + 18825) )
      {
        v18 = (*(float *)(this + 18732) - *(float *)(this + 18744)) * *(float *)(this + 17676)
            + *(float *)(this + 18744);
        if ( *(float *)(this + 18736) < v18 )
          v18 = *(float *)(this + 18736);
        if ( v18 <= v20 )
          *(float *)(this + 18736) = v20;
        else
          *(float *)(this + 18736) = v18;
      }
      else
      {
        *(float *)(this + 18736) = v20;
      }
    }
    else
    {
      *(float *)(this + 18736) = *(float *)(this + 18748) * *(float *)(this + 18728) * *(float *)(this + 17476)
                               + *(float *)(this + 18736);
    }
    if ( *(float *)(this + 18736) >= (double)*(float *)(this + 18744) )
    {
      if ( *(float *)(this + 18736) > (double)*(float *)(this + 18740) )
        *(_DWORD *)(this + 18736) = *(_DWORD *)(this + 18740);
    }
    else
    {
      *(_DWORD *)(this + 18736) = *(_DWORD *)(this + 18744);
    }
  }
}
