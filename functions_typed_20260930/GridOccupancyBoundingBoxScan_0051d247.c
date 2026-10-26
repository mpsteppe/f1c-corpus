int __usercall sub_51D247@<eax>(int a1@<eax>, int *a2@<esi>)
{
  int v2; // ecx
  int v3; // edi
  int v4; // eax
  int v6; // ecx
  int v7; // eax
  int v9; // ebx
  int v10; // ecx
  int v11; // edx
  _WORD *v12; // eax
  int v14; // ecx
  int v15; // edx
  _WORD *v16; // eax
  _WORD *v18; // eax
  int v19; // edx
  _WORD *v20; // eax
  int v21; // edx
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  int v25; // edi
  int result; // eax
  int v27; // [esp+8h] [ebp-28h]
  int v28; // [esp+Ch] [ebp-24h]
  int v29; // [esp+10h] [ebp-20h]
  _WORD *v30; // [esp+14h] [ebp-1Ch]
  _WORD *v31; // [esp+14h] [ebp-1Ch]
  int v32; // [esp+14h] [ebp-1Ch]
  int v33; // [esp+14h] [ebp-1Ch]
  _WORD *v34; // [esp+14h] [ebp-1Ch]
  int v35; // [esp+18h] [ebp-18h]
  int v36; // [esp+18h] [ebp-18h]
  int v37; // [esp+1Ch] [ebp-14h]
  int v38; // [esp+20h] [ebp-10h]
  int v39; // [esp+24h] [ebp-Ch]
  int v40; // [esp+28h] [ebp-8h]
  int v41; // [esp+28h] [ebp-8h]
  int v42; // [esp+28h] [ebp-8h]
  int v43; // [esp+28h] [ebp-8h]
  int v44; // [esp+28h] [ebp-8h]
  int v45; // [esp+2Ch] [ebp-4h]
  int v46; // [esp+2Ch] [ebp-4h]
  int v47; // [esp+2Ch] [ebp-4h]
  int v48; // [esp+2Ch] [ebp-4h]
  int v49; // [esp+2Ch] [ebp-4h]
  int v50; // [esp+2Ch] [ebp-4h]

  v2 = *a2;
  v29 = a2[3];
  v28 = *(_DWORD *)(*(_DWORD *)(a1 + 420) + 24);
  v3 = a2[2];
  v39 = a2[4];
  v35 = *a2;
  v38 = a2[1];
  v27 = v3;
  v37 = a2[5];
  if ( *a2 < v38 )
  {
    while ( 1 )
    {
      v40 = a2[2];
      if ( v3 <= v29 )
        break;
LABEL_8:
      if ( ++v2 > v38 )
        goto LABEL_11;
    }
    v4 = *(_DWORD *)(v28 + 4 * v2) + 2 * (v39 + 32 * v3);
    while ( 1 )
    {
      v45 = a2[4];
      v30 = (_WORD *)v4;
      if ( v39 <= v37 )
        break;
LABEL_7:
      ++v40;
      v4 += 64;
      if ( v40 > v29 )
        goto LABEL_8;
    }
    while ( !*v30++ )
    {
      if ( ++v45 > v37 )
        goto LABEL_7;
    }
    v35 = v2;
    *a2 = v2;
LABEL_11:
    v6 = v38;
    if ( v38 > v35 )
    {
      while ( 1 )
      {
        v41 = v3;
        if ( v3 <= v29 )
          break;
LABEL_18:
        if ( --v6 < v35 )
          goto LABEL_21;
      }
      v7 = *(_DWORD *)(v28 + 4 * v6) + 2 * (v39 + 32 * v3);
      while ( 1 )
      {
        v46 = v39;
        v31 = (_WORD *)v7;
        if ( v39 <= v37 )
          break;
LABEL_17:
        ++v41;
        v7 += 64;
        if ( v41 > v29 )
          goto LABEL_18;
      }
      while ( !*v31++ )
      {
        if ( ++v46 > v37 )
          goto LABEL_17;
      }
      v38 = v6;
      a2[1] = v6;
    }
  }
LABEL_21:
  v9 = v29;
  if ( v3 < v29 )
  {
    v42 = v3;
    v10 = 2 * (v39 + 32 * v3);
    while ( 1 )
    {
      v11 = v35;
      if ( v35 <= v38 )
        break;
LABEL_29:
      ++v42;
      v10 += 64;
      if ( v42 > v29 )
        goto LABEL_32;
    }
    while ( 1 )
    {
      v12 = (_WORD *)(v10 + *(_DWORD *)(v28 + 4 * v11));
      v47 = v39;
      if ( v39 <= v37 )
        break;
LABEL_27:
      if ( ++v11 > v38 )
      {
        v3 = v27;
        goto LABEL_29;
      }
    }
    while ( !*v12++ )
    {
      if ( ++v47 > v37 )
        goto LABEL_27;
    }
    v3 = v42;
    v27 = v42;
    a2[2] = v42;
LABEL_32:
    v9 = v29;
    if ( v29 > v3 )
    {
      v43 = v29;
      v14 = 2 * (v39 + 32 * v29);
      while ( 1 )
      {
        v15 = v35;
        if ( v35 <= v38 )
          break;
LABEL_40:
        --v43;
        v14 -= 64;
        if ( v43 < v3 )
        {
          v9 = v29;
          goto LABEL_43;
        }
      }
      while ( 1 )
      {
        v16 = (_WORD *)(v14 + *(_DWORD *)(v28 + 4 * v15));
        v48 = v39;
        if ( v39 <= v37 )
          break;
LABEL_38:
        if ( ++v15 > v38 )
        {
          v3 = v27;
          goto LABEL_40;
        }
      }
      while ( !*v16++ )
      {
        if ( ++v48 > v37 )
          goto LABEL_38;
      }
      v3 = v27;
      v9 = v43;
      v29 = v43;
      a2[3] = v43;
    }
  }
LABEL_43:
  if ( v39 < v37 )
  {
    v49 = v39;
    while ( 1 )
    {
      v32 = v35;
      if ( v35 <= v38 )
        break;
LABEL_50:
      if ( ++v49 > v37 )
        goto LABEL_53;
    }
    while ( 1 )
    {
      v18 = (_WORD *)(2 * (v49 + 32 * v3) + *(_DWORD *)(v28 + 4 * v32));
      v19 = v3;
      if ( v3 <= v9 )
        break;
LABEL_49:
      if ( ++v32 > v38 )
        goto LABEL_50;
    }
    while ( !*v18 )
    {
      ++v19;
      v18 += 32;
      if ( v19 > v9 )
        goto LABEL_49;
    }
    v39 = v49;
    a2[4] = v49;
LABEL_53:
    if ( v37 > v39 )
    {
      v50 = v37;
      while ( 1 )
      {
        v33 = v35;
        if ( v35 <= v38 )
          break;
LABEL_60:
        if ( --v50 < v39 )
          goto LABEL_63;
      }
      while ( 1 )
      {
        v20 = (_WORD *)(2 * (v50 + 32 * v3) + *(_DWORD *)(v28 + 4 * v33));
        v21 = v3;
        if ( v3 <= v9 )
          break;
LABEL_59:
        if ( ++v33 > v38 )
          goto LABEL_60;
      }
      while ( !*v20 )
      {
        ++v21;
        v20 += 32;
        if ( v21 > v9 )
          goto LABEL_59;
      }
      v37 = v50;
      a2[5] = v50;
    }
  }
LABEL_63:
  v22 = v9 - v3;
  v44 = 0;
  v23 = v35;
  a2[6] = 16 * (v38 - v35) * 16 * (v38 - v35) + 12 * (v9 - v3) * 12 * (v9 - v3) + 8 * (v37 - v39) * 8 * (v37 - v39);
  while ( v23 <= v38 )
  {
    if ( v27 <= v29 )
    {
      v24 = *(_DWORD *)(v28 + 4 * v23) + 2 * (v39 + 32 * v27);
      v25 = v22 + 1;
      do
      {
        v34 = (_WORD *)v24;
        if ( v39 <= v37 )
        {
          v36 = v37 - v39 + 1;
          do
          {
            if ( *v34 )
              ++v44;
            ++v34;
            --v36;
          }
          while ( v36 );
        }
        v24 += 64;
        --v25;
      }
      while ( v25 );
    }
    ++v23;
  }
  result = v44;
  a2[7] = v44;
  return result;
}

