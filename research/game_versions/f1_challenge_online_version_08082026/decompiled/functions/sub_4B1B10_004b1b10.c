char __thiscall sub_4B1B10(int *this, int a2)
{
  const char *v3; // eax
  char v5[256]; // [esp+Ch] [ebp-100h] BYREF

  v5[0] = 0;
  sub_4A1A60(v5, this + 5);
  sub_566C30(a2, aSS_6);
  v3 = (const char *)this[3];
  if ( !v3 )
    v3 = byte_5EA438;
  if ( strlen(v3) )
    sub_566C30(a2, aS_8);
  sub_566C30(a2, &word_5C30B4);
  return 0;
}
