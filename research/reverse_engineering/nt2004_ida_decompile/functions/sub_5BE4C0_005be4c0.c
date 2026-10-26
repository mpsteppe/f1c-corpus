int __thiscall sub_5BE4C0(_BYTE *this)
{
  int result; // eax
  int v2; // edx

  this[256] = 1;
  this[257] = 3;
  this[258] = 5;
  this[259] = 7;
  this[260] = 11;
  result = 0;
  v2 = 255;
  do
    this[result++] = v2--;
  while ( result < 256 );
  return result;
}
