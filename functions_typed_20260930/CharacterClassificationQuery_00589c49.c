int __cdecl sub_589C49(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 0x157;
  else
    return CharacterEncodingConvertViaLookupTableFallback(CharType, 343);
}

