int __usercall sub_6D9938@<eax>(int result@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int v3; // edi
  int v4; // esi
  int v5; // ebx
  int v6; // edx
  int v7; // edi
  int v8; // ecx
  unsigned __int16 v9; // si
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  __int16 v13; // si
  int v14; // ecx
  __int16 v15; // bx
  int v16; // ecx
  int v17; // edi
  int v18; // ecx
  unsigned __int16 v19; // si
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  __int16 v23; // si
  int v24; // ecx
  __int16 v25; // bx
  int v26; // ecx
  int v27; // ecx
  unsigned __int16 v28; // si
  int v29; // edi
  int v30; // ecx
  int v31; // ebx
  int v32; // ecx
  int v33; // esi
  int v34; // edi
  int v35; // ecx
  int v36; // ebx
  __int16 v37; // si
  int v38; // ebx
  int v39; // ecx
  int v40; // ecx
  unsigned __int16 v41; // si
  int v42; // edi
  int v43; // ecx
  int v44; // ebx
  int v45; // ecx
  int v46; // esi
  int v47; // edi
  int v48; // ecx
  int v49; // ebx
  unsigned __int16 v50; // si
  int v51; // edi
  int v52; // ecx
  int v53; // ebx
  int v54; // ecx
  int v55; // esi
  int v56; // edi
  int v57; // ecx
  int v58; // ebx
  int v59; // [esp-4h] [ebp-28h]
  int i; // [esp+Ch] [ebp-18h]
  int v61; // [esp+10h] [ebp-14h]
  int v62; // [esp+14h] [ebp-10h]
  int v63; // [esp+14h] [ebp-10h]
  int v64; // [esp+14h] [ebp-10h]
  int v65; // [esp+14h] [ebp-10h]
  unsigned __int16 *v66; // [esp+18h] [ebp-Ch]
  int v67; // [esp+1Ch] [ebp-8h]
  int v68; // [esp+20h] [ebp-4h]

  v61 = -1;
  v67 = *(unsigned __int16 *)(a3 + 2);
  v3 = 7;
  v4 = 0;
  v5 = 4;
  if ( !*(_WORD *)(a3 + 2) )
  {
    v3 = 138;
    v5 = 3;
  }
  if ( a2 >= 0 )
  {
    v66 = (unsigned __int16 *)(a3 + 6);
    for ( i = a2 + 1; i; --i )
    {
      v6 = v67;
      ++v4;
      v62 = v67;
      v67 = *v66;
      v68 = v4;
      if ( v4 < v3 && v6 == *v66 )
        goto LABEL_47;
      if ( v4 >= v5 )
      {
        if ( v6 )
        {
          if ( v6 != v61 )
          {
            v17 = *(unsigned __int16 *)(result + 4 * v6 + 2678);
            v18 = *(_DWORD *)(result + 5812);
            if ( v18 <= 16 - v17 )
            {
              v25 = *(_WORD *)(result + 4 * v6 + 2676) << v18;
              v26 = *(_DWORD *)(result + 5812);
              *(_WORD *)(result + 5808) |= v25;
              v24 = v17 + v26;
            }
            else
            {
              v19 = *(_WORD *)(result + 4 * v6 + 2676);
              v20 = v19 << v18;
              v21 = *(_DWORD *)(result + 8);
              *(_WORD *)(result + 5808) |= v20;
              *(_BYTE *)(v21 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
              *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
              v22 = *(_DWORD *)(result + 5812);
              ++*(_DWORD *)(result + 20);
              v23 = v19 >> (16 - v22);
              v24 = v22 + v17 - 16;
              v6 = v62;
              *(_WORD *)(result + 5808) = v23;
              v4 = v68;
            }
            --v4;
            *(_DWORD *)(result + 5812) = v24;
            v68 = v4;
          }
          v27 = *(_DWORD *)(result + 5812);
          v63 = *(unsigned __int16 *)(result + 2742);
          if ( v27 <= 16 - v63 )
          {
            *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2740) << v27;
            v32 = v63 + v27;
          }
          else
          {
            v28 = *(_WORD *)(result + 2740);
            v29 = v28 << v27;
            v30 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v29;
            *(_BYTE *)(v30 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
            v31 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v32 = v31 + v63 - 16;
            *(_WORD *)(result + 5808) = v28 >> (16 - v31);
            v4 = v68;
          }
          v33 = v4 - 3;
          *(_DWORD *)(result + 5812) = v32;
          if ( v32 > 14 )
          {
            v34 = v33 << v32;
            v35 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v34;
            *(_BYTE *)(v35 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
            v36 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v37 = (unsigned __int16)v33 >> (16 - v36);
            v38 = v36 - 14;
LABEL_31:
            *(_WORD *)(result + 5808) = v37;
            *(_DWORD *)(result + 5812) = v38;
            goto LABEL_40;
          }
          *(_WORD *)(result + 5808) |= v33 << v32;
          v39 = v32 + 2;
        }
        else
        {
          v40 = *(_DWORD *)(result + 5812);
          if ( v4 > 10 )
          {
            v65 = *(unsigned __int16 *)(result + 2750);
            if ( v40 <= 16 - v65 )
            {
              *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2748) << v40;
              v54 = v65 + v40;
            }
            else
            {
              v50 = *(_WORD *)(result + 2748);
              v51 = v50 << v40;
              v52 = *(_DWORD *)(result + 8);
              *(_WORD *)(result + 5808) |= v51;
              *(_BYTE *)(v52 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
              *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
              v53 = *(_DWORD *)(result + 5812);
              ++*(_DWORD *)(result + 20);
              v54 = v53 + v65 - 16;
              *(_WORD *)(result + 5808) = v50 >> (16 - v53);
              v4 = v68;
            }
            v55 = v4 - 11;
            *(_DWORD *)(result + 5812) = v54;
            if ( v54 > 9 )
            {
              v56 = v55 << v54;
              v57 = *(_DWORD *)(result + 8);
              *(_WORD *)(result + 5808) |= v56;
              *(_BYTE *)(v57 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
              *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
              v58 = *(_DWORD *)(result + 5812);
              ++*(_DWORD *)(result + 20);
              v37 = (unsigned __int16)v55 >> (16 - v58);
              v38 = v58 - 9;
              goto LABEL_31;
            }
            *(_WORD *)(result + 5808) |= v55 << v54;
            v39 = v54 + 7;
          }
          else
          {
            v64 = *(unsigned __int16 *)(result + 2746);
            if ( v40 <= 16 - v64 )
            {
              *(_WORD *)(result + 5808) |= *(_WORD *)(result + 2744) << v40;
              v45 = v64 + v40;
            }
            else
            {
              v41 = *(_WORD *)(result + 2744);
              v42 = v41 << v40;
              v43 = *(_DWORD *)(result + 8);
              *(_WORD *)(result + 5808) |= v42;
              *(_BYTE *)(v43 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
              *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
              v44 = *(_DWORD *)(result + 5812);
              ++*(_DWORD *)(result + 20);
              v45 = v44 + v64 - 16;
              *(_WORD *)(result + 5808) = v41 >> (16 - v44);
              v4 = v68;
            }
            v46 = v4 - 3;
            *(_DWORD *)(result + 5812) = v45;
            if ( v45 > 13 )
            {
              v47 = v46 << v45;
              v48 = *(_DWORD *)(result + 8);
              *(_WORD *)(result + 5808) |= v47;
              *(_BYTE *)(v48 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
              *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
              v49 = *(_DWORD *)(result + 5812);
              ++*(_DWORD *)(result + 20);
              v37 = (unsigned __int16)v46 >> (16 - v49);
              v38 = v49 - 13;
              goto LABEL_31;
            }
            *(_WORD *)(result + 5808) |= v46 << v45;
            v39 = v45 + 3;
          }
        }
        *(_DWORD *)(result + 5812) = v39;
      }
      else
      {
        do
        {
          v7 = *(unsigned __int16 *)(result + 4 * v6 + 2678);
          v8 = *(_DWORD *)(result + 5812);
          if ( v8 <= 16 - v7 )
          {
            v15 = *(_WORD *)(result + 4 * v6 + 2676) << v8;
            v16 = *(_DWORD *)(result + 5812);
            *(_WORD *)(result + 5808) |= v15;
            v14 = v7 + v16;
          }
          else
          {
            v9 = *(_WORD *)(result + 4 * v6 + 2676);
            v10 = v9 << v8;
            v11 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5808) |= v10;
            *(_BYTE *)(v11 + (*(_DWORD *)(result + 20))++) = *(_BYTE *)(result + 5808);
            *(_BYTE *)(*(_DWORD *)(result + 20) + *(_DWORD *)(result + 8)) = *(_BYTE *)(result + 5809);
            v12 = *(_DWORD *)(result + 5812);
            ++*(_DWORD *)(result + 20);
            v13 = v9 >> (16 - v12);
            v14 = v12 + v7 - 16;
            v6 = v62;
            *(_WORD *)(result + 5808) = v13;
            v4 = v68;
          }
          --v4;
          *(_DWORD *)(result + 5812) = v14;
          v68 = v4;
        }
        while ( v4 );
      }
LABEL_40:
      v4 = 0;
      v61 = v6;
      if ( v67 )
      {
        if ( v6 != v67 )
        {
          v3 = 7;
          v59 = 4;
          goto LABEL_46;
        }
        v3 = 6;
      }
      else
      {
        v3 = 138;
      }
      v59 = 3;
LABEL_46:
      v5 = v59;
LABEL_47:
      v66 += 2;
    }
  }
  return result;
}
