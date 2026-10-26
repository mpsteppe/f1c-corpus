// f1c  0x0051d897  size=384
int __usercall sub_51D897@<eax>(int a1@<eax>, int a2@<edi>, int a3, int a4, int a5)
{
  int v5; // edx
  int v6; // ebx
  int *v7; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // ecx
  int v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // edx
  int v20; // eax
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  bool v24; // cc
  int v25; // ecx
  int result; // eax
  _DWORD v27[256]; // [esp+8h] [ebp-428h]
  int v28; // [esp+408h] [ebp-28h]
  int v29; // [esp+40Ch] [ebp-24h]
  int v30; // [esp+410h] [ebp-20h]
  int v31; // [esp+414h] [ebp-1Ch]
  int v32; // [esp+418h] [ebp-18h]
  int v33; // [esp+41Ch] [ebp-14h]
  int v34; // [esp+420h] [ebp-10h]
  int v35; // [esp+424h] [ebp-Ch]
  int v36; // [esp+428h] [ebp-8h]
  int v37; // [esp+42Ch] [ebp-4h]

  v5 = a3;
  v37 = 0;
  v32 = (2 * a3 + 24) >> 1;
  v6 = a4;
  v30 = (2 * a2 + 28) >> 1;
  v35 = *(_DWORD *)(a1 + 112);
  v29 = (2 * a4 + 24) >> 1;
  v36 = 0x7FFFFFFF;
  if ( v35 > 0 )
  {
    v7 = *(int **)(a1 + 116);
    v28 = *v7;
    v8 = v7[1];
    v9 = v7[2];
    v34 = v8;
    v33 = v9;
    do
    {
      v10 = *(unsigned __int8 *)(v28 + v37);
      v11 = v5 + 24;
      if ( v10 >= v5 )
      {
        if ( v10 > v11 )
        {
          v12 = 2 * (v10 - v11) * 2 * (v10 - v11);
LABEL_7:
          v13 = v10 - v5;
          goto LABEL_8;
        }
        v12 = 0;
        if ( v10 > v32 )
          goto LABEL_7;
      }
      else
      {
        v12 = 2 * (v10 - v5) * 2 * (v10 - v5);
      }
      v13 = v10 - v11;
LABEL_8:
      v14 = 2 * v13 * 2 * v13;
      v15 = *(unsigned __int8 *)(v34 + v37);
      if ( v15 < a2 )
      {
        v12 += 3 * (v15 - a2) * 3 * (v15 - a2);
        v6 = a4;
        v16 = v15 - (a2 + 28);
        goto LABEL_15;
      }
      if ( v15 > a2 + 28 )
      {
        v12 += 3 * (v15 - (a2 + 28)) * 3 * (v15 - (a2 + 28));
        v6 = a4;
LABEL_14:
        v16 = v15 - a2;
        goto LABEL_15;
      }
      if ( v15 > v30 )
        goto LABEL_14;
      v16 = v15 - (a2 + 28);
LABEL_15:
      v17 = 3 * v16 * 3 * v16 + v14;
      v18 = *(unsigned __int8 *)(v33 + v37);
      if ( v18 < v6 )
      {
        v12 += (v18 - v6) * (v18 - v6);
        v6 = a4;
        v19 = a4 + 24;
LABEL_31:
        v20 = v18 - v19;
        goto LABEL_22;
      }
      v19 = v6 + 24;
      v31 = v6 + 24;
      if ( v18 <= v6 + 24 )
      {
        if ( v18 <= v29 )
          goto LABEL_31;
      }
      else
      {
        v12 += (v18 - v31) * (v18 - v31);
        v6 = a4;
      }
      v20 = v18 - v6;
LABEL_22:
      v21 = v20 * v20;
      v22 = v37;
      v23 = v21 + v17;
      v24 = v23 < v36;
      v5 = a3;
      v27[v37] = v12;
      if ( v24 )
        v36 = v23;
      v37 = v22 + 1;
    }
    while ( v22 + 1 < v35 );
  }
  v25 = 0;
  for ( result = 0; v25 < v35; ++v25 )
  {
    if ( v27[v25] <= v36 )
    {
      *(_BYTE *)(result + a5) = v25;
      ++result;
    }
  }
  return result;
}
