void __userpurge sub_55F550(double *a1@<ecx>, char a2@<sil>, double a3, double a4, double a5)
{
  if ( a5 <= 0.0
    && dword_B640C0 != 5
    && (unsigned __int8)sub_5612D0((int)byte_FAE910, 1, "\\Dev\\Src\\Copperhead\\App\\Source\\tire_manager.cpp", 198) )
  {
    sub_561210((int)byte_FAE910, "Tire load factor should be positive", a2);
  }
  *a1 = (a3 + a4) * 0.5;
  a1[1] = (a3 - a4) * 0.5;
  a1[2] = a5;
  a1[3] = 1.0 / a5;
}
