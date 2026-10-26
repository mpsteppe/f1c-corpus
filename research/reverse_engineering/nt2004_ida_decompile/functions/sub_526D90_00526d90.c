int __thiscall sub_526D90(void *this, float a2)
{
  CHAR *v3; // eax
  char *v4; // edx
  CHAR v5; // cl
  char *v6; // eax
  unsigned int v7; // ecx
  char v8; // dl
  unsigned int v9; // ecx
  char v10; // dl
  __int16 v11; // dx
  char *v12; // edi
  int v13; // ecx
  const char *v14; // ecx
  const char *v15; // eax
  CHAR *v16; // eax
  int v17; // ebp
  float *v18; // esi
  double v19; // st7
  CHAR *v20; // eax
  int v22; // eax
  float v23; // edi
  int v24; // esi
  int i; // esi
  float v26; // [esp+0h] [ebp-198h]
  int v27; // [esp+10h] [ebp-188h] BYREF
  float v28; // [esp+14h] [ebp-184h]
  char Buffer[253]; // [esp+18h] [ebp-180h] BYREF
  __int16 v30; // [esp+115h] [ebp-83h]
  char v31; // [esp+117h] [ebp-81h]
  char v32[125]; // [esp+118h] [ebp-80h] BYREF
  __int16 v33; // [esp+195h] [ebp-3h]
  char v34; // [esp+197h] [ebp-1h]

  if ( (byte_7DA984 & 1) == 0 )
  {
    byte_7DA984 |= 1u;
    sub_57B5D0(&unk_7DA778);
    atexit(unknown_libname_102);
  }
  v32[0] = byte_629120;
  memset(&v32[1], 0, 0x7Cu);
  v33 = 0;
  v34 = 0;
  if ( this )
  {
    Buffer[0] = byte_629120;
    memset(&Buffer[1], 0, 0xFCu);
    v30 = 0;
    v31 = 0;
    v3 = dword_766578;
    byte_7DAAD8 = 0;
    dword_7DAAAC = 0;
    dword_7DAAA8 = 0;
    if ( !dword_766578 )
      v3 = &byte_629120;
    v4 = (char *)(Buffer - v3);
    do
    {
      v5 = *v3;
      v3[(_DWORD)v4] = *v3;
      ++v3;
    }
    while ( v5 );
    v6 = &Buffer[strlen(Buffer)];
    if ( v6 > Buffer )
    {
      while ( *v6 != 46 )
      {
        if ( --v6 <= Buffer )
          goto LABEL_13;
      }
      *v6 = 0;
    }
LABEL_13:
    v7 = strlen(Buffer) + 1;
    v8 = Buffer[v7 - 1];
    v9 = v7 - 1;
    if ( v8 != 92 )
    {
      do
        v10 = Buffer[--v9];
      while ( v10 != 92 );
    }
    v11 = word_615398;
    Buffer[v9 + 5] = 0;
    v12 = &Buffer[strlen(Buffer) + 1];
    v13 = dword_615394;
    *(_DWORD *)--v12 = dword_615390;
    *((_DWORD *)v12 + 1) = v13;
    *((_WORD *)v12 + 4) = v11;
    if ( !sub_5922A0(&flt_7DAAD4, Buffer, 0, 1) )
      goto LABEL_21;
    v14 = (const char *)dword_62A0B0;
    if ( !dword_62A0B0 )
      v14 = &byte_629120;
    v15 = *(const char **)dword_62A068;
    if ( !*(_DWORD *)dword_62A068 )
      v15 = &byte_629120;
    sprintf(Buffer, "%s%s%s", v15, v14, aLoadJpg);
    if ( !sub_5922A0(&flt_7DAAD4, Buffer, 0, 1) )
    {
LABEL_21:
      sub_4AAF50(
        flt_7DAAD4,
        0,
        0,
        *(_DWORD *)(LODWORD(flt_7DAAD4) + 28),
        *(_DWORD *)(LODWORD(flt_7DAAD4) + 32),
        dword_7E8CDC,
        0,
        0,
        *(_DWORD *)(dword_7E8CDC + 28),
        *(_DWORD *)(dword_7E8CDC + 32),
        -1,
        -1,
        -1,
        -1);
      sub_4AB400(1);
      sub_4AAF50(
        flt_7DAAD4,
        0,
        0,
        *(_DWORD *)(LODWORD(flt_7DAAD4) + 28),
        *(_DWORD *)(LODWORD(flt_7DAAD4) + 32),
        dword_7E8CDC,
        0,
        0,
        *(_DWORD *)(dword_7E8CDC + 28),
        *(_DWORD *)(dword_7E8CDC + 32),
        -1,
        -1,
        -1,
        -1);
      sub_4AB400(1);
      v16 = (CHAR *)dword_62A098;
      if ( !dword_62A098 )
        v16 = &byte_629120;
      sub_591F10(v16);
      v27 = 0;
      if ( !sub_5924D0(dword_7DA988, (int)&v27, (int)aEaloadMas) )
      {
        v17 = 0;
        v18 = flt_7DA9E0;
        while ( 1 )
        {
          sprintf(v32, "EALoad%.4d.tga", v17 + 1);
          if ( sub_5922A0(v18, v32, 0, 1) )
            break;
          ++v18;
          ++dword_7DAAA8;
          ++v17;
          if ( (int)v18 >= (int)&dword_7DAAA8 )
            goto LABEL_29;
        }
        flt_7DA9E0[v17] = 0.0;
LABEL_29:
        dword_7DAAB0 = 0;
        dword_7DAAB4 = 0;
        v19 = (double)dword_6152E8 * 0.00125;
        flt_7DAAC0 = *(float *)(LODWORD(flt_7DA9E0[0]) + 28);
        flt_7DAAC4 = *(float *)(LODWORD(flt_7DA9E0[0]) + 32);
        v28 = (double)dword_6152EC * 0.001666666666666667;
        dword_7DAAB8 = (__int64)(0.0 * v19);
        dword_7DAABC = (__int64)(v28 * 459.0 + 0.5);
        dword_7DAAC8 = (__int64)((double)SLODWORD(flt_7DAAC0) * v19 + 0.5);
        dword_7DAACC = (__int64)((double)SLODWORD(flt_7DAAC4) * v28 + 0.5);
        sub_592750(v27);
      }
      v20 = (CHAR *)dword_62A098;
      if ( !dword_62A098 )
        v20 = &byte_629120;
      sub_592030(v20);
    }
    sub_57B610(1);
    sub_57B690(&unk_7DA778);
    return 0;
  }
  else
  {
    if ( !byte_7DAAD8 )
    {
      sub_4EFD80((int)&byte_7D6B78, 5.0);
      byte_7DAAD8 = 1;
    }
    v26 = sub_5ACA90(0);
    sub_4EFA90((int)&byte_7D6B78, v26);
    sub_4BB880();
    if ( sub_57B7C0(&unk_7DA778) > 0.05555555555555555 && a2 < 120.0 )
    {
      v22 = sub_4AB570();
      v23 = flt_7DA9E0[dword_7DAAAC];
      v24 = v22;
      if ( sub_5B4BC0(&unk_7E6B48) )
        sub_4AAF50(
          flt_7DAAD4,
          0,
          0,
          *(_DWORD *)(LODWORD(flt_7DAAD4) + 28),
          *(_DWORD *)(LODWORD(flt_7DAAD4) + 32),
          dword_7E8CDC,
          0,
          0,
          *(_DWORD *)(dword_7E8CDC + 28),
          *(_DWORD *)(dword_7E8CDC + 32),
          -1,
          -1,
          -1,
          -1);
      sub_4AAF50(
        v23,
        dword_7DAAB0,
        dword_7DAAB4,
        SLODWORD(flt_7DAAC0),
        SLODWORD(flt_7DAAC4),
        v24,
        dword_7DAAB8,
        dword_7DAABC,
        dword_7DAAC8,
        dword_7DAACC,
        -1,
        -1,
        -1,
        -1);
      sub_527360(0);
      dword_7DAAAC = (dword_7DAAAC + 1) % dword_7DAAA8;
      sub_57B690(&unk_7DA778);
    }
    if ( a2 >= 120.0 )
    {
      if ( LODWORD(flt_7DAAD4) )
      {
        sub_592310(LODWORD(flt_7DAAD4));
        flt_7DAAD4 = 0.0;
      }
      for ( i = 0; i < dword_7DAAA8; ++i )
      {
        if ( LODWORD(flt_7DA9E0[i]) )
        {
          sub_592310(LODWORD(flt_7DA9E0[i]));
          flt_7DA9E0[i] = 0.0;
        }
      }
      sub_4F01D0(0);
    }
    return 0;
  }
}
