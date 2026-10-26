void __thiscall sub_424080(char *this)
{
  _DWORD *v2; // edi
  int v3; // eax
  _DWORD *v4; // eax
  unsigned __int8 *v5; // eax
  _DWORD *v6; // eax
  unsigned __int8 *v7; // eax
  _DWORD *v8; // eax
  unsigned __int8 *v9; // eax
  _DWORD *v10; // eax
  unsigned __int8 *v11; // eax
  _DWORD *v12; // eax
  unsigned __int8 *v13; // eax
  _DWORD *v14; // eax
  unsigned __int8 *v15; // eax
  _DWORD *v16; // eax
  unsigned __int8 *v17; // eax
  _DWORD *v18; // eax
  unsigned __int8 *v19; // eax
  _DWORD *v20; // eax
  unsigned __int8 *v21; // eax
  _DWORD *v22; // eax
  unsigned __int8 *v23; // eax
  _DWORD *v24; // eax
  unsigned __int8 *v25; // eax
  _DWORD *v26; // eax
  unsigned __int8 *v27; // eax
  _DWORD *v28; // eax
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  unsigned __int8 v36; // c0
  unsigned __int8 v37; // c2
  _DWORD *v38; // eax
  _DWORD *v39; // eax
  _DWORD *v40; // ebx
  char *v41; // ebp
  char *v42; // eax
  float v43; // [esp+10h] [ebp-Ch]
  int v44; // [esp+10h] [ebp-Ch]
  float v45; // [esp+14h] [ebp-8h]
  int v46; // [esp+14h] [ebp-8h]
  float v47; // [esp+14h] [ebp-8h]

  v2 = (_DWORD *)AudioChannelStop(dword_8AD3B4, (const char *)(*(_DWORD *)this + 17952));
  *((_DWORD *)this + 4401) = 1077936128;
  *((_DWORD *)this + 4402) = 1077936128;
  v43 = 0.0;
  v45 = 0.0;
  *((_DWORD *)this + 4399) = 0x40000000;
  *((_DWORD *)this + 4400) = 1056964608;
  *((_DWORD *)this + 4403) = 1112014848;
  *((_DWORD *)this + 4404) = 1092616192;
  *((_DWORD *)this + 4407) = 1114636288;
  strcpy(this + 17632, aDefaultScp);
  *((_DWORD *)this + 4413) = 1065353216;
  *((_DWORD *)this + 4414) = 1065353216;
  v3 = RandLCGRandomNumberGenerator();
  *((_DWORD *)this + 4416) = 1069547520;
  *((_DWORD *)this + 4417) = 1064766013;
  *((_DWORD *)this + 4415) = v3 % 3;
  if ( v2 )
  {
    v4 = StringKeyedLinkedListSearch(v2, (int)aStartsdry);
    if ( v4 )
    {
      v5 = (unsigned __int8 *)DataEntryAccessor(v4);
      v43 = sub_58850F(v5);
    }
    v6 = StringKeyedLinkedListSearch(v2, (int)aStartswet);
    if ( v6 )
    {
      v7 = (unsigned __int8 *)DataEntryAccessor(v6);
      v45 = sub_58850F(v7);
    }
    v8 = StringKeyedLinkedListSearch(v2, (int)aStartstalls);
    if ( v8 )
    {
      v9 = (unsigned __int8 *)DataEntryAccessor(v8);
      *((float *)this + 4399) = sub_58850F(v9);
    }
    v10 = StringKeyedLinkedListSearch(v2, (int)aQualifyingabil);
    if ( v10 )
    {
      v11 = (unsigned __int8 *)DataEntryAccessor(v10);
      *((float *)this + 4400) = (22.0 - sub_58850F(v11)) * 0.045454547;
    }
    v12 = StringKeyedLinkedListSearch(v2, (int)aTrackaggressio);
    if ( v12 )
    {
      v13 = (unsigned __int8 *)DataEntryAccessor(v12);
      *((float *)this + 4414) = sub_58850F(v13);
    }
    v14 = StringKeyedLinkedListSearch(v2, (int)aRainability);
    if ( v14 )
    {
      v15 = (unsigned __int8 *)DataEntryAccessor(v14);
      *((float *)this + 4402) = sub_58850F(v15);
    }
    v16 = StringKeyedLinkedListSearch(v2, (int)aRaceability);
    if ( v16 )
    {
      v17 = (unsigned __int8 *)DataEntryAccessor(v16);
      *((float *)this + 4401) = sub_58850F(v17);
    }
    v18 = StringKeyedLinkedListSearch(v2, (int)aPassing);
    if ( v18 )
    {
      v19 = (unsigned __int8 *)DataEntryAccessor(v18);
      *((float *)this + 4403) = sub_58850F(v19);
    }
    v20 = StringKeyedLinkedListSearch(v2, (int)aCorneringadd);
    if ( v20 )
    {
      v21 = (unsigned __int8 *)DataEntryAccessor(v20);
      *((float *)this + 4416) = sub_58850F(v21);
    }
    v22 = StringKeyedLinkedListSearch(v2, (int)aCorneringmult);
    if ( v22 )
    {
      v23 = (unsigned __int8 *)DataEntryAccessor(v22);
      *((float *)this + 4417) = sub_58850F(v23);
    }
    v24 = StringKeyedLinkedListSearch(v2, (int)aCrash);
    if ( v24 )
    {
      v25 = (unsigned __int8 *)DataEntryAccessor(v24);
      *((float *)this + 4404) = sub_58850F(v25);
    }
    v26 = StringKeyedLinkedListSearch(v2, (int)aCompletedlaps);
    if ( v26 )
    {
      v27 = (unsigned __int8 *)DataEntryAccessor(v26);
      *((float *)this + 4407) = sub_58850F(v27);
    }
    v28 = StringKeyedLinkedListSearch(v2, (int)aScript);
    if ( v28 )
      strcpy(this + 17632, DataEntryAccessor(v28));
  }
  v29 = flt_7D017C * *((float *)this + 4414);
  *((float *)this + 4414) = v29;
  if ( v29 < 0.0099999998 )
    *((_DWORD *)this + 4414) = 1008981770;
  v30 = *((float *)this + 4402) * 0.0099999998 * flt_5EA3D8;
  *((float *)this + 4402) = v30;
  *((float *)this + 4448) = 1.0 - flt_8AFEE8 * v30;
  v31 = (1.0 - *((float *)this + 4401) * 0.0099999998) * flt_5EA3D8;
  *((float *)this + 4413) = v31;
  *((float *)this + 4406) = (1.0 - v31) * 0.67000002;
  *((float *)this + 4405) = (22.0 - *((float *)this + 4401) * 0.67000002) * 0.045454547;
  v32 = (22.0 - *((float *)this + 4401)) * 0.045454547;
  *((float *)this + 4401) = v32;
  if ( dword_7D01A0 < 100 )
    *((float *)this + 4401) = (double)dword_7D01A0 * 0.0099999998 * ((double)dword_7D01A0 * 0.0099999998) * v32;
  LateralForceTorqueCalculation((float *)this, 100);
  v33 = *((float *)this + 4403) * 0.001 + 0.89999998;
  *((float *)this + 4403) = v33;
  if ( v33 > 1.0 )
    *((_DWORD *)this + 4403) = 1065353216;
  *((float *)this + 4398) = (1.0 - flt_8AFEE8) * v43 + flt_8AFEE8 * v45;
  v34 = (double)(RandLCGRandomNumberGenerator() % 200) * 0.0099999998 + *((float *)this + 4398);
  *((float *)this + 4398) = v34;
  if ( v36 | v37 )
  {
    *((_DWORD *)this + 4398) = -1065353216;
  }
  else if ( v34 > 4.0 )
  {
    *((_DWORD *)this + 4398) = 1082130432;
  }
  *((float *)this + 4398) = *((float *)this + 4398) * 0.1 + 1.0;
  *((float *)this + 4447) = AIDifficultyScalar();
  if ( dword_7C56A4 == 7 && dword_7CEA5C > 0 )
  {
    if ( dword_7CEA5C <= 2 )
    {
      v47 = *((float *)this + 4399) * 100.0;
      if ( (double)(RandLCGRandomNumberGenerator() % 10000) < v47 )
      {
        if ( RandLCGRandomNumberGenerator() % 10 )
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
      v38 = (_DWORD *)SeasonRacesSectionFinder(0);
      if ( v38 )
      {
        v39 = StringKeyedLinkedListSearch(v38, (int)aRaceevents);
        if ( v39 )
        {
          if ( StringKeyedLinkedListSearch(v39, *(_DWORD *)this + 17952) )
          {
            v46 = 0;
            v40 = (_DWORD *)NullCheckWrapper(0);
            if ( v40 )
            {
              v41 = this + 16712;
              do
              {
                *(_DWORD *)v41 = 6;
                if ( !strcmp(DataEntryAccessor(v40), aStall) )
                {
                  *(_DWORD *)v41 = 4;
                }
                else if ( !strcmp(DataEntryAccessor(v40), aStallDns)
                       || !strcmp(DataEntryAccessor(v40), (const char *)&off_5C3188) )
                {
                  *(_DWORD *)v41 = 5;
                }
                else if ( !strcmp(DataEntryAccessor(v40), aSuspension) )
                {
                  *(_DWORD *)v41 = 3;
                }
                else if ( !strcmp(DataEntryAccessor(v40), aBrakes) )
                {
                  *(_DWORD *)v41 = 1;
                }
                else if ( !strcmp(DataEntryAccessor(v40), aEngine) )
                {
                  *(_DWORD *)v41 = 0;
                }
                else if ( !strcmp(DataEntryAccessor(v40), aGearbox) )
                {
                  *(_DWORD *)v41 = 2;
                }
                else if ( *(_DWORD *)v41 == 6 )
                {
                  *((_DWORD *)v41 - 1) = -1;
                  goto LABEL_63;
                }
                v42 = StringPointerAccessor(v40);
                v44 = CallWrapperWith0((int)v42, 0, 10);
                *((_DWORD *)v41 - 1) = v44;
                *((_DWORD *)v41 - 1) = CRTFtol((double)v44 / flt_8ACF9C);
LABEL_63:
                ++v46;
                v41 += 8;
                v40 = (_DWORD *)NullCheckWrapper(v46);
              }
              while ( v40 );
            }
          }
        }
      }
    }
  }
}

