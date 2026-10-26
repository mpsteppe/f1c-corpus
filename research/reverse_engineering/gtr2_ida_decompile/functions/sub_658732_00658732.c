signed int __thiscall sub_658732(_DWORD *this, int a2, int a3, int a4)
{
  const void *v5; // esi
  signed int result; // eax

  if ( this[21] )
    v5 = (const void *)sub_64EB2A(this, a4);
  else
    v5 = (const void *)a4;
  if ( this[4] )
    v5 = (const void *)sub_650093(this, (int)v5);
  result = sub_64F345((int)this, this[16] + a2, this[19] + a3, this[39] != this[26]);
  if ( result >= 0 )
  {
    result = 16 * this[26];
    qmemcpy((void *)(this[32] + 16 * (this[15] - this[33])), v5, result);
    this[40] = 1;
  }
  return result;
}
