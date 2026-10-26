__int16 __cdecl sub_51DCAA(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // ecx
  int v5; // edx
  int *v6; // eax
  int v7; // esi
  __int16 result; // ax
  int v9; // esi
  unsigned __int8 *v10; // eax
  _BYTE *v11; // esi
  _WORD *v12; // esi
  int v13; // ebx
  int v14; // edi
  int v15; // edi
  int v16; // ebx
  _WORD *v17; // eax
  int v18; // eax
  int v19; // edi
  int v20; // ebx
  int v21; // eax
  int v22; // ecx
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  __int16 v26; // dx
  int v27; // ecx
  int v28; // eax
  __int16 v29; // dx
  bool v30; // zf
  int v31; // [esp+4h] [ebp-68h]
  int v32; // [esp+Ch] [ebp-60h]
  int v33; // [esp+10h] [ebp-5Ch]
  int v34; // [esp+14h] [ebp-58h]
  _WORD *v35; // [esp+18h] [ebp-54h]
  int v36; // [esp+20h] [ebp-4Ch]
  int v37; // [esp+28h] [ebp-44h]
  int v38; // [esp+2Ch] [ebp-40h]
  int v39; // [esp+30h] [ebp-3Ch]
  int v40; // [esp+34h] [ebp-38h]
  __int16 v41; // [esp+38h] [ebp-34h]
  __int16 v42; // [esp+3Ch] [ebp-30h]
  __int16 v43; // [esp+40h] [ebp-2Ch]
  int v44; // [esp+44h] [ebp-28h]
  _DWORD *v45; // [esp+48h] [ebp-24h]
  __int16 v46; // [esp+4Ch] [ebp-20h]
  __int16 v47; // [esp+50h] [ebp-1Ch]
  __int16 v48; // [esp+54h] [ebp-18h]
  int v49; // [esp+58h] [ebp-14h]
  _BYTE *v50; // [esp+5Ch] [ebp-10h]
  int v51; // [esp+64h] [ebp-8h]
  int v52; // [esp+68h] [ebp-4h]
  int v53; // [esp+80h] [ebp+14h]
  int v54; // [esp+80h] [ebp+14h]
  __int16 v55; // [esp+80h] [ebp+14h]
  __int16 v56; // [esp+80h] [ebp+14h]
  __int16 v57; // [esp+80h] [ebp+14h]

  v4 = a1[105];
  v49 = a1[71];
  v36 = *(_DWORD *)(v4 + 24);
  v5 = a1[23];
  v6 = (int *)a1[29];
  v44 = *(_DWORD *)(v4 + 40);
  v34 = *v6;
  v7 = v6[1];
  v32 = v6[2];
  result = a4;
  v31 = v4;
  v38 = v5;
  v33 = v7;
  if ( a4 > 0 )
  {
    v9 = a2 - (_DWORD)a3;
    v45 = a3;
    v37 = a4;
    while ( 1 )
    {
      v10 = *(unsigned __int8 **)((char *)v45 + v9);
      v11 = (_BYTE *)*v45;
      v51 = (int)v10;
      v50 = (_BYTE *)*v45;
      if ( *(_BYTE *)(v4 + 36) )
      {
        v40 = -1;
        *(_BYTE *)(v4 + 36) = 0;
        v51 = (int)&v10[2 * v5 - 3 + v5];
        v50 = &v11[v5 - 1];
        v12 = (_WORD *)(*(_DWORD *)(v4 + 32) + 2 * (3 * v5 + 3));
        v10 = (unsigned __int8 *)v51;
        v52 = -3;
      }
      else
      {
        v12 = *(_WORD **)(v4 + 32);
        v40 = 1;
        v52 = 3;
        *(_BYTE *)(v4 + 36) = 1;
      }
      v5 = v38;
      v13 = 0;
      v46 = 0;
      v47 = 0;
      v48 = 0;
      v14 = 0;
      v53 = 0;
      v41 = 0;
      v42 = 0;
      v43 = 0;
      if ( v38 )
      {
        v39 = v38;
        while ( 1 )
        {
          v15 = *(unsigned __int8 *)(*v10 + *(_DWORD *)(v44 + 4 * (((__int16)v12[v52] + v14 + 8) >> 4)) + v49);
          v16 = *(unsigned __int8 *)(v10[1] + *(_DWORD *)(v44 + 4 * (((__int16)v12[v52 + 1] + v13 + 8) >> 4)) + v49);
          v54 = *(unsigned __int8 *)(v10[2] + *(_DWORD *)(v44 + 4 * (((__int16)v12[v52 + 2] + v53 + 8) >> 4)) + v49);
          v17 = (_WORD *)(*(_DWORD *)(v36 + 4 * (v15 >> 3)) + 2 * ((v54 >> 3) + 32 * (v16 >> 2)));
          v35 = v17;
          if ( !*v17 )
          {
            BitstreamTextureBlockCopy(v16 >> 2, (int)a1, v15 >> 3, v54 >> 3);
            v17 = v35;
          }
          v18 = (unsigned __int16)*v17 - 1;
          *v50 = v18;
          v19 = v15 - *(unsigned __int8 *)(v18 + v34);
          v20 = v16 - *(unsigned __int8 *)(v18 + v33);
          v21 = v54 - *(unsigned __int8 *)(v18 + v32);
          v55 = v19;
          v22 = 2 * v19;
          v19 *= 3;
          *v12 = v19 + v48;
          v23 = v22 + v19;
          v48 = v23 + v43;
          v43 = v55;
          v14 = v22 + v23;
          v56 = v20;
          v24 = 2 * v20;
          v20 *= 3;
          v12[1] = v20 + v47;
          v25 = v24 + v20;
          v47 = v25 + v42;
          v26 = v56;
          v57 = v21;
          v42 = v26;
          v13 = v24 + v25;
          v27 = 2 * v21;
          v21 *= 3;
          v12[2] = v21 + v46;
          v12 += v52;
          v28 = v27 + v21;
          v46 = v28 + v41;
          v29 = v57;
          v53 = v27 + v28;
          v51 += v52;
          v50 += v40;
          v30 = v39-- == 1;
          v41 = v29;
          if ( v30 )
            break;
          v10 = (unsigned __int8 *)v51;
        }
        v4 = v31;
        v5 = v38;
      }
      ++v45;
      v30 = v37-- == 1;
      *v12 = v48;
      v12[1] = v47;
      result = v46;
      v12[2] = v46;
      if ( v30 )
        break;
      v9 = a2 - (_DWORD)a3;
    }
  }
  return result;
}

