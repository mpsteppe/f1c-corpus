// f1c  0x00589bf3  size=40
int __cdecl sub_589BF3(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 8;
  else
    return sub_58C674(CharType, 8);
}
