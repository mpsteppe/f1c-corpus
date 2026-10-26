void __thiscall sub_50A34B(_DWORD *this, int a2, int a3, float *a4)
{
  __int16 *v4; // eax
  __int16 *i; // esi
  int v7; // [esp+14h] [ebp+10h]

  v4 = (__int16 *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[2 * this[1046]]; v4 < i; *(a4 - 1) = 1.0 )
  {
    v7 = *v4;
    v4 += 2;
    *a4 = (double)v7 * 0.000030517578;
    a4 += 4;
    *(a4 - 3) = (double)*(v4 - 1) * 0.000030517578;
    *(a4 - 2) = 0.0;
  }
  if ( this[4] )
    ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
