int __stdcall sub_49BE50(char *a1, int a2)
{
  char *v2; // edi
  int v3; // edx
  int v4; // eax
  int v5; // ecx
  double v6; // st7
  double v7; // st6
  long double v8; // st7
  float v10; // [esp+0h] [ebp-1Ch]
  int v11; // [esp+18h] [ebp-4h] BYREF

  v2 = strcpy(a1, asc_5CCE18);
  v3 = dword_7C54E0;
  if ( *(_DWORD *)(dword_7C54E0 + 16532) != 2 )
    return 0;
  if ( (byte_7CFFF0 & 2) != 0 )
  {
    v4 = sub_4D1B50(0);
    if ( v4 == 255 )
      return 0;
    v3 = dword_7C54E0;
    v5 = *(_DWORD *)(dword_7C54E0 + 16448);
    v6 = flt_5F0780[4656 * v4 + v5];
  }
  else
  {
    v5 = *(_DWORD *)(dword_7C54E0 + 16448);
    v6 = *(float *)(dword_7C54E0 + 4 * v5 + 16552);
  }
  if ( v6 <= 0.0 )
    return 0;
  v7 = *(float *)(v3 + 4 * v5 + 16460);
  if ( v7 <= 0.0 )
    return 0;
  v8 = v7 - v6;
  v10 = fabs(v8);
  sub_49B630(v10, &v11, (float *)&a1);
  if ( v8 < 0.0 )
    sub_58815F(v2, "-%.2d:%06.3f", v11, *(float *)&a1);
  else
    sub_58815F(v2, "+%.2d:%06.3f", v11, *(float *)&a1);
  return 0;
}
