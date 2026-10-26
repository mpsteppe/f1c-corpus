_DWORD *__thiscall sub_4F7E70(_DWORD *this, _DWORD *a2)
{
  int i; // edx
  _DWORD *v4; // eax
  int v5; // edx

  sub_4F7CC0(this);
  for ( i = 0; i < a2[96]; i = v5 + 1 )
  {
    v4 = sub_4F7D10(a2, i);
    this[2 * v5] = *v4;
    this[2 * v5 + 1] = v4[1];
  }
  this[96] = a2[96];
  return this;
}
