_DWORD *__thiscall sub_5C4540(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // eax

  sub_5D16B0(a2);
  *this = &off_729DD4;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  if ( operator new(8u) )
    v3 = sub_5D2DD0(this);
  else
    v3 = 0;
  sub_5C7220(this, v3);
  if ( operator new(8u) )
    v4 = sub_5D27C0(this);
  else
    v4 = 0;
  sub_5C7220(this, v4);
  return this;
}
