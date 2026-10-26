// f1c  0x0050a3ce  size=186
void __thiscall sub_50A3CE(_DWORD *this, int a2, int a3, float *a4)
{
  _DWORD *v4; // eax
  _DWORD *i; // ebx
  __int16 v7; // si
  double v8; // st6
  int v9; // [esp+14h] [ebp+10h]

  v4 = (_DWORD *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[this[1046]]; v4 < i; *(a4 - 1) = 1.0 )
  {
    v7 = (__int16)(32 * (*v4 >> 21)) >> 5;
    v8 = (double)((__int16)(*(_WORD *)v4 << 6) >> 6);
    v9 = (__int16)(32 * (*v4++ >> 10)) >> 5;
    *a4 = v8 * 0.001953125;
    a4 += 4;
    *(a4 - 3) = (double)v9 * 0.0009765625;
    *(a4 - 2) = (double)v7 * 0.0009765625;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
