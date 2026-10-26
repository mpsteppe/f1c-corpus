int __thiscall sub_61E0A0(int *this)
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
      sub_619A40(v4 + this[1]);
      result = *this;
      ++v3;
      v4 += 584;
    }
    while ( v3 < *this );
  }
  return result;
}
