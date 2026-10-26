int __thiscall sub_5A3CC0(int this)
{
  _DWORD *v2; // ebx
  _DWORD *v3; // eax
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  _DWORD *v7; // ecx
  int v8; // edx
  int v9; // ebp
  int v10; // edi
  int *v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  _BYTE *v18; // edi
  int v19; // ecx
  int v20; // ebp
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  _DWORD *v24; // ebx
  int v25; // eax
  bool v26; // cc
  int v27; // ecx
  int v28; // ecx
  int v29; // eax
  int v31; // [esp+10h] [ebp-14h]
  _DWORD *v32; // [esp+14h] [ebp-10h]
  int v33; // [esp+18h] [ebp-Ch]
  int v34; // [esp+1Ch] [ebp-8h]
  int v35; // [esp+20h] [ebp-4h]

  v2 = (_DWORD *)sub_59FD80(*(void **)(this + 180), *(_DWORD *)(*(_DWORD *)(this + 180) + 56), 0);
  v3 = *(_DWORD **)(this + 180);
  v34 = v3[8];
  v4 = (int)v3[10] >> 2;
  v5 = v3[7] + v4 * (v34 - 2);
  v6 = v2[v5 - 1];
  v7 = &v2[v5 - 2];
  *(_DWORD *)(this + 104) = v6;
  *(_DWORD *)(this + 108) = *v7;
  *(_DWORD *)(this + 112) = *(v7 - 1);
  v32 = v2;
  v8 = 1;
  do
  {
    v33 = *(_DWORD *)((char *)&v2[v8] + v3[10]);
    v9 = *(_DWORD *)(this + 104);
    ++v8;
  }
  while ( v33 != v9 );
  *(_DWORD *)(this + 116) = v8 - 1;
  v10 = v4;
  v11 = &v2[v10 + 1];
  *(_DWORD *)(this + 132) = v3[7] / (v8 - 1);
  v12 = 1;
  do
  {
    v13 = *v11;
    ++v12;
    v11 = (int *)((char *)v11 + v10 * 4);
  }
  while ( v13 != v9 );
  v14 = v12 - 1;
  v15 = v34 / (v12 - 1);
  *(_DWORD *)(this + 120) = v14;
  v16 = v15 * *(_DWORD *)(this + 132);
  *(_DWORD *)(this + 136) = v15;
  *(_DWORD *)(this + 140) = v16 + 32;
  v17 = 0;
  v35 = v16;
  v31 = 0;
  if ( v16 > 0 )
  {
    v18 = (_BYTE *)(this + 189);
    do
    {
      v19 = *(_DWORD *)(this + 132);
      v20 = *(_DWORD *)(this + 112);
      v21 = v17 / v19 * *(_DWORD *)(this + 120);
      v22 = v17 % v19 * *(_DWORD *)(this + 116) + 1;
      v23 = v21 + 1;
      v24 = (_DWORD *)((char *)&v2[v22] + v23 * *(_DWORD *)(*(_DWORD *)(this + 180) + 40));
      v25 = 0;
      if ( *v24 == v20 )
      {
LABEL_10:
        LOBYTE(v25) = v25 + 1;
      }
      else
      {
        while ( ++v25 < *(_DWORD *)(this + 116) )
        {
          if ( v24[v25] == v20 )
            goto LABEL_10;
        }
      }
      *(v18 - 1) = v25 - 1;
      *v18 = *(_BYTE *)(this + 120) - 1;
      *(_WORD *)(v18 - 5) = v22;
      *(_WORD *)(v18 - 3) = v23;
      v2 = v32;
      v17 = v31 + 1;
      v18 += 16;
      v26 = ++v31 < v35;
      *(float *)(v18 - 13) = (double)v22 / (double)*(int *)(*(_DWORD *)(this + 180) + 28);
      *(float *)(v18 - 9) = (double)v23 / (double)*(int *)(*(_DWORD *)(this + 180) + 32);
    }
    while ( v26 );
  }
  v27 = *(_DWORD *)(this + 180);
  if ( *(_DWORD *)(v27 + 28) * *(_DWORD *)(v27 + 32) > 0 )
  {
    v28 = *(_DWORD *)(v27 + 28) * *(_DWORD *)(v27 + 32);
    do
    {
      v29 = *v2;
      if ( *v2 == *(_DWORD *)(this + 112) || v29 == *(_DWORD *)(this + 104) || v29 == *(_DWORD *)(this + 108) )
      {
        *v2 = 15790320;
        *(_DWORD *)(*(_DWORD *)(this + 180) + 56) |= 0x800u;
      }
      ++v2;
      --v28;
    }
    while ( v28 );
  }
  *(_DWORD *)(this + 108) = 15790320;
  return sub_59FDA0(*(void **)(this + 180), *(_DWORD *)(*(_DWORD *)(this + 180) + 56), 0);
}
