int __thiscall sub_6ABB25(_DWORD *this, _DWORD *a2, _DWORD *a3)
{
  int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  int v8; // edi
  int v9; // edx
  int v10; // ebx
  unsigned int v11; // edx
  int v12; // eax
  int v13; // edi
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  unsigned int v17; // edx
  _DWORD *v18; // edx
  int v19; // esi
  _DWORD *v20; // esi
  int v21; // esi
  int v22; // eax
  _DWORD *v23; // edi
  bool v24; // cc
  int v25; // eax
  int v26; // edi
  _DWORD v27[36]; // [esp+4h] [ebp-C8h] BYREF
  int v28; // [esp+94h] [ebp-38h]
  unsigned int v29; // [esp+98h] [ebp-34h]
  int v30; // [esp+9Ch] [ebp-30h]
  int v31; // [esp+A0h] [ebp-2Ch]
  int v32; // [esp+A4h] [ebp-28h]
  int v33; // [esp+A8h] [ebp-24h]
  int v34; // [esp+ACh] [ebp-20h]
  unsigned int v35; // [esp+B0h] [ebp-1Ch]
  int v36; // [esp+B4h] [ebp-18h]
  int v37; // [esp+B8h] [ebp-14h]
  unsigned int v38; // [esp+BCh] [ebp-10h]
  int v39; // [esp+C0h] [ebp-Ch]
  int v40; // [esp+C4h] [ebp-8h]
  unsigned int v41; // [esp+C8h] [ebp-4h]

  if ( !a2 )
    return 1;
  v4 = *a2;
  if ( (*a2 & 0xFFF00000) == 0 )
    return 0;
  v39 = v4 & 0xFFFFF;
  v5 = a2[1] / (v4 & 0xFFFFFu);
  v41 = 0;
  v40 = 0;
  v36 = 0;
  v35 = v5;
  v6 = *a3 & 0xFFFFF;
  v7 = a3[1] / v6;
  v8 = this[34];
  v9 = this[32];
  v27[v9 + 18] = 0;
  v8 *= 4;
  *(_DWORD *)((char *)&v27[18] + v8) = 0;
  v10 = this[31];
  v27[v10 + 18] = 0;
  v27[v9] = 2;
  v11 = v35;
  *(_DWORD *)((char *)v27 + v8) = 5;
  v27[v10] = 3;
  v29 = v11 + v7;
  if ( v11 + v7 )
  {
    v37 = 0;
    v33 = 4 * v39;
    v31 = 4 * v6;
    v12 = -4 * v11 * v6;
    v28 = v12;
    v32 = v12;
    do
    {
      v13 = this[5];
      if ( v41 >= v35 )
        v14 = *(_DWORD *)(v12 + a3[2]);
      else
        v14 = *(_DWORD *)(v37 + a2[2]);
      v15 = *(_DWORD *)(v13 + 4 * v14);
      v16 = *(_DWORD *)(v15 + 4);
      v30 = *(_DWORD *)(this[4] + 4 * v16);
      v17 = 0;
      v38 = 0;
      if ( v41 )
      {
        v39 = 0;
        v34 = v28;
        do
        {
          if ( v17 >= v35 )
          {
            v18 = a3;
            v19 = v34;
          }
          else
          {
            v18 = a2;
            v19 = v39;
          }
          v20 = *(_DWORD **)(v13 + 4 * *(_DWORD *)(v19 + v18[2]));
          if ( v16 == v20[1] && *(_DWORD *)(v15 + 8) == v20[2] && *(_DWORD *)(v15 + 12) == v20[3] )
            break;
          v34 += v31;
          ++v38;
          v39 += v33;
          v17 = v38;
        }
        while ( v38 < v41 );
      }
      if ( v38 == v41 )
      {
        v21 = this[34];
        if ( v16 == v21 && *(_DWORD *)(v15 + 12) > 1u && (unsigned int)++v40 > 3 )
          return 1;
        if ( v16 == this[32] )
        {
          if ( *(_BYTE *)(v15 + 108) == 3 )
          {
            if ( (unsigned __int16)this[50] == 257 && (unsigned int)++v40 > 3 )
              return 1;
            v22 = v21;
          }
          else
          {
            v22 = this[32];
          }
          v23 = &v27[v22 + 18];
          v24 = ++*v23 <= v27[v22];
        }
        else
        {
          v25 = *(_DWORD *)(v30 + 4);
          if ( (v25 & 0x80u) != 0 )
            return 0;
          if ( (v25 & 0x200) != 0 )
          {
            v24 = (unsigned int)++v36 <= 3;
          }
          else
          {
            v26 = *(_DWORD *)(v15 + 4);
            v24 = ++v27[v26 + 18] <= v27[v26];
          }
        }
        if ( !v24 )
          return 1;
      }
      ++v41;
      v37 += v33;
      v12 = v31 + v32;
      v32 += v31;
    }
    while ( v41 < v29 );
  }
  return 0;
}
