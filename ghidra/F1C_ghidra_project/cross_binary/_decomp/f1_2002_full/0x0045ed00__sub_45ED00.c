// f1_2002_full  0x0045ed00  size=19
int __fastcall sub_45ED00(int *a1, int a2, int a3)
{
  int result; // eax

  result = *a1;
  if ( *a1 < a2 || (a2 = a3, result > a3) )
    *a1 = a2;
  return result;
}
