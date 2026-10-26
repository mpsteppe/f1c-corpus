double __cdecl sub_58850F(unsigned __int8 *a1)
{
  _BYTE v4[24]; // [esp+4h] [ebp-18h] BYREF

  while ( cbMultiByte <= 1 ? off_5E69C8[0][*a1] & 8 : CharacterEncodingConvertViaLookupTableFallback(*a1, 8) )
    ++a1;
  Strlen(a1);
  return *(double *)(EncodingLocaleDetectionFromParseResult(v4, a1) + 16);
}
