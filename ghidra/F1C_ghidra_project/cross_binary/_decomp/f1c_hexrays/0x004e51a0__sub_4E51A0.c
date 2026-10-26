// f1c  0x004e51a0  size=716
void __thiscall sub_4E51A0(int this)
{
  double v2; // st7
  float *v3; // ebx
  double v4; // st7
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st7
  int v11; // eax
  int v12; // ecx
  double v13; // st7
  int v14; // eax
  double v15; // st7
  unsigned __int8 v17; // c0
  unsigned __int8 v18; // c2
  int v19; // eax
  int v20; // eax
  double v21; // st7
  double v22; // st7
  float *v23; // eax
  int v24; // ecx
  double v25; // st7
  float v26; // [esp+14h] [ebp-10h]
  float v27; // [esp+14h] [ebp-10h]
  float v28; // [esp+18h] [ebp-Ch]
  float v29; // [esp+20h] [ebp-4h]

  v2 = *(float *)(this + 14740);
  v3 = (float *)(this + 13780);
  *(_DWORD *)(this + 13780) = 0;
  *(_DWORD *)(this + 14028) = 0;
  *(_DWORD *)(this + 14276) = 0;
  *(_DWORD *)(this + 14524) = 0;
  if ( v2 == 0.0 )
  {
    v4 = *(float *)(this + 14776);
    *(_DWORD *)(this + 13688) = 1065353216;
    if ( v4 > 0.0 )
    {
      v5 = *(float *)(this + 14776);
      v6 = v5 - *(float *)(this + 13480);
      *(float *)(this + 14776) = v6;
      if ( v6 <= *(float *)(this + 14788)
        && v5 > *(float *)(this + 14788)
        && *(float *)(this + 14740) < (double)*(float *)(this + 14748) )
      {
        sub_4F87C0(39, 2, 1.0, 1.0);
      }
      if ( *(float *)(this + 14776) <= 0.0 && *(float *)(this + 14740) < (double)*(float *)(this + 14748) )
        *(_DWORD *)(this + 14740) = *(_DWORD *)(this + 14748);
    }
  }
  v7 = *(float *)(this + 14896) * *(float *)(this + 13688) + *(float *)(this + 14900);
  *(float *)(this + 13784) = v7;
  *(float *)(this + 14032) = v7;
  v8 = *(float *)(this + 14916) * *(float *)(this + 13688) + *(float *)(this + 14920);
  *(float *)(this + 14280) = v8;
  *(float *)(this + 14528) = v8;
  if ( *(float *)(this + 14712) <= 0.0 )
    *(_DWORD *)(this + 13680) = 0;
  v9 = *(float *)(this + 14740) * 0.03125;
  v29 = *(float *)(this + 13680);
  v26 = v9;
  sub_5895A2(v9);
  v28 = v9;
  v10 = v26 - v28;
  v11 = *(_DWORD *)(this + 14756);
  v12 = (int)v28;
  *(float *)(this + 14760) = (*(float *)(v11 + 8 * v12 + 8) - *(float *)(v11 + 8 * v12)) * v10
                           + *(float *)(v11 + 8 * v12);
  v13 = v10 * (*(float *)(v11 + 8 * v12 + 12) - *(float *)(v11 + 8 * v12 + 4)) + *(float *)(v11 + 8 * v12 + 4);
  *(float *)(this + 14764) = v13;
  v14 = *(_DWORD *)(this + 14832);
  v27 = v13 * v29 + *(float *)(this + 14760);
  *(float *)(this + 14752) = v27;
  if ( v14 && *(float *)(this + 14740) > 0.0 )
  {
    if ( *(float *)(this + 14692) == *(float *)(this + 14740) )
    {
LABEL_15:
      v15 = -(v27 * *(float *)(this + 14792));
      goto LABEL_21;
    }
    if ( v17 | v18 )
    {
      if ( v27 >= 0.0 )
        goto LABEL_15;
      v15 = -(0.0 * *(float *)(this + 14792));
    }
    else
    {
      if ( v27 <= 0.0 )
        goto LABEL_15;
      v15 = -(0.0 * *(float *)(this + 14792));
    }
LABEL_21:
    v19 = *(_DWORD *)(this + 14772);
    if ( v19 )
    {
      v20 = v19 - 1;
      if ( v20 )
      {
        if ( v20 == 1 )
        {
          v21 = v15 * 0.5;
          *v3 = v21;
          *(float *)(this + 14028) = v21;
        }
      }
      else
      {
        v22 = v15 * 0.25;
        v23 = v3;
        v24 = 4;
        do
        {
          *v23 = v22;
          v23 += 62;
          --v24;
        }
        while ( v24 );
      }
    }
    else
    {
      v25 = v15 * 0.5;
      *(float *)(this + 14276) = v25;
      *(float *)(this + 14524) = v25;
    }
  }
}
