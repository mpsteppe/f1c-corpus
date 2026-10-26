// f1c  0x00589b9e  size=40
int __cdecl sub_589B9E(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 4;
  else
    return sub_58C674(CharType, 4);
}
