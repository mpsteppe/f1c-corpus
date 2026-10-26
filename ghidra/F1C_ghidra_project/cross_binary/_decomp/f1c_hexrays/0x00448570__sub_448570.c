// f1c  0x00448570  size=85
int __thiscall sub_448570(LPVOID *this)
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
      sub_448570();
      result = sub_587BCF(*v2);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  if ( this[23] )
  {
    sub_448570();
    result = sub_587BCF(this[23]);
    this[23] = 0;
  }
  return result;
}
