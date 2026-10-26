int __thiscall sub_552BA0(int this)
{
  int *v2; // ecx
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
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edx
  char *v23; // ebx
  int v24; // ebp
  char *v25; // edi
  int v26; // ebx
  int v27; // eax
  int v28; // ecx
  int v29; // edi
  int v30; // ecx
  int v32; // [esp+10h] [ebp-14h]
  int v33; // [esp+14h] [ebp-10h]
  _BYTE *v34; // [esp+14h] [ebp-10h]
  _WORD *v35; // [esp+18h] [ebp-Ch]
  int v36; // [esp+1Ch] [ebp-8h]
  int v37; // [esp+20h] [ebp-4h]
  int v38; // [esp+20h] [ebp-4h]

  v2 = *(int **)(this + 100);
  v36 = v2[12] != 5 ? 0 : 0x8000;
  v3 = (_WORD *)sub_543210(v2, v2[6], 0);
  v4 = *(_DWORD **)(this + 100);
  v37 = v4[8];
  v5 = (int)v4[10] >> 1;
  v6 = v4[7] + v5 * (v37 - 2);
  v7 = (unsigned __int16)v3[v6 - 1];
  v8 = &v3[v6 - 2];
  *(_DWORD *)(this + 40) = v7;
  *(_DWORD *)(this + 44) = *v8;
  *(_DWORD *)(this + 48) = *(v8 - 1);
  v35 = v3;
  v9 = 1;
  do
  {
    v33 = *(unsigned __int16 *)((char *)&v3[v9] + v4[10]);
    v10 = *(_DWORD *)(this + 40);
    ++v9;
  }
  while ( v33 != v10 );
  *(_DWORD *)(this + 52) = v9 - 1;
  v11 = v5;
  v12 = &v3[v11 + 1];
  *(_DWORD *)(this + 60) = v4[7] / (v9 - 1);
  v13 = 1;
  do
  {
    v14 = *v12;
    ++v13;
    v12 = (unsigned __int16 *)((char *)v12 + v11 * 2);
  }
  while ( v14 != v10 );
  v15 = v13 - 1;
  v16 = v37 / (v13 - 1);
  *(_DWORD *)(this + 56) = v15;
  v17 = v16 * *(_DWORD *)(this + 60);
  *(_DWORD *)(this + 64) = v16;
  *(_DWORD *)(this + 68) = v17 + 32;
  v18 = 0;
  v38 = v17;
  v32 = 0;
  if ( v17 > 0 )
  {
    v34 = (_BYTE *)(this + 109);
    do
    {
      v19 = *(_DWORD *)(this + 60);
      v20 = v18 / v19 * *(_DWORD *)(this + 56);
      v21 = v18 % v19 * *(_DWORD *)(this + 52) + 1;
      v22 = v20 + 1;
      v23 = (char *)v3 + v22 * *(_DWORD *)(*(_DWORD *)(this + 100) + 40);
      v24 = *(unsigned __int16 *)&v23[2 * v21];
      v25 = &v23[2 * v21];
      v26 = *(_DWORD *)(this + 48);
      v27 = 0;
      if ( v24 == v26 )
      {
LABEL_10:
        LOBYTE(v27) = v27 + 1;
      }
      else
      {
        while ( ++v27 < *(_DWORD *)(this + 52) )
        {
          if ( *(unsigned __int16 *)&v25[2 * v27] == v26 )
            goto LABEL_10;
        }
      }
      v3 = v35;
      *(v34 - 1) = v27 - 1;
      *v34 = *(_BYTE *)(this + 56) - 1;
      *(_WORD *)(v34 - 5) = v21;
      v18 = v32 + 1;
      *(_WORD *)(v34 - 3) = v22;
      v32 = v18;
      v34 += 8;
    }
    while ( v18 < v38 );
  }
  v28 = *(_DWORD *)(this + 100);
  if ( *(_DWORD *)(v28 + 28) * *(_DWORD *)(v28 + 32) > 0 )
  {
    v29 = *(_DWORD *)(v28 + 28) * *(_DWORD *)(v28 + 32);
    do
    {
      v30 = (unsigned __int16)*v3;
      if ( v30 == *(_DWORD *)(this + 48) || v30 == *(_DWORD *)(this + 40) || v30 == *(_DWORD *)(this + 44) )
      {
        *v3 = *(_WORD *)(this + 44) & ~(_WORD)v36;
        *(_DWORD *)(*(_DWORD *)(this + 100) + 24) |= 0x800u;
      }
      else
      {
        *v3 |= v36;
      }
      ++v3;
      --v29;
    }
    while ( v29 );
  }
  *(_DWORD *)(this + 44) &= ~v36;
  return sub_543230(*(void **)(this + 100), *(_DWORD *)(*(_DWORD *)(this + 100) + 24), 0);
}
