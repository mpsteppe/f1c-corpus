// f1c  0x00589c1b  size=46
int __cdecl sub_589C1B(int CharType)
{
  if ( cbMultiByte <= 1 )
    return off_5E69C8[0][CharType] & 0x107;
  else
    return sub_58C674(CharType, 263);
}
