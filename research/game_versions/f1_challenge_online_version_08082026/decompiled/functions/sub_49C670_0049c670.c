int __stdcall sub_49C670(int a1, int a2)
{
  int v2; // eax

  v2 = *(_DWORD *)(dword_7C54E0 + 16444) + 1;
  if ( v2 > dword_8ACF8C )
    v2 = dword_8ACF8C;
  if ( dword_8ACF8C == 0x7FFFFFFF )
    sub_58815F(a1, " %d/--", v2);
  else
    sub_58815F(a1, " %d/%d", v2, dword_8ACF8C);
  return 0;
}
