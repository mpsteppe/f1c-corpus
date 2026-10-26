void __thiscall sub_4E5AE0(int this)
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

  v2 = *(float *)(this + 13592);
  v3 = (float *)(this + 13632);
  v21 = v2 * *(float *)(this + 13644);
  v24 = v2 * *(float *)(this + 13648);
  v4 = v2 * *(float *)(this + 13652);
  *v3 = v21;
  v3[1] = v24;
  v29 = v4;
  v3[2] = v29;
  *(float *)(this + 13620) = *(float *)(this + 13496) * v3[2]
                           + *(float *)(this + 13492) * v3[1]
                           + *v3 * *(float *)(this + 13488);
  *(float *)(this + 13624) = *(float *)(this + 13500) * *v3
                           + *(float *)(this + 13508) * v3[2]
                           + *(float *)(this + 13504) * v3[1];
  *(float *)(this + 13628) = *(float *)(this + 13512) * *v3
                           + *(float *)(this + 13520) * v3[2]
                           + *(float *)(this + 13516) * v3[1];
  v25 = *(float *)(this + 13480) * *(float *)(this + 13552);
  v30 = *(float *)(this + 13480) * *(float *)(this + 13556);
  *(float *)(this + 13524) = *(float *)(this + 13480) * *(float *)(this + 13548) + *(float *)(this + 13524);
  *(float *)(this + 13528) = v25 + *(float *)(this + 13528);
  *(float *)(this + 13532) = v30 + *(float *)(this + 13532);
  v26 = *(float *)(this + 13480) * *(float *)(this + 13624);
  v31 = *(float *)(this + 13480) * *(float *)(this + 13628);
  *(float *)(this + 13548) = *(float *)(this + 13480) * *(float *)(this + 13620) + *(float *)(this + 13548);
  *(float *)(this + 13552) = v26 + *(float *)(this + 13552);
  *(float *)(this + 13556) = v31 + *(float *)(this + 13556);
  v5 = *(float *)(this + 13480);
  v22 = v5 * *(float *)(this + 13572);
  *(float *)v34 = v22;
  v27 = v5 * *(float *)(this + 13576);
  *(float *)&v34[1] = v27;
  v32 = v5 * *(float *)(this + 13580);
  *(float *)&v34[2] = v32;
  sub_567120(v34, this + 13536);
  v6 = *(float *)(this + 13660) * *(float *)(this + 13672);
  v33 = *(float *)(this + 13664) * *(float *)(this + 13676);
  v35 = *(float *)(this + 13656) * *(float *)(this + 13668) * *(float *)(this + 13608);
  v7 = v6 * *(float *)(this + 13612);
  v8 = v33 * *(float *)(this + 13616);
  v9 = *(float *)(this + 13480);
  v23 = v35 * v9;
  v28 = v7 * v9;
  *(float *)(this + 13572) = v23 + *(float *)(this + 13572);
  *(float *)(this + 13576) = v28 + *(float *)(this + 13576);
  *(float *)(this + 13580) = v9 * v8 + *(float *)(this + 13580);
  *(float *)(this + 13560) = *(float *)(this + 13512) * *(float *)(this + 13556)
                           + *(float *)(this + 13500) * *(float *)(this + 13552)
                           + *(float *)(this + 13488) * *(float *)(this + 13548);
  v10 = 4;
  *(float *)(this + 13564) = *(float *)(this + 13516) * *(float *)(this + 13556)
                           + *(float *)(this + 13504) * *(float *)(this + 13552)
                           + *(float *)(this + 13492) * *(float *)(this + 13548);
  v11 = (float *)(this + 13696);
  *(float *)(this + 13568) = *(float *)(this + 13520) * *(float *)(this + 13556)
                           + *(float *)(this + 13508) * *(float *)(this + 13552)
                           + *(float *)(this + 13496) * *(float *)(this + 13548);
  do
  {
    sub_4E43D0(v11);
    v11 += 62;
    --v10;
  }
  while ( v10 );
  v12 = *(_DWORD *)(this + 14772);
  if ( !v12 )
  {
    v14 = *(float *)(this + 14488) + *(float *)(this + 14240);
    goto LABEL_9;
  }
  v13 = v12 - 1;
  if ( !v13 )
  {
    v15 = (*(float *)(this + 14488) + *(float *)(this + 14240) + *(float *)(this + 13992) + *(float *)(this + 13744))
        * 0.25;
LABEL_10:
    *(float *)(this + 14692) = v15;
    goto LABEL_11;
  }
  if ( v13 == 1 )
  {
    v14 = *(float *)(this + 13992) + *(float *)(this + 13744);
LABEL_9:
    v15 = v14 * 0.5;
    goto LABEL_10;
  }
LABEL_11:
  v20 = -(*(float *)(this + 14792) * *(float *)(this + 14692));
  v16 = *(float *)(this + 14712);
  *(float *)(this + 14692) = v20;
  if ( v16 <= 0.0 || *(float *)(this + 14740) == 0.0 )
  {
    if ( *(float *)(this + 14740) <= 0.0
      || (v19 = *(float *)(this + 14752) * *(float *)(this + 14732) * *(float *)(this + 13480)
              + *(float *)(this + 14740),
          *(float *)(this + 14740) = v19,
          v19 < 0.0) )
    {
      *(_DWORD *)(this + 14740) = 0;
    }
  }
  else
  {
    v17 = *(_DWORD *)(this + 14832);
    if ( v17 )
    {
      if ( v17 == 1 && *(_BYTE *)(this + 14828) )
      {
        v18 = (*(float *)(this + 14736) - *(float *)(this + 14748)) * *(float *)(this + 13680)
            + *(float *)(this + 14748);
        if ( *(float *)(this + 14740) < v18 )
          v18 = *(float *)(this + 14740);
        if ( v18 <= v20 )
          *(float *)(this + 14740) = v20;
        else
          *(float *)(this + 14740) = v18;
      }
      else
      {
        *(float *)(this + 14740) = v20;
      }
    }
    else
    {
      *(float *)(this + 14740) = *(float *)(this + 14752) * *(float *)(this + 14732) * *(float *)(this + 13480)
                               + *(float *)(this + 14740);
    }
    if ( *(float *)(this + 14740) >= (double)*(float *)(this + 14748) )
    {
      if ( *(float *)(this + 14740) > (double)*(float *)(this + 14744) )
        *(_DWORD *)(this + 14740) = *(_DWORD *)(this + 14744);
    }
    else
    {
      *(_DWORD *)(this + 14740) = *(_DWORD *)(this + 14748);
    }
  }
}
