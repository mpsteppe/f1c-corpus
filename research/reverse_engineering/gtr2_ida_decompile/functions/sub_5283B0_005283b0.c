char __userpurge sub_5283B0@<al>(int a1@<ecx>, int a2@<edi>, int *a3)
{
  char v4; // bl

  v4 = 1;
  if ( *(float *)(a1 + 2892848) - *(float *)(a1 + 2892844) <= 0.0 )
    return 0;
  sub_522C30((int *)a1, *a3, 0);
  sub_527C40(&dword_BE1204, a2);
  sub_54AB10(&unk_BE2728);
  sub_403740((int)&flt_91BCA0);
  sub_556F90(&unk_FADD40);
  sub_463A40((float *)&dword_B69668);
  sub_42EF60((int)&unk_920488);
  sub_414DD0((int)&dword_91BF20);
  sub_540C90(&unk_BE1D30);
  sub_51E980((float *)&dword_BE10B0);
  sub_5206C0();
  sub_4E8030(&dword_B6E4D0);
  sub_5900D0(&unk_FB1E98);
  sub_408730(dword_91BE2C, dbl_FB1D10);
  sub_594840(&dword_FB1EF8);
  sub_4ED0E0();
  if ( dword_B6BA38
    || (dword_B698E8 & 1) != 0 && (byte_B699ED & 2) != 0
    || *(float *)(a1 + 2892852) >= (double)*(float *)(a1 + 2892848) )
  {
    return 0;
  }
  return v4;
}
