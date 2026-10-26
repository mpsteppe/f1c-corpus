int __thiscall sub_434600(char *this)
{
  int v1; // eax
  _BYTE *v2; // ecx

  v1 = 44;
  v2 = this + 5836;
  do
  {
    if ( !*v2 )
      break;
    ++v1;
    v2 += 64;
  }
  while ( v1 <= 50 );
  return v1 - 44;
}
