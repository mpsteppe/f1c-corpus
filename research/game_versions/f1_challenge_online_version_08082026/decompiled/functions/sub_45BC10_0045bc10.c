bool __stdcall sub_45BC10(const char *a1, int a2, int a3)
{
  const char *v3; // eax
  int v4; // eax

  v3 = a1;
  if ( !a1 )
    v3 = byte_5EA438;
  v4 = sub_58969D(a2, a3, "%s: ", v3);
  *(_BYTE *)(a2 + a3 - 1) = 0;
  return v4 >= 0;
}
