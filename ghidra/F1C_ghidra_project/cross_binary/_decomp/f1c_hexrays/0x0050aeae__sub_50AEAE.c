// f1c  0x0050aeae  size=141
signed int __thiscall sub_50AEAE(_DWORD *this, int a2, int a3, const void *a4)
{
  signed int result; // eax

  if ( this[1042] )
    a4 = (const void *)sub_506CE2(this, (int)a4);
  result = sub_50AB51((int)this, this[1037] + a2, this[1040] + a3, this[1058] != this[1046]);
  if ( result >= 0 )
  {
    result = 16 * this[1046];
    qmemcpy((void *)(this[1051] + 16 * (this[1036] - this[1052])), a4, result);
    this[1059] = 1;
  }
  return result;
}
