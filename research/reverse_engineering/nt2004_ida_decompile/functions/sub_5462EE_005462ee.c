int __thiscall sub_5462EE(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // eax
  _QWORD *v5; // esi
  int v6; // ecx
  int v7; // edi
  unsigned __int64 v8; // rt0
  int v10; // [esp+Ch] [ebp-2Ch]
  int v11; // [esp+10h] [ebp-28h]
  float v12; // [esp+24h] [ebp-14h]
  float v13; // [esp+24h] [ebp-14h]
  float v14; // [esp+24h] [ebp-14h]
  float v15; // [esp+24h] [ebp-14h]
  int v16; // [esp+28h] [ebp-10h]
  float v17; // [esp+2Ch] [ebp-Ch]
  unsigned int v18; // [esp+30h] [ebp-8h]
  _DWORD *v19; // [esp+34h] [ebp-4h]

  v19 = this;
  if ( this[1042] )
  {
    v4 = sub_543AE8(this, a4);
    this = v19;
    a4 = v4;
  }
  v5 = (_QWORD *)(this[6] + a3 * this[1045] + a2 * this[1044]);
  v16 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
  sub_544279();
  v18 = 0;
  if ( v19[1046] )
  {
    v6 = 0;
    do
    {
      v17 = *(float *)(v16 + 4 * (v18 & 3));
      v12 = *(float *)(v6 + a4) * 65535.0 + v17;
      v7 = (int)v12;
      v13 = *(float *)(v6 + a4 + 4) * 65535.0 + v17;
      v11 = (int)v13;
      v14 = *(float *)(v6 + a4 + 8) * 65535.0 + v17;
      v10 = (int)v14;
      v15 = *(float *)(v6 + a4 + 12) * 65535.0 + v17;
      v8 = v11 | ((v7 | (unsigned __int64)((__int64)(int)v15 << 16)) << 16);
      *v5++ = __PAIR64__((v10 >> 31) | (unsigned int)(v8 >> 16), (unsigned int)v10 | ((_DWORD)v8 << 16));
      ++v18;
      v6 += 16;
    }
    while ( v18 < v19[1046] );
  }
  return dword_7E0598;
}
