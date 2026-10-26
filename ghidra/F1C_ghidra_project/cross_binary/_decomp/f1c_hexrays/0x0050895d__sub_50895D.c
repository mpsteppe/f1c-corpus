// f1c  0x0050895d  size=235
int __thiscall sub_50895D(_DWORD *this, char a2, char a3, int a4)
{
  unsigned int v4; // edi
  int v5; // eax
  int v6; // ebx
  _BYTE *v7; // edx
  int v8; // esi
  float v10; // [esp+10h] [ebp-10h]
  float v11; // [esp+18h] [ebp-8h]
  _DWORD *v12; // [esp+1Ch] [ebp-4h]

  v4 = 0;
  v12 = this;
  if ( this[1042] )
  {
    v5 = sub_506CE2(this, a4);
    this = v12;
    a4 = v5;
  }
  v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_507473();
  if ( v12[1046] )
  {
    v8 = 0;
    do
    {
      v11 = (*(float *)(v8 + a4 + 8) * 0.072099999
           + *(float *)(v8 + a4 + 4) * 0.71539998
           + *(float *)(v8 + a4) * 0.21250001)
          * 15.0
          + *(float *)(v6 + 4 * (v4 & 3));
      v10 = *(float *)(v8 + a4 + 12) * 15.0 + *(float *)(v6 + 4 * (v4 & 3));
      *v7++ = (int)v11 | (16 * (int)v10);
      ++v4;
      v8 += 16;
    }
    while ( v4 < v12[1046] );
  }
  return dword_8B009C;
}
