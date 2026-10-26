int __fastcall sub_503B94(_DWORD *a1)
{
  int v1; // esi
  char *v2; // edx
  int v3; // edi
  char *v4; // ebp
  char *v5; // edi
  char *v6; // ebx
  __int16 v7; // si
  __int16 v8; // dx
  __int16 v9; // di
  _WORD *v10; // ecx
  bool v11; // cf
  _WORD *v13; // [esp+Ch] [ebp-24h]
  _WORD *v14; // [esp+10h] [ebp-20h]
  char *v15; // [esp+14h] [ebp-1Ch]
  char *v16; // [esp+18h] [ebp-18h]
  char *v17; // [esp+1Ch] [ebp-14h]
  unsigned int v18; // [esp+24h] [ebp-Ch]
  _DWORD *v19; // [esp+28h] [ebp-8h]
  char *i; // [esp+2Ch] [ebp-4h]

  v1 = *a1;
  v2 = *(char **)(*a1 + 24);
  v3 = *(_DWORD *)(*a1 + 4176);
  v4 = &v2[v3 * *(_DWORD *)(*a1 + 4188)];
  v19 = a1;
  v14 = *(_WORD **)(a1[1] + 24);
  v17 = v2;
  for ( i = v4; v2 < v4; v17 = v2 )
  {
    v13 = v14;
    v5 = &v2[v3];
    v6 = v2;
    v15 = v2;
    v16 = v5;
    v18 = (unsigned int)&v2[2 * *(_DWORD *)(v1 + 4184)];
    if ( (unsigned int)v2 < v18 )
    {
      do
      {
        v7 = *((_WORD *)v6 + 1);
        v8 = *((_WORD *)v5 + 1);
        v9 = *(_WORD *)v5;
        v10 = v13++;
        *v10 = (((v9 & 0x83E0) + (*(_WORD *)v6 & 0x83E0) + (v8 & 0x83E0) + (v7 & 0x83E0u) + 65600) >> 2)
             ^ ((((v7 & 0x7C1F) + (v9 & 0x7C1F) + (*(_WORD *)v6 & 0x7C1F) + (v8 & 0x7C1Fu) + 2050) >> 2)
              ^ (((v9 & 0x83E0) + (*(_WORD *)v6 & 0x83E0) + (v8 & 0x83E0) + (v7 & 0x83E0u) + 65600) >> 2))
             & 0x7C1F;
        v6 = v15 + 4;
        v5 = v16 + 4;
        v11 = (unsigned int)(v15 + 4) < v18;
        v15 += 4;
        v16 += 4;
      }
      while ( v11 );
      a1 = v19;
      v2 = v17;
      v4 = i;
    }
    v14 = (_WORD *)((char *)v14 + *(_DWORD *)(a1[1] + 4176));
    v1 = *a1;
    v3 = *(_DWORD *)(*a1 + 4176);
    v2 += 2 * v3;
  }
  return 0;
}
