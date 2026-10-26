// f1c  0x0048d380  size=25
int __thiscall sub_48D380(_DWORD *this, int a2)
{
  int result; // eax

  result = a2;
  if ( a2 >= 0 && a2 < this[202] )
    this[206] = a2;
  return result;
}
