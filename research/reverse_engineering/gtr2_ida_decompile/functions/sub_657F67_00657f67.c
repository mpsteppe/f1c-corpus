void __thiscall sub_657F67(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v4; // eax
  __int16 v6; // bx
  double v7; // st6
  _DWORD *i; // [esp+10h] [ebp+Ch]
  __int16 v9; // [esp+14h] [ebp+10h]

  v4 = (_DWORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *(a4 - 1) = v7 * 0.33333334 )
  {
    v6 = (__int16)((unsigned __int16)(*v4 >> 10) << 6) >> 6;
    v9 = (__int16)(*v4 >> 20 << 6) >> 6;
    *a4 = (double)(__int16)(((__int16)(*(_WORD *)v4 << 6) >> 6) + ((__int16)(*(_WORD *)v4 << 6) >> 6 == 0xFE00))
        * 0.0019569471;
    a4[1] = (double)(__int16)(v6 + (v6 == -512)) * 0.0019569471;
    a4[2] = (double)(__int16)(v9 + (v9 == -512)) * 0.0019569471;
    v7 = (double)(*v4++ >> 30);
    a4 += 4;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
