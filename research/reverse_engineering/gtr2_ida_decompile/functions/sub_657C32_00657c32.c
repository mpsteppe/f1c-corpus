void __thiscall sub_657C32(_DWORD *this, int a2, int a3, float *a4)
{
  _BYTE *v6; // eax
  char v7; // dl
  _BYTE *i; // [esp+10h] [ebp+8h]
  int v9; // [esp+18h] [ebp+10h]

  v6 = (_BYTE *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v6[2 * this[26]]; v6 < i; *(a4 - 1) = (double)v9 * 0.015873017 )
  {
    v7 = ((char)(8 * (*(unsigned __int16 *)v6 >> 5)) >> 3) + ((char)(8 * (*(unsigned __int16 *)v6 >> 5)) >> 3 == 0xF0);
    *a4 = (double)(char)(((char)(8 * *v6) >> 3) + ((char)(8 * *v6) >> 3 == 0xF0)) * 0.06666667;
    a4 += 4;
    *(a4 - 3) = (double)v7 * 0.06666667;
    *(a4 - 2) = 1.0;
    v9 = *(_WORD *)v6 >> 10;
    v6 += 2;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
