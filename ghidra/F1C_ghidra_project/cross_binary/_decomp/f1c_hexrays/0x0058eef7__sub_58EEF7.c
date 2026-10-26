// f1c  0x0058eef7  size=55
unsigned int __cdecl sub_58EEF7(int CharType)
{
  int v1; // esi
  int v2; // eax

  v1 = CharType;
  if ( cbMultiByte <= 1 )
    v2 = off_5E69C8[0][CharType] & 4;
  else
    v2 = sub_58C674(CharType, 4);
  if ( !v2 )
    return (CharType & 0xFFFFFFDF) - 7;
  return v1;
}
