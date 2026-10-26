_DWORD *__thiscall sub_567900(_DWORD *this, _DWORD *a2)
{
  int v3; // eax

  v3 = -1;
  this[4] = 0;
  this[5] = -1;
  this[6] = 0;
  this[7] = -1;
  *this = a2;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  if ( a2 )
    v3 = FieldGetter_79d0(a2);
  this[8] = v3;
  this[9] = 0;
  this[10] = 0;
  return this;
}
