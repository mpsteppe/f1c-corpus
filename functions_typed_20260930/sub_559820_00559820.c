int __stdcall sub_559820(int a1, const char *a2, int a3)
{
  int v3; // eax
  char v5[256]; // [esp+8h] [ebp-100h] BYREF

  if ( dword_8B8F2C )
  {
    v3 = UTF16StringSearchInLinkedList((int *)dword_8B8F2C, a2);
    if ( v3 )
    {
      *(_DWORD *)(a1 + 544) = v3;
      *(_DWORD *)(a1 + 540) = a3;
      return 0;
    }
    StringFormatWithBufferOverflowCheck(v5, "Could not find actor %s", a2);
    sub_53C590(-1, v5);
  }
  else
  {
    sub_53C590(-1, aCouldNotFindRe);
  }
  return -1;
}

