void __thiscall sub_424E70(int this)
{
  char v2; // al
  int v3; // eax
  double v4; // st7
  int v5; // eax
  _DWORD *v6; // edi
  int v7; // ebp
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  double v14; // st6
  double v15; // st7
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int v19; // edx
  double v20; // st7
  int v21; // ecx
  int *v22; // edi
  int v23; // ebp
  double v24; // st7
  int v25; // ebx
  double v26; // st7
  int v27; // ecx
  int v28; // eax
  double v29; // st6
  double v30; // st4
  double v31; // st5
  double v32; // st7
  long double v33; // st7
  long double v34; // st7
  double v35; // st7
  int v36; // eax
  float v37; // [esp+10h] [ebp-1Ch]
  float v38; // [esp+10h] [ebp-1Ch]
  float v39[3]; // [esp+14h] [ebp-18h] BYREF
  _DWORD v40[3]; // [esp+20h] [ebp-Ch] BYREF

  if ( *(_DWORD *)(this + 13000) > 1u )
    return;
  v2 = *(_BYTE *)(this + 17908);
  *(float *)(this + 17536) = dbl_8AFEA0;
  if ( !v2 && *(_DWORD *)(*(_DWORD *)this + 13000) == 1 )
  {
    v3 = *(_DWORD *)(this + 17484);
    *(_DWORD *)(this + 16424) = 0;
    *(_DWORD *)(this + 17460) = 0;
    if ( dword_7C56A8 != v3 )
    {
      v4 = *(float *)(this + 17480) - 0.025;
      *(float *)(this + 17480) = v4;
      if ( v4 < 0.0 )
      {
        sub_424C80((float *)this);
        v5 = dword_7C56A8;
        if ( dword_7C56A8 == 5 || dword_7C56A8 == 1 )
        {
          sub_42ADB0(this);
          v5 = dword_7C56A8;
        }
        *(_DWORD *)(this + 17484) = v5;
        if ( *(_BYTE *)(this + 17908) == 1 && byte_5C3160 == 1 )
        {
          v6 = (_DWORD *)(this + 16708);
          v7 = 5;
          *(float *)(this + 16700) = dbl_8AFEA0 + 2.0;
          do
          {
            v8 = v6[1];
            if ( v8 != 4 || *v6 )
            {
              if ( v8 == 5 && !*v6 )
              {
                sub_4EFAC0(this + 12);
                v11 = sub_5884ED(v10) % 4;
                v12 = v11 ? (v11 != 1 ? 8 : 3) : 7;
                if ( !*(_DWORD *)(this + 16488) )
                  *(_DWORD *)(this + 16488) = v12;
              }
            }
            else
            {
              sub_4EFAC0(this + 12);
              *(float *)(this + 16752) = (double)(sub_5884ED(v9) & 0x14) + dbl_8AFEA0 + 10.0;
            }
            v6 += 2;
            --v7;
          }
          while ( v7 );
        }
      }
    }
    if ( *(_DWORD *)(this + 17484) == 4 )
    {
      byte_5C3160 = 1;
      sub_4EF930(0);
      v14 = dbl_8AFEA0 - flt_8ACFB8;
      if ( v14 <= 0.2 )
      {
        if ( dbl_8AFEA0 < *(float *)(this + 17764) )
        {
          v17 = dbl_8AFEA0 - *(float *)(this + 17760);
          if ( v17 > 1.0 )
            v17 = 1.0;
          v18 = v17 * -25.0;
          if ( *(_DWORD *)(this + 17768) )
            *(_DWORD *)(this + 17460) = *((_DWORD *)&unk_5C30E0 - sub_587BDC(v18));
          else
            *(_DWORD *)(this + 17460) = dword_5C3144[sub_587BDC(v18)];
          *(_DWORD *)(this + 17464) = 1065353216;
          *(_DWORD *)(this + 17452) = 0;
          goto LABEL_86;
        }
        v19 = *(_DWORD *)(this + 17768);
        *(float *)(this + 17760) = dbl_8AFEA0;
        *(_DWORD *)(this + 17768) = v19 == 0;
        if ( v19 )
          v20 = (double)(sub_5884ED(v13) % 100) * 0.02 + dbl_8AFEA0 + 1.0;
        else
          v20 = (double)(sub_5884ED(v13) % 100) * 0.0099999998 + dbl_8AFEA0;
        *(float *)(this + 17764) = v20;
      }
      else
      {
        v37 = v14;
        v15 = (v37 - 0.2) * 0.55555558;
        if ( v15 <= 1.0 )
          v16 = 1250.0 - v15 * 1000.0;
        else
          v16 = 250.0;
        *(float *)(this + 17460) = (*(float *)(this + 14748) - *(float *)(this + 14752)) / v16 + 0.5;
        if ( *(float *)(this + 17460) < 0.0 )
        {
          *(_DWORD *)(this + 17460) = 0;
          *(_DWORD *)(this + 17464) = 1065353216;
          *(_DWORD *)(this + 17452) = 0;
LABEL_86:
          if ( *(_DWORD *)(this + 15724) == 2 )
          {
            v33 = *(float *)(this + 17448);
            *(_DWORD *)(this + 17460) = 0;
            v34 = fabs(v33);
            v38 = v34;
            if ( v34 <= 7.0 )
            {
              if ( v38 >= 5.0 )
                *(float *)(this + 17464) = (v38 - 5.0) * 0.1 + 0.0099999998;
              else
                *(_DWORD *)(this + 17464) = 1008981770;
            }
            else
            {
              *(_DWORD *)(this + 17464) = 1045891645;
            }
          }
          *(float *)(this + 13696) = *(float *)(this + 17452);
          v35 = *(float *)(this + 17464);
          *(_DWORD *)(this + 17916) = 0;
          *(float *)(this + 13700) = v35;
          *(float *)(this + 13692) = *(float *)(this + 17460);
          return;
        }
        if ( *(float *)(this + 17460) > 1.0 )
        {
          *(_DWORD *)(this + 17460) = 1065353216;
          *(_DWORD *)(this + 17464) = 1065353216;
          *(_DWORD *)(this + 17452) = 0;
          goto LABEL_86;
        }
      }
    }
    *(_DWORD *)(this + 17464) = 1065353216;
    *(_DWORD *)(this + 17452) = 0;
    goto LABEL_86;
  }
  *(float *)(this + 17548) = -sin(*(float *)(this + 13552));
  *(float *)(this + 17556) = -cos(*(float *)(this + 13552));
  if ( !(unsigned __int8)sub_426430(this) || *(_DWORD *)(*(_DWORD *)this + 13000) != 1 )
    return;
  if ( dbl_8AFEA0 > *(float *)(this + 16700) )
  {
    *(_DWORD *)(this + 16700) = 2139095039;
    if ( dword_7C56A8 == 8 )
      sub_42AC70(1);
    else
      sub_42A180(this);
    v22 = (int *)(this + 16712);
    v23 = 5;
    do
    {
      if ( *(_DWORD *)(this + 16444) == *(v22 - 1) && *v22 < 4 )
      {
        v24 = *(float *)(this + 16540);
        *(float *)(this + 16748) = *(float *)(this + 16540);
        if ( v24 < 40.0 )
          *(_DWORD *)(this + 16748) = 1109393408;
        v25 = sub_5884ED(v21);
        v21 = sub_587BDC(*(float *)(this + 16748));
        v26 = (double)(v25 % v21);
        *(float *)(this + 16748) = v26;
        *(float *)(this + 4 * *v22 + 15728) = v26;
      }
      v22 += 2;
      --v23;
    }
    while ( v23 );
  }
  if ( *(float *)(this + 17536) > (double)*(float *)(this + 17412) )
  {
    *(float *)(this + 17412) = *(float *)(this + 17536) + 4.0;
    sub_429470(this);
  }
  if ( *(float *)(this + 16752) < (double)*(float *)(this + 17536) )
  {
    *(_DWORD *)(this + 17468) = 0;
    *(_DWORD *)(this + 17400) = 0;
    sub_42AE00(this);
    if ( dword_7C56A4 == 7 )
      *(_DWORD *)(this + 17680) = 4;
    else
      *(_DWORD *)(this + 17680) = 5;
    *(_DWORD *)(this + 17700) = 0;
    *(_DWORD *)(this + 17464) = 1065353216;
    *(_DWORD *)(this + 17460) = 0;
    *(_DWORD *)(this + 17740) = 0;
    *(_DWORD *)(this + 17744) = 1;
    *(_DWORD *)(this + 17444) = 0;
    sub_426430(this);
    *(_DWORD *)(this + 16752) = 2139095039;
    *(float *)(this + 17532) = dbl_8AFEA0 + 4.0;
    sub_4EFA40(0);
  }
  v27 = *(_DWORD *)(this + 17680);
  if ( v27 != 4 && v27 != 5 )
  {
    if ( !*(_DWORD *)(this + 17916) && *(_DWORD *)(this + 15724) != 2 && *(float *)(this + 14724) > 0.001 )
      *(_DWORD *)(this + 17440) = 0;
    sub_42A7D0(this);
    *(_DWORD *)(this + 17540) = 1232348144;
    sub_425920(this);
    if ( *(_DWORD *)(this + 17744) < dword_5EA2CC )
      sub_4270A0(this);
    sub_426100(this);
    sub_426CF0(this);
    sub_426330(this);
    v28 = *(_DWORD *)(this + 17680);
    switch ( v28 )
    {
      case 0:
      case 6:
        sub_425670(this);
        break;
      case 1:
        sub_4258C0(this);
        break;
      case 3:
        sub_403F70(dword_5EA2C0, *(_DWORD *)(*(_DWORD *)this + 18596), v39, v40);
        v29 = v39[2] - *(float *)(this + 13544);
        v30 = v39[0] - *(float *)(this + 13536);
        v31 = v29 * v29 + v30 * v30;
        if ( v31 > *(float *)(this + 17948) )
          *(_DWORD *)(this + 17680) = 0;
        else
          *(float *)(this + 17948) = v31;
        break;
      case 2:
        sub_425660(this);
        return;
      case 7:
        v32 = *(float *)(this + 17472);
        *(_DWORD *)(this + 17452) = 0;
        *(_DWORD *)(this + 17464) = 1065353216;
        *(_DWORD *)(this + 17460) = 0;
        if ( v32 < 0.2 )
          *(_DWORD *)(this + 17680) = 0;
        break;
    }
    goto LABEL_86;
  }
  if ( dbl_8AFEA0 > *(float *)(this + 17716) || v27 == 4 )
  {
    if ( *(_DWORD *)(this + 17888) >= *(_DWORD *)(this + 17800) && dword_7C56A4 != 7 )
      *(_BYTE *)(this + 17908) = 0;
    if ( *(_DWORD *)(this + 16484) == 2 )
      *(_BYTE *)(this + 17908) = 0;
    if ( (unsigned __int8)sub_4A4110(this) && *(_BYTE *)(this + 17908) )
    {
      if ( *(_DWORD *)(this + 17680) == 5 )
      {
        v36 = sub_429FD0(this);
        sub_4F1A60(v36, 1);
        sub_4EFA40(0);
        *(_DWORD *)(this + 17680) = 3;
      }
      else
      {
        *(_DWORD *)(this + 17680) = 0;
      }
    }
    else
    {
      *(float *)(this + 17716) = dbl_8AFEA0 + 4.0;
    }
  }
  *(_DWORD *)(this + 13696) = 0;
  *(_DWORD *)(this + 13700) = 1065353216;
  *(_DWORD *)(this + 13692) = 0;
}
