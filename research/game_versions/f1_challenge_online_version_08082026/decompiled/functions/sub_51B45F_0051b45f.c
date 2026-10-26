char __cdecl sub_51B45F(_DWORD *a1, int *a2)
{
  int v3; // ecx
  _DWORD *v4; // esi
  bool v5; // zf
  char result; // al
  int v7; // eax
  int v8; // ebx
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  __int16 *v17; // eax
  __int16 v18; // dx
  int v19; // eax
  int v20; // ecx
  int v21; // eax
  int i; // eax
  __int16 *v23; // eax
  __int16 v24; // dx
  int j; // eax
  int v26; // ecx
  _DWORD v27[65]; // [esp+4h] [ebp-158h]
  unsigned __int8 *v28; // [esp+108h] [ebp-54h] BYREF
  int v29; // [esp+10Ch] [ebp-50h]
  int v30; // [esp+110h] [ebp-4Ch]
  int v31; // [esp+114h] [ebp-48h]
  int v32; // [esp+120h] [ebp-3Ch]
  _DWORD *v33; // [esp+124h] [ebp-38h]
  _DWORD *v34; // [esp+128h] [ebp-34h]
  int v35; // [esp+130h] [ebp-2Ch]
  int v36; // [esp+134h] [ebp-28h]
  __int16 *v37; // [esp+138h] [ebp-24h]
  int v38; // [esp+13Ch] [ebp-20h]
  int v39; // [esp+140h] [ebp-1Ch]
  int v40; // [esp+144h] [ebp-18h]
  int v41; // [esp+148h] [ebp-14h]
  int v42; // [esp+14Ch] [ebp-10h]
  int v43; // [esp+150h] [ebp-Ch]
  int v44; // [esp+154h] [ebp-8h]
  int v45; // [esp+158h] [ebp-4h]
  int v46; // [esp+164h] [ebp+8h]

  v3 = a1[93];
  v4 = (_DWORD *)a1[101];
  v42 = a1[91];
  v36 = 1 << v3;
  v5 = a1[63] == 0;
  v35 = -1 << v3;
  if ( !v5 && !v4[13] )
  {
    result = sub_51AEFC(a1);
    if ( !result )
      return result;
  }
  v7 = a1[5];
  v40 = 0;
  v33 = a1;
  v28 = *(unsigned __int8 **)v7;
  v29 = *(_DWORD *)(v7 + 4);
  v30 = a1[94];
  v46 = v4[4];
  v8 = v4[5];
  v34 = v4 + 6;
  v9 = v4[8];
  v41 = *a2;
  v39 = v4[18];
  v10 = a1[90];
  v43 = v9;
  v45 = v10;
  if ( v9 )
  {
LABEL_47:
    if ( v43 )
    {
      for ( i = v45; i <= v42; i = ++v45 )
      {
        v23 = (__int16 *)(v41 + 2 * dword_5AF778[i]);
        v5 = *v23 == 0;
        v37 = v23;
        if ( !v5 )
        {
          if ( v8 < 1 )
          {
            if ( !sub_51A794(&v28, v46, v8, 1) )
              goto LABEL_63;
            v8 = v32;
            v46 = v31;
            v23 = v37;
          }
          if ( ((v46 >> --v8) & 1) != 0 )
          {
            v24 = v36;
            if ( (*v23 & v36) == 0 )
            {
              if ( *v23 < 0 )
                v24 = v35;
              *v23 += v24;
            }
          }
        }
      }
      --v43;
    }
LABEL_61:
    *(_DWORD *)a1[5] = v28;
    *(_DWORD *)(a1[5] + 4) = v29;
    a1[94] = v30;
    --v4[13];
    v4[4] = v46;
    v4[8] = v43;
    v4[5] = v8;
    return 1;
  }
  while ( 1 )
  {
    if ( v10 > v42 )
      goto LABEL_61;
    if ( v8 >= 8 )
      goto LABEL_10;
    if ( !sub_51A794(&v28, v46, v8, 0) )
      goto LABEL_63;
    v8 = v32;
    v46 = v31;
    if ( v32 >= 8 )
    {
LABEL_10:
      v12 = (unsigned __int8)(v46 >> (v8 - 8));
      v13 = *(_DWORD *)(v39 + 4 * v12 + 212);
      if ( v13 )
      {
        v8 -= v13;
        v44 = *(unsigned __int8 *)(v12 + v39 + 1236);
        goto LABEL_15;
      }
      v11 = 9;
    }
    else
    {
      v11 = 1;
    }
    v44 = sub_51A87E((int)&v28, v46, v8, v39, v11);
    if ( v44 < 0 )
      goto LABEL_63;
    v8 = v32;
    v46 = v31;
LABEL_15:
    v14 = v44 >> 4;
    v5 = (v44 & 0xF) == 0;
    v44 &= 0xFu;
    v38 = v14;
    if ( v5 )
      break;
    if ( v44 != 1 )
    {
      *(_DWORD *)(*a1 + 20) = 114;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
    }
    if ( v8 < 1 )
    {
      if ( !sub_51A794(&v28, v46, v8, 1) )
        goto LABEL_63;
      v8 = v32;
      v46 = v31;
    }
    --v8;
    v15 = v36;
    if ( ((v46 >> v8) & 1) == 0 )
      v15 = v35;
    v44 = v15;
LABEL_25:
    v16 = v45;
    do
    {
      v17 = (__int16 *)(v41 + 2 * dword_5AF778[v16]);
      v5 = *v17 == 0;
      v37 = v17;
      if ( v5 )
      {
        if ( --v38 < 0 )
          break;
      }
      else
      {
        if ( v8 < 1 )
        {
          if ( !sub_51A794(&v28, v46, v8, 1) )
            goto LABEL_63;
          v8 = v32;
          v46 = v31;
          v17 = v37;
        }
        if ( ((v46 >> --v8) & 1) != 0 )
        {
          v18 = v36;
          if ( (*v17 & v36) == 0 )
          {
            if ( *v17 < 0 )
              v18 = v35;
            *v17 += v18;
          }
        }
      }
      v16 = ++v45;
    }
    while ( v45 <= v42 );
    if ( v44 )
    {
      v19 = dword_5AF778[v16];
      *(_WORD *)(v41 + 2 * v19) = v44;
      v20 = v40++;
      v27[v20 + 1] = v19;
    }
    v10 = ++v45;
  }
  if ( v14 == 15 )
    goto LABEL_25;
  v21 = 1 << v14;
  v39 = 1 << v14;
  v43 = 1 << v14;
  if ( !v14 )
    goto LABEL_47;
  if ( v8 >= v14 )
    goto LABEL_46;
  if ( sub_51A794(&v28, v46, v8, v14) )
  {
    v8 = v32;
    v46 = v31;
    v21 = v39;
LABEL_46:
    v8 -= v38;
    v43 += (v21 - 1) & (v46 >> v8);
    goto LABEL_47;
  }
LABEL_63:
  for ( j = v40; j > 0; --j )
  {
    v26 = v27[j];
    *(_WORD *)(v41 + 2 * v26) = 0;
  }
  return 0;
}
