int __cdecl sub_589BF3(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 8;
  else
    return CharacterEncodingConvertViaLookupTableFallback(CharType, 8);
}

