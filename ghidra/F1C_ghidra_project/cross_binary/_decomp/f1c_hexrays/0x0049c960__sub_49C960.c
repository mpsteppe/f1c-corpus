// f1c  0x0049c960  size=159
int __stdcall sub_49C960(int a1, int a2)
{
  char *v2; // edi
  double v3; // st6
  int v5; // [esp+10h] [ebp-4h] BYREF

  v2 = strcpy((char *)a1, asc_5CCE54);
  if ( dword_7C56A4 == 7 )
    return 0;
  if ( dword_7D0410 == 1 )
    return 0;
  v3 = flt_8ACF94 - dbl_8AFEA0;
  *(float *)&a1 = v3;
  if ( v3 <= 0.0 || flt_8ACF90 >= dbl_8AFEA0 )
    return 0;
  sub_49B630(*(float *)&a1, &v5, (float *)&a1);
  sub_58815F(v2, " %.2d:%06.3f", v5, *(float *)&a1);
  return 0;
}
