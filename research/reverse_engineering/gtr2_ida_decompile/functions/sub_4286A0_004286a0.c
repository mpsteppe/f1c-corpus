void __thiscall sub_4286A0(int this)
{
  double v2; // st7
  double v3; // st7
  double v4; // st7
  double v5; // st7
  double v6; // st6
  double v7; // st7
  double v8; // st7
  double v9; // st7
  double v10; // st6
  int v11; // ecx
  int v12; // edi
  int v13; // eax
  int v14; // ecx
  double v15; // st7
  _DWORD *v16; // ecx
  double v17; // st7
  BOOL v18; // ecx
  int v19; // edi
  unsigned __int64 v20; // rax
  double v21; // st7
  int v22; // [esp-4h] [ebp-1Ch]
  float v23; // [esp+10h] [ebp-8h]
  float v24; // [esp+10h] [ebp-8h]
  float v25; // [esp+10h] [ebp-8h]
  float v26; // [esp+10h] [ebp-8h]
  float v27; // [esp+14h] [ebp-4h]
  int v28; // [esp+14h] [ebp-4h]
  float v29; // [esp+14h] [ebp-4h]

  v22 = *(_DWORD *)(this + 19292);
  *(_DWORD *)(this + 20840) = 1;
  if ( sub_555630(&unk_FADD40, v22) == 2 )
  {
    *(_DWORD *)(this + 20840) = 0;
    if ( dword_B71FD8 >= 95 )
      v2 = 1.0;
    else
      v2 = (double)(dword_B71FD8 - 70) * 0.039999999 * 0.25 + 0.75;
    *(float *)(this + 20892) = v2 * 0.75;
  }
  else if ( !sub_555630(&unk_FADD40, *(_DWORD *)(this + 19292))
         || sub_555630(&unk_FADD40, *(_DWORD *)(this + 19292)) == 1 )
  {
    v4 = dword_B71FD8 >= 95 ? 1.0 : (double)(dword_B71FD8 - 70) * 0.039999999 * 0.25 + 0.75;
    *(float *)(this + 20892) = v4;
    if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( *(float *)(this + 20756) == 0.0 )
      {
        v7 = *(float *)(this + 20704);
        v28 = *(_DWORD *)(this + 19324);
        if ( v28 <= 1 )
        {
          v8 = v7 - *(float *)(this + 20676);
          v24 = *(float *)(this + 20832) - 0.0099999998;
          if ( v8 <= v24 )
            v8 = v24;
        }
        else
        {
          v8 = v7 + *(float *)(this + 20676);
          v23 = *(float *)(this + 20672) + *(float *)(this + 20832);
          if ( v8 >= v23 )
            v8 = v23;
        }
        *(float *)(this + 20832) = v8;
        v9 = (double)dword_757C10;
        v10 = (double)v28;
        v25 = v9 - (double)dword_91DC44;
        v29 = v9 * v9;
        v26 = (v9 - v10) * (v9 - v10) / v29 * (v25 * v25 / v29);
        if ( v26 * 50.0 > (double)(rand() % 1000) )
        {
          ++dword_91DC44;
          *(_DWORD *)(this + 20756) = *(_DWORD *)(this + 20672);
        }
      }
      else
      {
        v5 = *(float *)(this + 20832) - *(float *)(this + 20756);
        *(float *)(this + 20832) = v5;
        v6 = *(float *)(this + 20704) * *(float *)(this + 20636);
        if ( v6 > v5 )
        {
          v27 = v6;
          *(float *)(this + 20832) = v27;
          *(_DWORD *)(this + 20756) = 0;
          --dword_91DC44;
          *(_DWORD *)(this + 20760) = 0;
          *(_DWORD *)(this + 20764) = 0;
          goto LABEL_6;
        }
      }
      *(_DWORD *)(this + 20760) = 0;
      *(_DWORD *)(this + 20764) = 0;
    }
  }
LABEL_6:
  if ( *(_DWORD *)(this + 19380) == 1 )
  {
    if ( dword_B71FD8 >= 95 )
      v3 = 1.0;
    else
      v3 = (double)(dword_B71FD8 - 70) * 0.039999999 * 0.25 + 0.75;
    *(_DWORD *)(this + 20840) = 0;
    *(float *)(this + 20892) = v3 * 0.75;
  }
  v11 = *(_DWORD *)(this + 18428);
  if ( v11 == 2 || *(float *)(this + 17196) <= 0.001 || *(float *)(this + 19204) > 0.0 )
  {
    if ( *(_DWORD *)dword_B640C8 != 6
      || *(_DWORD *)(this + 19284) != dword_FADE18 - 1
      || (v13 = *(_DWORD *)(this + 19288), v13 != 2) && v13 != -1
      || *(float *)(this + 20476) < 5.0 )
    {
      v14 = *(_DWORD *)(this + 20184);
      *(float *)(this + 20804) = dbl_FB1D18 + 120.0;
      if ( *(float *)(v14 + 60) + *(float *)(this + 20448) >= *(float *)(v14 + 56) - *(float *)(this + 20448) )
        v15 = *(float *)(v14 + 60);
      else
        v15 = -*(float *)(v14 + 56);
      *(float *)(this + 20440) = v15;
      *(_BYTE *)(this + 20889) = 0;
      if ( *(_DWORD *)dword_B640C8 == 6 )
      {
        sub_573540(this + 16);
        if ( *(float *)(this + 19204) > 0.0 && !*(_DWORD *)(this + 19384) )
          *(_DWORD *)(this + 19384) = 6;
      }
      if ( *(float *)(this + 20476) < 1.0 )
      {
        if ( *(_DWORD *)dword_B640C8 == 6 )
        {
          *(_BYTE *)(this + 21516) = 0;
        }
        else
        {
          *(_BYTE *)(this + 20889) = 0;
          sub_4278D0((_DWORD *)this);
          v16 = (_DWORD *)(16 * *(_DWORD *)(this + 21496) + this + 20924);
          if ( *(float *)v16 >= 1.0 )
            v17 = *(float *)v16;
          else
            v17 = 1.0;
          if ( v17 <= *(float *)(this + 17200) )
          {
            if ( *(float *)v16 >= 1.0 )
              sub_578550(*v16);
            else
              sub_578550(1065353216);
          }
          else
          {
            sub_578550(*(_DWORD *)(this + 17200));
          }
          sub_4220E0(this);
          *(_DWORD *)(this + 20840) = 0;
          *(_DWORD *)(this + 20828) = dword_FADE50;
          *(_DWORD *)(this + 20852) = 1;
          *(_BYTE *)(this + 20844) = 1;
          *(_DWORD *)(this + 20472) = 0;
          sub_573810(this + 16);
          sub_41FC20();
          v18 = *(_DWORD *)dword_B640C8 != 6;
          *(_DWORD *)(this + 20788) = 0;
          *(_DWORD *)(this + 20468) = 1065353216;
          *(_DWORD *)(this + 20460) = 0;
          *(_DWORD *)(this + 20848) = 0;
          *(_DWORD *)(this + 20852) = 1;
          *(_DWORD *)(this + 20444) = 0;
          *(_DWORD *)(this + 20768) = v18 + 4;
          sub_427DB0((char *)this);
          *(float *)(this + 20804) = dbl_FB1D18 + 180.0;
        }
      }
    }
  }
  else if ( v11 == 1 )
  {
    v12 = *(_DWORD *)this + 2704;
    if ( sub_41FDD0(v12) || sub_41FDF0(v12) || *(_BYTE *)(this + 17319) && *(_DWORD *)(this + 19284) + 2 < dword_FADE18 )
      sub_421A90((_DWORD *)this);
    *(float *)(this + 20832) = *(float *)(this + 20704) * 0.85000002;
  }
  v19 = *(_DWORD *)(this + 21520);
  if ( v19 )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( dword_B72E08 )
      {
        if ( (int)(unsigned __int64)(*(float *)(this + 17196) * *(float *)(this + 15568) - 0.2) < 5 )
        {
          v20 = (unsigned __int64)(*(float *)(v19 + 17196) * *(float *)(v19 + 15568) - 0.2);
          if ( (int)v20 > 0 && (int)v20 < 5 && !sub_422720(*(_DWORD *)(this + 21520)) && !sub_422720(this) )
          {
            v21 = flt_BE08A4[(unsigned __int8)dword_BE08A0++];
            if ( v21 < 0.050000001 || sub_4226F0((float *)this) < 3 )
              sub_421A90((_DWORD *)this);
          }
        }
      }
    }
  }
  sub_427560(this);
  *(_DWORD *)(this + 20620) = -1;
}
