char __stdcall sub_45BC50(const char *a1, const char *a2, _BYTE *a3, int a4)
{
  char result; // al
  char v5[512]; // [esp+Ch] [ebp-200h] BYREF

  if ( a2 && strlen(a2) )
  {
    StringFormatWrapper(a1, (int)v5, 512);
    strcat(v5, a2);
    sub_587DD0(a3, v5, a4 - 1);
    a3[a4 - 1] = 0;
    return 1;
  }
  else
  {
    result = 0;
    *a3 = 0;
  }
  return result;
}
