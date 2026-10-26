// f1c  0x004cdbf0  size=121
char __thiscall sub_4CDBF0(const char **this, int a2)
{
  const char *v2; // ecx
  int v3; // eax
  char v5[256]; // [esp+0h] [ebp-100h] BYREF

  v2 = *this;
  if ( !v2 )
    v2 = byte_5EA438;
  strcpy(v5, v2);
  v3 = sub_5897CA(v5, asc_5D251C);
  if ( !v3 )
    return 0;
  while ( sub_587C20(a2, v3) != a2 )
  {
    v3 = sub_5897CA(0, asc_5D251C);
    if ( !v3 )
      return 0;
  }
  return 1;
}
