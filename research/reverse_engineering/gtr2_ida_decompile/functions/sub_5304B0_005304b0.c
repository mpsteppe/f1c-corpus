int __thiscall sub_5304B0(char *this)
{
  int result; // eax
  _BYTE *v2; // ecx
  int v3; // edx

  result = 0;
  v2 = this + 840;
  v3 = 103;
  do
  {
    if ( *v2 )
      ++result;
    v2 += 920;
    --v3;
  }
  while ( v3 );
  return result;
}
