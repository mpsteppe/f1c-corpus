// f1c  0x004f9ad0  size=78
int sub_4F9AD0()
{
  int result; // eax
  double v1; // kr00_8

  dbl_8AFE90 = sub_556730(0);
  v1 = dbl_8AFE90;
  result = LODWORD(v1);
  dbl_8AFE98 = dbl_8AFE90;
  dbl_8AFEA0 = dbl_8AFEA0 + dbl_8AFE90;
  dbl_8AFEA8 = dbl_8AFEA8 + dbl_8AFE90;
  return result;
}
