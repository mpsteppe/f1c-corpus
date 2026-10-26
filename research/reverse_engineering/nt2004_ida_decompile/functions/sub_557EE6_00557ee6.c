char __cdecl sub_557EE6(_DWORD *a1, int a2)
{
  bool v3; // zf
  _DWORD *v4; // eax
  int v5; // ecx
  char result; // al
  int v7; // ecx
  bool v8; // cc
  int v9; // edx
  int v10; // edi
  int v11; // eax
  int v12; // esi
  int v13; // ecx
  int v14; // esi
  int v15; // esi
  int v16; // ecx
  _DWORD *v17; // ecx
  int v18; // esi
  unsigned __int8 *v19; // [esp+8h] [ebp-58h] BYREF
  int v20; // [esp+Ch] [ebp-54h]
  int v21; // [esp+10h] [ebp-50h]
  int v22; // [esp+14h] [ebp-4Ch]
  int v23; // [esp+20h] [ebp-40h]
  _DWORD *v24; // [esp+24h] [ebp-3Ch]
  _DWORD *v25; // [esp+28h] [ebp-38h]
  _DWORD v26[5]; // [esp+30h] [ebp-30h] BYREF
  _WORD *v27; // [esp+44h] [ebp-1Ch]
  int v28; // [esp+48h] [ebp-18h]
  int v29; // [esp+4Ch] [ebp-14h]
  int *v30; // [esp+50h] [ebp-10h]
  int v31; // [esp+54h] [ebp-Ch]
  _DWORD *v32; // [esp+58h] [ebp-8h]
  int v33; // [esp+5Ch] [ebp-4h]
  int v34; // [esp+68h] [ebp+8h]

  v3 = a1[63] == 0;
  v4 = (_DWORD *)a1[101];
  v5 = a1[93];
  v32 = v4;
  v28 = v5;
  if ( !v3 && !v4[13] )
  {
    result = sub_557E8B(a1);
    if ( !result )
      return result;
    v4 = v32;
  }
  v7 = a1[5];
  v31 = 0;
  v8 = a1[79] <= 0;
  v24 = a1;
  v19 = *(unsigned __int8 **)v7;
  v20 = *(_DWORD *)(v7 + 4);
  v21 = a1[94];
  v9 = v4[5];
  v34 = v4[4];
  v25 = v4 + 6;
  qmemcpy(v26, v4 + 8, sizeof(v26));
  if ( !v8 )
  {
    v30 = a1 + 80;
    do
    {
      v27 = *(_WORD **)(a2 + 4 * v31);
      v29 = *v30;
      v10 = v4[*(_DWORD *)(a1[v29 + 73] + 20) + 14];
      if ( v9 < 8 )
      {
        if ( !sub_557723(&v19, v34, v9, 0) )
          return 0;
        v9 = v23;
        v34 = v22;
        if ( v23 < 8 )
        {
          v11 = 1;
          goto LABEL_15;
        }
        v4 = v32;
      }
      v12 = (unsigned __int8)(v34 >> (v9 - 8));
      v13 = *(_DWORD *)(v10 + 4 * v12 + 212);
      if ( v13 )
      {
        v14 = *(unsigned __int8 *)(v12 + v10 + 1236);
        v9 -= v13;
        goto LABEL_17;
      }
      v11 = 9;
LABEL_15:
      v14 = sub_55780D((int)&v19, v34, v9, v10, v11);
      if ( v14 < 0 )
        return 0;
      v9 = v23;
      v34 = v22;
      v4 = v32;
LABEL_17:
      if ( v14 )
      {
        if ( v9 < v14 )
        {
          if ( !sub_557723(&v19, v34, v9, v14) )
            return 0;
          v9 = v23;
          v34 = v22;
          v4 = v32;
        }
        v9 -= v14;
        v33 = (1 << v14) - 1;
        v15 = v14;
        v16 = (v34 >> v9) & v33;
        if ( v16 >= dword_5F5A28[v15] )
          v14 = (v34 >> v9) & v33;
        else
          v14 = v16 + dword_5F5A68[v15];
      }
      ++v30;
      v17 = &v26[v29 + 1];
      *v17 += v14;
      v18 = *v17 << v28;
      ++v31;
      *v27 = v18;
    }
    while ( v31 < a1[79] );
  }
  *(_DWORD *)a1[5] = v19;
  *(_DWORD *)(a1[5] + 4) = v20;
  a1[94] = v21;
  --v4[13];
  v4[4] = v34;
  v4[5] = v9;
  qmemcpy(v4 + 8, v26, 0x14u);
  return 1;
}
