void __thiscall sub_658073(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned int v4; // eax
  __int16 v6; // bx
  bool v7; // cl
  int v8; // [esp+8h] [ebp-Ch]
  _DWORD *v9; // [esp+Ch] [ebp-8h]
  unsigned int v10; // [esp+10h] [ebp-4h]
  int v11; // [esp+24h] [ebp+10h]

  v4 = this[8] + a3 * this[25] + a2 * this[24];
  v9 = this;
  v10 = v4 + 8 * this[26];
  if ( v4 < v10 )
  {
    do
    {
      v11 = *(_QWORD *)v4 >> 16;
      v6 = *(_DWORD *)(v4 + 4);
      v8 = *(_DWORD *)(v4 + 4);
      v7 = HIWORD(*(_DWORD *)v4) == 0x8000;
      *a4 = (double)(__int16)(*(_WORD *)v4 + (*(_WORD *)v4 == 0x8000)) * 0.000030518509;
      a4[1] = (double)(__int16)(v11 + v7) * 0.000030518509;
      v4 += 8;
      a4 += 4;
      *(a4 - 2) = (double)(__int16)(v6 + (v6 == -32768)) * 0.000030518509;
      *(a4 - 1) = (double)(__int16)(HIWORD(v8) + (HIWORD(v8) == 0x8000)) * 0.000030518509;
    }
    while ( v4 < v10 );
    this = v9;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
