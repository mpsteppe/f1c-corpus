// f1c  0x0059bf19  size=61
_DWORD *__thiscall sub_59BF19(_DWORD *this, _DWORD **a2)
{
  char *v3; // eax
  int v4; // eax

  *this = &exception::`vftable';
  v3 = sub_58E1B0(*a2);
  v4 = sub_587C03((int)(v3 + 1));
  this[1] = v4;
  if ( v4 )
    sub_58FCA0();
  this[2] = 1;
  return this;
}
