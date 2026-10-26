int __thiscall sub_4FE350(float *this, _DWORD *a2)
{
  int v3; // ecx
  int v4; // ecx
  int v6; // ebp
  int v7; // eax
  int v8; // ebp
  _DWORD *v9; // edi
  char *v10; // eax
  int v11; // eax
  int v12; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  double v18; // st7
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  double v25; // st7
  int v26; // eax
  int v27; // eax
  _DWORD *v28; // eax
  _DWORD *v29; // eax
  _DWORD *v30; // eax
  _DWORD *v31; // edi
  _DWORD *v32; // ecx
  int v33; // eax
  double i; // st7
  _DWORD *v35; // eax
  _DWORD *v36; // eax
  float *v37; // eax
  int v38; // eax
  int v39; // eax
  int v40; // eax
  int v41; // eax
  _DWORD *v42; // eax
  char *v43; // eax
  int v44; // eax
  int v45; // eax
  char *v46; // eax
  int v47; // [esp+10h] [ebp-1Ch]
  float v48; // [esp+10h] [ebp-1Ch]
  float v49; // [esp+14h] [ebp-18h]
  int v50; // [esp+18h] [ebp-14h]
  char *v51; // [esp+1Ch] [ebp-10h]
  char *v52; // [esp+20h] [ebp-Ch]
  char *v53; // [esp+24h] [ebp-8h]
  char *v54; // [esp+28h] [ebp-4h]
  char *v55; // [esp+30h] [ebp+4h]
  float v56; // [esp+30h] [ebp+4h]

  v49 = 0.30000001;
  v51 = SessionTypeNameLookup(dword_7C56A4, 0);
  v52 = 0;
  v53 = 0;
  v54 = SessionTypeNameLookup(7, 0);
  switch ( dword_7C56A4 )
  {
    case 1:
    case 7:
      v4 = 5;
      goto LABEL_8;
    case 2:
      v3 = 1;
      goto LABEL_6;
    case 3:
    case 4:
      v52 = SessionTypeNameLookup(5, 0);
      v53 = SessionTypeNameLookup(1, 0);
      break;
    case 5:
      v4 = 1;
LABEL_8:
      v52 = SessionTypeNameLookup(v4, 0);
      break;
    case 6:
      v3 = 7;
LABEL_6:
      v52 = SessionTypeNameLookup(v3, 0);
      v53 = SessionTypeNameLookup(5, 0);
      break;
    default:
      break;
  }
  v6 = 0;
  while ( 1 )
  {
    if ( (&v51)[v6] )
    {
      a2 = (_DWORD *)StringKeyedLinkedListSearch((&v51)[v6]);
      if ( a2 )
        break;
    }
    if ( ++v6 >= 4 )
      goto LABEL_24;
  }
  v47 = v6;
  v50 = CRTFtol(100.0 / flt_8ACF9C + 0.5);
  v7 = DataEntryAccessor(a2);
  v8 = sub_587ECE(v7);
  if ( v8 <= 0 )
    v8 = 100;
  v9 = a2;
  v55 = (&v51)[v47];
  while ( 1 )
  {
    v9 = (_DWORD *)ShortComputation_adb0(v9);
    if ( !v9 )
      break;
    v10 = StringPointerAccessor(v9);
    if ( !sub_588410(v10, v55) )
    {
      v11 = DataEntryAccessor(v9);
      v12 = sub_587ECE(v11);
      if ( v12 <= 0 )
        v12 = 100;
      if ( v12 >= v50 && v12 < v8 )
      {
        a2 = v9;
        v8 = v12;
      }
    }
  }
LABEL_24:
  if ( !a2 )
    return -1;
  this[8] = 0.0;
  this[9] = 0.0;
  this[10] = 0.0;
  this[11] = 0.0;
  this[12] = 20.0;
  this[13] = 22.0;
  v14 = StringKeyedLinkedListSearch(aConditions);
  if ( v14 )
  {
    v15 = DataEntryAccessor(v14);
    v49 = WeatherNameWetnessMultiplier(v15);
    sub_4FDE00((int)this, v49);
  }
  v16 = StringKeyedLinkedListSearch(aTrackwetness);
  if ( v16 )
  {
    v17 = DataEntryAccessor(v16);
    v18 = WeatherSeverityGripMultiplier(v17);
    this[10] = v18;
    this[11] = v18;
  }
  v19 = StringKeyedLinkedListSearch(aOnpathwetness);
  if ( v19 )
  {
    v20 = DataEntryAccessor(v19);
    this[10] = WeatherSeverityGripMultiplier(v20);
  }
  v21 = StringKeyedLinkedListSearch(aOffpathwetness_0);
  if ( v21 )
  {
    v22 = DataEntryAccessor(v21);
    this[11] = WeatherSeverityGripMultiplier(v22);
  }
  if ( this[11] < (double)this[10] )
    this[11] = this[10];
  v23 = StringKeyedLinkedListSearch(aAmbienttemp);
  if ( v23 )
  {
    v24 = DataEntryAccessor(v23);
    v25 = sub_4FE2B0(v24);
    this[12] = v25;
    this[13] = v25 + 2.0;
  }
  v26 = StringKeyedLinkedListSearch(aTracktemp);
  if ( v26 )
  {
    v27 = DataEntryAccessor(v26);
    this[13] = sub_4FE2B0(v27);
  }
  v28 = (_DWORD *)OperatorNewNhMallocWrapper(16);
  if ( v28 )
    v29 = FloatArrayInitializer(v28);
  else
    v29 = 0;
  *((_DWORD *)this + 15) = v29;
  *v29 = 0;
  *(float *)(*((_DWORD *)this + 15) + 4) = this[12];
  *(float *)(*((_DWORD *)this + 15) + 8) = v49;
  this[14] = this[15];
  v56 = flt_5EA408;
  if ( flt_5EA408 < 16.0 || flt_5EA408 > 1024.0 )
    v56 = 92.0;
  v30 = (_DWORD *)StringKeyedLinkedListSearch(aMinute);
  v31 = v30;
  if ( v30 )
  {
    v32 = v30;
LABEL_59:
    v45 = DataEntryAccessor(v32);
    for ( i = sub_58850F(v45) * 60.0; ; i = sub_58850F(v33) * v56 )
    {
      v35 = (_DWORD *)OperatorNewNhMallocWrapper(16);
      if ( v35 )
        v36 = FloatArrayInitializer(v35);
      else
        v36 = 0;
      *(_DWORD *)(*((_DWORD *)this + 14) + 12) = v36;
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 14) + 12) + 4) = *(_DWORD *)(*((_DWORD *)this + 14) + 4);
      *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 14) + 12) + 8) = *(_DWORD *)(*((_DWORD *)this + 14) + 8);
      v37 = *(float **)(*((_DWORD *)this + 14) + 12);
      *((_DWORD *)this + 14) = v37;
      v48 = i;
      *v37 = v48;
      *(_DWORD *)(*((_DWORD *)this + 14) + 12) = 0;
      v38 = StringKeyedLinkedListSearch(aConditions);
      if ( v38 )
      {
        v39 = DataEntryAccessor(v38);
        *(float *)(*((_DWORD *)this + 14) + 8) = WeatherNameWetnessMultiplier(v39);
      }
      v40 = StringKeyedLinkedListSearch(aAmbienttemp);
      if ( v40 )
      {
        v41 = DataEntryAccessor(v40);
        *(float *)(*((_DWORD *)this + 14) + 4) = sub_4FE2B0(v41);
      }
      v42 = (_DWORD *)ShortComputation_adb0(v31);
      v31 = v42;
      if ( !v42 )
        break;
      v43 = StringPointerAccessor(v42);
      v44 = sub_588410(v43, aMinute);
      v32 = v31;
      if ( !v44 )
        goto LABEL_59;
      v46 = StringPointerAccessor(v31);
      if ( sub_588410(v46, &off_5C330C) )
        break;
LABEL_49:
      v33 = DataEntryAccessor(v31);
    }
  }
  else
  {
    v31 = (_DWORD *)StringKeyedLinkedListSearch(&off_5C330C);
    if ( v31 )
      goto LABEL_49;
  }
  return 0;
}

