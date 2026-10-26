// f1c  0x004bdb90  size=78
_DWORD *__thiscall sub_4BDB90(_DWORD *this)
{
  _DWORD *v2; // edi
  int v3; // ebx

  v2 = this;
  v3 = 64;
  do
  {
    sub_4BD7D0(v2);
    v2 += 9;
    --v3;
  }
  while ( v3 );
  sub_4BD7D0(this + 576);
  this[585] = 0;
  this[586] = 0;
  this[587] = 0;
  this[588] = 0;
  this[589] = 0;
  return this;
}
