int __stdcall sub_49C280(int a1, int a2)
{
  int v2; // edi
  char *v3; // ebx
  double v4; // st7
  int v6; // [esp+14h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(dword_7C54E0 + 16448) + 1;
  if ( *(_DWORD *)(dword_7C54E0 + 16448) == 2 )
    v2 = 0;
  v3 = strcpy((char *)a1, asc_5CCE18);
  v4 = *(float *)(dword_7C54E0 + 4 * v2 + 16552);
  a1 = *(int *)(dword_7C54E0 + 4 * v2 + 16552);
  if ( v4 > 0.0 )
  {
    SpatialGridCell(*(float *)&a1, &v6, (float *)&a1);
    StringFormatWithBufferOverflowCheck(v3, " %.2d:%06.3f", v6, *(float *)&a1);
  }
  return 0;
}
