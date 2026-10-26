// f1c  0x0056f060  size=43
int __thiscall sub_56F060(int *this)
{
  int result; // eax
  int v3; // edi
  int v4; // ebx

  result = *this;
  v3 = 0;
  if ( *this > 0 )
  {
    v4 = 0;
    do
    {
      sub_56A150(v4 + this[1]);
      result = *this;
      ++v3;
      v4 += 580;
    }
    while ( v3 < *this );
  }
  return result;
}
