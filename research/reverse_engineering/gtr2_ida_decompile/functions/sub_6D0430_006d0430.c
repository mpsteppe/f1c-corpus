int __stdcall sub_6D0430(_DWORD *a1, int *a2)
{
  _DWORD *v2; // edx
  int v3; // ecx
  __int16 *v4; // ebx
  int result; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // ecx
  int v15; // ebx
  int v16; // eax
  int v17; // eax
  __int16 *v18; // ebx
  __int16 v19; // ax
  __int16 v20; // ax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // eax
  bool v25; // zf
  __int16 v26; // cx
  _DWORD *v27; // edx
  int v28; // edx
  int i; // eax
  int v30; // edx
  _DWORD v31[65]; // [esp+0h] [ebp-140h]
  int v32; // [esp+104h] [ebp-3Ch]
  int v33; // [esp+108h] [ebp-38h]
  int v34; // [esp+10Ch] [ebp-34h]
  int v35; // [esp+110h] [ebp-30h]
  unsigned __int8 *v36; // [esp+114h] [ebp-2Ch] BYREF
  int v37; // [esp+118h] [ebp-28h]
  int v38; // [esp+11Ch] [ebp-24h]
  int v39; // [esp+120h] [ebp-20h]
  _DWORD *v40; // [esp+124h] [ebp-1Ch]
  int v41; // [esp+128h] [ebp-18h]
  int v42; // [esp+12Ch] [ebp-14h]
  int v43; // [esp+130h] [ebp-10h]
  int v44; // [esp+134h] [ebp-Ch]
  int v45; // [esp+138h] [ebp-8h]
  __int16 *v46; // [esp+13Ch] [ebp-4h]
  int v47; // [esp+14Ch] [ebp+Ch]

  v2 = a1;
  v3 = a1[104];
  v43 = a1[102];
  v4 = (__int16 *)a1[112];
  v46 = v4;
  v35 = 1 << v3;
  v34 = -1 << v3;
  if ( a1[70] && !*((_DWORD *)v4 + 10) )
  {
    result = sub_6CFE70();
    if ( !result )
      return result;
    v4 = v46;
    v2 = a1;
  }
  if ( *((_DWORD *)v4 + 2) )
    goto LABEL_63;
  v6 = v2[6];
  v40 = v2;
  v36 = *(unsigned __int8 **)v6;
  v37 = *(_DWORD *)(v6 + 4);
  v7 = *((_DWORD *)v4 + 5);
  v8 = *((_DWORD *)v4 + 3);
  v9 = *((_DWORD *)v4 + 4);
  v42 = *a2;
  v32 = *((_DWORD *)v4 + 15);
  v10 = v2[101];
  v45 = v7;
  v33 = 0;
  v47 = v10;
  if ( v7 )
  {
LABEL_49:
    if ( v45 )
    {
      if ( v10 <= v43 )
      {
        do
        {
          v24 = dword_744A70[v10];
          v25 = *(_WORD *)(v42 + 2 * v24) == 0;
          v46 = (__int16 *)(v42 + 2 * v24);
          if ( !v25 )
          {
            if ( v9 < 1 )
            {
              if ( !sub_6CF670(&v36, v8, v9, 1) )
                goto LABEL_64;
              v8 = v38;
              v9 = v39;
              v2 = a1;
            }
            if ( ((v8 >> --v9) & 1) != 0 )
            {
              v26 = v35;
              if ( (*v46 & v35) == 0 )
              {
                if ( *v46 < 0 )
                  v26 = v34;
                *v46 += v26;
              }
            }
          }
          v10 = ++v47;
        }
        while ( v47 <= v43 );
      }
      --v45;
    }
    goto LABEL_62;
  }
  if ( v10 > v43 )
  {
LABEL_62:
    v27 = (_DWORD *)v2[6];
    *v27 = v36;
    v27[1] = v37;
    v28 = v45;
    *((_DWORD *)v4 + 3) = v8;
    *((_DWORD *)v4 + 4) = v9;
    *((_DWORD *)v4 + 5) = v28;
LABEL_63:
    --*((_DWORD *)v4 + 10);
    return 1;
  }
  while ( 1 )
  {
    if ( v9 >= 8 )
      goto LABEL_12;
    if ( !sub_6CF670(&v36, v8, v9, 0) )
      goto LABEL_64;
    v9 = v39;
    v8 = v38;
    if ( v39 >= 8 )
    {
LABEL_12:
      v11 = v32;
      v13 = (unsigned __int8)(v8 >> (v9 - 8));
      v14 = *(_DWORD *)(v32 + 4 * v13 + 144);
      if ( v14 )
      {
        v9 -= v14;
        v44 = *(unsigned __int8 *)(v13 + v32 + 1168);
        goto LABEL_17;
      }
      v12 = 9;
    }
    else
    {
      v11 = v32;
      v12 = 1;
    }
    v44 = sub_6CF790((int)&v36, v8, v9, v11, v12);
    if ( v44 < 0 )
      goto LABEL_64;
    v8 = v38;
    v9 = v39;
LABEL_17:
    v15 = v44 >> 4;
    v16 = v44 & 0xF;
    v41 = v44 >> 4;
    v44 = v16;
    if ( !v16 )
      break;
    if ( v16 != 1 )
    {
      v17 = *a1;
      *(_DWORD *)(v17 + 20) = 118;
      (*(void (__stdcall **)(_DWORD *, int))(v17 + 4))(a1, -1);
    }
    if ( v9 < 1 )
    {
      if ( !sub_6CF670(&v36, v8, v9, 1) )
        goto LABEL_64;
      v8 = v38;
      v9 = v39;
    }
    if ( ((v8 >> --v9) & 1) != 0 )
      v44 = v35;
    else
      v44 = v34;
    do
    {
LABEL_27:
      v18 = (__int16 *)(v42 + 2 * dword_744A70[v47]);
      if ( *v18 )
      {
        if ( v9 < 1 )
        {
          if ( !sub_6CF670(&v36, v8, v9, 1) )
            goto LABEL_64;
          v8 = v38;
          v9 = v39;
        }
        if ( ((v8 >> --v9) & 1) != 0 )
        {
          v19 = *v18;
          if ( (*v18 & v35) == 0 )
          {
            if ( v19 < 0 )
              v20 = v34 + v19;
            else
              v20 = v35 + v19;
            *v18 = v20;
          }
        }
      }
      else if ( --v41 < 0 )
      {
        break;
      }
      ++v47;
    }
    while ( v47 <= v43 );
    if ( v44 )
    {
      v21 = dword_744A70[v47];
      *(_WORD *)(v42 + 2 * v21) = v44;
      v22 = v33;
      v31[v33 + 1] = v21;
      v33 = v22 + 1;
    }
    if ( ++v47 > v43 )
    {
      v4 = v46;
      v2 = a1;
      goto LABEL_62;
    }
  }
  if ( v15 == 15 )
    goto LABEL_27;
  v23 = 1 << v15;
  v41 = 1 << v15;
  v45 = 1 << v15;
  if ( !v15 )
    goto LABEL_48;
  if ( v9 >= v15 )
    goto LABEL_47;
  if ( sub_6CF670(&v36, v8, v9, v15) )
  {
    v8 = v38;
    v9 = v39;
    v23 = v41;
LABEL_47:
    v9 -= v15;
    v45 += (v23 - 1) & (v8 >> v9);
LABEL_48:
    v4 = v46;
    v2 = a1;
    v10 = v47;
    goto LABEL_49;
  }
LABEL_64:
  for ( i = v33; i > 0; *(_WORD *)(v42 + 2 * v30) = 0 )
    v30 = v31[i--];
  return 0;
}
