int __userpurge sub_4FED10@<eax>(double *a1@<ecx>, char a2@<sil>, double a3, double a4, double a5)
{
  int result; // eax

  if ( a5 <= 0.0 && dword_75CBA8 != 5 && (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_22, 211) )
    sub_500FE0((int)&unk_7D7920, aTireLoadFactor, a2);
  result = LODWORD(a5);
  a1[2] = a5;
  *a1 = (a3 + a4) * 0.5;
  a1[1] = (a3 - a4) * 0.5;
  a1[3] = 1.0 / a5;
  return result;
}
