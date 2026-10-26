int __stdcall sub_4E5570(char *Buffer, int a2)
{
  char *v2; // edx
  char v3; // bl
  int v4; // ecx
  double v5; // st7
  int v6; // eax
  double v7; // st6
  long double v8; // st7
  long double v9; // st7
  int v11; // [esp+0h] [ebp-14h]
  double v12; // [esp+4h] [ebp-10h]

  strcpy(Buffer, " -:--.-");
  v2 = dword_91E07C;
  if ( *((_DWORD *)dword_91E07C + 4857) != 2 )
    return 0;
  v3 = 1;
  if ( (byte_B71DC8 & 1) != 0 || *(_DWORD *)dword_B72314 == 7 || *(_DWORD *)dword_B72314 == 8 )
  {
    v6 = sub_5511F0(&unk_FADD40, 0);
    if ( v6 == 255 )
      return 0;
    v2 = dword_91E07C;
    v4 = *((_DWORD *)dword_91E07C + 4822);
    v5 = *(float *)&dword_925098[5654 * v6 + v4];
  }
  else
  {
    v4 = *((_DWORD *)dword_91E07C + 4822);
    v5 = *(float *)&dword_91E07C[4 * v4 + 19448];
  }
  if ( v5 <= 0.0 )
    return 0;
  v7 = *(float *)&v2[4 * v4 + 19304];
  if ( v7 <= 0.0 )
    return 0;
  v8 = v7 - v5;
  if ( v8 < 0.0 )
    v3 = 0;
  v9 = fabs(v8);
  v12 = v9 - (double)(int)(unsigned __int64)((double)(int)(unsigned __int64)v9 * 0.016666668) * 60.0;
  v11 = (unsigned __int64)((double)(int)(unsigned __int64)v9 * 0.016666668);
  if ( v3 )
  {
    sprintf(Buffer, "+%.1d:%04.1f", v11, v12);
    return 0;
  }
  sprintf(Buffer, "-%.1d:%04.1f", v11, v12);
  return 0;
}
