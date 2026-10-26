void __thiscall sub_65768E(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *i; // edx
  int v7; // [esp+14h] [ebp+10h]

  v4 = (unsigned __int8 *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[this[26]]; v4 < i; *(a4 - 1) = (double)v7 * 0.0039215689 )
  {
    *a4 = 0.0;
    a4 += 4;
    *(a4 - 3) = 0.0;
    *(a4 - 2) = 0.0;
    v7 = *v4++;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
