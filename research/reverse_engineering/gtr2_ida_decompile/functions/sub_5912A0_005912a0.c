int sub_5912A0()
{
  int v0; // eax
  const CHAR *v1; // eax
  int v2; // eax
  char *v3; // eax
  int v4; // edx
  char v5; // cl
  int v6; // kr04_4
  int *i; // eax
  int v8; // kr08_4
  const char *v9; // ecx
  int v10; // eax
  char v11; // cl
  char *v12; // eax
  char *v13; // edi
  const char *v15; // ecx
  const char *v16; // eax
  int v17; // kr10_4
  int v18; // eax
  const char *v19; // eax
  int v20; // ecx
  int v22; // ecx
  char v23[4]; // [esp+Ch] [ebp-A18h] BYREF
  int v24; // [esp+10h] [ebp-A14h] BYREF
  int v25; // [esp+18h] [ebp-A0Ch] BYREF
  int v26[125]; // [esp+1Ch] [ebp-A08h] BYREF
  char v27; // [esp+213h] [ebp-811h] BYREF
  char v28[496]; // [esp+214h] [ebp-810h] BYREF
  char FileName[8]; // [esp+404h] [ebp-620h] BYREF
  char ArgList[520]; // [esp+40Ch] [ebp-618h] BYREF
  char Buffer[504]; // [esp+614h] [ebp-410h] BYREF
  char v32; // [esp+80Ch] [ebp-218h] BYREF
  char v33[528]; // [esp+814h] [ebp-210h] BYREF

  if ( sub_5612D0(byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\vidman.cpp", 1205) )
    sub_561210((int)byte_FAE910, "Entered VidMan::Init()");
  byte_FB1CEC = 0;
  v0 = *(_DWORD *)dword_FB27A4;
  v26[0] = 1;
  (*(void (__thiscall **)(int))(v0 + 340))(dword_FB27A4);
  sub_5D8D70(0);
  sub_5D8D50(dword_B717E8 != 0);
  sub_5D8D60(dword_B7180C != 0);
  sub_5F45F0(dword_B721D0);
  switch ( dword_B71734 )
  {
    case 1:
      sub_5E5AF0(1, 0);
      v25 = 0;
      break;
    case 2:
      sub_5E5AF0(1, 0);
      v25 = 1;
      break;
    case 3:
      sub_5E5AF0(1, 1);
      v25 = 1;
      break;
    default:
      sub_5E5AF0(1, 0);
      sub_5E5AF0(2, 0);
      sub_5E5AF0(4, 0);
      sub_5E5AF0(8, 0);
      v25 = 1;
      goto LABEL_11;
  }
  sub_5E5AF0(2, v25);
  sub_5E5AF0(4, 1);
  sub_5E5AF0(8, 1);
  v25 = 0;
LABEL_11:
  sub_5E5AF0(16, v25);
  v1 = dword_B6F6A8;
  if ( !dword_B6F6A8 )
    v1 = WindowName;
  sub_538860(&unk_BE1CFD, (int)v1, v26[0], v26[1]);
  v2 = 396 * dword_BE1CD4 + dword_BE1CD8;
  if ( v2 )
  {
    v3 = (char *)(v2 + 4);
    v4 = (char *)v26 - v3;
    do
    {
      v5 = *v3;
      v3[v4] = *v3;
      ++v3;
    }
    while ( v5 );
    v6 = strlen((const char *)v26);
    if ( v6 > 0 )
    {
      for ( i = (int *)((char *)&v25 + v6 + 3); i >= v26; i = (int *)((char *)i - 1) )
      {
        if ( *(_BYTE *)i == 92 )
          break;
        *(_BYTE *)i = 0;
      }
    }
    v8 = strlen((const char *)v26);
    if ( v8 > 0 && *((_BYTE *)&v25 + v8 + 3) == 92 )
      *((_BYTE *)&v25 + v8 + 3) = 0;
    sub_5D9420(dword_FB1CE0, v26, 0);
  }
  v9 = dword_B6F68C;
  v24 = 0;
  if ( !dword_B6F68C )
    v9 = WindowName;
  strcpy(v33, v9);
  if ( byte_B71BE8 )
  {
    v10 = 0;
    do
    {
      v11 = v33[v10];
      v28[v10++] = v11;
    }
    while ( v11 );
    v12 = &v28[strlen(v28)];
    if ( v12 > v28 )
    {
      while ( *v12 != 46 )
      {
        if ( --v12 <= v28 )
          goto LABEL_34;
      }
      *v12 = 0;
    }
LABEL_34:
    v13 = &v27;
    while ( *++v13 )
      ;
    strcpy(v13, "_LowTex.GTR");
    sub_5EE940((int)&v24, (char)v28, 0);
  }
  v15 = (const char *)dword_91CAE8;
  if ( !dword_91CAE8 )
    v15 = WindowName;
  v16 = *(const char **)dword_91CA70;
  if ( !*(_DWORD *)dword_91CA70 )
    v16 = WindowName;
  sprintf(Buffer, "%s%s", v16, v15);
  v17 = strlen(Buffer);
  if ( v17 > 0 && ArgList[v17 + 519] == 92 )
    ArgList[v17 + 519] = 0;
  sub_5D9420(dword_FB1CE0, Buffer, 0);
  sub_5DCDC0(sub_590650, 1090519040);
  v18 = sub_5E24F0(dword_FB1CE0, (char)&v32);
  sub_5D8DB0(v18, 1.0);
  v19 = (const char *)dword_91CAF8;
  if ( !dword_91CAF8 )
    v19 = WindowName;
  sprintf(ArgList, "%stmp.TRK", v19);
  sub_58FE10();
  v20 = 0;
  switch ( dword_B71230 )
  {
    case 1:
    case 2:
      v20 = 0x20000;
      break;
    case 3:
      v20 = 196608;
      break;
    case 4:
      v20 = 983040;
      break;
    default:
      break;
  }
  if ( sub_5DEB30(&dword_FB1D04, ArgList, v20 | 0x200200) )
  {
    sub_5D8CB0(0, v23);
    if ( sub_5612D0(byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\vidman.cpp", 1354) )
      sub_561210((int)byte_FAE910, "CUBE error loading TRK file %s: %s", ArgList, v23);
    return 1;
  }
  else
  {
    v22 = dword_FB1D04;
    if ( dword_FB1D04 )
    {
      if ( dword_B71230 == 1 || dword_B70618[0] == 3 || dword_B70618[0] == 2 && flt_B70858 > 0.5 )
      {
        sub_5E62F0(1);
        v22 = dword_FB1D04;
      }
      *(_DWORD *)(v22 + 284) = dword_B716A4;
      *(float *)(dword_FB1D04 + 268) = flt_B716C8;
      if ( dword_B71254 )
      {
        if ( dword_B71254 == 1 )
        {
          sub_5FE360(18);
        }
        else if ( dword_B71254 == 2 )
        {
          sub_5FE360(24);
        }
      }
      else
      {
        sub_5FE360(12);
      }
    }
    sub_5DCDC0(0, 0);
    sub_551060();
    sub_590650();
    sub_5EEA30(dword_FB1CE0, (void *)0x3F8147AE, 0);
    sub_617680(FileName);
    return 0;
  }
}
