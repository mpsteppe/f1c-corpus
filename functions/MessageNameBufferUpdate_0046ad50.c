char __stdcall sub_46AD50(int a1, char *a2, char a3)
{
  char *v3; // edi
  char *v4; // eax
  const char *v5; // esi
  const char *v6; // edi

  v3 = ArrayIndexedAccessor(&ppvOut, a1);
  v4 = sub_455260(&dword_7D1B08[7 * a1]);
  v5 = v4;
  if ( v3 && a2 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, v3, byte_5EC4CC) )
      strcpy(byte_5EC4CC, v3);
    strcpy(a2, byte_5EC4CC);
    StrlenOverwrite(a2);
    if ( v5 )
    {
      if ( BinarySearchInStringTable(byte_5EC4C0, v5, byte_5EC4CC) )
        strcpy(byte_5EC4CC, v5);
      v6 = byte_5EC4CC;
    }
    else
    {
      v6 = byte_5EA438;
    }
    LOBYTE(v4) = a3;
    strcat(a2, v6);
    if ( a3 )
      LOBYTE(v4) = UIMenuItemCreator(a2, 0, 0, 0, 0);
  }
  return (char)v4;
}
