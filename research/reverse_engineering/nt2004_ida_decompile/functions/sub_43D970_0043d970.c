int __stdcall sub_43D970(char *ArgList, int a2, int a3)
{
  _DWORD *v3; // eax
  int result; // eax
  double *v5; // eax
  double v6; // st7
  double v7; // st6
  double v8; // st5
  double v9; // st4

  v3 = (_DWORD *)sub_5818C0(ArgList);
  if ( v3 )
  {
    if ( v3[1] == a2 )
      v5 = (double *)v3[2];
    else
      v5 = (double *)v3[4];
    v6 = *(double *)(a2 + 44) * v5[2] + *(double *)(a2 + 36) * v5[1] + *v5 * *(double *)(a2 + 28);
    v7 = *(double *)(a2 + 52) * *v5 + *(double *)(a2 + 68) * v5[2] + *(double *)(a2 + 60) * v5[1];
    v8 = *(double *)(a2 + 76) * *v5 + *(double *)(a2 + 92) * v5[2];
    v9 = *(double *)(a2 + 84) * v5[1];
    result = a3;
    *(double *)a3 = v6 + *(double *)(a2 + 4);
    *(double *)(a3 + 8) = v7 + *(double *)(a2 + 12);
    *(double *)(a3 + 16) = v8 + v9 + *(double *)(a2 + 20);
  }
  else
  {
    if ( dword_75CBA8 != 5 )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004, 2852) )
        sub_500FE0((int)&unk_7D7920, aCouldNotFindSu, (char)ArgList);
    }
    result = a3;
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 4) = 0;
    *(_DWORD *)(a3 + 8) = 0;
    *(_DWORD *)(a3 + 12) = 0;
    *(_DWORD *)(a3 + 16) = 0;
    *(_DWORD *)(a3 + 20) = 0;
  }
  return result;
}
