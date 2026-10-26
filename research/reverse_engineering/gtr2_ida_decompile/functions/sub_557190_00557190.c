int __thiscall sub_557190(_DWORD *this, int a2, int a3)
{
  int i; // eax
  int v4; // edx
  int v5; // ebp
  int v6; // ebx

  for ( i = 0; i < a3; this[70] = v4 )
  {
    v4 = this[68];
    v5 = v4 * *(unsigned __int8 *)(i + a2) + this[71];
    this[68] = this[69];
    v6 = this[70];
    ++i;
    this[71] = v5;
    this[69] = v6;
  }
  return sub_631E50(a2, a3, 1, *this);
}
