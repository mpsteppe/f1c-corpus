// f1c  0x00589b70  size=46
int __cdecl sub_589B70(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 0x103;
  else
    return sub_58C674(CharType, 259);
}
