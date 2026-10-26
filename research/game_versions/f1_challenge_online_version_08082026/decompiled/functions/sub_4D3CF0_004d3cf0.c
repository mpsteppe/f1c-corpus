int __thiscall sub_4D3CF0(int this)
{
  int v2; // eax
  int v3; // edx
  int v4; // edx
  char *v5; // eax
  const char *v6; // ebp
  char *v7; // edx
  char v8; // cl
  char *v9; // edi
  __int16 v10; // cx
  int v11; // eax
  bool v12; // zf
  int v13; // eax
  char v14; // cl
  int v15; // eax
  char v16; // cl
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
  int v27; // ebp
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  int v37; // eax
  char *v38; // eax
  char *v39; // edx
  char v40; // cl
  int v41; // edx
  char v42; // al
  char *v43; // edi
  char *v44; // eax
  char *v45; // edx
  char v46; // cl
  char v47; // dl
  char *v48; // edi
  int v49; // eax
  int v50; // eax
  int v51; // eax
  int v52; // eax
  int v53; // eax
  int v54; // eax
  int v55; // eax
  int v56; // eax
  char *v57; // eax
  int v58; // ebp
  char *v59; // edx
  char v60; // cl
  char v61; // dl
  char *v62; // edi
  int v63; // eax
  int v64; // eax
  int v65; // eax
  int v66; // eax
  int result; // eax
  float *v68; // ecx
  double v69; // [esp-4h] [ebp-16Ch]
  float v70; // [esp+10h] [ebp-158h] BYREF
  float v71; // [esp+14h] [ebp-154h] BYREF
  int v72; // [esp+18h] [ebp-150h]
  char *v73; // [esp+1Ch] [ebp-14Ch]
  int v74; // [esp+20h] [ebp-148h] BYREF
  int v75; // [esp+24h] [ebp-144h]
  char v76[64]; // [esp+28h] [ebp-140h] BYREF
  char v77[64]; // [esp+68h] [ebp-100h] BYREF
  char v78[64]; // [esp+A8h] [ebp-C0h] BYREF
  _BYTE v79[64]; // [esp+E8h] [ebp-80h] BYREF
  char v80[64]; // [esp+128h] [ebp-40h] BYREF

  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_3, 2481) )
    sub_4D7AA0(&unk_8AD25C, aEnteredSteward_1);
  *(_BYTE *)(this + 192) = 0;
  *(_DWORD *)(this + 188) = 1065353216;
  *(_DWORD *)(this + 288) = 0;
  sub_4D1CD0((_DWORD *)this, 0);
  sub_4D0EC0((_DWORD *)(this + 232), 1);
  sub_4D0EC0((_DWORD *)(this + 244), 2);
  v2 = *(_DWORD *)(this + 268);
  v3 = 0;
  *(_BYTE *)(this + 260) = 0;
  *(_DWORD *)(this + 280) = -831624408;
  if ( v2 > 0 )
  {
    do
    {
      sub_4D0F00((_DWORD *)(*(_DWORD *)(this + 272) + 8 * v3), 0);
      *(_DWORD *)(*(_DWORD *)(this + 276) + 4 * v4) = 0;
      v3 = v4 + 1;
    }
    while ( v3 < *(_DWORD *)(this + 268) );
  }
  *(_DWORD *)(this + 216) = 2139095039;
  *(_BYTE *)(this + 193) = 0;
  *(_BYTE *)(this + 194) = 0;
  *(_DWORD *)(this + 284) = 0;
  v5 = sub_42CE30(dword_7C56A4, 0);
  v6 = v5;
  v73 = v5;
  v7 = (char *)(v77 - v5);
  do
  {
    v8 = *v5;
    v5[(_DWORD)v7] = *v5;
    ++v5;
  }
  while ( v8 );
  *(_DWORD *)&v77[strlen(v77)] = off_5D438C;
  strcpy(v78, v6);
  v9 = &v78[strlen(v78) + 1];
  v10 = word_5D4388;
  *(_DWORD *)--v9 = dword_5D4384;
  v11 = dword_7C56A4;
  v12 = dword_7C56A4 == 0;
  *((_WORD *)v9 + 2) = v10;
  if ( v12 || v11 == 6 || v11 == 7 )
  {
    v15 = 0;
    do
    {
      v16 = byte_5D4368[v15];
      v79[v15++] = v16;
    }
    while ( v16 );
  }
  else
  {
    v13 = 0;
    do
    {
      v14 = byte_5D4374[v13];
      v79[v13++] = v14;
    }
    while ( v14 );
  }
  *(_DWORD *)(this + 212) = 1102169884;
  strcpy((char *)(this + 195), aWednesday);
  *(_DWORD *)(this + 208) = 1190993920;
  v72 = sub_568210(aDefaultscoring);
  if ( v72 )
  {
    v17 = sub_5679C0(v79);
    if ( v17 )
    {
      v18 = sub_567970(v17);
      *(float *)(this + 212) = sub_58850F(v18) * 0.2777777777777778;
    }
    v19 = sub_5679C0(v77);
    if ( v19 )
    {
      v20 = sub_567970(v19);
      sub_587DD0(this + 195, v20, 11);
      *(_BYTE *)(this + 206) = 0;
    }
    v21 = sub_5679C0(v78);
    if ( v21 )
    {
      LODWORD(v69) = &v70;
      v70 = 0.0;
      v22 = sub_567970(v21);
      if ( (int)sub_5887ED(v22, "%d:%d:%f", &v74, &v71, v69) >= 2 )
        *(float *)(this + 208) = (double)v74 * 3600.0 + (double)SLODWORD(v71) * 60.0 + v70;
    }
    v23 = sub_5679C0(aRacetime);
    if ( v23 )
    {
      LODWORD(v69) = &v71;
      v24 = sub_567970(v23);
      if ( sub_5887ED(v24, "%f", v69) == 1 )
        *(float *)(this + 184) = v71 * 60.0;
    }
    v25 = sub_5679C0(aRacetimescaled);
    if ( v25 )
    {
      LODWORD(v69) = &v71;
      v26 = sub_567970(v25);
      if ( sub_5887ED(v26, "%f", v69) == 1 )
        *(float *)(this + 184) = flt_7D0798 * v71 * 60.0;
    }
  }
  v27 = sub_4C5840(0);
  v75 = v27;
  if ( v27 )
  {
    v28 = sub_5679C0(v79);
    if ( v28 )
    {
      v29 = sub_567970(v28);
      *(float *)(this + 212) = sub_58850F(v29) * 0.2777777777777778;
    }
    v30 = sub_5679C0(v77);
    if ( v30 )
    {
      v31 = sub_567970(v30);
      sub_587DD0(this + 195, v31, 11);
      *(_BYTE *)(this + 206) = 0;
    }
    v32 = sub_5679C0(v78);
    if ( v32 )
    {
      LODWORD(v69) = &v70;
      v70 = 0.0;
      v33 = sub_567970(v32);
      if ( (int)sub_5887ED(v33, "%d:%d:%f", &v71, &v74, v69) >= 2 )
        *(float *)(this + 208) = (double)SLODWORD(v71) * 3600.0 + (double)v74 * 60.0 + v70;
    }
    v34 = sub_5679C0(aRacetime);
    if ( v34 )
    {
      LODWORD(v69) = &v71;
      v35 = sub_567970(v34);
      if ( sub_5887ED(v35, "%f", v69) == 1 )
        *(float *)(this + 184) = v71 * 60.0;
    }
    v36 = sub_5679C0(aRacetimescaled);
    if ( v36 )
    {
      LODWORD(v69) = &v71;
      v37 = sub_567970(v36);
      if ( sub_5887ED(v37, "%f", v69) == 1 )
        *(float *)(this + 184) = flt_7D0798 * v71 * 60.0;
    }
  }
  switch ( dword_7C56A4 )
  {
    case 0:
      sub_42D140(&dword_7C569C, 5u);
      *(_DWORD *)(this + 172) = 0x7FFFFFFF;
      *(_DWORD *)(this + 176) = 0;
      *(_DWORD *)(this + 180) = 2139095039;
      sub_4D0EC0((_DWORD *)(this + 244), 1);
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      sub_42D140(&dword_7C569C, 0);
      *(_DWORD *)(this + 176) = 1106247680;
      sub_4D0EC0((_DWORD *)(this + 244), 2);
      if ( dword_7C56A4 == 5 )
        *(_DWORD *)(this + 172) = dword_7D04A4;
      else
        *(_DWORD *)(this + 172) = 0x7FFFFFFF;
      switch ( dword_7C56A4 )
      {
        case 1:
        case 2:
        case 5:
          v70 = 3600.0;
          break;
        case 3:
        case 4:
          v70 = 2700.0;
          break;
        case 6:
          v70 = 1800.0;
          break;
        default:
          break;
      }
      v38 = v73;
      v39 = (char *)(v80 - v73);
      do
      {
        v40 = *v38;
        v39[(_DWORD)v38] = *v38;
        ++v38;
      }
      while ( v40 );
      v41 = dword_5D4324;
      v42 = byte_5D4328;
      v43 = &v80[strlen(v80)];
      *(_DWORD *)v43 = dword_5D4320;
      *((_DWORD *)v43 + 1) = v41;
      v43[8] = v42;
      v44 = v73;
      v45 = (char *)(v76 - v73);
      do
      {
        v46 = *v44;
        v45[(_DWORD)v44] = *v44;
        ++v44;
      }
      while ( v46 );
      v47 = aLaps_1[4];
      v48 = &v76[strlen(v76)];
      v12 = v72 == 0;
      *(_DWORD *)v48 = *(_DWORD *)aLaps_1;
      v48[4] = v47;
      if ( !v12 )
      {
        v49 = sub_5679C0(v80);
        if ( v49 )
        {
          v50 = sub_567970(v49);
          v70 = sub_58850F(v50) * 60.0;
        }
        v51 = sub_5679C0(v76);
        if ( v51 )
        {
          v52 = sub_567970(v51);
          *(_DWORD *)(this + 172) = sub_587ECE(v52);
        }
      }
      if ( v27 )
      {
        v53 = sub_5679C0(v80);
        if ( v53 )
        {
          v54 = sub_567970(v53);
          v70 = sub_58850F(v54) * 60.0;
        }
        v55 = sub_5679C0(v76);
        if ( v55 )
        {
          v56 = sub_567970(v55);
          *(_DWORD *)(this + 172) = sub_587ECE(v56);
        }
      }
      *(float *)(this + 180) = v70 + *(float *)(this + 176);
      break;
    case 7:
      sub_40DA30((char *)this);
      sub_40DC00();
      sub_40DCD0((_DWORD *)this, (int)aPreracepresent);
      v57 = v73;
      *(float *)&v58 = NAN;
      v70 = NAN;
      v59 = (char *)(v76 - v73);
      do
      {
        v60 = *v57;
        v59[(_DWORD)v57] = *v57;
        ++v57;
      }
      while ( v60 );
      v61 = aLaps_1[4];
      v62 = &v76[strlen(v76)];
      v12 = v72 == 0;
      *(_DWORD *)v62 = *(_DWORD *)aLaps_1;
      v62[4] = v61;
      if ( !v12 )
      {
        v63 = sub_5679C0(v76);
        if ( v63 )
        {
          v64 = sub_567970(v63);
          *(float *)&v58 = COERCE_FLOAT(sub_587ECE(v64));
          v70 = *(float *)&v58;
        }
      }
      if ( v75 )
      {
        v65 = sub_5679C0(v76);
        if ( v65 )
        {
          v66 = sub_567970(v65);
          *(float *)&v58 = COERCE_FLOAT(sub_587ECE(v66));
          v70 = *(float *)&v58;
        }
      }
      *(_DWORD *)(this + 172) = dword_7D05A0;
      *(_DWORD *)(this + 284) = dword_7D0894;
      if ( *(float *)&v58 != NAN )
        *(float *)(this + 188) = (double)SLODWORD(v70) / (double)*(int *)(this + 172);
      if ( dword_7CEC90 )
      {
        sub_42D140(&dword_7C569C, 0);
        *(_DWORD *)(this + 176) = 1106247680;
        *(float *)(this + 180) = (double)dword_7CEC30 + (double)dword_7CEC54 + 30.0;
        sub_4D0EC0((_DWORD *)(this + 244), 2);
        sub_4D2DD0((_DWORD *)this);
      }
      else if ( dword_7CED8C )
      {
        sub_42D140(&dword_7C569C, 2u);
        *(_DWORD *)(this + 176) = 0;
        *(_DWORD *)(this + 180) = 1133903872;
        sub_4D0EC0((_DWORD *)(this + 244), 2);
        sub_4D2DD0((_DWORD *)this);
      }
      else
      {
        if ( dword_7CEE88 )
        {
          sub_42D140(&dword_7C569C, 3u);
          *(_DWORD *)(this + 176) = 0;
          *(_DWORD *)(this + 180) = 0;
        }
        else
        {
          *(_BYTE *)(this + 194) = 0;
          sub_42D140(&dword_7C569C, 4u);
          *(_DWORD *)(this + 216) = 2139095039;
          *(_DWORD *)(this + 176) = 2139095039;
          *(_DWORD *)(this + 180) = 2139095039;
        }
        sub_4D0EC0((_DWORD *)(this + 244), 2);
      }
      break;
    default:
      break;
  }
  memset((void *)(this + 296), 0xFFu, 0x68u);
  *(_WORD *)(this + 400) = -1;
  *(_BYTE *)(this + 402) = -1;
  result = sub_4C29F0(dword_7D2DB0);
  v68 = *(float **)(this + 168);
  if ( v68 )
    return sub_448300(v68);
  return result;
}
