void __thiscall sub_50A2B4(_DWORD *this, int a2, int a3, float *a4)
{
  char *v4; // eax
  char *i; // esi
  int v7; // [esp+14h] [ebp+10h]

  v4 = (char *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[4 * this[1046]]; v4 < i; *(a4 - 1) = (double)*(v4 - 1) * 0.0078125 )
  {
    v7 = *v4;
    v4 += 4;
    *a4 = (double)v7 * 0.0078125;
    a4 += 4;
    *(a4 - 3) = (double)*(v4 - 3) * 0.0078125;
    *(a4 - 2) = (double)*(v4 - 2) * 0.0078125;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
