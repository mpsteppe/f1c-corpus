void __thiscall sub_65786D(_DWORD *this, int a2, int a3, float *a4)
{
  unsigned __int8 *v4; // eax
  float *v6; // edi
  float *v7; // edx
  unsigned __int8 *v8; // eax
  unsigned __int8 *i; // [esp+Ch] [ebp+8h]
  int v10; // [esp+14h] [ebp+10h]

  v4 = (unsigned __int8 *)(this[8] + a3 * this[25] + a2 * this[24]);
  for ( i = &v4[2 * this[26]]; v4 < i; *(a4 - 1) = (double)v10 * 0.0039215689 )
  {
    v6 = a4;
    a4 += 4;
    v7 = (float *)(this[14] + 16 * *v4);
    v8 = v4 + 1;
    *v6++ = *v7;
    *v6++ = v7[1];
    *v6 = v7[2];
    v6[1] = v7[3];
    v10 = *v8;
    v4 = v8 + 1;
  }
  if ( this[6] )
    sub_650019((int)this, (unsigned int)&a4[-4 * this[26]]);
  if ( this[4] )
    sub_650286(this, (unsigned int)&a4[-4 * this[26]]);
}
