void __usercall sub_42DCC0(void *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  int v5; // esi
  int v6; // edx
  int *v7; // eax
  char *v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  bool v13; // bl
  double v14; // st7
  int v15; // ecx
  int v16; // edi
  int v17; // esi
  char *v18; // ecx
  int v19; // esi
  int v20; // eax
  int v21; // ecx
  double v22; // st7
  int v23; // ecx
  float v24; // [esp+4h] [ebp-238h]
  float v25; // [esp+8h] [ebp-234h]
  float v27; // [esp+20h] [ebp-21Ch]
  int v28; // [esp+24h] [ebp-218h]
  int v29; // [esp+28h] [ebp-214h]
  int v30[2]; // [esp+2Ch] [ebp-210h] BYREF
  int v31; // [esp+34h] [ebp-208h]
  int v32[3]; // [esp+38h] [ebp-204h] BYREF
  int v33[126]; // [esp+44h] [ebp-1F8h] BYREF

  v29 = a3;
  if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\dynman.cpp", 639) )
    sub_561210((int)byte_FAE910, "Entered DynMan::Init()", v29);
  sub_42CB90();
  sub_42D2C0();
  sub_4188D0((char)&dword_91BF88, a2, (int)a1, a4, a4, v29, v30[0], v30[1], v31, v32[0], v32[1], v32[2], v33[0]);
  v5 = *(_DWORD *)dword_B72314;
  v6 = 0;
  v7 = &dword_923E84;
  while ( 1 )
  {
    if ( v5 != 4 )
      v7[1124] = v6 + 1;
    if ( !*v7 )
      break;
    v7 += 5654;
    ++v6;
    if ( (int)v7 >= (int)dword_B62244 )
      goto LABEL_19;
  }
  v8 = (char *)&unk_9204A0 + 22616 * v6;
  dword_91E07C = v8;
  v9 = 0;
  while ( (char *)*(&dword_91E088 + v9) != v8 )
  {
    if ( ++v9 >= 104 )
      goto LABEL_14;
  }
  dword_91E078 = v9;
LABEL_14:
  dword_91E084 = (int)&unk_9204A0 + 22616 * v6;
  v10 = 0;
  while ( (char *)*(&dword_91E088 + v10) != v8 )
  {
    if ( ++v10 >= 104 )
      goto LABEL_19;
  }
  dword_91E080 = v10;
LABEL_19:
  if ( v6 == 104 && dword_BE1204 != 2 )
  {
    dword_91E07C = (char *)&unk_9204A0;
    v11 = 0;
    while ( (_UNKNOWN *)*(&dword_91E088 + v11) != &unk_9204A0 )
    {
      if ( ++v11 >= 104 )
        goto LABEL_26;
    }
    dword_91E078 = v11;
LABEL_26:
    dword_91E084 = (int)&unk_9204A0;
    v12 = 0;
    while ( (_UNKNOWN *)*(&dword_91E088 + v12) != &unk_9204A0 )
    {
      if ( ++v12 >= 104 )
        goto LABEL_31;
    }
    dword_91E080 = v12;
  }
LABEL_31:
  HIBYTE(v30[0]) = v5 == 4;
  v13 = *(_DWORD *)dword_B640C8 == 1 || *(_DWORD *)dword_B640C8 == 2;
  sub_533DF0(a2, v28);
  if ( !byte_91E234 )
  {
    v27 = COERCE_FLOAT(v33);
    sub_501CC0(&byte_B6F530, *(_DWORD *)dword_B72314);
    sub_536CC0(v32);
    if ( *(_DWORD *)dword_B72314 != 3 || !byte_B6FEEC && !byte_B6FF04 && !byte_B722E4 )
    {
      sub_531060(v30);
      goto LABEL_44;
    }
    goto LABEL_43;
  }
  if ( HIBYTE(v31) && v13 )
LABEL_43:
    sub_531280(v30);
LABEL_44:
  sub_42CC30(a1);
  v14 = floor((double)dword_757C10 * 1.5 + 113.0);
  LOBYTE(v15) = 0;
  *(float *)&v31 = v14 - 101.0;
  sub_590650(v15, 1065437102);
  v16 = 0;
  if ( dword_757C14 > 0 )
  {
    v17 = 0;
    do
    {
      v18 = (char *)off_757C18 + v17;
      dword_91E228[v16] = (int)off_757C18 + v17;
      sub_53F5D0(v18, 1, 1);
      *(_DWORD *)((char *)off_757C18 + v17 + 22584) = 1;
      *(_DWORD *)((char *)off_757C18 + v17 + 22548) = 51;
      *(_DWORD *)((char *)off_757C18 + v17 + 22552) = 0;
      *(_DWORD *)((char *)off_757C18 + v17 + 19316) = 104;
      ++v16;
      v17 += 22616;
    }
    while ( v16 < dword_757C14 );
  }
  v19 = 0;
  while ( v19 < dword_757C10 )
  {
    sub_53F5D0(*(&dword_91E088 + v19), 1, 1);
    v20 = *(&dword_91E088 + v19++);
    *(_DWORD *)(v20 + 22584) = 0;
    LOBYTE(v21) = 0;
    v25 = ((double)v19 / (double)dword_757C10 * v27 + 101.0) * 0.0099999998;
    sub_590650(v21, LODWORD(v25));
  }
  v22 = floor((double)dword_757C10 * 1.5 + 113.0);
  LOBYTE(v23) = 0;
  v24 = (v22 + 1.0) * 0.0099999998;
  sub_590650(v23, LODWORD(v24));
  sub_438020(&dword_B65FF8);
  if ( (unsigned int)dword_91E080 < 0x68 && !*(_DWORD *)(*(&dword_91E088 + dword_91E080) + 14820) )
    sub_438180(dword_91E080);
  if ( dword_91E238 == 1 )
    dword_91E238 = 2;
  byte_920484 = 0;
  byte_920485 = 0;
  sub_42DAB0();
}
