unsigned __int8 **__stdcall sub_6D2A30(int a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  _DWORD *v5; // eax
  int v6; // edx
  unsigned __int8 **result; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // ebx
  int v11; // edx
  int v12; // ebx
  int v13; // ecx
  unsigned __int8 *v14; // edi
  int v15; // eax
  int v16; // edx
  int v17; // ebx
  int v18; // eax
  int v19; // ecx
  int v20; // esi
  unsigned __int8 **v21; // [esp+4h] [ebp-48h]
  int v22; // [esp+8h] [ebp-44h]
  int v23; // [esp+Ch] [ebp-40h]
  unsigned __int8 **v24; // [esp+10h] [ebp-3Ch]
  int v25; // [esp+14h] [ebp-38h]
  int v26; // [esp+18h] [ebp-34h]
  int v27; // [esp+1Ch] [ebp-30h]
  int v28; // [esp+20h] [ebp-2Ch]
  int v29; // [esp+24h] [ebp-28h]
  int v30; // [esp+28h] [ebp-24h]
  int v31; // [esp+2Ch] [ebp-20h]
  int v32; // [esp+30h] [ebp-1Ch]
  int v33; // [esp+34h] [ebp-18h]
  int v34; // [esp+38h] [ebp-14h]
  int v35; // [esp+3Ch] [ebp-10h]
  int v36; // [esp+40h] [ebp-Ch]
  int v37; // [esp+44h] [ebp-8h]
  int v38; // [esp+48h] [ebp-4h]
  _BYTE *v39; // [esp+54h] [ebp+8h]
  int v40; // [esp+58h] [ebp+Ch]
  int v41; // [esp+5Ch] [ebp+10h]
  int v42; // [esp+64h] [ebp+18h]

  v5 = *(_DWORD **)(a1 + 460);
  v31 = v5[6];
  v30 = v5[7];
  v25 = v5[8];
  v23 = v5[9];
  v29 = v5[10];
  v27 = v5[11];
  v22 = v5[12];
  v28 = v5[13];
  v6 = v5[14];
  result = (unsigned __int8 **)v5[15];
  v26 = v6;
  v24 = result;
  v35 = *(_DWORD *)(a1 + 112);
  if ( a5 - 1 >= 0 )
  {
    v8 = a2[1];
    v9 = *a2 - v8;
    v10 = a2[2] - v8;
    result = (unsigned __int8 **)(v8 + 4 * a3);
    v38 = v9;
    v37 = v10;
    v36 = a2[3] - v8;
    v41 = a5;
    while ( 1 )
    {
      v11 = *(int *)((char *)result + v10);
      v12 = *(int *)((char *)result + v36);
      v13 = *(int *)((char *)result + v9);
      v14 = *result;
      v39 = *a4++;
      v21 = ++result;
      if ( v35 )
      {
        v15 = v13 - (_DWORD)v14;
        v16 = v11 - (_DWORD)v14;
        v17 = v12 - (_DWORD)v14;
        v34 = v13 - (_DWORD)v14;
        v33 = v16;
        v32 = v17;
        v40 = v35;
        while ( 1 )
        {
          v18 = 255 - v14[v15];
          v19 = 255 - *v14;
          v20 = 255 - v14[v16];
          v42 = *(_DWORD *)(v31 + 4 * (255 - v14[v17]));
          *v39 = (*(_DWORD *)(v28 + 4 * v20)
                * ((*(_DWORD *)(v29 + 4 * v19) * ((unsigned int)(v42 * *(_DWORD *)(v30 + 4 * v18)) >> 16)) >> 16)) >> 24;
          v39[1] = (*(_DWORD *)(v25 + 4 * v18)
                  * ((*(_DWORD *)(v26 + 4 * v20) * ((unsigned int)(v42 * *(_DWORD *)(v27 + 4 * v19)) >> 16)) >> 16)) >> 24;
          v39[2] = (*(_DWORD *)(v22 + 4 * v19)
                  * ((*(_DWORD *)(v23 + 4 * v18) * ((unsigned int)(v42 * (_DWORD)v24[v20]) >> 16)) >> 16)) >> 24;
          ++v14;
          v39 += 3;
          if ( !--v40 )
            break;
          v15 = v34;
          v16 = v33;
          v17 = v32;
        }
        result = v21;
      }
      if ( !--v41 )
        break;
      v9 = v38;
      v10 = v37;
    }
  }
  return result;
}
