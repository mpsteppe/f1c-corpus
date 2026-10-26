int __fastcall sub_538CE0(int a1, int a2, int a3)
{
  int v3; // ebp
  int v4; // esi
  int result; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // edx
  int v9; // ecx
  int v10; // edi
  unsigned __int16 v11; // si
  int v12; // edx
  int v13; // ecx
  char v14; // bl
  int v15; // edx
  int v16; // edx
  int v17; // ecx
  int v18; // ecx
  int v19; // edi
  unsigned __int16 v20; // si
  int v21; // edx
  int v22; // ecx
  char v23; // bl
  int v24; // edx
  int v25; // edx
  int v26; // ecx
  int v27; // ecx
  int v28; // edi
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
  unsigned __int16 v58; // si
  int v59; // edx
  int v60; // ecx
  char v61; // bl
  int v62; // edx
  int v63; // edx
  int v64; // ecx
  int v65; // esi
  int v66; // edx
  int v67; // ecx
  char v68; // bl
  int v69; // edx
  int v70; // edx
  bool v71; // zf
  _WORD *v72; // [esp+10h] [ebp-10h]
  int v73; // [esp+14h] [ebp-Ch]
  int v74; // [esp+18h] [ebp-8h]
  int i; // [esp+1Ch] [ebp-4h]
  int v76; // [esp+24h] [ebp+4h]

  v3 = *(unsigned __int16 *)(a2 + 2);
  v4 = 0;
  result = a1;
  v73 = -1;
  v6 = 7;
  v7 = 4;
  if ( !(_WORD)v3 )
  {
    v6 = 138;
    v7 = 3;
  }
  if ( a3 >= 0 )
  {
    v72 = (_WORD *)(a2 + 6);
    for ( i = a3 + 1; ; --i )
    {
      HIWORD(v8) = 0;
      ++v4;
      v74 = (unsigned __int16)*v72;
      v76 = v4;
      if ( v4 >= v6 )
        break;
      LOWORD(v8) = *v72;
      if ( v3 != v8 )
        break;
LABEL_45:
      v71 = i == 1;
      v72 += 2;
      if ( v71 )
        return result;
      v3 = v74;
    }
    if ( v4 < v7 )
    {
      do
      {
        v9 = *(_DWORD *)(result + 5805);
        v10 = *(unsigned __int16 *)(result + 4 * v3 + 2676);
        if ( v9 <= 16 - (unsigned __int16)v10 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(result + 4 * v3 + 2674) << v9;
          v17 = v10 + v9;
        }
        else
        {
          v11 = *(_WORD *)(result + 4 * v3 + 2674);
          v12 = v11 << v9;
          v13 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v12;
          *(_BYTE *)(v13 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v14 = *(_BYTE *)(result + 5804);
          v15 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v15;
          *(_BYTE *)(v15 + *(_DWORD *)(result + 8)) = v14;
          v16 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          v17 = v16 + v10 - 16;
          *(_WORD *)(result + 5803) = v11 >> (16 - v16);
          v4 = v76;
        }
        --v4;
        *(_DWORD *)(result + 5805) = v17;
        v76 = v4;
      }
      while ( v4 );
      goto LABEL_40;
    }
    if ( v3 )
    {
      if ( v3 != v73 )
      {
        v18 = *(_DWORD *)(result + 5805);
        v19 = *(unsigned __int16 *)(result + 4 * v3 + 2676);
        if ( v18 <= 16 - (unsigned __int16)v19 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(result + 4 * v3 + 2674) << v18;
          v26 = v19 + v18;
        }
        else
        {
          v20 = *(_WORD *)(result + 4 * v3 + 2674);
          v21 = v20 << v18;
          v22 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v21;
          *(_BYTE *)(v22 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v23 = *(_BYTE *)(result + 5804);
          v24 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v24;
          *(_BYTE *)(v24 + *(_DWORD *)(result + 8)) = v23;
          v25 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          v26 = v25 + v19 - 16;
          *(_WORD *)(result + 5803) = v20 >> (16 - v25);
          v4 = v76;
        }
        --v4;
        *(_DWORD *)(result + 5805) = v26;
        v76 = v4;
      }
      v27 = *(_DWORD *)(result + 5805);
      v28 = *(unsigned __int16 *)(result + 2740);
      if ( v27 <= 16 - (unsigned __int16)v28 )
      {
        *(_WORD *)(result + 5803) |= *(_WORD *)(result + 2738) << v27;
        v35 = v28 + v27;
      }
      else
      {
        v29 = *(_WORD *)(result + 2738);
        v30 = v29 << v27;
        v31 = *(_DWORD *)(result + 8);
        *(_WORD *)(result + 5803) |= v30;
        *(_BYTE *)(v31 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
        v32 = *(_BYTE *)(result + 5804);
        v33 = *(_DWORD *)(result + 20) + 1;
        *(_DWORD *)(result + 20) = v33;
        *(_BYTE *)(v33 + *(_DWORD *)(result + 8)) = v32;
        v34 = *(_DWORD *)(result + 5805);
        ++*(_DWORD *)(result + 20);
        v35 = v34 + v28 - 16;
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
        goto LABEL_40;
      }
      *(_WORD *)(result + 5803) |= v36 << v35;
      v42 = v35 + 2;
    }
    else
    {
      v43 = *(_DWORD *)(result + 5805);
      HIWORD(v44) = 0;
      if ( v4 > 10 )
      {
        LOWORD(v44) = *(_WORD *)(result + 2748);
        if ( v43 <= 16 - v44 )
        {
          *(_WORD *)(result + 5803) |= *(_WORD *)(result + 2746) << v43;
          v64 = v44 + v43;
        }
        else
        {
          v58 = *(_WORD *)(result + 2746);
          v59 = v58 << v43;
          v60 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v59;
          *(_BYTE *)(v60 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v61 = *(_BYTE *)(result + 5804);
          v62 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v62;
          *(_BYTE *)(v62 + *(_DWORD *)(result + 8)) = v61;
          v63 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          v64 = v63 + v44 - 16;
          *(_WORD *)(result + 5803) = v58 >> (16 - v63);
          v4 = v76;
        }
        v65 = v4 - 11;
        *(_DWORD *)(result + 5805) = v64;
        if ( v64 > 9 )
        {
          v66 = v65 << v64;
          v67 = *(_DWORD *)(result + 8);
          *(_WORD *)(result + 5803) |= v66;
          *(_BYTE *)(v67 + *(_DWORD *)(result + 20)) = *(_BYTE *)(result + 5803);
          v68 = *(_BYTE *)(result + 5804);
          v69 = *(_DWORD *)(result + 20) + 1;
          *(_DWORD *)(result + 20) = v69;
          *(_BYTE *)(v69 + *(_DWORD *)(result + 8)) = v68;
          v70 = *(_DWORD *)(result + 5805);
          ++*(_DWORD *)(result + 20);
          *(_DWORD *)(result + 5805) = v70 - 9;
          *(_WORD *)(result + 5803) = (unsigned __int16)v65 >> (16 - v70);
          goto LABEL_40;
        }
        *(_WORD *)(result + 5803) |= v65 << v64;
        v42 = v64 + 7;
      }
      else
      {
        LOWORD(v44) = *(_WORD *)(result + 2744);
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
          goto LABEL_40;
        }
        *(_WORD *)(result + 5803) |= v52 << v51;
        v42 = v51 + 3;
      }
    }
    *(_DWORD *)(result + 5805) = v42;
LABEL_40:
    v4 = 0;
    v73 = v3;
    if ( v74 )
    {
      if ( v3 == v74 )
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
      v6 = 138;
      v7 = 3;
    }
    goto LABEL_45;
  }
  return result;
}
