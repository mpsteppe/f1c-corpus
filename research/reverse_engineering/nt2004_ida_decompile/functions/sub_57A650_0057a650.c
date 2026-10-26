_DWORD *__thiscall sub_57A650(_DWORD *this, _DWORD *a2)
{
  int v3; // eax

  v3 = -1;
  this[3] = 0;
  this[4] = -1;
  this[5] = 0;
  this[6] = -1;
  *this = a2;
  this[1] = 0;
  this[2] = 0;
  if ( a2 )
    v3 = sub_4EC5D0(a2);
  this[7] = v3;
  this[8] = 0;
  return this;
}
