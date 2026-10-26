void __usercall sub_429EF0(int a1@<ecx>, float a2@<edi>)
{
  unsigned int v3; // eax
  char v4; // al
  int v5; // eax
  float *v6; // edi
  double v7; // st7
  int v8; // eax
  double v9; // st6
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st6
  int v14; // edx
  double v15; // st7
  int *v16; // edi
  int v17; // ebp
  double v18; // st7
  double v19; // st7
  BOOL v20; // eax
  int v21; // ecx
  unsigned __int64 v22; // rax
  int v23; // eax
  double v24; // st6
  double v25; // st4
  double v26; // st5
  double v27; // st7
  long double v28; // st7
  long double v29; // st7
  int v30; // eax
  int v31; // ecx
  int v32; // edx
  int v33; // eax
  float v35; // [esp+8h] [ebp-24h]
  float v36; // [esp+10h] [ebp-1Ch]
  float v37; // [esp+10h] [ebp-1Ch]

  v3 = *(_DWORD *)(a1 + 14820);
  *(_DWORD *)(a1 + 20880) = 0;
  *(_DWORD *)(a1 + 20884) = 0;
  if ( v3 > 1 )
    return;
  v4 = *(_BYTE *)(a1 + 21516);
  *(float *)(a1 + 20568) = dbl_FB1D18;
  if ( !v4 && *(_DWORD *)(*(_DWORD *)a1 + 14820) == 1 )
  {
    v5 = *(_DWORD *)(a1 + 20488);
    v6 = (float *)(a1 + 20460);
    *(_DWORD *)(a1 + 19244) = 0;
    *(_DWORD *)(a1 + 20460) = 0;
    *(_DWORD *)(a1 + 20464) = 0;
    if ( dword_B64134 != v5 )
    {
      v7 = *(float *)(a1 + 20484) - 0.025;
      *(float *)(a1 + 20484) = v7;
      if ( v7 < 0.0 )
      {
        sub_4206C0((float *)a1);
        v8 = dword_B64134;
        if ( dword_B64134 == 5 || dword_B64134 == 1 )
        {
          sub_41FC00(a1);
          v8 = dword_B64134;
        }
        *(_DWORD *)(a1 + 20488) = v8;
        if ( *(_BYTE *)(a1 + 21516) == 1 && byte_757C08 == 1 )
          *(float *)(a1 + 19648) = dbl_FB1D18 + 2.0;
      }
    }
    if ( *(_DWORD *)(a1 + 20488) == 4 )
    {
      byte_757C08 = 1;
      sub_573480(0);
      v9 = dbl_FB1D18 - flt_FADE5C;
      if ( v9 <= 0.2 )
      {
        if ( dbl_FB1D18 >= *(float *)(a1 + 20868) )
        {
          v14 = *(_DWORD *)(a1 + 20872);
          *(float *)(a1 + 20864) = dbl_FB1D18;
          *(_DWORD *)(a1 + 20872) = v14 == 0;
          if ( v14 )
            v15 = (double)(rand() % 100) * 0.02 + dbl_FB1D18 + 1.0;
          else
            v15 = (double)(rand() % 100) * 0.0099999998 + dbl_FB1D18;
          *(float *)(a1 + 20868) = v15;
        }
        else
        {
          v12 = dbl_FB1D18 - *(float *)(a1 + 20864);
          if ( v12 > 1.0 )
            v12 = 1.0;
          v13 = -25.0 * v12;
          if ( *(_DWORD *)(a1 + 20872) )
            *v6 = *((float *)&unk_757B88 - (unsigned __int64)v13);
          else
            *v6 = flt_757BEC[(unsigned int)(unsigned __int64)v13];
          if ( v12 < 0.0 )
            *v6 = 0.1;
        }
      }
      else
      {
        v36 = v9;
        v10 = (v36 - 0.2) * 0.55555558;
        if ( v10 <= 1.0 )
          v11 = 1250.0 - v10 * 1000.0;
        else
          v11 = 250.0;
        *v6 = (*(float *)(a1 + 17224) - *(float *)(a1 + 17228)) / v11 + 0.5;
        sub_401760((float *)(a1 + 20460), 0.0, 1.0);
      }
    }
    *(_DWORD *)(a1 + 20468) = 1065353216;
    *(_DWORD *)(a1 + 20452) = 0;
LABEL_72:
    if ( *(_DWORD *)(a1 + 18428) == 2 )
    {
      v28 = *(float *)(a1 + 20448);
      *(_DWORD *)(a1 + 20460) = 0;
      v29 = fabs(v28);
      v37 = v29;
      if ( v29 <= 7.0 )
      {
        if ( v37 >= 5.0 )
          *(float *)(a1 + 20468) = (v37 - 5.0) * 0.1 + 0.0099999998;
        else
          *(_DWORD *)(a1 + 20468) = 1008981770;
      }
      else
      {
        *(_DWORD *)(a1 + 20468) = 1045891645;
      }
    }
    v30 = *(_DWORD *)(a1 + 20452);
    v31 = *(_DWORD *)(a1 + 20468);
    v32 = *(_DWORD *)(a1 + 20460);
    *(_DWORD *)(a1 + 21524) = 0;
    *(_DWORD *)(a1 + 16152) = v30;
    *(_DWORD *)(a1 + 16156) = v31;
    *(_DWORD *)(a1 + 16148) = v32;
    return;
  }
  *(float *)(a1 + 20584) = -sin(*(float *)(a1 + 16004));
  *(float *)(a1 + 20592) = -cos(*(float *)(a1 + 16004));
  if ( !sub_427DB0((char *)a1) || *(_DWORD *)(*(_DWORD *)a1 + 14820) != 1 )
    return;
  if ( dbl_FB1D18 > *(float *)(a1 + 19648) )
  {
    *(_DWORD *)(a1 + 19648) = 2139095039;
    if ( dword_B64134 == 8 )
      *(_DWORD *)(a1 + 20848) = 1;
    else
      sub_421B50(a1);
    v16 = (int *)(a1 + 19660);
    v17 = 5;
    do
    {
      if ( *(_DWORD *)(a1 + 19284) == *(v16 - 1) && *v16 < 4 )
      {
        v18 = *(float *)(a1 + 19436);
        *(float *)(a1 + 19696) = *(float *)(a1 + 19436);
        if ( v18 < 40.0 )
          *(_DWORD *)(a1 + 19696) = 1109393408;
        v19 = (double)(rand() % (int)(unsigned __int64)*(float *)(a1 + 19696));
        *(float *)(a1 + 19696) = v19;
        *(float *)(a1 + 4 * *v16 + 18432) = v19;
      }
      v16 += 2;
      --v17;
    }
    while ( v17 );
  }
  if ( *(float *)(a1 + 20568) > (double)*(float *)(a1 + 20364) )
  {
    *(float *)(a1 + 20364) = *(float *)(a1 + 20568) + 4.0;
    sub_4286A0(a1);
  }
  if ( *(float *)(a1 + 19700) < (double)*(float *)(a1 + 20568) )
  {
    *(_DWORD *)(a1 + 20472) = 0;
    sub_41FC20();
    v20 = *(_DWORD *)dword_B640C8 != 6;
    *(_DWORD *)(a1 + 20788) = 0;
    *(_DWORD *)(a1 + 20468) = 1065353216;
    *(_DWORD *)(a1 + 20460) = 0;
    *(_DWORD *)(a1 + 20464) = 0;
    *(_DWORD *)(a1 + 20848) = 0;
    *(_DWORD *)(a1 + 20768) = v20 + 4;
    *(_DWORD *)(a1 + 20852) = 1;
    *(_DWORD *)(a1 + 20444) = 0;
    sub_427DB0((char *)a1);
    *(_DWORD *)(a1 + 19700) = 2139095039;
    *(float *)(a1 + 20564) = dbl_FB1D18 + 4.0;
    sub_577660(a1 + 16, 0);
  }
  v21 = *(_DWORD *)(a1 + 20768);
  if ( v21 != 4 && v21 != 5 )
  {
    if ( !*(_DWORD *)(a1 + 21524) && *(_DWORD *)(a1 + 18428) != 2 && *(float *)(a1 + 17196) > 0.001 )
      *(float *)(a1 + 20440) = sin(*(float *)(a1 + 20568) / *(float *)(a1 + 20900)) * *(float *)(a1 + 20904);
    sub_422140((_DWORD *)a1);
    *(_DWORD *)(a1 + 20576) = 1232348144;
    sub_4296A0(a1);
    if ( *(_DWORD *)(a1 + 20852) < dword_91BCB0 )
      sub_424090(a1);
    if ( *(_DWORD *)dword_B640C8 == 6 )
      sub_4229C0((float *)a1);
    sub_420A30((float *)a1);
    sub_421250(v22, a1);
    sub_4210D0(a1);
    v23 = *(_DWORD *)(a1 + 20768);
    switch ( v23 )
    {
      case 0:
      case 6:
        sub_420710(a1);
        break;
      case 1:
        sub_420970(a1);
        break;
      case 3:
        sub_401410();
        v24 = v35 - *(float *)(a1 + 15996);
        v25 = a2 - *(float *)(a1 + 15988);
        v26 = v24 * v24 + v25 * v25;
        if ( v26 > *(float *)(a1 + 21560) )
          *(_DWORD *)(a1 + 20768) = 0;
        else
          *(float *)(a1 + 21560) = v26;
        break;
      case 2:
        *(_DWORD *)(a1 + 20768) = 0;
        return;
      case 7:
        v27 = *(float *)(a1 + 20476);
        *(_DWORD *)(a1 + 20452) = 0;
        *(_DWORD *)(a1 + 20468) = 1065353216;
        *(_DWORD *)(a1 + 20460) = 0;
        *(_DWORD *)(a1 + 20464) = 0;
        if ( v27 < 0.2 )
          *(_DWORD *)(a1 + 20768) = 0;
        break;
    }
    goto LABEL_72;
  }
  if ( dbl_FB1D18 > *(float *)(a1 + 20804) || v21 == 4 )
  {
    if ( *(_DWORD *)(a1 + 21496) >= *(_DWORD *)(a1 + 20912) && *(_DWORD *)dword_B640C8 != 6 )
      *(_BYTE *)(a1 + 21516) = 0;
    if ( *(_DWORD *)(a1 + 19380) == 2 )
      *(_BYTE *)(a1 + 21516) = 0;
    if ( (unsigned __int8)sub_4FAE10(a1) && *(_BYTE *)(a1 + 21516) )
    {
      if ( *(_DWORD *)(a1 + 20768) == 5 )
      {
        v33 = sub_421930((_DWORD *)a1);
        sub_57F2F0(v33, v33, 1);
        sub_577660(a1 + 16, 0);
        *(_DWORD *)(a1 + 20768) = 3;
      }
      else
      {
        *(_DWORD *)(a1 + 20768) = 0;
        sub_577660(a1 + 16, 0);
      }
    }
    else
    {
      *(float *)(a1 + 20804) = dbl_FB1D18 + 4.0;
    }
  }
  *(_DWORD *)(a1 + 16152) = 0;
  *(_DWORD *)(a1 + 16156) = 1065353216;
  *(_DWORD *)(a1 + 16148) = 0;
}
