int __stdcall sub_49BDE0(int a1, int a2)
{
  const char *v2; // esi

  v2 = off_5CCBE4[0];
  if ( BinarySearchInStringTable(byte_5EC4C0, off_5CCBE4[0], byte_5EC4CC) )
  {
    if ( v2 )
      strcpy(byte_5EC4CC, v2);
    else
      byte_5EC4CC[0] = 0;
  }
  sub_587DD0(a1, byte_5EC4CC, a2 - 1);
  *(_BYTE *)(a2 - 1 + a1) = 0;
  return 0;
}

