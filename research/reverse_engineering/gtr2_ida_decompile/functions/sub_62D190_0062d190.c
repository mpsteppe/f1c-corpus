int __userpurge sub_62D190@<eax>(int result@<eax>, int a2@<ecx>, int a3)
{
  int v4; // esi
  int v5; // ebx
  int v6; // ecx
  int v7; // edx
  int v8; // ebp
  int v9; // edi
  int v10; // ecx
  unsigned __int16 v11; // si
  int v12; // edx
  int v13; // ecx
  char v14; // bl
  int v15; // edx
  int v16; // edx
  int v17; // ecx
  int v18; // edi
  int v19; // ecx
  unsigned __int16 v20; // si
  int v21; // edx
  int v22; // ecx
  char v23; // bl
  int v24; // edx
  int v25; // edx
  int v26; // ecx
  int v27; // edi
  int v28; // ecx
  unsigned __int16 v29; // si
  int v30; // edx
  int v31; // ecx
  char v32; // bl
  int v33; // edx
  int v34; // edx
  int v35; // ecx
  int v36; // esi
  int v37; // edx
  int v38; // ecx
  char v39; // bl
  int v40; // edx
  int v41; // edx
  int v42; // ecx
  int v43; // ecx
  int v44; // edi
  unsigned __int16 v45; // si
  int v46; // edx
  int v47; // ecx
  char v48; // bl
  int v49; // edx
  int v50; // edx
  int v51; // ecx
  int v52; // esi
  int v53; // edx
  int v54; // ecx
  char v55; // bl
  int v56; // edx
  int v57; // edx
  int v58; // edi
  unsigned __int16 v59; // si
  int v60; // edx
  int v61; // ecx
  char v62; // bl
  int v63; // edx
  int v64; // edx
  int v65; // ecx
  int v66; // esi
  int v67; // edx
  int v68; // ecx
  char v69; // bl
  int v70; // edx
  int v71; // edx
  bool v72; // zf
  int v73; // [esp+10h] [ebp-Ch]
  unsigned __int16 *v74; // [esp+14h] [ebp-8h]
  int v75; // [esp+18h] [ebp-4h]
  int v76; // [esp+20h] [ebp+4h]

  v73 = *(unsigned __int16 *)(a2 + 2);
  v4 = 0;
  v5 = -1;
  v6 = 7;
  v7 = 4;
  if ( !v73 )
  {
    v6 = 138;
    v7 = 3;
  }
  if ( a3 >= 0 )
  {
    v74 = (unsigned __int16 *)(a2 + 6);
    v75 = a3 + 1;
    do
    {
      v8 = v73;
      ++v4;
      v73 = *v74;
      v76 = v4;
      if ( v4 < v6 && v8 == *v74 )
        goto LABEL_44;
      if ( v4 < v7 )
      {
        do
        {
          v9 = *(unsigned __int16 *)(result + 4 * v8 + 2676);
          v10 = *(_DWORD *)(result + 5805);
          if ( v10 <= 16 - v9 )
          {
            *(_WORD *)(result + 5803) |= *(_WORD *)(result + 4 * v8 + 2674) << v10;
            v17 = v9 + v10;
          }
          else
          {
            v11 = *(_WORD *)(result + 4 * v8 + 2674);
            v12 = v11 << v10;
            v13 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v12;
            *(_BYTE *)(v13 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v14 = *(_BYTE *)(result + 5804);
            v15 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v15;
            *(_BYTE *)(v15 + *(_DWORD *)(result + 8)) = v14;
            v16 = *(_DWORD *)(result + 5805);
            ++*(_DWORD *)(result + 20);
            v17 = v16 + v9 - 16;
            *(_WORD *)(result + 5803) = v11 >> (16 - v16);
            v4 = v76;
          }
          --v4;
          *(_DWORD *)(result + 5805) = v17;
          v76 = v4;
        }
        while ( v4 );
        goto LABEL_39;
      }
      if ( v8 )
      {
        if ( v8 != v5 )
        {
          v18 = *(unsigned __int16 *)(result + 4 * v8 + 2676);
          v19 = *(_DWORD *)(result + 5805);
          if ( v19 <= 16 - v18 )
          {
            *(_WORD *)(result + 5803) |= *(_WORD *)(result + 4 * v8 + 2674) << v19;
            v26 = v18 + v19;
          }
          else
          {
            v20 = *(_WORD *)(result + 4 * v8 + 2674);
            v21 = v20 << v19;
            v22 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v21;
            *(_BYTE *)(v22 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v23 = *(_BYTE *)(result + 5804);
            v24 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v24;
            *(_BYTE *)(v24 + *(_DWORD *)(result + 8)) = v23;
            v25 = *(_DWORD *)(result + 5805);
            ++*(_DWORD *)(result + 20);
            v26 = v25 + v18 - 16;
            *(_WORD *)(result + 5803) = v20 >> (16 - v25);
            v4 = v76;
          }
          --v4;
          *(_DWORD *)(result + 5805) = v26;
          v76 = v4;
        }
        v27 = *(unsigned __int16 *)(result + 2740);
        v28 = *(_DWORD *)(result + 5805);
        if ( v28 <= 16 - v27 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(result + 2738) << v28;
          v35 = v27 + v28;
        }
        else
        {
          v29 = *(_WORD *)(result + 2738);
          v30 = v29 << v28;
          v31 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v30;
          *(_BYTE *)(v31 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v32 = *(_BYTE *)(result + 5804);
          v33 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v33;
          *(_BYTE *)(v33 + *(_DWORD *)(result + 8)) = v32;
          v34 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          v35 = v34 + v27 - 16;
          *(_WORD *)(result + 5803) = v29 >> (16 - v34);
          v4 = v76;
        }
        v36 = v4 - 3;
        *(_DWORD *)(result + 5805) = v35;
        if ( v35 > 14 )
        {
          v37 = v36 << v35;
          v38 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v37;
          *(_BYTE *)(v38 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v39 = *(_BYTE *)(result + 5804);
          v40 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v40;
          *(_BYTE *)(v40 + *(_DWORD *)(result + 8)) = v39;
          v41 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5805) = v41 - 14;
          *(_WORD *)(result + 5803) = (unsigned __int16)v36 >> (16 - v41);
          goto LABEL_39;
        }
        *(_WORD *)(result + 5803) |= v36 << v35;
        v42 = v35 + 2;
      }
      else
      {
        v43 = *(_DWORD *)(result + 5805);
        if ( v4 > 10 )
        {
          v58 = *(unsigned __int16 *)(result + 2748);
          if ( v43 <= 16 - v58 )
          {
            *(_WORD *)(result + 5803) |= *(_WORD *)(result + 2746) << v43;
            v65 = v58 + v43;
          }
          else
          {
            v59 = *(_WORD *)(result + 2746);
            v60 = v59 << v43;
            v61 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v60;
            *(_BYTE *)(v61 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v62 = *(_BYTE *)(result + 5804);
            v63 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v63;
            *(_BYTE *)(v63 + *(_DWORD *)(result + 8)) = v62;
            v64 = *(_DWORD *)(result + 5805);
            ++*(_DWORD *)(result + 20);
            v65 = v64 + v58 - 16;
            *(_WORD *)(result + 5803) = v59 >> (16 - v64);
            v4 = v76;
          }
          v66 = v4 - 11;
          *(_DWORD *)(result + 5805) = v65;
          if ( v65 > 9 )
          {
            v67 = v66 << v65;
            v68 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v67;
            *(_BYTE *)(v68 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v69 = *(_BYTE *)(result + 5804);
            v70 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v70;
            *(_BYTE *)(v70 + *(_DWORD *)(result + 8)) = v69;
            v71 = *(_DWORD *)(result + 5805);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5805) = v71 - 9;
            *(_WORD *)(result + 5803) = (unsigned __int16)v66 >> (16 - v71);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5803) |= v66 << v65;
          v42 = v65 + 7;
        }
        else
        {
          v44 = *(unsigned __int16 *)(result + 2744);
          if ( v43 <= 16 - v44 )
          {
            *(_WORD *)(result + 5803) |= *(_WORD *)(result + 2742) << v43;
            v51 = v44 + v43;
          }
          else
          {
            v45 = *(_WORD *)(result + 2742);
            v46 = v45 << v43;
            v47 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v46;
            *(_BYTE *)(v47 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v48 = *(_BYTE *)(result + 5804);
            v49 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v49;
            *(_BYTE *)(v49 + *(_DWORD *)(result + 8)) = v48;
            v50 = *(_DWORD *)(result + 5805);
            ++*(_DWORD *)(result + 20);
            v51 = v50 + v44 - 16;
            *(_WORD *)(result + 5803) = v45 >> (16 - v50);
            v4 = v76;
          }
          v52 = v4 - 3;
          *(_DWORD *)(result + 5805) = v51;
          if ( v51 > 13 )
          {
            v53 = v52 << v51;
            v54 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v53;
            *(_BYTE *)(v54 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v55 = *(_BYTE *)(result + 5804);
            v56 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v56;
            *(_BYTE *)(v56 + *(_DWORD *)(result + 8)) = v55;
            v57 = *(_DWORD *)(result + 5805);
            ++*(_DWORD *)(result + 20);
            *(_DWORD *)(result + 5805) = v57 - 13;
            *(_WORD *)(result + 5803) = (unsigned __int16)v52 >> (16 - v57);
            goto LABEL_39;
          }
          *(_WORD *)(result + 5803) |= v52 << v51;
          v42 = v51 + 3;
        }
      }
      *(_DWORD *)(result + 5805) = v42;
LABEL_39:
      v4 = 0;
      v5 = v8;
      if ( v73 )
      {
        if ( v8 == v73 )
        {
          v6 = 6;
          v7 = 3;
        }
        else
        {
          v6 = 7;
          v7 = 4;
        }
      }
      else
      {
        v6 = dword_16C9980;
        v7 = 3;
      }
LABEL_44:
      v72 = v75 == 1;
      v74 += 2;
      --v75;
    }
    while ( !v72 );
  }
  return result;
}
