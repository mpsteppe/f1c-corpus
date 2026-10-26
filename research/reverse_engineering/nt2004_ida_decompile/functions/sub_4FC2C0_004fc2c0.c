int __thiscall sub_4FC2C0(int this)
{
  int v2; // eax
  int v3; // edx
  int v4; // edx
  int v5; // eax
  int v6; // edx
  int v7; // edx
  char *v8; // eax
  const char *v9; // ebp
  char *v10; // edx
  char v11; // cl
  char *v12; // edi
  __int16 v13; // cx
  int v14; // eax
  bool v15; // zf
  int v16; // eax
  char v17; // cl
  int v18; // eax
  char v19; // cl
  int v20; // eax
  const char *v21; // eax
  int v22; // eax
  const char *v23; // eax
  int v24; // eax
  const char *v25; // eax
  int v26; // eax
  const char *v27; // eax
  int v28; // eax
  int v29; // ebp
  char *v30; // ecx
  int v31; // eax
  const char *v32; // eax
  int v33; // eax
  const char *v34; // eax
  int v35; // eax
  const char *v36; // eax
  int v37; // eax
  const char *v38; // eax
  char *v39; // eax
  char *v40; // edx
  char v41; // cl
  char *v42; // edi
  int v43; // eax
  char v44; // cl
  char *v45; // eax
  char *v46; // edx
  char v47; // cl
  char v48; // al
  char *v49; // edi
  int v50; // eax
  const char *v51; // eax
  int v52; // eax
  const char *v53; // eax
  int v54; // eax
  const char *v55; // eax
  int v56; // eax
  const char *v57; // eax
  char *v58; // eax
  int v59; // ebp
  char *v60; // edx
  char v61; // cl
  char v62; // al
  char *v63; // edi
  int v64; // eax
  const char *v65; // eax
  int v66; // eax
  const char *v67; // eax
  int v68; // eax
  signed int v69; // edi
  int v70; // edx
  char v72; // [esp+0h] [ebp-164h]
  float v73; // [esp+Ch] [ebp-158h] BYREF
  int v74; // [esp+10h] [ebp-154h] BYREF
  int v75; // [esp+14h] [ebp-150h] BYREF
  char *v76; // [esp+18h] [ebp-14Ch]
  int v77; // [esp+1Ch] [ebp-148h]
  int v78; // [esp+20h] [ebp-144h] BYREF
  char v79[64]; // [esp+24h] [ebp-140h] BYREF
  char v80[64]; // [esp+64h] [ebp-100h] BYREF
  char v81[64]; // [esp+A4h] [ebp-C0h] BYREF
  char String1[64]; // [esp+E4h] [ebp-80h] BYREF
  char v83[64]; // [esp+124h] [ebp-40h] BYREF

  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_21, 3304) )
    sub_500FE0((int)&unk_7D7920, aEnteredSteward_1, v72);
  *(_BYTE *)(this + 160) = 0;
  *(_DWORD *)(this + 156) = 1065353216;
  *(_DWORD *)(this + 292) = 0;
  *(_DWORD *)(this + 296) = 0;
  sub_4FA8E0((_DWORD *)this, 0);
  sub_4F8D30((_DWORD *)(this + 212), 1);
  sub_4F8D30((_DWORD *)(this + 224), 2);
  v2 = *(_DWORD *)(this + 264);
  v3 = 0;
  *(_BYTE *)(this + 256) = 0;
  if ( v2 > 0 )
  {
    do
    {
      sub_4F8D70((_DWORD *)(*(_DWORD *)(this + 268) + 8 * v3), 0);
      v3 = v4 + 1;
    }
    while ( v3 < *(_DWORD *)(this + 264) );
  }
  v5 = *(_DWORD *)(this + 264);
  v6 = 0;
  *(_DWORD *)(this + 196) = 2139095039;
  *(_BYTE *)(this + 161) = 0;
  *(_BYTE *)(this + 162) = 0;
  if ( v5 > 0 )
  {
    do
    {
      sub_4F8D70((_DWORD *)(*(_DWORD *)(this + 268) + 8 * v6), 0);
      v6 = v7 + 1;
    }
    while ( v6 < *(_DWORD *)(this + 264) );
  }
  *(_DWORD *)(this + 280) = 0;
  *(_DWORD *)(this + 284) = 5;
  *(_DWORD *)(this + 288) = 0;
  *(_BYTE *)(this + 188) = 0;
  *(_BYTE *)(this + 189) = 0;
  sub_4F7ED0((_DWORD *)(this + 356));
  *(_DWORD *)(this + 1192) = 0;
  *(_BYTE *)(this + 1196) = 0;
  v8 = sub_42F570(dword_75CBB0, 0);
  v9 = v8;
  v76 = v8;
  v10 = (char *)(v80 - v8);
  do
  {
    v11 = *v8;
    v8[(_DWORD)v10] = *v8;
    ++v8;
  }
  while ( v11 );
  *(_DWORD *)&v80[strlen(v80)] = off_611DB4;
  strcpy(v81, v9);
  v12 = &v81[strlen(v81) + 1];
  v13 = word_611DB0;
  *(_DWORD *)--v12 = dword_611DAC;
  v14 = dword_75CBB0;
  v15 = dword_75CBB0 == 6;
  *((_WORD *)v12 + 2) = v13;
  if ( v15 || v14 == 7 )
  {
    v18 = 0;
    do
    {
      v19 = byte_611D90[v18];
      String1[v18++] = v19;
    }
    while ( v19 );
  }
  else
  {
    v16 = 0;
    do
    {
      v17 = byte_611D9C[v16];
      String1[v16++] = v17;
    }
    while ( v17 );
  }
  *(_DWORD *)(this + 180) = 1102169884;
  *(_DWORD *)(this + 184) = 1102169884;
  strcpy((char *)(this + 164), aWednesday);
  *(_DWORD *)(this + 176) = 1190993920;
  v77 = sub_57AE50(aDefaultscoring);
  if ( v77 )
  {
    v20 = sub_57A720(aFormationspeed);
    if ( v20 )
    {
      v21 = (const char *)sub_57A6D0(v20);
      *(float *)(this + 184) = atof(v21) * 0.44704;
    }
    v22 = sub_57A720(String1);
    if ( v22 )
    {
      v23 = (const char *)sub_57A6D0(v22);
      *(float *)(this + 180) = atof(v23) * 0.44704;
    }
    v24 = sub_57A720(v80);
    if ( v24 )
    {
      v25 = (const char *)sub_57A6D0(v24);
      strncpy((char *)(this + 164), v25, 0xBu);
      *(_BYTE *)(this + 175) = 0;
    }
    v26 = sub_57A720(v81);
    if ( v26 )
    {
      v73 = 0.0;
      v27 = (const char *)sub_57A6D0(v26);
      if ( sscanf(v27, "%d:%d:%f", &v75, &v78, &v73) >= 2 )
        *(float *)(this + 176) = (double)v75 * 3600.0 + (double)v78 * 60.0 + v73;
    }
  }
  v28 = sub_57AE50(aSeasonraces);
  v29 = 0;
  v75 = 0;
  if ( v28 )
  {
    v30 = dword_766594;
    if ( !dword_766594 )
      v30 = &byte_629120;
    v29 = sub_57A720(v30);
    v75 = v29;
    if ( v29 )
    {
      v31 = sub_57A720(aFormationspeed);
      if ( v31 )
      {
        v32 = (const char *)sub_57A6D0(v31);
        *(float *)(this + 184) = atof(v32) * 0.44704;
      }
      v33 = sub_57A720(String1);
      if ( v33 )
      {
        v34 = (const char *)sub_57A6D0(v33);
        *(float *)(this + 180) = atof(v34) * 0.44704;
      }
      v35 = sub_57A720(v80);
      if ( v35 )
      {
        v36 = (const char *)sub_57A6D0(v35);
        strncpy((char *)(this + 164), v36, 0xBu);
        *(_BYTE *)(this + 175) = 0;
      }
      v37 = sub_57A720(v81);
      if ( v37 )
      {
        v73 = 0.0;
        v38 = (const char *)sub_57A6D0(v37);
        if ( sscanf(v38, "%d:%d:%f", &v78, &v74, &v73) >= 2 )
          *(float *)(this + 176) = (double)v78 * 3600.0 + (double)v74 * 60.0 + v73;
      }
    }
  }
  switch ( dword_75CBB0 )
  {
    case 0:
    case 8:
      sub_42F950(&dword_75CBA8, 5);
      *(_DWORD *)(this + 144) = 0x7FFFFFFF;
      *(_DWORD *)(this + 148) = 0;
      *(_DWORD *)(this + 152) = 2139095039;
      sub_4F8D30((_DWORD *)(this + 224), 1);
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      sub_42F950(&dword_75CBA8, 0);
      *(_DWORD *)(this + 148) = 1084227584;
      sub_4F8D30((_DWORD *)(this + 224), 2);
      if ( dword_75CBB0 == 5 )
        *(_DWORD *)(this + 144) = *(_DWORD *)dword_768A2C;
      else
        *(_DWORD *)(this + 144) = 0x7FFFFFFF;
      switch ( dword_75CBB0 )
      {
        case 1:
        case 2:
        case 3:
        case 4:
        case 6:
          v73 = 3600.0;
          break;
        case 5:
          v73 = 3.4028235e38;
          break;
        default:
          break;
      }
      v39 = v76;
      v40 = (char *)(v83 - v76);
      do
      {
        v41 = *v39;
        v40[(_DWORD)v39] = *v39;
        ++v39;
      }
      while ( v41 );
      v42 = &v83[strlen(v83) + 1];
      v43 = dword_611D4C;
      v44 = byte_611D50;
      *(_DWORD *)--v42 = dword_611D48;
      *((_DWORD *)v42 + 1) = v43;
      v45 = v76;
      v42[8] = v44;
      v46 = (char *)(v79 - v45);
      do
      {
        v47 = *v45;
        v46[(_DWORD)v45] = *v45;
        ++v45;
      }
      while ( v47 );
      v48 = aLaps_1[4];
      v49 = &v79[strlen(v79)];
      *(_DWORD *)v49 = *(_DWORD *)aLaps_1;
      v49[4] = v48;
      if ( v77 )
      {
        v50 = sub_57A720(v83);
        if ( v50 )
        {
          v51 = (const char *)sub_57A6D0(v50);
          v73 = atof(v51) * 60.0;
        }
        v52 = sub_57A720(v79);
        if ( v52 )
        {
          v53 = (const char *)sub_57A6D0(v52);
          *(_DWORD *)(this + 144) = atol(v53);
        }
      }
      if ( v29 )
      {
        v54 = sub_57A720(v83);
        if ( v54 )
        {
          v55 = (const char *)sub_57A6D0(v54);
          v73 = atof(v55) * 60.0;
        }
        v56 = sub_57A720(v79);
        if ( v56 )
        {
          v57 = (const char *)sub_57A6D0(v56);
          *(_DWORD *)(this + 144) = atol(v57);
        }
      }
      *(float *)(this + 152) = v73 + *(float *)(this + 148);
      break;
    case 7:
      sub_414BB0((char *)this);
      sub_414D80();
      sub_414E50((_DWORD *)this, aPreracepresent);
      v58 = v76;
      v59 = -1;
      v60 = (char *)(v79 - v76);
      do
      {
        v61 = *v58;
        v60[(_DWORD)v58] = *v58;
        ++v58;
      }
      while ( v61 );
      v62 = aLaps_1[4];
      v63 = &v79[strlen(v79)];
      *(_DWORD *)v63 = *(_DWORD *)aLaps_1;
      v63[4] = v62;
      if ( v77 )
      {
        v64 = sub_57A720(v79);
        if ( v64 )
        {
          v65 = (const char *)sub_57A6D0(v64);
          v59 = atol(v65);
        }
      }
      if ( v75 )
      {
        v66 = sub_57A720(v79);
        if ( v66 )
        {
          v67 = (const char *)sub_57A6D0(v66);
          v59 = atol(v67);
        }
      }
      v68 = *(_DWORD *)dword_768B70;
      *(_DWORD *)(this + 144) = *(_DWORD *)dword_768B70;
      if ( v59 != -1 )
      {
        v74 = v68 + 1;
        *(float *)(this + 156) = (double)(v59 + 1) / (double)(v68 + 1);
      }
      if ( dword_766E00 )
      {
        sub_42F950(&dword_75CBA8, 0);
        *(_DWORD *)(this + 148) = 1084227584;
        *(_DWORD *)(this + 152) = 1155637248;
        sub_4F8D30((_DWORD *)(this + 224), 2);
        if ( dword_766F44 )
          *(float *)(this + 152) = *(float *)(this + 152) - 300.0;
      }
      else
      {
        if ( dword_766F44 )
        {
          sub_42F950(&dword_75CBA8, 2);
          *(_DWORD *)(this + 148) = 0;
          *(_DWORD *)(this + 152) = 1133903872;
        }
        else if ( dword_767088 )
        {
          sub_42F950(&dword_75CBA8, 3);
          *(_DWORD *)(this + 148) = 0;
          *(_DWORD *)(this + 152) = 0;
        }
        else
        {
          *(_BYTE *)(this + 162) = 0;
          sub_42F950(&dword_75CBA8, 4);
          *(_DWORD *)(this + 196) = 2139095039;
          *(_DWORD *)(this + 148) = 2139095039;
          *(_DWORD *)(this + 152) = 2139095039;
        }
        sub_4F8D30((_DWORD *)(this + 224), 2);
      }
      sub_4F80D0((_DWORD *)(this + 356));
      break;
    default:
      break;
  }
  if ( dword_75CBB0 == 5 && !sub_463490(dword_764D70) )
  {
    v69 = NumOfElements;
    v70 = rand() % v69;
    *(_DWORD *)(this + 192) = v70;
    if ( *(_DWORD *)(dword_75AAD0[v70] + 16584) != 1 )
      *(_DWORD *)(this + 192) = (v70 + 1) % (int)NumOfElements;
  }
  memset((void *)(this + 304), 0xFFu, 0x30u);
  sub_4F9F50((_DWORD *)this);
  nullsub_6(&unk_76BB28);
  byte_766124 = 0;
  dword_766128 = 0;
  return sub_4BA410();
}
