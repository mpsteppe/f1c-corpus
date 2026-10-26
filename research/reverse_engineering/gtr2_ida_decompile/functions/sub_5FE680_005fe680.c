bool __thiscall sub_5FE680(char *this, float *a2)
{
  int v4; // eax
  float *v5; // eax
  float *v6; // eax
  float *v7; // eax
  float v8; // eax
  float v9; // ecx
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  float *v13; // ebp
  int v14; // ebx
  float *i; // esi
  int v16; // edi
  int v17; // edx
  float *v18; // ecx
  float v19; // [esp+0h] [ebp-4Ch]
  float v20; // [esp+4h] [ebp-48h]
  float v21; // [esp+8h] [ebp-44h]
  float v22; // [esp+10h] [ebp-3Ch] BYREF
  float v23; // [esp+14h] [ebp-38h]
  float v24; // [esp+18h] [ebp-34h]
  float v25; // [esp+1Ch] [ebp-30h] BYREF
  float v26; // [esp+20h] [ebp-2Ch]
  float v27; // [esp+24h] [ebp-28h]
  float v28[3]; // [esp+28h] [ebp-24h] BYREF
  float v29[3]; // [esp+34h] [ebp-18h] BYREF
  _BYTE v30[4]; // [esp+40h] [ebp-Ch] BYREF
  float v31; // [esp+44h] [ebp-8h] BYREF
  _BYTE v32[4]; // [esp+48h] [ebp-4h] BYREF

  if ( (*this & 2) == 0 )
    return 0;
  v4 = *((_DWORD *)this + 69);
  if ( v4 )
  {
    sub_5D77B0((float *)this + 50, &v22, (float *)(v4 + 184));
    sub_5D7810((float *)this + 47, &v25, (float *)(*((_DWORD *)this + 69) + 184));
    sub_5D77B0((float *)this + 53, v29, (float *)(*((_DWORD *)this + 69) + 184));
    sub_5D7940(&v22, v29, v28);
    sub_5D7750(v28);
    sub_5D7940(v29, v28, &v22);
    sub_5D7750(&v22);
    v5 = (float *)*((_DWORD *)this + 68);
    v5[87] = v28[0];
    v5[91] = v28[1];
    v5[95] = v28[2];
    v6 = (float *)*((_DWORD *)this + 68);
    v6[88] = v29[0];
    v6[92] = v29[1];
    v6[96] = v29[2];
    v7 = (float *)(*((_DWORD *)this + 68) + 344);
    v7[3] = v22;
    v7[7] = v23;
    v7[11] = v24;
    v21 = v24 * *((float *)this + 56) - v27;
    v20 = v23 * *((float *)this + 56) - v26;
    v19 = v22 * *((float *)this + 56) - v25;
    sub_5E4C80(*((float **)this + 68), v19, v20, v21);
    v8 = v26;
    v9 = v27;
    *((float *)this + 11) = v25;
    *((float *)this + 12) = v8;
    *((float *)this + 13) = v9;
  }
  sub_5E4D90(a2, (int)v30, (int)&v31, (int)v32);
  if ( v11 | v12 )
    return 0;
  sub_5FE3F0(this);
  v13 = (float *)(this + 64);
  v14 = 0;
  for ( i = a2 + 64; ; i += 4 )
  {
    v16 = 0;
    v17 = 0;
    v31 = -i[1];
    v18 = v13;
    do
    {
      if ( *(v18 - 1) * *(i - 1) + *(v18 - 2) * *(i - 2) + *i * *v18 <= v31 )
        break;
      ++v16;
      ++v17;
      v18 += 3;
    }
    while ( v17 < 8 );
    if ( v16 )
      break;
    if ( ++v14 >= 6 )
      return 1;
  }
  return v16 != 8;
}
