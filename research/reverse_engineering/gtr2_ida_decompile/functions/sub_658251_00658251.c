void __thiscall sub_658251(_DWORD *this, int a2, int a3, int a4)
{
  unsigned int v6; // esi
  unsigned int i; // [esp+14h] [ebp+8h]

  v6 = this[8] + a3 * this[25] + a2 * this[24];
  for ( i = v6 + 2 * this[26]; v6 < i; *(float *)(a4 - 12) = 1.0 )
  {
    sub_5A9459();
    *(float *)(a4 + 12) = 1.0;
    v6 += 2;
    *(float *)(a4 + 8) = 1.0;
    a4 += 16;
  }
  if ( this[6] )
    sub_650019((int)this, a4 - 16 * this[26]);
  if ( this[4] )
    sub_650286(this, a4 - 16 * this[26]);
}
