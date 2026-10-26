int __userpurge sub_6DA010@<eax>(int result@<eax>, int a2, int a3)
{
  int v3; // ebx
  unsigned int v4; // ecx
  int v5; // edi
  int v6; // esi
  int v7; // ecx
  unsigned __int16 *v8; // esi
  int v9; // edi
  int v10; // esi
  int v11; // edx
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // ebx
  int v18; // ecx
  unsigned __int16 v19; // di
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // esi
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  int v30; // ecx
  unsigned int v31; // edi
  int v32; // ecx
  int v33; // esi
  unsigned __int16 *v34; // edx
  int v35; // ecx
  unsigned __int16 v36; // si
  int v37; // edx
  int v38; // ecx
  int v39; // edx
  int v40; // ecx
  int v41; // edx
  unsigned int v42; // edi
  unsigned int v43; // edx
  int v44; // ecx
  int v45; // edx
  int v46; // edx
  int v47; // ecx
  unsigned __int16 v48; // si
  int v49; // edx
  int v50; // ecx
  int v51; // edx
  int v52; // ecx
  unsigned int v53; // [esp+Ch] [ebp-10h]
  int v54; // [esp+10h] [ebp-Ch]
  int v55; // [esp+14h] [ebp-8h]
  int v56; // [esp+14h] [ebp-8h]
  int v57; // [esp+18h] [ebp-4h]
  int v58; // [esp+18h] [ebp-4h]
  int v59; // [esp+18h] [ebp-4h]
  int v60; // [esp+18h] [ebp-4h]
  int v61; // [esp+24h] [ebp+8h]

  v3 = a2;
  v4 = 0;
  if ( *(_DWORD *)(result + 5784) )
  {
    do
    {
      v5 = *(unsigned __int16 *)(*(_DWORD *)(result + 5788) + 2 * v4);
      v6 = *(unsigned __int8 *)(v4 + *(_DWORD *)(result + 5776));
      v54 = v5;
      v53 = v4 + 1;
      if ( *(_WORD *)(*(_DWORD *)(result + 5788) + 2 * v4) )
      {
        v15 = (unsigned __int8)byte_748810[v6];
        v57 = v15;
        v16 = *(unsigned __int16 *)(4 * v15 + v3 + 1030);
        v17 = 16 - v16;
        v55 = v16;
        v18 = *(_DWORD *)(result + 5812);
        if ( v18 <= v17 )
        {
          *(_WORD *)(result + 5808) |= *(_WORD *)(a2 + 4 * v15 + 1028) << v18;
          v23 = v55 + v18;
        }
        else
        {
          v19 = *(_WORD *)(a2 + 4 * v15 + 1028);
          v20 = v19 << v18;
          v21 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v20;
          *(_BYTE *)(v21 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
          v22 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v23 = v22 + v55 - 16;
          *(_WORD *)(result + 5808) = v19 >> (16 - v22);
          v5 = v54;
        }
        *(_DWORD *)(result + 5812) = v23;
        v24 = v57 * 4;
        v58 = dword_747FC8[v57];
        if ( v58 )
        {
          v25 = v6 - *(int *)((char *)&dword_748910 + v24);
          v26 = *(_DWORD *)(result + 5812);
          if ( v26 <= 16 - v58 )
          {
            *(_WORD *)(result + 5808) |= v25 << v26;
            v30 = v58 + v26;
          }
          else
          {
            v27 = v25 << v26;
            v28 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v27;
            *(_BYTE *)(v28 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
            v29 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v30 = v29 + v58 - 16;
            *(_WORD *)(result + 5808) = (unsigned __int16)v25 >> (16 - v29);
          }
          *(_DWORD *)(result + 5812) = v30;
        }
        v31 = v5 - 1;
        if ( v31 >= 0x100 )
          v32 = (unsigned __int8)byte_748710[v31 >> 7];
        else
          v32 = (unsigned __int8)byte_748610[v31];
        v33 = 4 * v32;
        v34 = (unsigned __int16 *)(4 * v32 + a3);
        v56 = v34[1];
        v35 = *(_DWORD *)(result + 5812);
        v59 = v33;
        if ( v35 <= 16 - v56 )
        {
          *(_WORD *)(result + 5808) |= *v34 << v35;
          v40 = v56 + v35;
        }
        else
        {
          v36 = *v34;
          v37 = *v34 << v35;
          v38 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v37;
          *(_BYTE *)(v38 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
          v39 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v40 = v39 + v56 - 16;
          *(_WORD *)(result + 5808) = v36 >> (16 - v39);
          v33 = v59;
        }
        v3 = a2;
        *(_DWORD *)(result + 5812) = v40;
        v41 = *(int *)((char *)&dword_748040 + v33);
        v60 = v41;
        if ( !v41 )
          goto LABEL_25;
        v42 = v31 - *(int *)((char *)&dword_748988 + v33);
        if ( v40 <= 16 - v41 )
        {
          *(_WORD *)(result + 5808) |= v42 << v40;
          v14 = v41 + v40;
        }
        else
        {
          v43 = v42 << v40;
          v44 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v43;
          *(_BYTE *)(v44 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
          v45 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v14 = v45 + v60 - 16;
          *(_WORD *)(result + 5808) = (unsigned __int16)v42 >> (16 - v45);
        }
      }
      else
      {
        v7 = *(_DWORD *)(result + 5812);
        v8 = (unsigned __int16 *)(v3 + 4 * v6);
        v9 = v8[1];
        if ( v7 <= 16 - v9 )
        {
          *(_WORD *)(result + 5808) |= *v8 << v7;
          v14 = v9 + v7;
        }
        else
        {
          v10 = *v8;
          v11 = v10 << v7;
          v12 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5808) |= v11;
          *(_BYTE *)(v12 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
          *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
          v13 = *(_DWORD *)(result + 5812);
          ++*(_DWORD *)(result + 20);
          v3 = a2;
          v14 = v13 + v9 - 16;
          *(_WORD *)(result + 5808) = (unsigned __int16)v10 >> (16 - v13);
        }
      }
      *(_DWORD *)(result + 5812) = v14;
LABEL_25:
      v4 = v53;
    }
    while ( v53 < *(_DWORD *)(result + 5784) );
  }
  v46 = *(unsigned __int16 *)(v3 + 1026);
  v47 = *(_DWORD *)(result + 5812);
  v61 = v46;
  if ( v47 <= 16 - v46 )
  {
    *(_WORD *)(result + 5808) |= *(_WORD *)(v3 + 1024) << v47;
    v52 = v46 + v47;
  }
  else
  {
    v48 = *(_WORD *)(v3 + 1024);
    v49 = v48 << v47;
    v50 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5808) |= v49;
    *(_BYTE *)(v50 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
    *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
    v51 = *(_DWORD *)(result + 5812);
    ++*(_DWORD *)(result + 20);
    v52 = v51 + v61 - 16;
    *(_WORD *)(result + 5808) = v48 >> (16 - v51);
  }
  *(_DWORD *)(result + 5812) = v52;
  *(_DWORD *)(result + 5804) = *(unsigned __int16 *)(v3 + 1026);
  return result;
}
