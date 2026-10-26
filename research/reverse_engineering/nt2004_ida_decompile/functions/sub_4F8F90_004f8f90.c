char __stdcall sub_4F8F90(_DWORD *a1, float *a2, _DWORD *a3)
{
  if ( dword_75CBB0 == 5 )
  {
    if ( !sub_4EED40(a1) || !byte_76617C )
    {
      sub_4042F0(&flt_628F60, 0, a2, a3);
      return 0;
    }
LABEL_6:
    if ( a1[5223] )
      goto LABEL_13;
    goto LABEL_7;
  }
  if ( byte_76617C )
    goto LABEL_6;
LABEL_7:
  if ( dword_75CBB0 == 7 && !a1[6325] && (dword_75CBB4 == 2 || dword_75CBB4 == 3 || dword_75CBB4 == 4) )
  {
    sub_4F8EF0((int)a1, a2, a3);
    return 1;
  }
LABEL_13:
  sub_4F8F50(a1, a2, a3);
  return 0;
}
