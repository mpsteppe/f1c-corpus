int __stdcall sub_49BD40(int a1, int a2)
{
  char *v2; // edi
  int v3; // eax
  double v4; // st7
  int v6; // [esp+10h] [ebp-4h] BYREF

  v2 = strcpy((char *)a1, asc_5CCE18);
  if ( (byte_7CFFF0 & 1) != 0 )
  {
    v3 = sub_4D1B50(0);
    if ( v3 == 255 )
      return 0;
    v4 = MEMORY[0x5F0780][4656 * v3];
  }
  else
  {
    v4 = *(float *)(dword_7C54E0 + 16552);
  }
  *(float *)&a1 = v4;
  if ( v4 > 0.0 )
  {
    SpatialGridCell(*(float *)&a1, &v6, (float *)&a1);
    StringFormatWithBufferOverflowCheck(v2, " %.2d:%06.3f", v6, *(float *)&a1);
  }
  return 0;
}

