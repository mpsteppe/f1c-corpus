int __thiscall sub_44A9B0(LPVOID *this)
{
  LPVOID *v2; // esi
  int v3; // ebx
  int result; // eax

  v2 = this + 19;
  v3 = 4;
  do
  {
    if ( *v2 )
    {
      sub_44A9B0();
      result = sub_5BE8AE(*v2);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  if ( this[23] )
  {
    sub_44A9B0();
    result = sub_5BE8AE(this[23]);
    this[23] = 0;
  }
  return result;
}
