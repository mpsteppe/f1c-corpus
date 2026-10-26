int __stdcall sub_494F10(int a1, const char *a2, int a3, int a4, int a5, char a6)
{
  if ( !a6 )
    return sub_53D2E0(a1, a2, a3, a4, a5);
  if ( BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC) )
  {
    if ( a2 )
      strcpy(byte_5EC4CC, a2);
    else
      byte_5EC4CC[0] = 0;
  }
  return sub_53D2E0(a1, byte_5EC4CC, a3, a4, a5);
}

