// f1c  0x0049bff0  size=183
int __stdcall sub_49BFF0(int a1, int a2)
{
  int v2; // esi
  char *v3; // edi
  int v4; // eax
  double v5; // st7
  int v7; // [esp+14h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(dword_7C54E0 + 16448) + 1;
  if ( *(_DWORD *)(dword_7C54E0 + 16448) == 2 )
    v2 = 0;
  v3 = strcpy((char *)a1, asc_5CCE18);
  if ( (byte_7CFFF0 & 1) != 0 )
  {
    v4 = sub_4D1B50(0);
    if ( v4 == 255 )
      return 0;
    v5 = flt_5F0780[4656 * v4 + v2];
  }
  else
  {
    v5 = *(float *)(dword_7C54E0 + 4 * v2 + 16552);
  }
  *(float *)&a1 = v5;
  if ( v5 > 0.0 )
  {
    sub_49B630(*(float *)&a1, &v7, (float *)&a1);
    sub_58815F(v3, " %.2d:%06.3f", v7, *(float *)&a1);
  }
  return 0;
}
