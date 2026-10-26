int __cdecl sub_589BC6(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 0x80;
  else
    return sub_58C674(CharType, 128);
}
