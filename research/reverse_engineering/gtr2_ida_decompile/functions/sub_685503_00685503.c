int __thiscall sub_685503(_DWORD *this, int a2, double *a3, double *a4)
{
  int v4; // edx
  int v5; // esi
  int result; // eax
  _DWORD *v7; // esi
  unsigned int v8; // edx
  unsigned int v9; // ecx
  unsigned int v10; // edx
  _DWORD *v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // ebx
  _DWORD *v14; // eax
  int v15; // edx
  int v16; // edi
  int *v17; // eax
  int v18; // ecx
  _DWORD *v19; // edi
  int v20; // edx
  double *v21; // eax
  double v22; // st7
  int v23; // [esp+10h] [ebp-1Ch]
  int v24; // [esp+14h] [ebp-18h]
  int v25; // [esp+1Ch] [ebp-10h]
  int v26; // [esp+20h] [ebp-Ch]
  unsigned int v27; // [esp+24h] [ebp-8h]
  _DWORD *v28; // [esp+28h] [ebp-4h]
  unsigned int v29; // [esp+34h] [ebp+8h]

  v4 = *(_DWORD *)(this[5] + 4 * a2);
  v5 = *(_DWORD *)(v4 + 72);
  v26 = this[5];
  result = -1;
  if ( v5 != -1 && *(_DWORD *)(v4 + 8) == -1 )
  {
    v7 = *(_DWORD **)(this[6] + 4 * v5);
    v8 = *v7 & 0xFFF00000;
    v27 = v8;
    if ( v8 == 269484032 )
    {
      v9 = v7[3];
      v10 = 0;
      if ( v9 )
      {
        v11 = (_DWORD *)v7[4];
        do
        {
          if ( *v11 == a2 )
            break;
          ++v10;
          ++v11;
        }
        while ( v10 < v9 );
      }
      if ( a3 )
        *a3 = -*a3;
      return *(_DWORD *)(v7[2] + 4 * v10);
    }
    else if ( v8 == 542113792 || v8 == 541065216 )
    {
      v12 = v7[3];
      v13 = 0;
      if ( v12 )
      {
        v14 = (_DWORD *)v7[4];
        do
        {
          if ( *v14 == a2 )
            break;
          ++v13;
          ++v14;
        }
        while ( v13 < v12 );
      }
      v15 = v7[3];
      v16 = v7[2];
      v29 = 0;
      v25 = this[4];
      v24 = 4 * v15;
      v17 = (int *)(v16 + 4 * v13);
      v18 = -1 * v15;
      v19 = (_DWORD *)(v16 + 4 * (v13 + v15));
      v28 = v19;
      while ( 1 )
      {
        v23 = *v17;
        v20 = *(_DWORD *)(v26 + 4 * *v19);
        if ( (*(_BYTE *)(*(_DWORD *)(v25 + 4 * *(_DWORD *)(v20 + 4)) + 5) & 1) != 0 && *(_DWORD *)(v20 + 8) == -1 )
          break;
        ++v29;
        v17 = (int *)((char *)v17 + v24);
        v19 = &v28[v18];
        v28 = (_DWORD *)((char *)v28 + v18 * 4);
        if ( v29 >= 2 )
        {
          if ( v27 != 541065216 || *(_DWORD *)(v7[2] + 4 * v13) != *(_DWORD *)(v7[2] + 4 * (v7[3] + v13)) )
            return -1;
          if ( a3 )
            *a3 = *a3 + *a3;
          return *(_DWORD *)(4 * v13 + v7[2]);
        }
      }
      v21 = a3;
      if ( a3 )
      {
        v22 = *(double *)(v20 + 32) * *a3;
        if ( v27 != 542113792 )
        {
          v21 = a4;
          v22 = v22 + *a4;
        }
        *v21 = v22;
      }
      return v23;
    }
  }
  return result;
}
