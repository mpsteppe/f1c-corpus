int __stdcall sub_5427D0(int a1, int a2, int a3, int a4)
{
  CHAR SrcStr[768]; // [esp+114h] [ebp-600h] BYREF

  if ( a1 )
  {
    if ( strlen((const char *)a1) > 0x300 )
      *(_BYTE *)(a1 + 767) = 0;
    strcpy(SrcStr, (const char *)a1);
    sub_589901(SrcStr);
    if ( sub_543130(SrcStr, a2, a3, a4) )
      JUMPOUT(0x8D9580);
  }
  return 0;
}
