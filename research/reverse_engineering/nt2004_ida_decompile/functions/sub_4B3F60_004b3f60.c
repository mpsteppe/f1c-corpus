int __stdcall sub_4B3F60(char *Buffer, int a2)
{
  char *v2; // edi
  double v3; // st6
  int v5; // [esp+10h] [ebp-4h] BYREF

  v2 = strcpy(Buffer, asc_609460);
  if ( dword_75CBB0 == 7 )
    return 0;
  if ( *(_DWORD *)dword_7689CC == 1 )
    return 0;
  v3 = flt_7D74C0 - dbl_7DA9D0;
  *(float *)&Buffer = v3;
  if ( v3 <= 0.0 || flt_7D74BC >= dbl_7DA9D0 )
    return 0;
  sub_4B2BD0(*(float *)&Buffer, &v5, (float *)&Buffer);
  sprintf(v2, "%.2d:%06.3f", v5, *(float *)&Buffer);
  return 0;
}
