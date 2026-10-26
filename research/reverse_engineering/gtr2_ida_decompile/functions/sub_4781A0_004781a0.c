int __usercall sub_4781A0@<eax>(int a1@<ecx>, int a2@<esi>)
{
  int v3; // ecx
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  char v25; // cl
  char v26; // cl
  char v27; // cl
  int v28; // ecx
  double v29; // st7
  int v30; // ecx
  int v31; // ecx
  int v32; // ecx
  int v33; // eax
  int v34; // ecx
  int v35; // eax
  int v36; // ecx
  int v37; // ecx
  char v38; // cl
  char v39; // cl
  char v40; // cl
  char v41; // cl
  char v42; // cl
  int v44; // [esp+4h] [ebp-Ch]
  int v46; // [esp+8h] [ebp-8h]

  sub_538940(&unk_BE1CFD, a1 + 32, a2);
  sub_53A160(0);
  v3 = dword_B737B8;
  dword_B737B0 = *(_DWORD *)(a1 + 152);
  if ( dword_B737B0 < dword_B737B8 || (v3 = dword_B737BC, dword_B737B0 > dword_B737BC) )
    dword_B737B0 = v3;
  v4 = dword_B737DC;
  dword_B737D4 = *(_DWORD *)(a1 + 156);
  if ( dword_B737D4 < (unsigned int)dword_B737DC || (v4 = dword_B737E0, dword_B737D4 > (unsigned int)dword_B737E0) )
    dword_B737D4 = v4;
  sub_50F030(&byte_B6F530, *(unsigned __int8 *)(a1 + 160), v44, v46);
  sub_5100A0(&byte_B6F530, a1 + 64);
  v5 = *(char *)(a1 + 104);
  v6 = dword_B72C24;
  dword_B72C1C = v5;
  if ( v5 < dword_B72C24 || (v6 = dword_B72C28, v5 > dword_B72C28) )
    dword_B72C1C = v6;
  v7 = *(char *)(a1 + 106);
  v8 = dword_B733C8;
  dword_B733C0 = v7;
  if ( v7 < dword_B733C8 || (v8 = dword_B733CC, v7 > dword_B733CC) )
    dword_B733C0 = v8;
  v9 = *(char *)(a1 + 107);
  v10 = dword_B72EC4;
  dword_B72EBC = v9;
  if ( v9 < dword_B72EC4 || (v10 = dword_B72EC8, v9 > dword_B72EC8) )
    dword_B72EBC = v10;
  v11 = *(char *)(a1 + 108);
  v12 = dword_B73008;
  dword_B73000 = v11;
  if ( v11 < dword_B73008 || (v12 = dword_B7300C, v11 > dword_B7300C) )
    dword_B73000 = v12;
  v13 = *(char *)(a1 + 109);
  v14 = dword_B71DF4;
  dword_B71DEC = v13;
  if ( v13 < dword_B71DF4 || (v14 = dword_B71DF8, v13 > dword_B71DF8) )
    dword_B71DEC = v14;
  v15 = *(char *)(a1 + 110);
  v16 = dword_B6FE28;
  dword_B6FE20 = v15;
  if ( v15 < dword_B6FE28 || (v16 = dword_B6FE2C, v15 > dword_B6FE2C) )
    dword_B6FE20 = v16;
  v17 = *(char *)(a1 + 111);
  v18 = dword_B732C0;
  dword_B732B8 = v17;
  if ( v17 < dword_B732C0 || (v18 = dword_B732C4, v17 > dword_B732C4) )
    dword_B732B8 = v18;
  v19 = *(char *)(a1 + 112);
  v20 = dword_B706D4;
  dword_B706CC = v19;
  if ( v19 < dword_B706D4 || (v20 = dword_B706D8, v19 > dword_B706D8) )
    dword_B706CC = v20;
  v21 = *(char *)(a1 + 113);
  v22 = dword_B70590;
  dword_B70588 = v21;
  if ( v21 < dword_B70590 || (v22 = dword_B70594, v21 > dword_B70594) )
    dword_B70588 = v22;
  dword_B72958 = *(_DWORD *)(a1 + 96);
  if ( *(float *)&dword_B72958 >= (double)flt_B72960 )
  {
    if ( *(float *)&dword_B72958 > (double)flt_B72964 )
      dword_B72958 = LODWORD(flt_B72964);
  }
  else
  {
    dword_B72958 = LODWORD(flt_B72960);
  }
  v23 = *(__int16 *)(a1 + 166);
  v24 = dword_B73350;
  dword_B73348 = v23;
  if ( v23 < dword_B73350 || (v24 = dword_B73354, v23 > dword_B73354) )
    dword_B73348 = v24;
  v25 = byte_B7352A;
  byte_B73528 = *(_BYTE *)(a1 + 114);
  if ( (unsigned __int8)byte_B73528 < (unsigned __int8)byte_B7352A
    || (v25 = byte_B7352B, (unsigned __int8)byte_B73528 > (unsigned __int8)byte_B7352B) )
  {
    byte_B73528 = v25;
  }
  v26 = byte_B73572;
  byte_B73570 = *(_BYTE *)(a1 + 115);
  if ( (unsigned __int8)byte_B73570 < (unsigned __int8)byte_B73572
    || (v26 = byte_B73573, (unsigned __int8)byte_B73570 > (unsigned __int8)byte_B73573) )
  {
    byte_B73570 = v26;
  }
  v27 = byte_B7358A;
  byte_B73588 = *(_BYTE *)(a1 + 116);
  if ( (unsigned __int8)byte_B73588 < (unsigned __int8)byte_B7358A
    || (v27 = byte_B7358B, (unsigned __int8)byte_B73588 > (unsigned __int8)byte_B7358B) )
  {
    byte_B73588 = v27;
  }
  v28 = dword_B6FC30;
  dword_B6FC28 = (unsigned __int16)(*(_WORD *)(a1 + 180) & 0x100) >> 8;
  if ( dword_B6FC28 < dword_B6FC30 || (v28 = dword_B6FC34, dword_B6FC28 > dword_B6FC34) )
    dword_B6FC28 = v28;
  if ( (*(_BYTE *)(a1 + 180) & 8) != 0 )
  {
    v29 = (double)*(unsigned __int16 *)(a1 + 186) * 0.001;
    flt_B735A0 = v29;
    if ( v29 >= flt_B735A8 )
    {
      if ( flt_B735A0 > (double)flt_B735AC )
        flt_B735A0 = flt_B735AC;
    }
    else
    {
      flt_B735A0 = flt_B735A8;
    }
  }
  v30 = dword_B700EC;
  dword_B700E4 = (unsigned __int16)(*(_WORD *)(a1 + 180) & 0x200) >> 9;
  if ( dword_B700E4 < dword_B700EC || (v30 = dword_B700F0, dword_B700E4 > dword_B700F0) )
    dword_B700E4 = v30;
  v31 = dword_B70230;
  dword_B70228 = (unsigned __int16)(*(_WORD *)(a1 + 180) & 0x400) >> 10;
  if ( dword_B70228 < dword_B70230 || (v31 = dword_B70234, dword_B70228 > dword_B70234) )
    dword_B70228 = v31;
  v32 = dword_B70014;
  dword_B7000C = ((int)*(unsigned __int16 *)(a1 + 180) >> 11) & 1;
  if ( dword_B7000C < dword_B70014 || (v32 = dword_B70018, dword_B7000C > dword_B70018) )
    dword_B7000C = v32;
  v33 = *(__int16 *)(a1 + 182);
  v34 = dword_B6FFB4;
  dword_B6FFAC = v33;
  if ( v33 < dword_B6FFB4 || (v34 = dword_B6FFB8, v33 > dword_B6FFB8) )
    dword_B6FFAC = v34;
  v35 = *(__int16 *)(a1 + 184);
  v36 = dword_B6FFD8;
  dword_B6FFD0 = v35;
  if ( v35 < dword_B6FFD8 || (v36 = dword_B6FFDC, v35 > dword_B6FFDC) )
    dword_B6FFD0 = v36;
  v37 = dword_B71F74;
  dword_B71F6C = (*(unsigned __int8 *)(a1 + 161) >> 1) & 1;
  if ( dword_B71F6C < dword_B71F74 || (v37 = dword_B71F78, dword_B71F6C > dword_B71F78) )
    dword_B71F6C = v37;
  v38 = byte_B6FEBE;
  byte_B6FEBC = *(_BYTE *)(a1 + 168);
  if ( (unsigned __int8)byte_B6FEBC < (unsigned __int8)byte_B6FEBE
    || (v38 = byte_B6FEBF, (unsigned __int8)byte_B6FEBC > (unsigned __int8)byte_B6FEBF) )
  {
    byte_B6FEBC = v38;
  }
  v39 = byte_B6FED6;
  byte_B6FED4 = *(_BYTE *)(a1 + 169);
  if ( (unsigned __int8)byte_B6FED4 < (unsigned __int8)byte_B6FED6
    || (v39 = byte_B6FED7, (unsigned __int8)byte_B6FED4 > (unsigned __int8)byte_B6FED7) )
  {
    byte_B6FED4 = v39;
  }
  v40 = byte_B6FEEE;
  byte_B6FEEC = *(_BYTE *)(a1 + 170);
  if ( (unsigned __int8)byte_B6FEEC < (unsigned __int8)byte_B6FEEE
    || (v40 = byte_B6FEEF, (unsigned __int8)byte_B6FEEC > (unsigned __int8)byte_B6FEEF) )
  {
    byte_B6FEEC = v40;
  }
  v41 = byte_B6FF06;
  byte_B6FF04 = *(_BYTE *)(a1 + 171);
  if ( (unsigned __int8)byte_B6FF04 < (unsigned __int8)byte_B6FF06
    || (v41 = byte_B6FF07, (unsigned __int8)byte_B6FF04 > (unsigned __int8)byte_B6FF07) )
  {
    byte_B6FF04 = v41;
  }
  v42 = byte_B6FF1E;
  byte_B6FF1C = *(_BYTE *)(a1 + 172);
  if ( (unsigned __int8)byte_B6FF1C < (unsigned __int8)byte_B6FF1E
    || (v42 = byte_B6FF1F, (unsigned __int8)byte_B6FF1C > (unsigned __int8)byte_B6FF1F) )
  {
    byte_B6FF1C = v42;
  }
  return sub_50FD00(5);
}
