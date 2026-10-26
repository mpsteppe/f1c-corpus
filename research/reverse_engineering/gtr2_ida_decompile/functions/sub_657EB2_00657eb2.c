void __thiscall sub_657EB2(_DWORD *this, int a2, int a3, float *a4)
{
  _WORD *v4; // eax
  __int16 v6; // dx
  int v7; // edi
  _WORD *i; // [esp+Ch] [ebp+8h]

  v4 = (_WORD *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[2 * this[26]]; v4 < i; *(a4 - 1) = 1.0 )
  {
    v6 = v4[1];
    v7 = (__int16)(*v4 + (*v4 == 0x8000));
    v4 += 2;
    *a4 = (double)v7 * 0.000030518509;
    a4 += 4;
    *(a4 - 3) = (double)(__int16)(v6 + (v6 == (__int16)0x8000)) * 0.000030518509;
    *(a4 - 2) = 1.0;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
