char *__stdcall sub_4AE6B0(char *Source)
{
  char *result; // eax
  CHAR Text[128]; // [esp+0h] [ebp-80h] BYREF

  result = Source;
  if ( Source )
  {
    strncpy(Text, Source, 0x7Fu);
    Text[127] = 0;
    MessageBoxA(0, Text, aOptionsError, 0);
    exit(1);
  }
  return result;
}
