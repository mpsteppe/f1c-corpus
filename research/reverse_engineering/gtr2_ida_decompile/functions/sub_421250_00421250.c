int __usercall sub_421250@<eax>(unsigned __int64 a1@<edx:eax>, int a2@<ecx>)
{
  long double v3; // st7
  double v4; // st6
  double v5; // st6
  double v6; // st5
  int v7; // edi
  long double v8; // st7
  int v9; // ecx
  double v10; // st7
  double v11; // st7
  double v13; // st7
  char v14; // c0
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st6
  double v21; // st5
  double v22; // st6
  double v23; // st7
  double v24; // st6
  double v25; // st7
  double v26; // st6
  double v27; // st6
  int result; // eax
  float v29; // [esp+8h] [ebp-24h]
  float v30; // [esp+8h] [ebp-24h]
  float v31; // [esp+Ch] [ebp-20h]
  float v32; // [esp+Ch] [ebp-20h]
  float v33; // [esp+10h] [ebp-1Ch]
  float v34; // [esp+10h] [ebp-1Ch]
  float v35; // [esp+10h] [ebp-1Ch]
  float v36; // [esp+10h] [ebp-1Ch]
  float v37; // [esp+10h] [ebp-1Ch]
  float v38[3]; // [esp+14h] [ebp-18h] BYREF
  _BYTE v39[12]; // [esp+20h] [ebp-Ch] BYREF

  v3 = fabs(*(float *)(a2 + 20452));
  if ( v3 > 0.1 && *(float *)(a2 + 20476) > 20.0 )
    *(float *)(a2 + 20460) = (1.0 - 0.69999999 * v3) * *(float *)(a2 + 20460);
  if ( *(float *)(a2 + 20828) < (double)*(float *)(a2 + 20576) )
    *(float *)(a2 + 20576) = *(float *)(a2 + 20828);
  if ( *(float *)(a2 + 20576) < 5.0 )
    *(_DWORD *)(a2 + 20576) = 1084227584;
  if ( *(_DWORD *)(a2 + 20424) )
  {
    switch ( *(_DWORD *)(a2 + 20420) )
    {
      case 1:
        *(float *)(a2 + 20576) = *(float *)(a2 + 20476) - 6.0;
        break;
      case 2:
        *(_DWORD *)(a2 + 20576) = *(_DWORD *)(a2 + 20476);
        break;
      case 3:
        *(_DWORD *)(a2 + 20576) = 1203982208;
        break;
    }
  }
  v4 = dbl_FB1D18;
  *(_DWORD *)(a2 + 20824) = 1065353216;
  v29 = v4 - *(float *)(a2 + 20808);
  if ( v29 > 0.0 )
  {
    if ( *(_BYTE *)(a2 + 20820) )
    {
      if ( *(float *)(a2 + 20812) + *(float *)(a2 + 20812) <= v29 )
        goto LABEL_25;
      if ( v29 >= (double)*(float *)(a2 + 20812) )
        v5 = 1.0
           - (*(float *)(a2 + 20812) - (v29 - *(float *)(a2 + 20812)))
           / *(float *)(a2 + 20812)
           * (1.0 - *(float *)(a2 + 20816));
      else
        v5 = 1.0 - (1.0 - *(float *)(a2 + 20816)) * (v29 / *(float *)(a2 + 20812));
      a1 = (unsigned __int64)(100.0 * v5);
      v6 = (double)(int)a1;
    }
    else
    {
      if ( v29 >= (double)*(float *)(a2 + 20812) )
        goto LABEL_25;
      v5 = 1.0 - (1.0 - *(float *)(a2 + 20816)) * ((*(float *)(a2 + 20812) - v29) / *(float *)(a2 + 20812));
      a1 = (unsigned __int64)(100.0 * v5);
      v6 = (double)(int)a1;
    }
    *(float *)(a2 + 20832) = v6 * *(float *)(a2 + 20704) * 0.0099999998;
    *(float *)(a2 + 20824) = v5;
  }
LABEL_25:
  v7 = *(_DWORD *)(a2 + 20628);
  if ( v7 )
  {
    v8 = 1.0 - (100.0 - *(float *)(a2 + 20632)) * 0.0099999998 * (1.0 - v3 * 4.0) * 0.1;
    if ( v8 > 1.0 )
      v8 = 1.0;
    a1 = (unsigned __int64)(100.0 * v8);
    *(_DWORD *)(a2 + 20628) = v7 - 1;
    *(float *)(a2 + 20832) = (double)(int)a1 * *(float *)(a2 + 20704) * 0.0099999998;
    *(float *)(a2 + 20460) = v8 * *(float *)(a2 + 20460);
    if ( v7 == 1 )
    {
      sub_41FC70();
      *(_BYTE *)(a2 + 20844) = 0;
    }
  }
  v31 = *(float *)(a2 + 20576) - 2.0;
  if ( *(float *)(a2 + 20476) >= (double)v31 )
  {
    v9 = a2 + 16;
    if ( *(float *)(a2 + 20576) + 5.0 > *(float *)(a2 + 20476) )
    {
      v10 = *(float *)(a2 + 20576) + 2.0;
      if ( v10 > *(float *)(a2 + 20476) )
      {
        v13 = *(float *)(a2 + 20476);
        if ( v14 )
        {
          v35 = (v13 - v31) * 0.5;
          v16 = sub_573020(v9, HIDWORD(a1));
          v15 = v16 + (1.0 - v16) * (1.0 - v35);
        }
        else
        {
          v34 = (v13 - *(float *)(a2 + 20576)) * 0.5;
          v15 = sub_573020(v9, HIDWORD(a1)) * (1.0 - v34);
        }
        if ( v15 < *(float *)(a2 + 20460) )
        {
          *(float *)(a2 + 20460) = v15;
          *(float *)(a2 + 20464) = v15;
        }
      }
      else
      {
        v33 = (*(float *)(a2 + 20476) - v10) * 0.33333334;
        v11 = sub_573160(v9, HIDWORD(a1)) * v33;
        if ( v11 > *(float *)(a2 + 20468) )
          *(float *)(a2 + 20468) = v11;
        *(_DWORD *)(a2 + 20460) = 0;
        *(_DWORD *)(a2 + 20464) = 0;
      }
    }
    else
    {
      *(float *)(a2 + 20468) = sub_573160(v9, HIDWORD(a1));
      *(_DWORD *)(a2 + 20460) = 0;
      *(_DWORD *)(a2 + 20464) = 0;
    }
    if ( *(float *)(a2 + 20468) >= 0.0 )
    {
      if ( *(float *)(a2 + 20468) > 1.0 )
        *(_DWORD *)(a2 + 20468) = 1065353216;
    }
    else
    {
      *(_DWORD *)(a2 + 20468) = 0;
    }
    if ( *(float *)(a2 + 20460) >= 0.0 )
    {
      if ( *(float *)(a2 + 20460) > 1.0 )
        *(_DWORD *)(a2 + 20460) = 1065353216;
    }
    else
    {
      *(_DWORD *)(a2 + 20460) = 0;
    }
  }
  if ( !byte_757C08 )
  {
    if ( *(float *)(a2 + 20460) <= (double)*(float *)(a2 + 20892) )
      goto LABEL_62;
    v18 = *(float *)(a2 + 20892);
    goto LABEL_61;
  }
  if ( *(float *)(a2 + 20644) <= 1.0 )
    v17 = *(float *)(a2 + 20644);
  else
    v17 = 1.0;
  if ( v17 < *(float *)(a2 + 20460) )
  {
    if ( *(float *)(a2 + 20644) <= 1.0 )
      v18 = *(float *)(a2 + 20644);
    else
      v18 = 1.0;
LABEL_61:
    *(float *)(a2 + 20460) = v18;
    *(float *)(a2 + 20464) = v18;
  }
LABEL_62:
  if ( *(float *)(a2 + 20572) < (double)flt_91BCA0 )
  {
    sub_54FE30(*(_DWORD *)a2, v38, v39);
    v19 = v38[0] - *(float *)(a2 + 15988);
    v20 = v38[1] - *(float *)(a2 + 15992);
    v21 = v38[2] - *(float *)(a2 + 15996);
    *(_DWORD *)(a2 + 20452) = 0;
    *(float *)(a2 + 20572) = sqrt(v21 * v21 + v20 * v20 + v19 * v19);
  }
  v30 = 0.0;
  v22 = *(float *)(a2 + 17000);
  if ( *(float *)(a2 + 16748) <= v22 )
  {
    v23 = v22 * 0.30000001;
    v24 = *(float *)(a2 + 16748) * 0.69999999;
  }
  else
  {
    v23 = v22 * 0.69999999;
    v24 = *(float *)(a2 + 16748) * 0.30000001;
  }
  v36 = *(float *)(a2 + 20744);
  v32 = v23 + v24;
  if ( v32 < (double)v36 && (*(float *)(a2 + 20476) > 4.0 || *(_DWORD *)(a2 + 20548)) )
  {
    v25 = sub_572FD0(a2 + 16) * *(float *)(a2 + 20748);
    if ( v25 > 1.0 )
      v25 = 1.0;
    v26 = (1.0 - v32 / v36) * *(float *)(a2 + 20752);
    if ( v26 >= 0.0 )
    {
      if ( v26 > 1.0 )
        v26 = 1.0;
    }
    else
    {
      v26 = 0.0;
    }
    v37 = (v25 - *(float *)(a2 + 20460)) * v26 + *(float *)(a2 + 20460);
    if ( *(float *)(a2 + 20460) > (double)v37 && *(_BYTE *)(a2 + 17318) )
    {
      v27 = (*(float *)(a2 + 20460) - v37) * 4.0;
      v30 = v27;
      if ( v27 >= 0.0 )
      {
        if ( v30 > 1.0 )
          v30 = 1.0;
      }
      else
      {
        v30 = 0.0;
      }
    }
    *(float *)(a2 + 20460) = v25;
    *(float *)(a2 + 20464) = v25;
  }
  result = LODWORD(v32);
  *(float *)(a2 + 20540) = v32;
  *(float *)(a2 + 19244) = v30;
  return result;
}
