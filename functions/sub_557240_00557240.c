_DWORD *__thiscall sub_557240(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // ebx

  GlobalZeroInit_c2a0(this);
  v2 = this + 1;
  v3 = 8;
  do
  {
    StructInitWithDefaultValues(v2);
    v2 += 16;
    --v3;
  }
  while ( v3 );
  this[129] = 0;
  this[130] = 0;
  this[131] = 0;
  return this;
}
