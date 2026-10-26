int __cdecl sub_589C1B(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 0x107;
  else
    return CharacterEncodingConvertViaLookupTableFallback(CharType, 263);
}

