char __thiscall sub_4B1C80(int this, int a2)
{
  const char *v3; // eax
  char v5[256]; // [esp+Ch] [ebp-100h] BYREF

  v5[0] = 0;
  ArithmeticComparison(v5, (_BYTE *)(this + 20));
  BufferWriteWithStringLengthCheck(a2, aSS_6);
  v3 = *(const char **)(this + 12);
  if ( !v3 )
    v3 = byte_5EA438;
  if ( strlen(v3) )
    BufferWriteWithStringLengthCheck(a2, aS_8);
  BufferWriteWithStringLengthCheck(a2, &word_5C30B4);
  return 0;
}

