// f1c  0x00509f70  size=110
void __thiscall sub_509F70(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *i; // esi
  double v7; // st7
  int v8; // [esp+14h] [ebp+10h]

  v4 = (unsigned __int8 *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  for ( i = &v4[this[1046]]; v4 < i; *(a4 - 1) = 1.0 )
  {
    v8 = *v4++;
    v7 = (double)v8 * 0.0039215689;
    a4[2] = v7;
    a4[1] = v7;
    *a4 = v7;
    a4 += 4;
  }
  if ( this[4] )
    sub_507845((int)this, (unsigned int)&a4[-4 * this[1046]]);
}
