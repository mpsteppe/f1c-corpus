void __usercall sub_556F90(int a1@<ecx>, int a2@<edi>)
{
  int *v3; // ecx
  double v4; // st7
  float v5; // [esp+0h] [ebp-Ch]
  float v6; // [esp+8h] [ebp-4h]

  v3 = *(int **)(a1 + 176);
  if ( v3 )
  {
    v5 = dbl_FB1D10;
    sub_54F720(v3, v5);
  }
  if ( *(_DWORD *)(a1 + 180) )
  {
    if ( dword_BE1204 == 2 )
      v4 = sub_5210A0(&dword_BE120C);
    else
      v4 = dbl_FB1D18;
    v6 = v4;
    sub_4582A0(*(float **)(a1 + 180), v6);
  }
  sub_550360();
  if ( !byte_B6413C && dword_BE1204 != 2 )
  {
    sub_5556A0((float *)a1);
    if ( (dword_B640C4 & 1) != 0 )
      sub_556B40(a1, a2);
  }
}
