int __thiscall sub_6624E8(
        _DWORD *this,
        int a2,
        unsigned int a3,
        unsigned int a4,
        __int16 a5,
        unsigned int *a6,
        unsigned int a7,
        _DWORD *a8,
        int a9,
        int *a10)
{
  unsigned int v10; // eax
  unsigned int v11; // ebx
  int v12; // edx
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ebx
  int v16; // edi
  int v17; // eax
  bool v19; // zf
  int v20; // esi
  unsigned int v21; // edi
  unsigned int v22; // eax
  int v23; // edx
  _DWORD *v24; // eax
  int v25; // edx
  int v26; // esi
  int v27; // ecx
  int v28; // [esp+8h] [ebp-20h]
  unsigned int v29; // [esp+10h] [ebp-18h]
  int v30; // [esp+14h] [ebp-14h]
  int v32; // [esp+1Ch] [ebp-Ch]
  int v33; // [esp+20h] [ebp-8h]
  int v34; // [esp+24h] [ebp-4h]
  unsigned int *v35; // [esp+30h] [ebp+8h]
  unsigned int *v36; // [esp+3Ch] [ebp+14h]

  v10 = a3;
  v11 = a4;
  v12 = a4 * a3;
  v28 = a4 * a3;
  if ( a4 * a3 )
  {
    if ( a2 != 2 || (a5 & 0x400) != 0 )
    {
      v32 = 0;
    }
    else
    {
      a3 = a4;
      v32 = 1;
      a4 = v10;
      v11 = v10;
    }
    v13 = this[2];
    v14 = a7;
    v15 = (v11 + 3) >> 2;
    v16 = a3 * v15;
    if ( a7 >= *(_DWORD *)(v13 + 4) )
      v17 = 0;
    else
      v17 = *(_DWORD *)(*(_DWORD *)(v13 + 16) + 4 * a7);
    if ( !v17 )
      return -2147467259;
    v19 = (*(_BYTE *)(v17 + 4) & 0x40) == 0;
    v30 = *(_DWORD *)(v17 + 16);
    v20 = v30;
    *(_DWORD *)(v17 + 16) = v30 + v16;
    if ( !v19 )
      *(_DWORD *)(v17 + 8) = v30 + v16;
    if ( a3 )
    {
      v33 = 0;
      v34 = 0;
      v36 = a6;
      v29 = a3;
      do
      {
        v21 = 0;
        if ( a4 )
        {
          v35 = v36;
          do
          {
            if ( v32 )
              v22 = *v35;
            else
              v22 = a6[v21 + v34];
            v23 = this[2];
            if ( v22 >= *(_DWORD *)(v23 + 8) )
              v24 = 0;
            else
              v24 = *(_DWORD **)(*(_DWORD *)(v23 + 20) + 4 * v22);
            if ( v24 )
            {
              v24[1] = v14;
              v25 = v33 + (v21 >> 2) + v20;
              v24[26] = a9;
              v26 = v21 & 3;
              v24[3] = v25;
              v24[4] = v26;
              v27 = v26 + *a8 + 4 * (v25 - v30);
              v20 = v30;
              v24[28] = v27;
              v14 = a7;
            }
            v35 += a3;
            ++v21;
          }
          while ( v21 < a4 );
        }
        ++v36;
        v34 += a4;
        v33 += v15;
        --v29;
      }
      while ( v29 );
      v16 = a3 * v15;
    }
    v12 = v28;
    *a8 += 4 * v16;
  }
  if ( a10 )
    *a10 = v12;
  return 0;
}
