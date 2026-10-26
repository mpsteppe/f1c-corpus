int __thiscall sub_684AF5(_DWORD *this, int a2)
{
  int v2; // esi
  int v3; // eax
  int v4; // edx
  unsigned int v5; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int *v11; // edx
  int v12; // ebx
  bool v13; // zf
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // edx
  int v17; // esi
  int v18; // eax
  int v19; // edx
  int *v20; // esi
  int v21; // ebx
  int v22; // edi
  int v23; // eax
  int v24; // ebx
  _DWORD *v25; // eax
  int v26; // edx
  int v27; // [esp+8h] [ebp-10h]
  int v28; // [esp+8h] [ebp-10h]
  unsigned int v29; // [esp+Ch] [ebp-Ch]
  int v30; // [esp+Ch] [ebp-Ch]
  int v31; // [esp+10h] [ebp-8h]
  int v32; // [esp+14h] [ebp-4h]
  int v33; // [esp+14h] [ebp-4h]
  int v34; // [esp+14h] [ebp-4h]
  unsigned int v35; // [esp+14h] [ebp-4h]
  unsigned int v36; // [esp+20h] [ebp+8h]

  v2 = 4 * a2;
  v3 = 4 * a2 + this[6];
  v4 = *(_DWORD *)v3;
  v5 = *(_DWORD *)(*(_DWORD *)v3 + 44);
  v31 = 4 * a2;
  v27 = *(_DWORD *)v3;
  if ( (v5 & 1) == 0 )
    return 0;
  v7 = a2;
  if ( a2 )
  {
    v8 = v3 - 4;
    v32 = v8;
    do
    {
      if ( v5 >= *(_DWORD *)(*(_DWORD *)v8 + 44) )
        break;
      --v7;
      v8 = v32 - 4;
      v32 -= 4;
    }
    while ( v7 );
  }
  if ( (unsigned int)(a2 - v7) >> 1 )
  {
    v9 = 4 * v7;
    v33 = 4 * v7;
    v29 = (unsigned int)(a2 - v7) >> 1;
    do
    {
      v10 = this[6];
      v11 = (int *)(v10 + v9);
      v12 = *v11;
      *v11 = *(_DWORD *)(v2 + v10 - 4);
      *(_DWORD *)(v2 + this[6] - 4) = v12;
      v9 = v33 + 4;
      v2 -= 4;
      v13 = v29-- == 1;
      v33 += 4;
    }
    while ( !v13 );
    v4 = v27;
    v2 = 4 * a2;
  }
  v14 = v7;
  v28 = v7;
  if ( !v7 )
    goto LABEL_17;
  v15 = *(_DWORD *)(v4 + 44);
  if ( v15 <= *(_DWORD *)(*(_DWORD *)(this[6] + 4 * v7 - 4) + 44) )
  {
    v34 = this[6] + 4 * v7 - 4;
    do
    {
      if ( v15 != *(_DWORD *)(*(_DWORD *)v34 + 44) )
        break;
      v34 -= 4;
      v28 = --v14;
    }
    while ( v14 );
LABEL_17:
    v16 = (unsigned int)(v7 - v14) >> 1;
    if ( v16 )
    {
      v17 = 4 * v14;
      v30 = 4 * v14;
      v18 = 4 * v7;
      v35 = v16;
      do
      {
        v19 = this[6];
        v20 = (int *)(v19 + v17);
        v21 = *v20;
        *v20 = *(_DWORD *)(v18 + v19 - 4);
        *(_DWORD *)(v18 + this[6] - 4) = v21;
        v17 = v30 + 4;
        v18 -= 4;
        v13 = v35-- == 1;
        v30 += 4;
      }
      while ( !v13 );
      v14 = v28;
      v2 = 4 * a2;
    }
    goto LABEL_21;
  }
  v14 = v7 - 1;
LABEL_21:
  if ( v14 == v7 )
    return 0;
  if ( (unsigned int)(a2 - v14) >> 1 )
  {
    v22 = 4 * v14;
    v36 = (unsigned int)(a2 - v14) >> 1;
    do
    {
      v23 = this[6];
      v24 = *(_DWORD *)(v22 + v23);
      *(_DWORD *)(v22 + v23) = *(_DWORD *)(v2 + v23 - 4);
      *(_DWORD *)(v2 + this[6] - 4) = v24;
      v22 += 4;
      v2 -= 4;
      --v36;
    }
    while ( v36 );
    v2 = v31;
  }
  v25 = (_DWORD *)(v2 + this[6]);
  v26 = *(v25 - 1);
  *(v25 - 1) = *v25;
  *(_DWORD *)(v2 + this[6]) = v26;
  return 1;
}
