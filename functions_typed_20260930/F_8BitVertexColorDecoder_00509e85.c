void __thiscall sub_509E85(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int8 *v4; // eax
  float *v6; // edi
  float *v7; // esi
  unsigned __int8 *i; // [esp+8h] [ebp+8h]
  int v9; // [esp+10h] [ebp+10h]

  v4 = (unsigned __int8 *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[2 * this[1046]]; v4 < i; *(a4 - 1) = (double)v9 * 0.0039215689 )
  {
    v6 = a4;
    a4 += 4;
    v7 = (float *)&this[4 * *v4 + 12];
    *v6 = *v7++;
    *++v6 = *v7++;
    *++v6 = *v7;
    v6[1] = v7[1];
    v9 = v4[1];
    v4 += 2;
  }
  if ( this[4] )
    ContactManifoldCleanup((int)this, (unsigned int)&a4[-4 * this[1046]]);
}

