void __thiscall sub_579170(int this)
{
  double v2; // st7
  float *v3; // ecx
  double v4; // st7
  double v5; // st7
  double v6; // st7
  double v7; // st7
  double v8; // st7
  int v9; // ebx
  float *v10; // edi
  int v11; // eax
  int v12; // eax
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // eax
  double v17; // st7
  double v18; // st7
  int v19; // ecx
  double v20; // st7
  float v21; // [esp+Ch] [ebp-2Ch]
  float v22; // [esp+Ch] [ebp-2Ch]
  float v23; // [esp+10h] [ebp-28h]
  float v24; // [esp+14h] [ebp-24h]
  float v25; // [esp+14h] [ebp-24h]
  float v26; // [esp+18h] [ebp-20h]
  float v27; // [esp+18h] [ebp-20h]
  float v28; // [esp+1Ch] [ebp-1Ch]
  float v29; // [esp+1Ch] [ebp-1Ch]
  float v30; // [esp+20h] [ebp-18h]
  float v31; // [esp+20h] [ebp-18h]
  float v32; // [esp+20h] [ebp-18h]
  float v33; // [esp+20h] [ebp-18h]
  float v34; // [esp+20h] [ebp-18h]
  float v35; // [esp+24h] [ebp-14h]
  float v36; // [esp+24h] [ebp-14h]
  float v37; // [esp+24h] [ebp-14h]
  float v38; // [esp+24h] [ebp-14h]
  float v39; // [esp+24h] [ebp-14h]
  float v40; // [esp+28h] [ebp-10h]
  float v41; // [esp+28h] [ebp-10h]
  float v42; // [esp+28h] [ebp-10h]
  float v43; // [esp+28h] [ebp-10h]
  float v44; // [esp+28h] [ebp-10h]
  _DWORD v45[3]; // [esp+2Ch] [ebp-Ch] BYREF

  v2 = *(float *)(this + 16040);
  v3 = (float *)(this + 16084);
  v24 = v2 * *(float *)(this + 16096);
  v26 = v2 * *(float *)(this + 16100);
  v4 = v2 * *(float *)(this + 16104);
  *v3 = v24;
  v3[1] = v26;
  v28 = v4;
  v3[2] = v28;
  *(float *)(this + 16072) = *(float *)(this + 15944) * v3[2]
                           + *(float *)(this + 15940) * v3[1]
                           + *(float *)(this + 15936) * *v3;
  *(float *)(this + 16076) = *(float *)(this + 15956) * v3[2]
                           + *(float *)(this + 15952) * v3[1]
                           + *(float *)(this + 15948) * *v3;
  *(float *)(this + 16080) = *(float *)(this + 15968) * v3[2]
                           + *(float *)(this + 15964) * v3[1]
                           + *(float *)(this + 15960) * *v3;
  v5 = *(float *)(this + 15928);
  v25 = v5 * *(float *)(this + 15996);
  v27 = v5 * *(float *)(this + 16000);
  v29 = v5 * *(float *)(this + 16004);
  *(float *)(this + 15972) = v25 + *(float *)(this + 15972);
  *(float *)(this + 15976) = v27 + *(float *)(this + 15976);
  *(float *)(this + 15980) = v29 + *(float *)(this + 15980);
  v6 = *(float *)(this + 15928);
  v30 = v6 * *(float *)(this + 16072);
  v35 = v6 * *(float *)(this + 16076);
  v40 = v6 * *(float *)(this + 16080);
  *(float *)(this + 15996) = v30 + *(float *)(this + 15996);
  *(float *)(this + 16000) = v35 + *(float *)(this + 16000);
  *(float *)(this + 16004) = v40 + *(float *)(this + 16004);
  v7 = *(float *)(this + 15928);
  v31 = v7 * *(float *)(this + 16020);
  *(float *)v45 = v31;
  v36 = v7 * *(float *)(this + 16024);
  *(float *)&v45[1] = v36;
  v41 = v7 * *(float *)(this + 16028);
  *(float *)&v45[2] = v41;
  sub_614F40(v45);
  sub_40D5D0((float *)(this + 15936), this + 15984);
  v32 = *(float *)(this + 16108) * *(float *)(this + 16120);
  v37 = *(float *)(this + 16124) * *(float *)(this + 16112);
  v42 = *(float *)(this + 16128) * *(float *)(this + 16116);
  v33 = v32 * *(float *)(this + 16056);
  v38 = v37 * *(float *)(this + 16060);
  v43 = v42 * *(float *)(this + 16064);
  v8 = *(float *)(this + 15928);
  v34 = v33 * v8;
  v9 = 4;
  v39 = v38 * v8;
  v44 = v43 * v8;
  *(float *)(this + 16020) = v34 + *(float *)(this + 16020);
  *(float *)(this + 16024) = v39 + *(float *)(this + 16024);
  *(float *)(this + 16028) = v44 + *(float *)(this + 16028);
  *(float *)(this + 16008) = *(float *)(this + 15960) * *(float *)(this + 16004)
                           + *(float *)(this + 15948) * *(float *)(this + 16000)
                           + *(float *)(this + 15996) * *(float *)(this + 15936);
  *(float *)(this + 16012) = *(float *)(this + 15940) * *(float *)(this + 15996)
                           + *(float *)(this + 15964) * *(float *)(this + 16004)
                           + *(float *)(this + 15952) * *(float *)(this + 16000);
  v10 = (float *)(this + 16148);
  *(float *)(this + 16016) = *(float *)(this + 15944) * *(float *)(this + 15996)
                           + *(float *)(this + 15968) * *(float *)(this + 16004)
                           + *(float *)(this + 15956) * *(float *)(this + 16000);
  do
  {
    sub_5744A0(v10);
    v10 += 63;
    --v9;
  }
  while ( v9 );
  v11 = *(_DWORD *)(this + 17244);
  if ( !v11 )
  {
    v13 = *(float *)(this + 16952) + *(float *)(this + 16700);
    goto LABEL_9;
  }
  v12 = v11 - 1;
  if ( !v12 )
  {
    v14 = (*(float *)(this + 16952) + *(float *)(this + 16700) + *(float *)(this + 16448) + *(float *)(this + 16196))
        * 0.25;
LABEL_10:
    *(float *)(this + 17160) = v14;
    goto LABEL_11;
  }
  if ( v12 == 1 )
  {
    v13 = *(float *)(this + 16448) + *(float *)(this + 16196);
LABEL_9:
    v14 = v13 * 0.5;
    goto LABEL_10;
  }
LABEL_11:
  v21 = -(*(float *)(this + 17264) * *(float *)(this + 17160));
  v15 = *(float *)(this + 17180);
  *(float *)(this + 17160) = v21;
  if ( v15 <= 0.0 || *(float *)(this + 17212) == 0.0 )
  {
    if ( *(float *)(this + 17212) <= 0.0
      || (v20 = *(float *)(this + 17224) * *(float *)(this + 17204) * *(float *)(this + 15928)
              + *(float *)(this + 17212),
          *(float *)(this + 17212) = v20,
          v20 < 0.0) )
    {
      *(_DWORD *)(this + 17212) = 0;
    }
  }
  else
  {
    v16 = *(_DWORD *)(this + 17304);
    if ( v16 )
    {
      if ( v16 == 1 && *(_BYTE *)(this + 17301) )
      {
        v17 = (*(float *)(this + 17208) - *(float *)(this + 17220)) * *(float *)(this + 16132)
            + *(float *)(this + 17220);
        v23 = v17;
        if ( v17 < *(float *)(this + 17212) )
        {
          v22 = *(float *)(this + 17204)
              * *(float *)(this + 15928)
              * sub_573930((_DWORD *)(this + 17228), *(float *)(this + 17212), 0.0)
              + *(float *)(this + 17212);
          v18 = v23;
          if ( v23 < (double)v22 )
            v18 = v22;
        }
        else
        {
          v18 = *(float *)(this + 17212);
        }
        if ( v18 > *(float *)(this + 17332) )
          v18 = *(float *)(this + 17332);
        if ( v18 <= *(float *)(this + 17160) )
        {
          v19 = *(_DWORD *)(this + 17160);
          *(_BYTE *)(this + 17301) = 0;
          *(_DWORD *)(this + 17212) = v19;
        }
        else
        {
          *(float *)(this + 17212) = v18;
        }
      }
      else
      {
        *(float *)(this + 17212) = v21;
      }
    }
    else
    {
      *(float *)(this + 17212) = *(float *)(this + 17224) * *(float *)(this + 17204) * *(float *)(this + 15928)
                               + *(float *)(this + 17212);
    }
    if ( *(float *)(this + 17212) >= (double)*(float *)(this + 17220) )
    {
      if ( *(float *)(this + 17212) > (double)*(float *)(this + 17216) )
        *(_DWORD *)(this + 17212) = *(_DWORD *)(this + 17216);
    }
    else
    {
      *(_DWORD *)(this + 17212) = *(_DWORD *)(this + 17220);
    }
  }
}
