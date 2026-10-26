double __stdcall sub_51CCE0(double a1, double a2, double a3)
{
  double v4[6]; // [esp+4h] [ebp-38h] BYREF
  int v5; // [esp+34h] [ebp-8h]

  v4[0] = a1;
  v4[1] = a2;
  v5 = 0;
  v4[2] = a3;
  v4[3] = 2.0;
  v4[4] = 9.999999933815813e36;
  if ( sub_45D190(dbl_B68610, (int)v4) )
    return v4[5];
  else
    return -100000000.0;
}
