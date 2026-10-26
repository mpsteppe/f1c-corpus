int __thiscall sub_4E4C30(char *this)
{
  int result; // eax
  _BYTE *v2; // ecx
  int v3; // edx

  result = 0;
  v2 = this + 656;
  v3 = 47;
  do
  {
    if ( *v2 )
      ++result;
    v2 += 644;
    --v3;
  }
  while ( v3 );
  return result;
}
