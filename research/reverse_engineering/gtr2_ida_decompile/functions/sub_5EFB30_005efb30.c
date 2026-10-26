int __thiscall sub_5EFB30(int this)
{
  _DWORD *v2; // ecx
  _WORD *v3; // ebx
  _DWORD *v4; // eax
  int v5; // edi
  int v6; // ecx
  int v7; // edx
  unsigned __int16 *v8; // ecx
  int i; // edx
  int v10; // ebp
  int v11; // edi
  unsigned __int16 *v12; // ecx
  int v13; // eax
  int v14; // edx
  int v15; // ecx
  int v16; // eax
  int v17; // ecx
  int v18; // eax
  int v19; // edi
  int v20; // ecx
  int v21; // edx
  int v22; // ecx
  int v23; // edx
  char *v24; // eax
  int v25; // ebp
  char *v26; // ebx
  int v27; // eax
  unsigned __int8 v28; // al
  char v29; // bl
  int v30; // eax
  double v31; // st7
  int v32; // ecx
  int v33; // edi
  int v34; // ecx
  int v36; // [esp+10h] [ebp-18h]
  _WORD *v37; // [esp+14h] [ebp-14h]
  int v38; // [esp+18h] [ebp-10h]
  int v39; // [esp+20h] [ebp-8h]
  int v40; // [esp+20h] [ebp-8h]
  int v41; // [esp+20h] [ebp-8h]
  int v42; // [esp+24h] [ebp-4h]

  v2 = *(_DWORD **)(this + 172);
  v38 = v2[6] != 5 ? 0 : 0x8000;
  v3 = (_WORD *)sub_5E6E70(v2, *v2, 0, 2);
  v4 = *(_DWORD **)(this + 172);
  v39 = v4[2];
  v5 = (int)v4[4] >> 1;
  v6 = v4[1] + v5 * (v39 - 2);
  v7 = (unsigned __int16)v3[v6 - 1];
  v8 = &v3[v6 - 2];
  *(_DWORD *)(this + 88) = v7;
  *(_DWORD *)(this + 92) = *v8;
  *(_DWORD *)(this + 96) = *(v8 - 1);
  v37 = v3;
  for ( i = 1; ; ++i )
  {
    v10 = *(_DWORD *)(this + 88);
    if ( *(unsigned __int16 *)((char *)&v3[i] + v4[4]) == v10 )
      break;
  }
  *(_DWORD *)(this + 100) = i;
  v11 = v5;
  v12 = &v3[v11 + 1];
  *(_DWORD *)(this + 116) = v4[1] / i;
  v13 = 1;
  do
  {
    v14 = *v12;
    ++v13;
    v12 = (unsigned __int16 *)((char *)v12 + v11 * 2);
  }
  while ( v14 != v10 );
  v15 = v13 - 1;
  v16 = v39 / (v13 - 1);
  *(_DWORD *)(this + 104) = v15;
  v17 = v16 * *(_DWORD *)(this + 116);
  *(_DWORD *)(this + 120) = v16;
  *(_DWORD *)(this + 124) = v17 + 32;
  v18 = 0;
  v42 = v17;
  v36 = 0;
  if ( v17 > 0 )
  {
    v19 = this + 184;
    do
    {
      v20 = *(_DWORD *)(this + 116);
      v21 = v18 / v20 * *(_DWORD *)(this + 104);
      v22 = v18 % v20 * *(_DWORD *)(this + 100) + 1;
      v23 = v21 + 1;
      v24 = (char *)v3 + v23 * *(_DWORD *)(*(_DWORD *)(this + 172) + 16);
      v25 = *(unsigned __int16 *)&v24[2 * v22];
      v26 = &v24[2 * v22];
      v27 = 0;
      if ( v25 == *(_DWORD *)(this + 96) )
      {
LABEL_11:
        LOBYTE(v27) = v27 + 1;
      }
      else
      {
        while ( ++v27 < *(_DWORD *)(this + 100) )
        {
          if ( *(unsigned __int16 *)&v26[2 * v27] == *(_DWORD *)(this + 96) )
            goto LABEL_11;
        }
      }
      v28 = v27 - 1;
      *(_BYTE *)(v19 + 4) = v28;
      v29 = *(_BYTE *)(this + 104);
      *(_WORD *)v19 = v22;
      *(_WORD *)(v19 + 2) = v23;
      *(_BYTE *)(v19 + 5) = v29 - 1;
      v40 = v22 + v28;
      v30 = v23 + *(unsigned __int8 *)(v19 + 5);
      v19 += 24;
      *(float *)(v19 - 16) = (double)v22 / (double)*(int *)(*(_DWORD *)(this + 172) + 4);
      v3 = v37;
      *(float *)(v19 - 12) = (double)v23 / (double)*(int *)(*(_DWORD *)(this + 172) + 8);
      v31 = (double)v40;
      v41 = v30;
      v18 = ++v36;
      *(float *)(v19 - 8) = v31 / (double)*(int *)(*(_DWORD *)(this + 172) + 4);
      *(float *)(v19 - 4) = (double)v41 / (double)*(int *)(*(_DWORD *)(this + 172) + 8);
    }
    while ( v36 < v42 );
  }
  v32 = *(_DWORD *)(this + 172);
  if ( *(_DWORD *)(v32 + 4) * *(_DWORD *)(v32 + 8) > 0 )
  {
    v33 = *(_DWORD *)(v32 + 4) * *(_DWORD *)(v32 + 8);
    do
    {
      v34 = (unsigned __int16)*v3;
      if ( v34 == *(_DWORD *)(this + 96) || v34 == *(_DWORD *)(this + 88) || v34 == *(_DWORD *)(this + 92) )
      {
        *v3 = *(_WORD *)(this + 92) & ~(_WORD)v38;
        **(_DWORD **)(this + 172) |= 0x200u;
      }
      else
      {
        *v3 |= v38;
      }
      ++v3;
      --v33;
    }
    while ( v33 );
  }
  *(_DWORD *)(this + 92) &= ~v38;
  return sub_5E6EA0(*(void **)(this + 172), **(_DWORD **)(this + 172), 0, 2);
}
