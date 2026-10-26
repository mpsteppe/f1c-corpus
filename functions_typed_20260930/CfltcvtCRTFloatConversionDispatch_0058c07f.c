_BYTE *__cdecl sub_58C07F(double *a1, _BYTE *a2, int a3, int a4, int a5)
{
  if ( a3 == 101 || a3 == 69 )
    return (_BYTE *)FloatToStringWithSignWidth(a1, (int)a2, a4, a5);
  if ( a3 == 102 )
    return (_BYTE *)IntToStringWithSignPositionDraw(a1, (int)a2, a4);
  return UtilityFunction_bfec(a1, a2, a4, a5);
}

