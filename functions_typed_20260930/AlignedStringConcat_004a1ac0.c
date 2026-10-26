int __stdcall sub_4A1AC0(char *a1, unsigned __int16 *a2)
{
  int result; // eax
  int v3; // [esp-4h] [ebp-2Ch]
  char v4[32]; // [esp+8h] [ebp-20h] BYREF

  v3 = *a2;
  v4[0] = 0;
  StringFormatWithBufferOverflowCheck(v4, "%d", v3);
  result = 0;
  strcat(a1, v4);
  return result;
}

