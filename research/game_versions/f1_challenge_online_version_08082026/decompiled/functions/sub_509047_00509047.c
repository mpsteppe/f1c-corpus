int __thiscall sub_509047(_DWORD *this, char a2, char a3, int a4)
{
  int v4; // eax
  int *v5; // edx
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  int v10; // [esp+Ch] [ebp-28h]
  float v11; // [esp+20h] [ebp-14h]
  float v12; // [esp+20h] [ebp-14h]
  float v13; // [esp+20h] [ebp-14h]
  float v14; // [esp+20h] [ebp-14h]
  int v15; // [esp+24h] [ebp-10h]
  float v16; // [esp+28h] [ebp-Ch]
  unsigned int v17; // [esp+2Ch] [ebp-8h]
  _DWORD *v18; // [esp+30h] [ebp-4h]

  v18 = this;
  if ( this[1042] )
  {
    v4 = sub_506CE2(this, a4);
    this = v18;
    a4 = v4;
  }
  v15 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_507473();
  v17 = 0;
  if ( v18[1046] )
  {
    v6 = 0;
    do
    {
      v16 = *(float *)(v15 + 4 * (v17 & 3));
      v11 = *(float *)(v6 + a4) * 512.0 + v16;
      v7 = (int)v11;
      v12 = *(float *)(v6 + a4 + 4) * 512.0 + v16;
      v10 = (int)v12;
      v13 = *(float *)(v6 + a4 + 8) * 512.0 + v16;
      v8 = (int)v13;
      v14 = *(float *)(v6 + a4 + 12) + *(float *)(v6 + a4 + 12) + v16;
      *v5++ = v7 & 0x3FF | ((v10 & 0x3FF | ((((int)v14 << 10) | v8 & 0x3FF) << 10)) << 10);
      ++v17;
      v6 += 16;
    }
    while ( v17 < v18[1046] );
  }
  return dword_8B009C;
}
