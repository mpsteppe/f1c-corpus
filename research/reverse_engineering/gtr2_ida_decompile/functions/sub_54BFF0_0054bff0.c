int __stdcall sub_54BFF0(int a1)
{
  int v1; // ecx
  int v2; // ecx
  int v3; // ecx
  char v4; // cl
  int v5; // ecx
  int v6; // ecx
  char v7; // cl
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  int v11; // ecx
  int v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // ecx
  int v16; // ecx
  int v17; // ecx

  sub_615860(a1);
  sub_615860(a1 + 128);
  sub_615860(a1 + 256);
  v1 = dword_B70038;
  dword_B70030 = *(_DWORD *)(a1 + 384);
  if ( dword_B70030 < dword_B70038 || (v1 = dword_B7003C, dword_B70030 > dword_B7003C) )
    dword_B70030 = v1;
  v2 = dword_B7017C;
  dword_B70174 = *(_DWORD *)(a1 + 388);
  if ( dword_B70174 < dword_B7017C || (v2 = dword_B70180, dword_B70174 > dword_B70180) )
    dword_B70174 = v2;
  v3 = dword_B70014;
  dword_B7000C = *(_DWORD *)(a1 + 392);
  if ( dword_B7000C < dword_B70014 || (v3 = dword_B70018, dword_B7000C > dword_B70018) )
    dword_B7000C = v3;
  v4 = byte_B702BA;
  byte_B702B8 = *(_BYTE *)(a1 + 396);
  if ( (unsigned __int8)byte_B702B8 < (unsigned __int8)byte_B702BA
    || (v4 = byte_B702BB, (unsigned __int8)byte_B702B8 > (unsigned __int8)byte_B702BB) )
  {
    byte_B702B8 = v4;
  }
  v5 = dword_B704DC;
  dword_B704D4 = *(_DWORD *)(a1 + 400);
  if ( dword_B704D4 < dword_B704DC || (v5 = dword_B704E0, dword_B704D4 > dword_B704E0) )
    dword_B704D4 = v5;
  v6 = dword_B70620;
  dword_B70618[0] = *(_DWORD *)(a1 + 404);
  if ( dword_B70618[0] < dword_B70620 || (v6 = dword_B70624, dword_B70618[0] > dword_B70624) )
    dword_B70618[0] = v6;
  v7 = byte_B7075E;
  byte_B7075C[0] = *(_BYTE *)(a1 + 408);
  if ( (unsigned int)byte_B7075C[0] < (unsigned __int8)byte_B7075E
    || (v7 = byte_B7075F, (unsigned int)byte_B7075C[0] > (unsigned __int8)byte_B7075F) )
  {
    byte_B7075C[0] = v7;
  }
  v8 = dword_B71DF4;
  dword_B71DEC = *(_DWORD *)(a1 + 412);
  if ( dword_B71DEC < dword_B71DF4 || (v8 = dword_B71DF8, dword_B71DEC > dword_B71DF8) )
    dword_B71DEC = v8;
  v9 = dword_B71F2C;
  dword_B71F24 = *(_DWORD *)(a1 + 416);
  if ( dword_B71F24 < dword_B71F2C || (v9 = dword_B71F30, dword_B71F24 > dword_B71F30) )
    dword_B71F24 = v9;
  v10 = dword_B71F98;
  dword_B71F90 = *(_DWORD *)(a1 + 420);
  if ( dword_B71F90 < dword_B71F98 || (v10 = dword_B71F9C, dword_B71F90 > dword_B71F9C) )
    dword_B71F90 = v10;
  dword_B71FB4 = *(_DWORD *)(a1 + 424);
  if ( *(float *)&dword_B71FB4 >= (double)flt_B71FBC )
  {
    if ( *(float *)&dword_B71FB4 > (double)flt_B71FC0 )
      dword_B71FB4 = LODWORD(flt_B71FC0);
  }
  else
  {
    dword_B71FB4 = LODWORD(flt_B71FBC);
  }
  v11 = dword_B71FE0;
  dword_B71FD8 = *(_DWORD *)(a1 + 428);
  if ( dword_B71FD8 < dword_B71FE0 || (v11 = dword_B71FE4, dword_B71FD8 > dword_B71FE4) )
    dword_B71FD8 = v11;
  v12 = dword_B7231C;
  *(_DWORD *)dword_B72314 = *(_DWORD *)(a1 + 432);
  if ( *(int *)dword_B72314 < dword_B7231C || (v12 = dword_B72320, *(int *)dword_B72314 > dword_B72320) )
    *(_DWORD *)dword_B72314 = v12;
  v13 = dword_B72624;
  dword_B7261C = *(_DWORD *)(a1 + 440);
  if ( dword_B7261C < dword_B72624 || (v13 = dword_B72628, dword_B7261C > dword_B72628) )
    dword_B7261C = v13;
  v14 = dword_B72768;
  dword_B72760 = *(_DWORD *)(a1 + 444);
  if ( dword_B72760 < dword_B72768 || (v14 = dword_B7276C, dword_B72760 > dword_B7276C) )
    dword_B72760 = v14;
  flt_B728A4 = *(float *)(a1 + 448);
  if ( flt_B728A4 >= (double)flt_B728AC )
  {
    if ( flt_B728A4 > (double)flt_B728B0 )
      flt_B728A4 = flt_B728B0;
  }
  else
  {
    flt_B728A4 = flt_B728AC;
  }
  dword_B72A00 = *(_DWORD *)(a1 + 452);
  if ( *(float *)&dword_B72A00 >= (double)flt_B72A08 )
  {
    if ( *(float *)&dword_B72A00 > (double)flt_B72A0C )
      dword_B72A00 = LODWORD(flt_B72A0C);
  }
  else
  {
    dword_B72A00 = LODWORD(flt_B72A08);
  }
  v15 = dword_B723D4;
  dword_B723CC = *(_DWORD *)(a1 + 592);
  if ( dword_B723CC < (unsigned int)dword_B723D4 || (v15 = dword_B723D8, dword_B723CC > (unsigned int)dword_B723D8) )
    dword_B723CC = v15;
  sub_50F030(&byte_B6F530, *(_DWORD *)(a1 + 436));
  sub_5100A0(&byte_B6F530, a1 + 456);
  v16 = dword_B72E10;
  dword_B72E08 = *(_DWORD *)(a1 + 584);
  if ( dword_B72E08 < dword_B72E10 || (v16 = dword_B72E14, dword_B72E08 > dword_B72E14) )
    dword_B72E08 = v16;
  v17 = dword_B72F54;
  dword_B72F4C = *(_DWORD *)(a1 + 588);
  if ( dword_B72F4C < dword_B72F54 || (v17 = dword_B72F58, dword_B72F4C > dword_B72F58) )
    dword_B72F4C = v17;
  sub_538940(&unk_BE1CFD, a1);
  return sub_53A160(a1);
}
