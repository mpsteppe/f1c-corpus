int __userpurge sub_62D910@<eax>(int result@<eax>, int a2, int a3)
{
  int v3; // ebx
  unsigned int v4; // ecx
  int v5; // ebp
  int v6; // esi
  int v7; // ecx
  int v8; // edi
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  char v12; // bl
  int v13; // edx
  int v14; // edx
  int v15; // ecx
  int v16; // edx
  int v17; // edi
  int v18; // edx
  int v19; // ecx
  char v20; // bl
  int v21; // edx
  int v22; // edx
  int v23; // edi
  int v24; // esi
  int v25; // ecx
  int v26; // edx
  int v27; // ecx
  char v28; // bl
  int v29; // edx
  int v30; // edx
  int v31; // ecx
  unsigned int v32; // ebp
  int v33; // edi
  int v34; // edx
  int v35; // ecx
  unsigned __int16 v36; // si
  int v37; // edx
  int v38; // ecx
  char v39; // bl
  int v40; // edx
  int v41; // edx
  int v42; // esi
  unsigned int v43; // ebp
  int v44; // ecx
  unsigned int v45; // edx
  int v46; // ecx
  char v47; // bl
  int v48; // edx
  int v49; // edx
  int v50; // edi
  int v51; // ecx
  unsigned __int16 v52; // si
  int v53; // edx
  int v54; // ecx
  int v55; // ecx
  int v56; // edx
  int v57; // edx
  int v58; // [esp+10h] [ebp-Ch]
  int v59; // [esp+10h] [ebp-Ch]
  int v60; // [esp+14h] [ebp-8h]
  int v61; // [esp+14h] [ebp-8h]
  int v62; // [esp+14h] [ebp-8h]
  unsigned int v63; // [esp+18h] [ebp-4h]

  v3 = a2;
  v4 = 0;
  if ( *(_DWORD *)(result + 5779) )
  {
    do
    {
      v5 = *(unsigned __int16 *)(*(_DWORD *)(result + 5783) + 2 * v4);
      v6 = *(unsigned __int8 *)(v4 + *(_DWORD *)(result + 5771));
      v63 = v4 + 1;
      v7 = *(_DWORD *)(result + 5805);
      if ( v5 )
      {
        v16 = (unsigned __int8)byte_72FB50[v6];
        v59 = *(unsigned __int16 *)(v3 + 4 * v16 + 1030);
        v60 = v16;
        if ( v7 <= 16 - v59 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(a2 + 4 * v16 + 1028) << v7;
          *(_DWORD *)(result + 5805) = v59 + v7;
        }
        else
        {
          v17 = *(unsigned __int16 *)(a2 + 4 * v16 + 1028);
          v18 = v17 << v7;
          v19 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v18;
          *(_BYTE *)(v19 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v20 = *(_BYTE *)(result + 5804);
          v21 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v21;
          *(_BYTE *)(v21 + *(_DWORD *)(result + 8)) = v20;
          v22 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          LOWORD(v17) = (unsigned __int16)v17 >> (16 - v22);
          *(_DWORD *)(result + 5805) = v22 + v59 - 16;
          v16 = v60;
          *(_WORD *)(result + 5803) = v17;
        }
        v23 = dword_72F308[v16];
        v3 = a2;
        if ( v23 )
        {
          v24 = v6 - dword_72FC50[v16];
          v25 = *(_DWORD *)(result + 5805);
          if ( v25 <= 16 - v23 )
          {
            *(_WORD *)(result + 5803) |= v24 << v25;
            v31 = v23 + v25;
          }
          else
          {
            v26 = v24 << v25;
            v27 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v26;
            *(_BYTE *)(v27 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v28 = *(_BYTE *)(result + 5804);
            v29 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v29;
            *(_BYTE *)(v29 + *(_DWORD *)(result + 8)) = v28;
            v30 = *(_DWORD *)(result + 5805);
            v3 = a2;
            ++*(_DWORD *)(result + 20);
            v31 = v30 + v23 - 16;
            *(_WORD *)(result + 5803) = (unsigned __int16)v24 >> (16 - v30);
          }
          *(_DWORD *)(result + 5805) = v31;
        }
        v32 = v5 - 1;
        if ( v32 >= 0x100 )
          v33 = (unsigned __int8)byte_72FA50[v32 >> 7];
        else
          v33 = (unsigned __int8)byte_72F950[v32];
        v34 = *(unsigned __int16 *)(a3 + 4 * v33 + 2);
        v35 = *(_DWORD *)(result + 5805);
        v61 = v34;
        if ( v35 <= 16 - v34 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(a3 + 4 * v33) << v35;
          *(_DWORD *)(result + 5805) = v34 + v35;
        }
        else
        {
          v36 = *(_WORD *)(a3 + 4 * v33);
          v37 = v36 << v35;
          v38 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v37;
          *(_BYTE *)(v38 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v39 = *(_BYTE *)(result + 5804);
          v40 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v40;
          *(_BYTE *)(v40 + *(_DWORD *)(result + 8)) = v39;
          v41 = *(_DWORD *)(result + 5805);
          v3 = a2;
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5805) = v41 + v61 - 16;
          *(_WORD *)(result + 5803) = v36 >> (16 - v41);
        }
        v42 = dword_72F380[v33];
        if ( !v42 )
          goto LABEL_25;
        v43 = v32 - dword_72FCC8[v33];
        v44 = *(_DWORD *)(result + 5805);
        if ( v44 <= 16 - v42 )
        {
          *(_WORD *)(result + 5803) |= v43 << v44;
          v15 = v42 + v44;
        }
        else
        {
          v45 = v43 << v44;
          v46 = *(_DWORD *)(result + 8);
          v62 = v3;
          *(_WORD *)(result + 5803) |= v45;
          *(_BYTE *)(v46 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v47 = *(_BYTE *)(result + 5804);
          v48 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v48;
          *(_BYTE *)(v48 + *(_DWORD *)(result + 8)) = v47;
          v49 = *(_DWORD *)(result + 5805);
          v3 = v62;
          ++*(_DWORD *)(result + 20);
          v15 = v49 + v42 - 16;
          *(_WORD *)(result + 5803) = (unsigned __int16)v43 >> (16 - v49);
        }
      }
      else
      {
        v8 = *(unsigned __int16 *)(v3 + 4 * v6 + 2);
        if ( v7 <= 16 - v8 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(v3 + 4 * v6) << v7;
          v15 = v8 + v7;
        }
        else
        {
          v9 = *(unsigned __int16 *)(v3 + 4 * v6);
          v10 = v9 << v7;
          v11 = *(_DWORD *)(result + 8);
          v58 = v3;
          *(_WORD *)(result + 5803) |= v10;
          *(_BYTE *)(v11 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v12 = *(_BYTE *)(result + 5804);
          v13 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v13;
          *(_BYTE *)(v13 + *(_DWORD *)(result + 8)) = v12;
          v14 = *(_DWORD *)(result + 5805);
          v3 = v58;
          ++*(_DWORD *)(result + 20);
          v15 = v14 + v8 - 16;
          *(_WORD *)(result + 5803) = (unsigned __int16)v9 >> (16 - v14);
        }
      }
      *(_DWORD *)(result + 5805) = v15;
LABEL_25:
      v4 = v63;
    }
    while ( v63 < *(_DWORD *)(result + 5779) );
  }
  v50 = *(unsigned __int16 *)(v3 + 1026);
  v51 = *(_DWORD *)(result + 5805);
  if ( v51 <= 16 - v50 )
  {
    *(_WORD *)(result + 5803) |= *(_WORD *)(v3 + 1024) << v51;
    *(_DWORD *)(result + 5805) = v50 + v51;
  }
  else
  {
    v52 = *(_WORD *)(v3 + 1024);
    v53 = v52 << v51;
    v54 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5803) |= v53;
    *(_BYTE *)(v54 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
    v55 = *(_DWORD *)(result + 8);
    v56 = *(_DWORD *)(result + 20) + 1;
    *(_DWORD *)(result + 20) = v56;
    *(_BYTE *)(v55 + v56) = *(_BYTE *)(result + 5804);
    v57 = *(_DWORD *)(result + 5805);
    ++*(_DWORD *)(result + 20);
    *(_DWORD *)(result + 5805) = v57 + v50 - 16;
    *(_WORD *)(result + 5803) = v52 >> (16 - v57);
  }
  *(_DWORD *)(result + 5799) = *(unsigned __int16 *)(v3 + 1026);
  return result;
}
