// f1c  0x0058c07f  size=81
_BYTE *__cdecl sub_58C07F(double *a1, _BYTE *a2, int a3, int a4, int a5)
{
  if ( a3 == 101 || a3 == 69 )
    return (_BYTE *)sub_58BDCD(a1, (int)a2, a4, a5);
  if ( a3 == 102 )
    return (_BYTE *)sub_58BEF0(a1, (int)a2, a4);
  return sub_58BFEC(a1, a2, a4, a5);
}
