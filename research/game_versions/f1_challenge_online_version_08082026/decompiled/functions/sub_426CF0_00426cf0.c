void __thiscall sub_426CF0(int this)
{
  long double v2; // st7
  double v3; // st6
  double v4; // st7
  double v5; // st6
  double v6; // st7
  double v7; // st7
  double v8; // st6
  double v9; // st6
  double v11; // st7
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c2
  double v14; // st6
  double v15; // st7
  double v16; // st7
  float v17; // [esp+8h] [ebp-Ch]
  float v18; // [esp+Ch] [ebp-8h]
  float v19; // [esp+Ch] [ebp-8h]
  float v20; // [esp+10h] [ebp-4h]

  if ( *(_DWORD *)(this + 17916) )
    *(float *)(this + 17788) = sub_424750() * 0.75;
  v2 = fabs(*(float *)(this + 17452));
  if ( v2 > 0.1 && *(float *)(this + 17472) > 20.0 )
  {
    v18 = v2;
    *(float *)(this + 17460) = (1.0 - v18 * 0.69999999) * *(float *)(this + 17460);
  }
  v17 = 0.0;
  v3 = *(float *)(this + 14532);
  if ( *(float *)(this + 14284) <= v3 )
  {
    v4 = v3 * 0.30000001;
    v5 = *(float *)(this + 14284) * 0.69999999;
  }
  else
  {
    v4 = v3 * 0.69999999;
    v5 = *(float *)(this + 14284) * 0.30000001;
  }
  v19 = v4 + v5;
  v6 = (v19 + *(float *)(this + 17508)) * 0.5;
  v20 = v6;
  if ( v6 < 0.89999998 && (*(float *)(this + 17472) > 4.0 || *(_DWORD *)(this + 17516)) )
  {
    v7 = sub_4E8780(this + 12);
    v8 = 1.0 - v20 * 1.1111112 + 1.0 - v20 * 1.1111112;
    if ( v8 >= 0.0 )
    {
      if ( v8 > 1.0 )
        v8 = 1.0;
    }
    else
    {
      v8 = 0.0;
    }
    v9 = (v7 - *(float *)(this + 17460)) * v8 + *(float *)(this + 17460);
    v11 = v9;
    if ( v12 | v13 && *(_BYTE *)(this + 14841) )
    {
      v14 = (*(float *)(this + 17460) - v9) * 4.0;
      v17 = v14;
      if ( v14 >= 0.0 )
      {
        if ( v17 > 1.0 )
          v17 = 1.0;
      }
      else
      {
        v17 = 0.0;
      }
    }
    *(float *)(this + 17460) = v11;
  }
  *(float *)(this + 16424) = v17;
  *(float *)(this + 17508) = v19;
  if ( dword_7C56A8 < 5 && dword_7C56A4 == 7 )
    sub_42B0E0(this);
  sub_42A740(*(float *)(this + 17720));
  if ( dbl_8AFEA0 >= flt_8ACF90 + 2.5 )
  {
    if ( *(float *)(this + 17540) + 10.0 >= *(float *)(this + 17472) )
    {
      if ( *(float *)(this + 17540) + 3.0 >= *(float *)(this + 17472) )
      {
        if ( *(float *)(this + 17540) + 1.0 >= *(float *)(this + 17472) )
        {
          if ( *(float *)(this + 17472) > (double)*(float *)(this + 17540) && *(float *)(this + 17464) == 0.0 )
            *(float *)(this + 17460) = sub_4E87E0(this + 12) * 0.80000001;
        }
        else
        {
          if ( *(float *)(this + 17464) == 0.0 )
            *(_DWORD *)(this + 17464) = 0;
          *(_DWORD *)(this + 17460) = 0;
        }
      }
      else
      {
        v15 = sub_4E88B0(this + 12) * 0.5;
        if ( v15 > *(float *)(this + 17464) )
          *(float *)(this + 17464) = v15;
        *(_DWORD *)(this + 17460) = 0;
      }
    }
    else
    {
      *(float *)(this + 17464) = sub_4E88B0(this + 12);
      *(_DWORD *)(this + 17460) = 0;
    }
  }
  else if ( *(float *)(this + 17464) > 0.0 )
  {
    *(_DWORD *)(this + 17464) = 0;
  }
  if ( byte_5C3160 )
  {
    if ( *(float *)(this + 17592) <= 1.0 )
      v16 = *(float *)(this + 17592);
    else
      v16 = 1.0;
    if ( v16 < *(float *)(this + 17460) )
    {
      if ( *(float *)(this + 17592) <= 1.0 )
        *(float *)(this + 17460) = *(float *)(this + 17592);
      else
        *(float *)(this + 17460) = 1.0;
    }
  }
  else if ( *(float *)(this + 17460) > (double)*(float *)(this + 17788) )
  {
    *(_DWORD *)(this + 17460) = *(_DWORD *)(this + 17788);
  }
}
