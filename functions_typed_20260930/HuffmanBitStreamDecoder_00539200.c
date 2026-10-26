int __fastcall sub_539200(int a1, int a2, int a3)
{
  int result; // eax
  unsigned int v4; // edi
  int v5; // ebp
  int v6; // ecx
  int v7; // esi
  unsigned __int16 v8; // di
  int v9; // esi
  int v10; // ecx
  char v11; // bl
  int v12; // ecx
  int v13; // ebx
  int v14; // ecx
  int v15; // ebx
  int v16; // edi
  unsigned __int16 v17; // di
  int v18; // edx
  int v19; // ecx
  char v20; // bl
  int v21; // edx
  int v22; // edx
  __int16 v23; // dx
  int v24; // ecx
  int v25; // edi
  int v26; // esi
  int v27; // ecx
  int v28; // edx
  int v29; // ecx
  char v30; // bl
  int v31; // edx
  int v32; // edx
  int v33; // ecx
  unsigned int v34; // ebp
  int v35; // ebx
  int v36; // ecx
  int v37; // edi
  unsigned __int16 v38; // si
  int v39; // edx
  int v40; // ecx
  char v41; // bl
  int v42; // edx
  int v43; // edx
  int v44; // ecx
  int v45; // esi
  unsigned int v46; // ebp
  int v47; // ecx
  unsigned int v48; // edi
  int v49; // ecx
  char v50; // bl
  int v51; // ecx
  int v52; // ebx
  int v53; // ecx
  int v54; // edi
  unsigned __int16 v55; // si
  int v56; // ebx
  int v57; // ecx
  int v58; // ecx
  int v59; // ebp
  int v60; // ebx
  int v61; // ecx
  int v62; // [esp+10h] [ebp-10h]
  int v63; // [esp+10h] [ebp-10h]
  int v64; // [esp+14h] [ebp-Ch]
  int v65; // [esp+18h] [ebp-8h]
  unsigned int v66; // [esp+1Ch] [ebp-4h]

  result = a1;
  v4 = 0;
  v64 = a2;
  if ( *(_DWORD *)(a1 + 5779) )
  {
    do
    {
      v5 = *(unsigned __int16 *)(*(_DWORD *)(result + 5783) + 2 * v4);
      v6 = *(_DWORD *)(result + 5805);
      v7 = *(unsigned __int8 *)(v4 + *(_DWORD *)(result + 5771));
      v66 = v4 + 1;
      if ( (_WORD)v5 )
      {
        HIWORD(v16) = 0;
        v15 = (unsigned __int8)byte_5B84F8[v7];
        v62 = v15;
        LOWORD(v16) = *(_WORD *)(a2 + 4 * v15 + 1030);
        v65 = (unsigned __int16)v16;
        if ( v6 <= 16 - (unsigned __int16)v16 )
        {
          v23 = *(_WORD *)(v64 + 4 * v15 + 1028) << v6;
          v24 = *(_DWORD *)(result + 5805);
          *(_WORD *)(result + 5803) |= v23;
          *(_DWORD *)(result + 5805) = v16 + v24;
        }
        else
        {
          v17 = *(_WORD *)(v64 + 4 * v15 + 1028);
          v18 = v17 << v6;
          v19 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v18;
          *(_BYTE *)(v19 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v20 = *(_BYTE *)(result + 5804);
          v21 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v21;
          *(_BYTE *)(v21 + *(_DWORD *)(result + 8)) = v20;
          v22 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          v15 = v62;
          *(_WORD *)(result + 5803) = v17 >> (16 - v22);
          *(_DWORD *)(result + 5805) = v22 + v65 - 16;
        }
        v25 = dword_5B7CB0[v15];
        if ( v25 )
        {
          v26 = v7 - dword_5B85F8[v15];
          v27 = *(_DWORD *)(result + 5805);
          if ( v27 <= 16 - v25 )
          {
            *(_WORD *)(result + 5803) |= v26 << v27;
            v33 = v25 + v27;
          }
          else
          {
            v28 = v26 << v27;
            v29 = *(_DWORD *)(result + 8);
            *(_WORD *)(result + 5803) |= v28;
            *(_BYTE *)(v29 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
            v30 = *(_BYTE *)(result + 5804);
            v31 = *(_DWORD *)(result + 20) + 1;
            *(_DWORD *)(result + 20) = v31;
            *(_BYTE *)(v31 + *(_DWORD *)(result + 8)) = v30;
            v32 = *(_DWORD *)(result + 5805);
            ++*(_DWORD *)(result + 20);
            v33 = v32 + v25 - 16;
            *(_WORD *)(result + 5803) = (unsigned __int16)v26 >> (16 - v32);
          }
          *(_DWORD *)(result + 5805) = v33;
        }
        v34 = v5 - 1;
        if ( v34 >= 0x100 )
          v35 = (unsigned __int8)byte_5B83F8[v34 >> 7];
        else
          v35 = (unsigned __int8)byte_5B82F8[v34];
        v36 = *(_DWORD *)(result + 5805);
        v37 = *(unsigned __int16 *)(a3 + 4 * v35 + 2);
        v63 = v35;
        if ( v36 <= 16 - (unsigned __int16)v37 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(a3 + 4 * v35) << v36;
          v44 = v37 + v36;
        }
        else
        {
          v38 = *(_WORD *)(a3 + 4 * v35);
          v39 = v38 << v36;
          v40 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v39;
          *(_BYTE *)(v40 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v41 = *(_BYTE *)(result + 5804);
          v42 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v42;
          *(_BYTE *)(v42 + *(_DWORD *)(result + 8)) = v41;
          v43 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          v35 = v63;
          v44 = v43 + v37 - 16;
          *(_WORD *)(result + 5803) = v38 >> (16 - v43);
        }
        a2 = v64;
        *(_DWORD *)(result + 5805) = v44;
        v45 = dword_5B7D28[v35];
        if ( !v45 )
          goto LABEL_25;
        v46 = v34 - dword_5B8670[v35];
        v47 = *(_DWORD *)(result + 5805);
        if ( v47 <= 16 - v45 )
        {
          *(_WORD *)(result + 5803) |= v46 << v47;
          v14 = v45 + v47;
        }
        else
        {
          v48 = v46 << v47;
          v49 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v48;
          *(_BYTE *)(v49 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v50 = *(_BYTE *)(result + 5804);
          v51 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v51;
          *(_BYTE *)(v51 + *(_DWORD *)(result + 8)) = v50;
          ++*(_DWORD *)(result + 20);
          v52 = *(_DWORD *)(result + 5805);
          v14 = v52 + v45 - 16;
          *(_WORD *)(result + 5803) = (unsigned __int16)v46 >> (16 - v52);
        }
      }
      else
      {
        LOWORD(v5) = *(_WORD *)(a2 + 4 * v7 + 2);
        if ( v6 <= 16 - (unsigned __int16)v5 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(a2 + 4 * v7) << v6;
          v14 = v5 + v6;
        }
        else
        {
          v8 = *(_WORD *)(a2 + 4 * v7);
          v9 = v8 << v6;
          v10 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v9;
          *(_BYTE *)(v10 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v11 = *(_BYTE *)(result + 5804);
          v12 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v12;
          *(_BYTE *)(v12 + *(_DWORD *)(result + 8)) = v11;
          ++*(_DWORD *)(result + 20);
          v13 = *(_DWORD *)(result + 5805);
          v14 = v13 + v5 - 16;
          *(_WORD *)(result + 5803) = v8 >> (16 - v13);
        }
      }
      *(_DWORD *)(result + 5805) = v14;
LABEL_25:
      v4 = v66;
    }
    while ( v66 < *(_DWORD *)(result + 5779) );
  }
  v53 = *(_DWORD *)(result + 5805);
  v54 = *(unsigned __int16 *)(a2 + 1026);
  if ( v53 <= 16 - (unsigned __int16)v54 )
  {
    *(_WORD *)(result + 5803) |= *(_WORD *)(a2 + 1024) << v53;
    v61 = v54 + v53;
  }
  else
  {
    v55 = *(_WORD *)(a2 + 1024);
    v56 = v55 << v53;
    v57 = *(_DWORD *)(result + 8);
    *(_WORD *)(result + 5803) |= v56;
    *(_BYTE *)(v57 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
    v58 = *(_DWORD *)(result + 8);
    LOBYTE(v56) = *(_BYTE *)(result + 5804);
    v59 = *(_DWORD *)(result + 20) + 1;
    *(_DWORD *)(result + 20) = v59;
    *(_BYTE *)(v58 + v59) = v56;
    v60 = *(_DWORD *)(result + 5805);
    ++*(_DWORD *)(result + 20);
    v61 = v60 + v54 - 16;
    *(_WORD *)(result + 5803) = v55 >> (16 - v60);
  }
  *(_DWORD *)(result + 5805) = v61;
  *(_DWORD *)(result + 5799) = *(unsigned __int16 *)(a2 + 1026);
  return result;
}

