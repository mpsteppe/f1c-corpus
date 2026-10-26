void __thiscall sub_65848E(_DWORD *this, int a2, int a3, void *a4)
{
  qmemcpy(a4, (const void *)(this[8] + a3 * this[25] + a2 * this[24]), 16 * this[26]);
  if ( this[6] )
    sub_650019((int)this, (unsigned int)a4);
  if ( this[4] )
    sub_650286(this, (unsigned int)a4);
}
