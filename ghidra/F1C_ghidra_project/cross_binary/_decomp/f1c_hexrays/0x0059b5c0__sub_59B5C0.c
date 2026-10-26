// f1c  0x0059b5c0  size=132
char __thiscall sub_59B5C0(_DWORD *this, int a2, _DWORD *a3)
{
  unsigned int v4; // eax
  unsigned int v5; // ebp
  _BYTE *v6; // edi
  char v7; // dl
  int v8; // eax

  sub_59B490((int)this, a2);
  sub_59B530((int)this);
  *(_WORD *)(this[2] + 4 * this[5]) = *((_WORD *)this + 8);
  *(_WORD *)(this[2] + 4 * this[5] + 2) = a2;
  v4 = *(unsigned __int16 *)(this[2] + 4 * this[5]);
  v5 = (unsigned __int16)v4 + a2;
  if ( (unsigned __int16)v4 < v5 )
  {
    do
    {
      v6 = (_BYTE *)(*this + (v4 >> 3));
      v7 = ~(1 << (v4++ & 7));
      *v6 &= v7;
    }
    while ( v4 < v5 );
  }
  *a3 = this[5];
  v8 = this[5] + 1;
  this[4] += a2;
  this[5] = v8;
  return 1;
}
