int __thiscall sub_4C1370(char *this)
{
  int result; // eax
  _BYTE *v2; // ecx
  int v3; // edx

  result = 0;
  v2 = this + 432;
  v3 = 103;
  do
  {
    if ( *v2 )
      ++result;
    v2 += 436;
    --v3;
  }
  while ( v3 );
  return result;
}

