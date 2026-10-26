void __thiscall sub_658E5F(int this, int a2, int a3, _DWORD *a4)
{
  int v5; // esi
  int v6; // edi
  void *v7; // eax
  void *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int i; // edi
  unsigned int v13; // eax
  _DWORD *v14; // edx
  unsigned int v15; // ecx
  _DWORD *v16; // esi
  _DWORD *v17; // edi
  _DWORD *v18; // ecx
  float v19; // [esp+1Ch] [ebp-18h]
  float v20; // [esp+20h] [ebp-14h]
  float v21; // [esp+24h] [ebp-10h]
  float v22; // [esp+28h] [ebp-Ch]
  int v23; // [esp+3Ch] [ebp+8h]
  int v24; // [esp+3Ch] [ebp+8h]
  int v25; // [esp+3Ch] [ebp+8h]
  void *v26; // [esp+40h] [ebp+Ch]
  int v27; // [esp+40h] [ebp+Ch]
  float v28; // [esp+44h] [ebp+10h]
  float v29; // [esp+44h] [ebp+10h]
  float v30; // [esp+44h] [ebp+10h]
  float v31; // [esp+44h] [ebp+10h]

  v5 = *(_DWORD *)(this + 64) + a2;
  v6 = *(_DWORD *)(this + 76) + a3;
  if ( *(_DWORD *)(this + 240)
    || ((v23 = 16 * *(_DWORD *)(this + 220), v7 = operator new(*(_DWORD *)(this + 220) << 8), (v26 = v7) == 0)
      ? (v8 = 0)
      : (sub_41D1B0((int)v7, 16, v23, (int)sub_681563), v8 = v26),
        (*(_DWORD *)(this + 240) = v8) != 0) )
  {
    v9 = v5 & 0xFFFFFFFC;
    if ( (v5 & 0xFFFFFFFC) != *(_DWORD *)(this + 232) || v6 != *(_DWORD *)(this + 236) )
    {
      *(_DWORD *)(this + 232) = v9;
      v10 = *(_DWORD *)(this + 196);
      v11 = *(_DWORD *)(this + 32)
          + v6 * *(_DWORD *)(this + 100)
          + *(_DWORD *)(this + 136) * (v10 >> 2)
          + *(_DWORD *)(this + 96) * (v9 >> 2);
      *(_DWORD *)(this + 236) = v6;
      v24 = v11;
      v27 = *(_DWORD *)(this + 240);
      for ( i = v10; i < *(_DWORD *)(this + 204); i += 4 )
      {
        (*(void (__stdcall **)(int, int))(this + 140))(v27, v24);
        v24 += *(_DWORD *)(this + 136);
        v27 += 256;
      }
    }
    v13 = *(_DWORD *)(this + 60) - *(_DWORD *)(this + 196);
    v14 = a4;
    v25 = (v5 - *(_DWORD *)(this + 200)) & 3;
    v15 = v13 + *(_DWORD *)(this + 104);
    while ( v13 < v15 )
    {
      v16 = (_DWORD *)(*(_DWORD *)(this + 240) + 16 * (v13 & 3 | (4 * (v25 | v13 & 0xFFFFFFFC))));
      *v14 = *v16++;
      v14[1] = *v16++;
      v14[2] = *v16;
      v17 = v14 + 3;
      v14 += 4;
      *v17 = v16[1];
      ++v13;
    }
    if ( *(_DWORD *)(this + 24) )
    {
      v18 = v14;
      v14 -= 4 * *(_DWORD *)(this + 104);
      *(_DWORD *)(this + 124) = a4;
      while ( v14 < v18 )
      {
        v28 = *(float *)v14 * 31.0 + 0.5;
        v19 = (double)(int)v28 * 0.032258064;
        if ( v19 == *(float *)(this + 36) )
        {
          v29 = *((float *)v14 + 1) * 63.0 + 0.5;
          v20 = (double)(int)v29 * 0.015873017;
          if ( v20 == *(float *)(this + 40) )
          {
            v30 = *((float *)v14 + 2) * 31.0 + 0.5;
            v21 = (double)(int)v30 * 0.032258064;
            if ( v21 == *(float *)(this + 44) )
            {
              v31 = *((float *)v14 + 3) * *(float *)(this + 128) + 0.5;
              v22 = (double)(int)v31 * *(float *)(this + 132);
              if ( v22 == *(float *)(this + 48) )
              {
                *(float *)v14 = 0.0;
                *((float *)v14 + 1) = 0.0;
                *((float *)v14 + 2) = 0.0;
                *((float *)v14 + 3) = 0.0;
              }
            }
          }
        }
        v14 += 4;
      }
    }
    if ( *(_DWORD *)(this + 16) )
      sub_650286((_DWORD *)this, (unsigned int)&v14[-4 * *(_DWORD *)(this + 104)]);
  }
}
