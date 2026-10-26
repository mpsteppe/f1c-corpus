int __stdcall sub_49C4E0(int a1, int a2)
{
  char *v2; // ebx
  int v3; // eax
  int v4; // edi
  const char *v5; // esi
  int v7; // [esp+14h] [ebp-4h] BYREF

  v2 = strcpy((char *)a1, asc_5CCE54);
  if ( *(_DWORD *)(dword_7C54E0 + 16484) )
    return 0;
  v3 = *(_DWORD *)(dword_7C54E0 + 16596);
  if ( !v3 || *(_DWORD *)(v3 + 16484) || LapTimeGapCalculation(dword_7C54E0, v3, (float *)&a1, &v7) )
    return 0;
  v4 = v7;
  if ( v7 <= 0 )
  {
    *(float *)&a1 = fabs(*(float *)&a1);
    SpatialGridCell(*(float *)&a1, &v7, (float *)&a1);
    StringFormatWithBufferOverflowCheck(v2, "+%.2d:%06.3f", v7, *(float *)&a1);
    return 0;
  }
  v5 = (const char *)&off_5CCE74;
  if ( v7 != 1 )
    v5 = aLaps_0;
  if ( BinarySearchInStringTable(byte_5EC4C0, v5, byte_5EC4CC) )
  {
    if ( v5 )
      strcpy(byte_5EC4CC, v5);
    else
      byte_5EC4CC[0] = 0;
  }
  StringFormatWithBufferOverflowCheck(v2, " +%d %s", v4, byte_5EC4CC);
  return 0;
}

