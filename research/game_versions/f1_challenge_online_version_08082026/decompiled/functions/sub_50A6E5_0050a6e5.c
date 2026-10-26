void __fastcall sub_50A6E5(_DWORD *a1, int a2, int a3, int a4, float *a5)
{
  _DWORD *v5; // esi
  _DWORD *v7; // [esp+8h] [ebp-4h]
  _DWORD *v8; // [esp+14h] [ebp+8h]
  unsigned int v9; // [esp+1Ch] [ebp+10h]

  v5 = (_DWORD *)(a1[6] + a4 * a1[1045] + a3 * a1[1044]);
  v7 = a1;
  v8 = &v5[2 * a1[1046]];
  if ( v5 < v8 )
  {
    do
    {
      LOBYTE(a1) = 32;
      *a5 = (double)(unsigned __int16)sub_58A870(a1, v5[1]) * 0.000015259022;
      a1 = (_DWORD *)HIWORD(v5[1]);
      a5[1] = (double)(unsigned __int16)HIWORD(*v5) * 0.000015259022;
      v9 = (unsigned __int16)*v5;
      v5 += 2;
      a5 += 4;
      *(a5 - 2) = (double)v9 * 0.000015259022;
      *(a5 - 1) = (double)*((unsigned __int16 *)v5 - 1) * 0.000015259022;
    }
    while ( v5 < v8 );
    a1 = v7;
  }
  if ( a1[4] )
    sub_507845((int)a1, (unsigned int)&a5[-4 * a1[1046]]);
}
