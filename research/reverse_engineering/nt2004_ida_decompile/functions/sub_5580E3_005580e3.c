char __cdecl sub_5580E3(_DWORD *a1, int *a2)
{
  bool v3; // zf
  _DWORD *v4; // esi
  char result; // al
  int v6; // eax
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // ecx
  int v15; // edx
  int v16; // ebx
  unsigned __int8 *v17; // [esp+8h] [ebp-48h] BYREF
  int v18; // [esp+Ch] [ebp-44h]
  int v19; // [esp+10h] [ebp-40h]
  int v20; // [esp+14h] [ebp-3Ch]
  int v21; // [esp+20h] [ebp-30h]
  _DWORD *v22; // [esp+24h] [ebp-2Ch]
  _DWORD *v23; // [esp+28h] [ebp-28h]
  int v24; // [esp+30h] [ebp-20h]
  int v25; // [esp+34h] [ebp-1Ch]
  int v26; // [esp+38h] [ebp-18h]
  int v27; // [esp+3Ch] [ebp-14h]
  int v28; // [esp+40h] [ebp-10h]
  int v29; // [esp+44h] [ebp-Ch]
  int v30; // [esp+48h] [ebp-8h]
  int v31; // [esp+4Ch] [ebp-4h]
  int v32; // [esp+58h] [ebp+8h]
  int v33; // [esp+58h] [ebp+8h]
  int v34; // [esp+58h] [ebp+8h]

  v3 = a1[63] == 0;
  v4 = (_DWORD *)a1[101];
  v26 = a1[91];
  v25 = a1[93];
  if ( !v3 && !v4[13] )
  {
    result = sub_557E8B(a1);
    if ( !result )
      return result;
  }
  v30 = v4[8];
  if ( v30 )
  {
    v6 = v30 - 1;
    goto LABEL_37;
  }
  v7 = a1[5];
  v22 = a1;
  v17 = *(unsigned __int8 **)v7;
  v18 = *(_DWORD *)(v7 + 4);
  v19 = a1[94];
  v8 = v4[4];
  v9 = v4[5];
  v23 = v4 + 6;
  v24 = *a2;
  v27 = v4[18];
  v10 = a1[90];
  v29 = v8;
  v31 = v10;
  while ( v10 <= v26 )
  {
    if ( v9 >= 8 )
      goto LABEL_11;
    if ( !sub_557723(&v17, v8, v9, 0) )
      return 0;
    v9 = v21;
    v8 = v20;
    v29 = v20;
    if ( v21 >= 8 )
    {
LABEL_11:
      v12 = (unsigned __int8)(v8 >> (v9 - 8));
      v13 = *(_DWORD *)(v27 + 4 * v12 + 212);
      if ( v13 )
      {
        v9 -= v13;
        v32 = *(unsigned __int8 *)(v12 + v27 + 1236);
        goto LABEL_16;
      }
      v11 = 9;
    }
    else
    {
      v11 = 1;
    }
    v32 = sub_55780D((int)&v17, v8, v9, v27, v11);
    if ( v32 < 0 )
      return 0;
    v8 = v20;
    v9 = v21;
    v29 = v20;
LABEL_16:
    v14 = v32 >> 4;
    v3 = (v32 & 0xF) == 0;
    v33 = v32 & 0xF;
    v28 = v14;
    if ( v3 )
    {
      if ( v14 != 15 )
      {
        v34 = 1 << v14;
        v30 = 1 << v14;
        if ( v28 )
        {
          if ( v9 < v28 )
          {
            if ( !sub_557723(&v17, v8, v9, v28) )
              return 0;
            v8 = v20;
            v9 = v21;
          }
          v9 -= v28;
          v30 += (v34 - 1) & (v8 >> v9);
        }
        --v30;
        break;
      }
      v31 += 15;
    }
    else
    {
      v31 += v14;
      if ( v9 < v33 )
      {
        if ( !sub_557723(&v17, v8, v9, v33) )
          return 0;
        v8 = v20;
        v9 = v21;
        v29 = v20;
      }
      v9 -= v33;
      v15 = (v8 >> v9) & ((1 << v33) - 1);
      if ( v15 >= dword_5F5A28[v33] )
        v16 = (v8 >> v9) & ((1 << v33) - 1);
      else
        v16 = v15 + dword_5F5A68[v33];
      *(_WORD *)(v24 + 2 * dword_5F4D18[v31]) = v16 << v25;
      v8 = v29;
    }
    v10 = ++v31;
  }
  *(_DWORD *)a1[5] = v17;
  *(_DWORD *)(a1[5] + 4) = v18;
  a1[94] = v19;
  v4[5] = v9;
  v6 = v30;
  v4[4] = v8;
LABEL_37:
  --v4[13];
  v4[8] = v6;
  return 1;
}
