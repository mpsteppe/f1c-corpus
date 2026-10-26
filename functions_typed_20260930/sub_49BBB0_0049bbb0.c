int __stdcall sub_49BBB0(char *a1, int a2)
{
  int v2; // edx
  double v3; // st7
  int v4; // eax
  double v5; // st7
  int v7; // [esp+Ch] [ebp-8h] BYREF
  int v8; // [esp+10h] [ebp-4h] BYREF

  v2 = dword_7C54E0;
  v3 = dbl_8AFEA0 - *(float *)(dword_7C54E0 + 16536);
  *(float *)&v7 = v3;
  if ( v3 < flt_5CCC0C )
  {
    v4 = *(_DWORD *)(dword_7C54E0 + 16444);
    if ( v4 > 0 )
    {
      v5 = ArithmeticComparison_c2a0(v4 - 1);
      *(float *)&v8 = v5;
      if ( v5 > 0.0 )
      {
        SpatialGridCell(*(float *)&v8, &v8, (float *)&v7);
        StringFormatWithBufferOverflowCheck(a1, " %.2d:%06.3f", v8, *(float *)&v7);
        return 0;
      }
      v2 = dword_7C54E0;
    }
  }
  if ( *(_DWORD *)(v2 + 16532) != 2 || *(float *)&v7 < 0.0 || *(_DWORD *)(v2 + 16484) )
  {
    strcpy(a1, asc_5CCE18);
    return 0;
  }
  else
  {
    SpatialGridCell(*(float *)&v7, &v8, (float *)&v7);
    StringFormatWithBufferOverflowCheck(a1, " %.2d:%06.3f", v8, *(float *)&v7);
    return 0;
  }
}

