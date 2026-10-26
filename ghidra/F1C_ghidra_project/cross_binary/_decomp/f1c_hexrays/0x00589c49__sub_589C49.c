// f1c  0x00589c49  size=46
int __cdecl sub_589C49(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 0x157;
  else
    return sub_58C674(CharType, 343);
}
