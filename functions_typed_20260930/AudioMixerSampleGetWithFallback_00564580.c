double __fastcall sub_564580(int a1, int a2, double a3)
{
  int *v3; // eax

  v3 = DoubleCallWrapper(a1, a2);
  if ( v3 )
    return sub_58850F(v3[1]);
  else
    return a3;
}

