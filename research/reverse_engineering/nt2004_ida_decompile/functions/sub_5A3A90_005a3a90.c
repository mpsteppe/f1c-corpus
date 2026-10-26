int __thiscall sub_5A3A90(int this)
{
  _DWORD *v2; // ecx
  _WORD *v3; // ebx
  _DWORD *v4; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // edx
  unsigned __int16 *v8; // ecx
  int v9; // edx
  int v10; // ebp
  int v11; // edi
  unsigned __int16 *v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  _BYTE *v19; // edi
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  unsigned __int16 *v24; // ebp
  int v25; // ebx
  int v26; // eax
  bool v27; // cc
  int v28; // ecx
  int v29; // edi
  int v30; // ecx
  int v32; // [esp+10h] [ebp-1Ch]
  _WORD *v33; // [esp+14h] [ebp-18h]
  int v34; // [esp+18h] [ebp-14h]
  int v35; // [esp+1Ch] [ebp-10h]
  int v36; // [esp+20h] [ebp-Ch]
  int v37; // [esp+28h] [ebp-4h]

  v2 = *(_DWORD **)(this + 180);
  v34 = v2[12] != 5 ? 0 : 0x8000;
  v3 = (_WORD *)sub_59FD80(v2, v2[14], 0);
  v4 = *(_DWORD **)(this + 180);
  v36 = v4[8];
  v5 = (int)v4[10] >> 1;
  v6 = v4[7] + v5 * (v36 - 2);
  v7 = (unsigned __int16)v3[v6 - 1];
  v8 = &v3[v6 - 2];
  *(_DWORD *)(this + 104) = v7;
  *(_DWORD *)(this + 108) = *v8;
  *(_DWORD *)(this + 112) = *(v8 - 1);
  v33 = v3;
  v9 = 1;
  do
  {
    v35 = *(unsigned __int16 *)((char *)&v3[v9] + v4[10]);
    v10 = *(_DWORD *)(this + 104);
    ++v9;
  }
  while ( v35 != v10 );
  *(_DWORD *)(this + 116) = v9 - 1;
  v11 = v5;
  v12 = &v3[v11 + 1];
  *(_DWORD *)(this + 132) = v4[7] / (v9 - 1);
  v13 = 1;
  do
  {
    v14 = *v12;
    ++v13;
    v12 = (unsigned __int16 *)((char *)v12 + v11 * 2);
  }
  while ( v14 != v10 );
  v15 = v13 - 1;
  v16 = v36 / (v13 - 1);
  *(_DWORD *)(this + 120) = v15;
  v17 = v16 * *(_DWORD *)(this + 132);
  *(_DWORD *)(this + 136) = v16;
  *(_DWORD *)(this + 140) = v17 + 32;
  v18 = 0;
  v37 = v17;
  v32 = 0;
  if ( v17 > 0 )
  {
    v19 = (_BYTE *)(this + 189);
    do
    {
      v20 = *(_DWORD *)(this + 132);
      v21 = v18 / v20 * *(_DWORD *)(this + 120);
      v22 = v18 % v20 * *(_DWORD *)(this + 116) + 1;
      v23 = v21 + 1;
      v24 = (_WORD *)((char *)&v3[v22] + v23 * *(_DWORD *)(*(_DWORD *)(this + 180) + 40));
      v25 = *(_DWORD *)(this + 112);
      v26 = 0;
      if ( *v24 == v25 )
      {
LABEL_10:
        LOBYTE(v26) = v26 + 1;
      }
      else
      {
        while ( ++v26 < *(_DWORD *)(this + 116) )
        {
          if ( v24[v26] == v25 )
            goto LABEL_10;
        }
      }
      *(v19 - 1) = v26 - 1;
      *v19 = *(_BYTE *)(this + 120) - 1;
      *(_WORD *)(v19 - 5) = v22;
      *(_WORD *)(v19 - 3) = v23;
      v3 = v33;
      v18 = v32 + 1;
      v19 += 16;
      v27 = ++v32 < v37;
      *(float *)(v19 - 13) = (double)v22 / (double)*(int *)(*(_DWORD *)(this + 180) + 28);
      *(float *)(v19 - 9) = (double)v23 / (double)*(int *)(*(_DWORD *)(this + 180) + 32);
    }
    while ( v27 );
  }
  v28 = *(_DWORD *)(this + 180);
  if ( *(_DWORD *)(v28 + 28) * *(_DWORD *)(v28 + 32) > 0 )
  {
    v29 = *(_DWORD *)(v28 + 28) * *(_DWORD *)(v28 + 32);
    do
    {
      v30 = (unsigned __int16)*v3;
      if ( v30 == *(_DWORD *)(this + 112) || v30 == *(_DWORD *)(this + 104) || v30 == *(_DWORD *)(this + 108) )
      {
        *v3 = *(_WORD *)(this + 108) & ~(_WORD)v34;
        *(_DWORD *)(*(_DWORD *)(this + 180) + 56) |= 0x800u;
      }
      else
      {
        *v3 |= v34;
      }
      ++v3;
      --v29;
    }
    while ( v29 );
  }
  *(_DWORD *)(this + 108) &= ~v34;
  return sub_59FDA0(*(void **)(this + 180), *(_DWORD *)(*(_DWORD *)(this + 180) + 56), 0);
}
