int sub_47F0A0()
{
  char *v0; // esi

  v0 = VehicleDescriptionAccessor(dword_7CD25C);
  if ( v0 && strlen(v0) )
  {
    if ( BinarySearchInStringTable(byte_5EC4C0, v0, byte_5EC4CC) )
      strcpy(byte_5EC4CC, v0);
    UIStringComparison(byte_5EC4CC);
    return 0;
  }
  else
  {
    UIStringComparison(byte_5EA438);
    return 0;
  }
}

