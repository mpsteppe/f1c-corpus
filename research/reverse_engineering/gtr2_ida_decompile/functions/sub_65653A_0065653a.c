int __thiscall sub_65653A(_DWORD *this, int a2, int a3, int a4)
{
  unsigned int v5; // ebx
  int result; // eax
  int v7; // esi

  v5 = 0;
  if ( this[4] )
    a4 = sub_650093(this, a4);
  result = a3 * this[25];
  v7 = this[8] + result + a2 * this[24];
  if ( this[26] )
  {
    do
    {
      result = sub_5A939E();
      a4 += 16;
      v7 += 2;
      ++v5;
    }
    while ( v5 < this[26] );
  }
  return result;
}
