int __stdcall sub_6D0110(_DWORD *a1, int *a2)
{
  _DWORD *v2; // edi
  _DWORD *v3; // esi
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // esi
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // esi
  int v16; // edi
  int v17; // esi
  int v18; // edx
  int v19; // esi
  int v20; // esi
  _DWORD *v22; // edi
  unsigned __int8 *v23; // [esp+Ch] [ebp-2Ch] BYREF
  int v24; // [esp+10h] [ebp-28h]
  int v25; // [esp+14h] [ebp-24h]
  int v26; // [esp+18h] [ebp-20h]
  _DWORD *v27; // [esp+1Ch] [ebp-1Ch]
  int v28; // [esp+20h] [ebp-18h]
  int v29; // [esp+24h] [ebp-14h]
  _DWORD *v30; // [esp+28h] [ebp-10h]
  int v31; // [esp+2Ch] [ebp-Ch]
  int v32; // [esp+30h] [ebp-8h]
  int v33; // [esp+34h] [ebp-4h]
  int v34; // [esp+44h] [ebp+Ch]
  int v35; // [esp+44h] [ebp+Ch]

  v2 = a1;
  v3 = (_DWORD *)a1[112];
  v4 = a1[104];
  v31 = a1[102];
  v5 = a1[70];
  v30 = v3;
  v29 = v4;
  if ( v5 && !v3[10] && !sub_6CFE70() )
    return 0;
  if ( v3[2] )
    goto LABEL_39;
  v33 = v3[5];
  v6 = v33;
  if ( v33 )
  {
    v6 = v33 - 1;
    goto LABEL_38;
  }
  v7 = a1[6];
  v27 = a1;
  v23 = *(unsigned __int8 **)v7;
  v8 = *a2;
  v24 = *(_DWORD *)(v7 + 4);
  v9 = v3[3];
  v10 = v3[4];
  v28 = v8;
  v32 = v3[15];
  v34 = a1[101];
  if ( v34 > v31 )
    goto LABEL_37;
  while ( 1 )
  {
    if ( v10 >= 8 )
      goto LABEL_12;
    if ( !sub_6CF670(&v23, v9, v10, 0) )
      return 0;
    v10 = v26;
    v9 = v25;
    if ( v26 >= 8 )
    {
LABEL_12:
      v11 = v32;
      v13 = (unsigned __int8)(v9 >> (v10 - 8));
      v14 = *(_DWORD *)(v32 + 4 * v13 + 144);
      if ( v14 )
      {
        v15 = *(unsigned __int8 *)(v13 + v32 + 1168);
        v10 -= v14;
        goto LABEL_17;
      }
      v12 = 9;
    }
    else
    {
      v11 = v32;
      v12 = 1;
    }
    v15 = sub_6CF790((int)&v23, v9, v10, v11, v12);
    if ( v15 < 0 )
      return 0;
    v9 = v25;
    v10 = v26;
LABEL_17:
    v16 = v15 >> 4;
    v17 = v15 & 0xF;
    if ( v17 )
    {
      v35 = v16 + v34;
      if ( v10 < v17 )
      {
        if ( !sub_6CF670(&v23, v9, v10, v17) )
          return 0;
        v9 = v25;
        v10 = v26;
      }
      v10 -= v17;
      v18 = (v9 >> v10) & ((1 << v17) - 1);
      if ( v18 >= dword_747D68[v17] )
        v19 = (v9 >> v10) & ((1 << v17) - 1);
      else
        v19 = v18 + dword_747DA8[v17];
      *(_WORD *)(v28 + 2 * dword_744A70[v35]) = v19 << v29;
      goto LABEL_27;
    }
    if ( v16 != 15 )
      break;
    v35 = v34 + 15;
LABEL_27:
    v34 = v35 + 1;
    if ( v34 > v31 )
      goto LABEL_36;
  }
  v20 = 1 << v16;
  if ( v16 )
  {
    if ( v10 < v16 )
    {
      if ( !sub_6CF670(&v23, v9, v10, v16) )
        return 0;
      v9 = v25;
      v10 = v26;
    }
    v10 -= v16;
    v20 += (v20 - 1) & (v9 >> v10);
  }
  v33 = v20 - 1;
LABEL_36:
  v2 = a1;
  v3 = v30;
  v6 = v33;
LABEL_37:
  v22 = (_DWORD *)v2[6];
  *v22 = v23;
  v22[1] = v24;
  v3[3] = v9;
  v3[4] = v10;
LABEL_38:
  v3[5] = v6;
LABEL_39:
  --v3[10];
  return 1;
}
