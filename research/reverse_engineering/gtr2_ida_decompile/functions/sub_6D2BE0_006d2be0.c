unsigned __int8 *__stdcall sub_6D2BE0(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  _DWORD *v5; // eax
  unsigned __int8 *result; // eax
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // ecx
  unsigned __int8 **v11; // edx
  int v12; // esi
  int v13; // edi
  _BYTE *v14; // ecx
  int v15; // edx
  int v16; // esi
  int v17; // edx
  int v18; // esi
  int v19; // esi
  int v20; // edi
  unsigned __int8 **v21; // [esp+4h] [ebp-60h]
  int v22; // [esp+8h] [ebp-5Ch]
  int v23; // [esp+Ch] [ebp-58h]
  int v24; // [esp+14h] [ebp-50h]
  int v25; // [esp+18h] [ebp-4Ch]
  int v26; // [esp+1Ch] [ebp-48h]
  int v27; // [esp+20h] [ebp-44h]
  int v28; // [esp+24h] [ebp-40h]
  int v29; // [esp+28h] [ebp-3Ch]
  int v30; // [esp+2Ch] [ebp-38h]
  int v31; // [esp+30h] [ebp-34h]
  int v32; // [esp+34h] [ebp-30h]
  int v33; // [esp+38h] [ebp-2Ch]
  int v34; // [esp+3Ch] [ebp-28h]
  int v35; // [esp+40h] [ebp-24h]
  int v36; // [esp+44h] [ebp-20h]
  int v37; // [esp+48h] [ebp-1Ch]
  int v38; // [esp+4Ch] [ebp-18h]
  int v39; // [esp+50h] [ebp-14h]
  int v40; // [esp+54h] [ebp-10h]
  int v41; // [esp+58h] [ebp-Ch]
  int v42; // [esp+5Ch] [ebp-8h]
  int v43; // [esp+60h] [ebp-4h]
  unsigned __int8 *v44; // [esp+6Ch] [ebp+8h]
  int v45; // [esp+70h] [ebp+Ch]
  int v46; // [esp+74h] [ebp+10h]
  int v47; // [esp+7Ch] [ebp+18h]
  int v48; // [esp+7Ch] [ebp+18h]

  v5 = (_DWORD *)a1[115];
  v31 = v5[6];
  v30 = v5[7];
  v25 = v5[8];
  v23 = v5[9];
  v29 = v5[10];
  v27 = v5[11];
  v22 = v5[12];
  v28 = v5[13];
  v26 = v5[14];
  v24 = v5[15];
  v36 = v5[2];
  v33 = v5[3];
  v34 = v5[4];
  v35 = v5[5];
  result = (unsigned __int8 *)a1[82];
  v39 = a1[28];
  v44 = result;
  if ( a5 - 1 >= 0 )
  {
    v7 = a2[1];
    v8 = *a2 - v7;
    v9 = a2[2] - v7;
    v10 = a2[3] - v7;
    v11 = (unsigned __int8 **)(v7 + 4 * a3);
    v42 = v8;
    v40 = v9;
    v41 = v10;
    v43 = a5;
    while ( 1 )
    {
      v12 = *(int *)((char *)v11 + v9);
      result = *v11;
      v13 = *(int *)((char *)v11 + v8);
      v47 = *(int *)((char *)v11 + v10);
      v14 = *a4++;
      v21 = ++v11;
      if ( v39 )
      {
        v15 = v13 - (_DWORD)result;
        v16 = v12 - (_DWORD)result;
        v37 = v13 - (_DWORD)result;
        v38 = v16;
        v32 = v47 - (_DWORD)result;
        v46 = v39;
        while ( 1 )
        {
          v17 = result[v15];
          v18 = result[v16];
          v45 = v44[v17 + *(_DWORD *)(v36 + 4 * v18)];
          v19 = v44[v17 + ((*(_DWORD *)(v34 + 4 * v18) + *(_DWORD *)(v35 + 4 * *result)) >> 16)];
          v20 = v44[v17 + *(_DWORD *)(v33 + 4 * *result)];
          v48 = *(_DWORD *)(v31 + 4 * (255 - result[v32]));
          *v14 = (*(_DWORD *)(v28 + 4 * v20)
                * ((*(_DWORD *)(v29 + 4 * v19) * ((unsigned int)(v48 * *(_DWORD *)(v30 + 4 * v45)) >> 16)) >> 16)) >> 24;
          v14[1] = (*(_DWORD *)(v25 + 4 * v45)
                  * ((*(_DWORD *)(v26 + 4 * v20) * ((unsigned int)(v48 * *(_DWORD *)(v27 + 4 * v19)) >> 16)) >> 16)) >> 24;
          v14[2] = (*(_DWORD *)(v22 + 4 * v19)
                  * ((*(_DWORD *)(v23 + 4 * v45) * ((unsigned int)(v48 * *(_DWORD *)(v24 + 4 * v20)) >> 16)) >> 16)) >> 24;
          v14 += 3;
          ++result;
          if ( !--v46 )
            break;
          v16 = v38;
          v15 = v37;
        }
        v11 = v21;
      }
      if ( !--v43 )
        break;
      v8 = v42;
      v10 = v41;
      v9 = v40;
    }
  }
  return result;
}
