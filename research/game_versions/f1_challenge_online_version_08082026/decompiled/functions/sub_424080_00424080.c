void __thiscall sub_424080(char *this)
{
  int v2; // edi
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  int v34; // ecx
  double v35; // st7
  double v36; // st7
  unsigned __int8 v38; // c0
  unsigned __int8 v39; // c2
  int v40; // ecx
  int v41; // ebx
  _DWORD *v42; // ebp
  int v43; // eax
  float v44; // [esp+10h] [ebp-Ch]
  int v45; // [esp+10h] [ebp-Ch]
  float v46; // [esp+14h] [ebp-8h]
  int v47; // [esp+14h] [ebp-8h]
  float v48; // [esp+14h] [ebp-8h]

  v2 = sub_568210(*(_DWORD *)this + 17952);
  *((_DWORD *)this + 4401) = 1077936128;
  *((_DWORD *)this + 4402) = 1077936128;
  v44 = 0.0;
  v46 = 0.0;
  *((_DWORD *)this + 4399) = 0x40000000;
  *((_DWORD *)this + 4400) = 1056964608;
  *((_DWORD *)this + 4403) = 1112014848;
  *((_DWORD *)this + 4404) = 1092616192;
  *((_DWORD *)this + 4407) = 1114636288;
  strcpy(this + 17632, aDefaultScp);
  *((_DWORD *)this + 4413) = 1065353216;
  *((_DWORD *)this + 4414) = 1065353216;
  v4 = sub_5884ED(v3);
  *((_DWORD *)this + 4416) = 1069547520;
  *((_DWORD *)this + 4417) = 1064766013;
  *((_DWORD *)this + 4415) = v4 % 3;
  if ( v2 )
  {
    v5 = sub_5679C0(aStartsdry);
    if ( v5 )
    {
      v6 = sub_567970(v5);
      v44 = sub_58850F(v6);
    }
    v7 = sub_5679C0(aStartswet);
    if ( v7 )
    {
      v8 = sub_567970(v7);
      v46 = sub_58850F(v8);
    }
    v9 = sub_5679C0(aStartstalls);
    if ( v9 )
    {
      v10 = sub_567970(v9);
      *((float *)this + 4399) = sub_58850F(v10);
    }
    v11 = sub_5679C0(aQualifyingabil);
    if ( v11 )
    {
      v12 = sub_567970(v11);
      *((float *)this + 4400) = (22.0 - sub_58850F(v12)) * 0.045454547;
    }
    v13 = sub_5679C0(aTrackaggressio);
    if ( v13 )
    {
      v14 = sub_567970(v13);
      *((float *)this + 4414) = sub_58850F(v14);
    }
    v15 = sub_5679C0(aRainability);
    if ( v15 )
    {
      v16 = sub_567970(v15);
      *((float *)this + 4402) = sub_58850F(v16);
    }
    v17 = sub_5679C0(aRaceability);
    if ( v17 )
    {
      v18 = sub_567970(v17);
      *((float *)this + 4401) = sub_58850F(v18);
    }
    v19 = sub_5679C0(aPassing);
    if ( v19 )
    {
      v20 = sub_567970(v19);
      *((float *)this + 4403) = sub_58850F(v20);
    }
    v21 = sub_5679C0(aCorneringadd);
    if ( v21 )
    {
      v22 = sub_567970(v21);
      *((float *)this + 4416) = sub_58850F(v22);
    }
    v23 = sub_5679C0(aCorneringmult);
    if ( v23 )
    {
      v24 = sub_567970(v23);
      *((float *)this + 4417) = sub_58850F(v24);
    }
    v25 = sub_5679C0(aCrash);
    if ( v25 )
    {
      v26 = sub_567970(v25);
      *((float *)this + 4404) = sub_58850F(v26);
    }
    v27 = sub_5679C0(aCompletedlaps);
    if ( v27 )
    {
      v28 = sub_567970(v27);
      *((float *)this + 4407) = sub_58850F(v28);
    }
    v29 = sub_5679C0(aScript);
    if ( v29 )
      strcpy(this + 17632, (const char *)sub_567970(v29));
  }
  v30 = flt_7D017C * *((float *)this + 4414);
  *((float *)this + 4414) = v30;
  if ( v30 < 0.0099999998 )
    *((_DWORD *)this + 4414) = 1008981770;
  v31 = *((float *)this + 4402) * 0.0099999998 * flt_5EA3D8;
  *((float *)this + 4402) = v31;
  *((float *)this + 4448) = 1.0 - flt_8AFEE8 * v31;
  v32 = (1.0 - *((float *)this + 4401) * 0.0099999998) * flt_5EA3D8;
  *((float *)this + 4413) = v32;
  *((float *)this + 4406) = (1.0 - v32) * 0.67000002;
  *((float *)this + 4405) = (22.0 - *((float *)this + 4401) * 0.67000002) * 0.045454547;
  v33 = (22.0 - *((float *)this + 4401)) * 0.045454547;
  *((float *)this + 4401) = v33;
  if ( dword_7D01A0 < 100 )
    *((float *)this + 4401) = (double)dword_7D01A0 * 0.0099999998 * ((double)dword_7D01A0 * 0.0099999998) * v33;
  sub_42AD00(100);
  v35 = *((float *)this + 4403) * 0.001 + 0.89999998;
  *((float *)this + 4403) = v35;
  if ( v35 > 1.0 )
    *((_DWORD *)this + 4403) = 1065353216;
  *((float *)this + 4398) = (1.0 - flt_8AFEE8) * v44 + flt_8AFEE8 * v46;
  v36 = (double)(sub_5884ED(v34) % 200) * 0.0099999998 + *((float *)this + 4398);
  *((float *)this + 4398) = v36;
  if ( v38 | v39 )
  {
    *((_DWORD *)this + 4398) = -1065353216;
  }
  else if ( v36 > 4.0 )
  {
    *((_DWORD *)this + 4398) = 1082130432;
  }
  *((float *)this + 4398) = *((float *)this + 4398) * 0.1 + 1.0;
  *((float *)this + 4447) = sub_424750();
  if ( dword_7C56A4 == 7 && dword_7CEA5C > 0 )
  {
    if ( dword_7CEA5C <= 2 )
    {
      v48 = *((float *)this + 4399) * 100.0;
      if ( (double)(sub_5884ED(v40) % 10000) < v48 )
      {
        if ( sub_5884ED(10000) % 10 )
        {
          *((_DWORD *)this + 4178) = 5;
          *((_DWORD *)this + 4177) = 0;
        }
        else
        {
          *((_DWORD *)this + 4177) = 0;
          *((_DWORD *)this + 4178) = 4;
        }
      }
    }
    else if ( dword_7CEA5C == 3 )
    {
      if ( sub_4C5840(0) )
      {
        if ( sub_5679C0(aRaceevents) )
        {
          if ( sub_5679C0(*(_DWORD *)this + 17952) )
          {
            v47 = 0;
            v41 = sub_5679A0(0);
            if ( v41 )
            {
              v42 = this + 16712;
              do
              {
                *v42 = 6;
                if ( !strcmp((const char *)sub_567970(v41), aStall) )
                {
                  *v42 = 4;
                }
                else if ( !strcmp((const char *)sub_567970(v41), aStallDns)
                       || !strcmp((const char *)sub_567970(v41), (const char *)&off_5C3188) )
                {
                  *v42 = 5;
                }
                else if ( !strcmp((const char *)sub_567970(v41), aSuspension) )
                {
                  *v42 = 3;
                }
                else if ( !strcmp((const char *)sub_567970(v41), aBrakes) )
                {
                  *v42 = 1;
                }
                else if ( !strcmp((const char *)sub_567970(v41), aEngine) )
                {
                  *v42 = 0;
                }
                else if ( !strcmp((const char *)sub_567970(v41), aGearbox) )
                {
                  *v42 = 2;
                }
                else if ( *v42 == 6 )
                {
                  *(v42 - 1) = -1;
                  goto LABEL_63;
                }
                v43 = sub_499E20(v41);
                v45 = sub_589278(v43, 0, 10);
                *(v42 - 1) = v45;
                *(v42 - 1) = sub_587BDC((double)v45 / flt_8ACF9C);
LABEL_63:
                ++v47;
                v42 += 2;
                v41 = sub_5679A0(v47);
              }
              while ( v41 );
            }
          }
        }
      }
    }
  }
}
