char __thiscall sub_59BB10(_BYTE *this, int a2)
{
  int v2; // edx
  char result; // al
  int v4; // esi

  v2 = 0;
  result = 1;
  v4 = a2 - (_DWORD)this;
  while ( *this == this[v4] )
  {
    ++v2;
    ++this;
    if ( v2 >= 16 )
      return result;
  }
  return 0;
}
