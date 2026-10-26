int __stdcall sub_49C0B0(char *lpSrcStr, int a2)
{
  const CHAR *v2; // esi
  int v3; // eax
  char *v4; // ecx

  v2 = strcpy(lpSrcStr, asc_5CCE54);
  if ( (byte_7CFFF0 & 1) != 0 )
  {
    v3 = sub_4D1B50(0);
    if ( v3 == 255 )
      return 0;
    v4 = (char *)&stru_5EC6D8 + 18624 * v3;
  }
  else
  {
    v4 = (char *)dword_7C54E0;
  }
  if ( v4 && *(float *)&v4[4 * *(_DWORD *)(dword_7C54E0 + 16448) + 16552] > 0.0 )
  {
    StringFormatWithBufferOverflowCheck(v2, &off_5C3730, v4 + 18168);
    sub_589901(v2);
  }
  return 0;
}

