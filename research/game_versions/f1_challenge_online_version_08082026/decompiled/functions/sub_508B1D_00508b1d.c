int __thiscall sub_508B1D(_DWORD *this, char a2, char a3, int a4)
{
  unsigned int v4; // ebx
  int v5; // eax
  _WORD *v6; // edx
  int v7; // esi
  char v8; // cl
  char v9; // al
  float v11; // [esp+18h] [ebp-10h]
  float v12; // [esp+18h] [ebp-10h]
  float v13; // [esp+18h] [ebp-10h]
  int v14; // [esp+1Ch] [ebp-Ch]
  float v15; // [esp+20h] [ebp-8h]
  _DWORD *v16; // [esp+24h] [ebp-4h]

  v4 = 0;
  v16 = this;
  if ( this[1042] )
  {
    v5 = sub_506CE2(this, a4);
    this = v16;
    a4 = v5;
  }
  v14 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_507473();
  if ( v16[1046] )
  {
    v7 = 0;
    do
    {
      v15 = *(float *)(v14 + 4 * (v4 & 3));
      v11 = *(float *)(v7 + a4) * 16.0 + v15;
      v8 = (int)v11;
      v12 = *(float *)(v7 + a4 + 4) * 16.0 + v15;
      v9 = (int)v12;
      v13 = *(float *)(v7 + a4 + 12) * 63.0 + v15;
      *v6++ = v8 & 0x1F | (32 * ((32 * (int)v13) | v9 & 0x1F));
      ++v4;
      v7 += 16;
    }
    while ( v4 < v16[1046] );
  }
  return dword_8B009C;
}
