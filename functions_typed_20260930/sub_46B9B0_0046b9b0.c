int __thiscall sub_46B9B0(int *this)
{
  int result; // eax
  int v3; // eax
  char v4; // cl

  result = StateCleanupNotification(this);
  this[94] = -1;
  if ( dword_7D0410 == 5 )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, aLoadingGrid, byte_5EC4CC) )
    {
      v3 = 0;
      do
      {
        v4 = aLoadingGrid[v3];
        byte_5EC4CC[v3++] = v4;
      }
      while ( v4 );
    }
    return UIMenuItemCreator(this, (int)byte_5EC4CC, byte_5EA438, (int)byte_5EA438, (int)byte_5EA438, 0);
  }
  return result;
}

