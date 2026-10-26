_DWORD *__thiscall sub_67F6FF(_DWORD *this, _DWORD *a2, const void *a3)
{
  bool v4; // zf

  sub_67EC68(this, 14);
  *this = &off_73CE7C;
  this[4] = *a2;
  this[5] = a2[1];
  this[6] = a2[2];
  this[7] = a2[3];
  v4 = this[4] == 4;
  qmemcpy(this + 8, a3, 0x20u);
  if ( v4 && this[6] )
    this[6] = sub_67ECC3(this[6]);
  return this;
}
