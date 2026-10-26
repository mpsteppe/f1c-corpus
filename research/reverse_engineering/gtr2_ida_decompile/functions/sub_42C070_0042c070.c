char __usercall sub_42C070@<al>(int a1@<ecx>, int a2@<ebx>, float a3@<edi>)
{
  char result; // al
  char v5; // al
  bool v6; // zf
  char *v7; // eax
  char v8; // cl
  char v9; // al
  int v10; // edx
  char v11; // cl
  char v12; // cl
  int v13; // eax
  double v14; // st7
  double v15; // st7
  double v16; // st7
  char v17; // al
  unsigned int v18; // eax
  float v19; // [esp+28h] [ebp-40h]
  float v20[4]; // [esp+30h] [ebp-38h] BYREF
  int v21; // [esp+40h] [ebp-28h]
  float v22; // [esp+44h] [ebp-24h]
  char v23; // [esp+4Ch] [ebp-1Ch]

  if ( *(_DWORD *)dword_B72314 != 8 )
    return 0;
  v5 = *(_BYTE *)(a1 + 1026);
  v21 = a2;
  if ( v5 )
  {
    if ( *(_BYTE *)(a1 + 496) == 1 )
      *(float *)(a1 + 500) = dbl_FB1D18;
    *(_BYTE *)(a1 + 1026) = 0;
  }
  else
  {
    sub_527D30(a1 + 1016, v21);
  }
  v6 = *(_BYTE *)(a1 + 1025) == 1;
  v23 = 0;
  if ( v6 )
  {
    sub_583170(dword_91E084 + 16, 0, 0);
    v7 = (char *)(a1 + 760);
    do
    {
      v8 = *v7;
      *(v7 - 256) = *v7;
      ++v7;
    }
    while ( v8 );
    LOBYTE(v22) = 1;
    *(_BYTE *)(a1 + 1025) = 0;
  }
  v9 = *(_BYTE *)(a1 + 504);
  v20[1] = a3;
  if ( v9 )
  {
    v20[0] = v22;
    sub_42B610();
    sub_42BC50((_DWORD *)a1, (char *)(a1 + 504));
    *(_BYTE *)(a1 + 504) = 0;
  }
  if ( *(_BYTE *)(a1 + 1040) == 1 )
    return 0;
  v10 = *(_DWORD *)(a1 + 8);
  if ( v10 )
  {
    if ( ((v11 = *(_BYTE *)(a1 + 496)) == 0 && *(float *)(v10 + 52) >= 6.0
       || v11 == 1 && *(float *)(a1 + 500) + 4.0 <= dbl_FB1D18)
      && !*(_BYTE *)(a1 + 480)
      && !*(_BYTE *)(a1 + 481) )
    {
      *(float *)(a1 + 472) = dbl_FB1D18;
      if ( v11 )
        *(_DWORD *)(a1 + 484) = 0;
      else
        *(_DWORD *)(a1 + 484) = *(_DWORD *)(v10 + 52);
      *(_BYTE *)(a1 + 480) = 1;
      if ( !v11 )
      {
        sub_583170(dword_91E084 + 16, 0, 1);
        dword_B6C3D0 = *(_DWORD *)(dword_91E084 + 16152);
        sub_44A3C0(&dbl_B66040, 0, 0);
      }
      if ( *(_BYTE *)(a1 + 1024) == 2 )
      {
        if ( *(float *)(a1 + 452) <= 0.0 )
          sub_53F0E0(0);
        else
          sub_53F0E0(1);
      }
      sub_4226C0((float *)dword_91E084, 99999);
    }
  }
  v12 = *(_BYTE *)(a1 + 480);
  if ( v12 == 1 )
  {
    v13 = *(_DWORD *)(a1 + 4);
    v14 = v13 ? *(float *)(v13 + 52) : 0.0;
    v15 = v14 - *(float *)(a1 + 484) - (dbl_FB1D18 - *(float *)(a1 + 472));
    *(float *)(a1 + 488) = v15;
    v16 = *(float *)(a1 + 424) == 0.0 ? v15 + *(float *)(a1 + 36) : v15 - *(float *)(a1 + 424);
    *(float *)(a1 + 488) = v16;
    if ( *(float *)(a1 + 488) < 0.0 )
      *(_DWORD *)(a1 + 488) = 0;
  }
  v17 = *(_BYTE *)(a1 + 1024);
  if ( v17 && v17 != 2
    || v12 != 1
    || *(_BYTE *)(a1 + 481)
    || (v19 = sub_5210A0(a1 + 1020), sub_521080(a1 + 1020) > v19)
    || (sub_528650(a1 + 1016), sub_583170(&unk_925D08, 1, 1), *(_BYTE *)(a1 + 1024)) )
  {
    if ( sub_410B50(&dword_91BF20) != 5 )
    {
      v18 = *(_DWORD *)(dword_91BF40 + 52);
      if ( v18 < 4 )
        *(_DWORD *)(a1 + 1044) = v18;
    }
    if ( *(float *)(a1 + 1052) != 0.0 && *(float *)(a1 + 1052) + 10.0 < dbl_FB1D18 )
    {
      sub_521110(1);
      sub_42A890();
      sub_5401B0(&unk_BE1D30);
      dword_B6F11C = 1;
      *(_DWORD *)(a1 + 1052) = 0;
    }
    if ( *(_DWORD *)a1 )
      sub_401290(*(float **)a1, (float *)(dword_91E084 + 15988), v20);
    return off_16C9694();
  }
  else
  {
    *(_BYTE *)(a1 + 481) = 1;
    sub_412EB0(&dword_91BF20, 5, 1);
    sub_4E5FC0(&dword_B6E4D0, 5);
    byte_B699B4 = 0;
    byte_B699BC = 0;
    dword_B6E4D8 = 101;
    result = 7;
    *(float *)(a1 + 1052) = dbl_FB1D18;
    *(_BYTE *)(a1 + 1027) = 7;
  }
  return result;
}
