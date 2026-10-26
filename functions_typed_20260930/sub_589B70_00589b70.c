int __cdecl sub_589B70(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 0x103;
  else
    return CharacterEncodingConvertViaLookupTableFallback(CharType, 259);
}

