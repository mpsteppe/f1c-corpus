// Address: 0x0050af57
// Size: 111 bytes
// Name: sub_50AF57
// Type: signed int __thiscall(_DWORD *this, int, int, void *)
// Source: IDA Hex-Rays decompilation

signed int __thiscall sub_50AF57(_DWORD *this, int a2, int a3, void *a4)
{
  signed int result; // eax

  result = sub_50AB51(this[1037] + a2, this[1040] + a3, 1);
  if ( result >= 0 )
  {
    result = 16 * this[1046];
    qmemcpy(a4, (const void *)(this[1051] + 16 * (this[1036] - this[1052])), result);
    if ( this[4] )
      return sub_507845(a4);
  }
  return result;
}
