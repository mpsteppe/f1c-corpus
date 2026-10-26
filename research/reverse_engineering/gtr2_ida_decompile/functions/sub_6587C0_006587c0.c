void __thiscall sub_6587C0(_DWORD *this, int a2, int a3, void *a4)
{
  if ( sub_64F345((int)this, this[16] + a2, this[19] + a3, 1) >= 0 )
  {
    qmemcpy(a4, (const void *)(this[32] + 16 * (this[15] - this[33])), 16 * this[26]);
    if ( this[6] )
      sub_650019((int)this, (unsigned int)a4);
    if ( this[4] )
      sub_650286(this, (unsigned int)a4);
  }
}
