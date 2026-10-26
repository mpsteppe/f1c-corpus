void __thiscall sub_450820(int this, int a2, int a3)
{
  int v4; // edx
  int v5; // eax
  int v6; // eax
  double v7; // st7
  int v8; // ecx
  double v9; // st7
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c3
  double v13; // st7
  double v14; // st6
  double v15; // st6
  double v16; // st6
  double v17; // st6
  double v18; // st6
  double v19; // st7
  double v20; // st6
  double v21; // st7
  int v22; // eax
  int v23; // ecx
  int v24; // ecx
  double v25; // st6
  long double v26; // st6
  double v27; // st5
  long double v28; // st6
  double v29; // st7
  double v30; // st7
  int v31; // ecx
  double v32; // st7
  double v33; // st6
  long double v34; // st7
  double v35; // st6
  long double v36; // st7
  double v37; // [esp+8h] [ebp-8h]
  double v38; // [esp+8h] [ebp-8h]
  double v39; // [esp+8h] [ebp-8h]

  v4 = *(_DWORD *)(this + 9384);
  *(double *)(this + 24) = 0.0;
  if ( !v4 )
    goto LABEL_14;
  v5 = *(_DWORD *)(this + 9104);
  if ( v5 )
  {
    v6 = v5 - 1;
    if ( v6 )
    {
      if ( v6 == 1 )
        v7 = (*(double *)(this + 2184) + *(double *)(this + 904)) * -0.5;
      else
        v7 = v37;
    }
    else
    {
      v7 = (*(double *)(this + 4744) + *(double *)(this + 3464) + *(double *)(this + 2184) + *(double *)(this + 904))
         * -0.25;
    }
  }
  else
  {
    v7 = (*(double *)(this + 4744) + *(double *)(this + 3464)) * -0.5;
  }
  v8 = *(_DWORD *)(this + 9380);
  v38 = v7 * *(double *)(this + 8 * (v8 == -1 ? 0 : v8) + 9312);
  v9 = *(double *)(this + 9224) - *(double *)(this + 136);
  *(double *)(this + 9224) = v9;
  if ( v11 | v12 )
    *(_DWORD *)(this + 9376) = v8;
  if ( *(double *)(this + 8656) == v38 )
  {
    *(_DWORD *)(this + 9376) = v8;
LABEL_13:
    *(_DWORD *)(this + 9384) = 0;
    goto LABEL_14;
  }
  if ( !*(_BYTE *)(this + 9216) )
  {
    if ( !a3 )
      goto LABEL_14;
    if ( v4 <= 0 )
    {
      if ( (a2 == 2 || a2 == 3 || (*(_BYTE *)(this + 160) & 2) != 0) && *(double *)(this + 8656) < v38 )
      {
        if ( *(double *)(this + 8) <= *(double *)(this + 9272) )
          v20 = *(double *)(this + 9272);
        else
          v20 = *(double *)(this + 8);
        *(double *)(this + 8) = v20;
      }
      if ( v9 >= 0.0 )
        goto LABEL_14;
      if ( v9 <= *(double *)(this + 9264) )
        goto LABEL_13;
      v19 = v9 / *(double *)(this + 9264);
    }
    else
    {
      if ( (a2 == 1 || a2 == 3 || (*(_BYTE *)(this + 160) & 1) != 0) && *(double *)(this + 8656) > v38 )
      {
        if ( *(double *)(this + 8) >= *(double *)(this + 9248) )
          v18 = *(double *)(this + 9248);
        else
          v18 = *(double *)(this + 8);
        *(double *)(this + 8) = v18;
      }
      if ( v9 >= 0.0 )
        goto LABEL_14;
      if ( v9 <= *(double *)(this + 9240) )
        goto LABEL_13;
      v19 = v9 / *(double *)(this + 9240);
    }
    v21 = 1.0 - v19;
    if ( v21 > *(double *)(this + 32) )
      *(double *)(this + 32) = v21;
    goto LABEL_14;
  }
  v15 = *(double *)(this + 8656);
  if ( v4 <= 0 )
  {
    if ( v15 < v38 )
    {
      if ( *(double *)(this + 8) <= *(double *)(this + 9272) )
        v17 = *(double *)(this + 9272);
      else
        v17 = *(double *)(this + 8);
      *(double *)(this + 8) = v17;
    }
    if ( v9 < 0.0 )
    {
      if ( v9 > *(double *)(this + 9264) )
      {
        *(double *)(this + 24) = 1.0 - v9 / *(double *)(this + 9264);
        goto LABEL_14;
      }
LABEL_39:
      if ( *(double *)(this + 9144) == v38 )
        *(_DWORD *)(this + 9384) = 0;
    }
  }
  else
  {
    if ( v15 > v38 )
    {
      if ( *(double *)(this + 8) >= *(double *)(this + 9248) )
        v16 = *(double *)(this + 9248);
      else
        v16 = *(double *)(this + 8);
      *(double *)(this + 8) = v16;
    }
    if ( v9 < 0.0 )
    {
      if ( v9 > *(double *)(this + 9240) )
      {
        *(double *)(this + 24) = 1.0 - v9 / *(double *)(this + 9240);
        goto LABEL_14;
      }
      goto LABEL_39;
    }
  }
LABEL_14:
  v39 = (double)(*(double *)(this + 8656) > *(double *)(this + 8792));
  if ( v39 != 0.0 || *(_BYTE *)(this + 8649) )
  {
    v13 = *(double *)(this + 8);
    if ( v39 != 0.0 )
    {
      v14 = (*(double *)(this + 8800) - *(double *)(this + 8656))
          / (*(double *)(this + 8800) - *(double *)(this + 8792));
      if ( v14 < *(double *)(this + 8) )
      {
        if ( v14 < 0.0 )
          v14 = 0.0;
        *(double *)(this + 8) = v14;
      }
    }
    if ( *(_BYTE *)(this + 8649) )
    {
      v22 = *(_DWORD *)(this + 9376);
      if ( v22 )
      {
        v23 = *(_DWORD *)(this + 9104);
        if ( v23 )
        {
          v24 = v23 - 1;
          if ( v24 )
            v25 = v24 == 1 ? (*(double *)(this + 2528) + *(double *)(this + 1248)) * 0.5 : v39;
          else
            v25 = (*(double *)(this + 5088)
                 + *(double *)(this + 3808)
                 + *(double *)(this + 2528)
                 + *(double *)(this + 1248))
                * 0.25;
        }
        else
        {
          v25 = (*(double *)(this + 5088) + *(double *)(this + 3808)) * 0.5;
        }
        v26 = fabs(v25 * (*(double *)(this + 8656) / *(double *)(this + 8 * (v22 == -1 ? 0 : v22) + 9312)));
        v27 = *(_BYTE *)(this + 8648) ? 0.5 : 1.0;
        v28 = (*(float *)&dword_FADE50 - v26) / v27;
        if ( v28 < *(double *)(this + 8) )
        {
          if ( v28 < 0.0 )
            v28 = 0.0;
          *(long double *)(this + 8) = v28;
        }
      }
    }
    v29 = (v13 - *(double *)(this + 8)) * 0.166;
    if ( v29 > *(double *)(this + 408) )
      *(double *)(this + 408) = v29;
  }
  if ( *(double *)(this + 8656) < *(double *)(this + 8704) )
  {
    if ( *(double *)(this + 8656) <= *(double *)(this + 8696) )
      v30 = *(double *)(this + 8688);
    else
      v30 = (*(double *)(this + 8704) - *(double *)(this + 8656))
          * *(double *)(this + 8688)
          / (*(double *)(this + 8704) - *(double *)(this + 8696));
    if ( v30 > *(double *)(this + 8) )
      *(double *)(this + 8) = v30;
    if ( *(double *)(this + 8696) * 0.0078125 >= *(double *)(this + 8656)
      && *(double *)(this + 8840) <= 0.0
      && dword_B64134 != 2
      && !byte_B6F118
      && !sub_43A440(dword_B6BD58)
      && sub_449750(this) )
    {
      if ( *(_DWORD *)(this + 9380) )
      {
        v31 = *(_DWORD *)(this + 9392) + 24;
        *(double *)(this + 9224) = *(double *)(this + 9256);
        *(_DWORD *)(this + 9384) = 0;
        *(_DWORD *)(this + 9380) = 0;
        *(_DWORD *)(this + 9376) = 0;
        sub_58C790(v31);
        *(double *)(this + 56) = *(double *)(this + 128);
        *(_DWORD *)(this + 52) = 5;
      }
      sub_4497C0(this, 0);
    }
  }
  if ( *(double *)(this + 8840) > 0.0 )
  {
    v32 = *(double *)(this + 8840);
    v33 = v32 - *(double *)(this + 136);
    *(double *)(this + 8840) = v33;
    if ( v33 <= *(double *)(this + 8864)
      && v32 > *(double *)(this + 8864)
      && *(double *)(this + 8656) < *(double *)(this + 8696) )
    {
      sub_58C630(53);
    }
    if ( *(double *)(this + 8840) <= 0.0 && *(double *)(this + 8656) < *(double *)(this + 8696) )
      *(double *)(this + 8656) = *(double *)(this + 8696);
  }
  if ( *(double *)(this + 9000) > 0.0 )
  {
    v34 = fabs(fmod(dbl_FB1D18 / *(double *)(this + 8784) * *(double *)(this + 8656) * 11.5, 2147483647.0));
    v35 = flt_BE08A4[(unsigned __int8)(unsigned __int64)v34];
    v36 = (flt_BE08A4[(unsigned __int8)((unsigned __int64)v34 + 1)] - v35) * (v34 - (double)(int)(unsigned __int64)v34)
        + v35;
    *(long double *)(this + 8) = (1.0 - v36 * *(double *)(this + 9000) * v36) * *(double *)(this + 8);
  }
  *(double *)(this + 8) = sub_44A270(this) * *(double *)(this + 8);
}
