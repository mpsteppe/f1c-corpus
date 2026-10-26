// f1c  0x00503a70  size=292
int __fastcall sub_503A70(_DWORD *a1)
{
  int v1; // eax
  int v2; // ebx
  unsigned __int16 *v3; // esi
  unsigned __int16 *v4; // edx
  unsigned __int16 *v5; // ebx
  unsigned __int16 *v6; // ebp
  int v7; // edx
  int v8; // eax
  int v9; // ebx
  unsigned int v10; // ebp
  int v11; // eax
  _WORD *v12; // eax
  _WORD *v14; // [esp+8h] [ebp-20h]
  _WORD *v15; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 *v16; // [esp+10h] [ebp-18h]
  unsigned __int16 *v17; // [esp+14h] [ebp-14h]
  int v18; // [esp+18h] [ebp-10h]
  unsigned __int16 *v19; // [esp+1Ch] [ebp-Ch]
  _DWORD *v20; // [esp+20h] [ebp-8h]
  unsigned __int16 *i; // [esp+24h] [ebp-4h]

  v15 = *(_WORD **)(a1[1] + 24);
  v1 = *a1;
  v2 = *(_DWORD *)(*a1 + 4176);
  v3 = *(unsigned __int16 **)(*a1 + 24);
  v4 = (unsigned __int16 *)((char *)v3 + v2 * *(_DWORD *)(*a1 + 4188));
  v20 = a1;
  for ( i = v4; v3 < v4; v3 += v2 )
  {
    v14 = v15;
    v5 = (unsigned __int16 *)((char *)v3 + v2);
    v6 = v3;
    v16 = v3;
    v17 = v5;
    v19 = &v3[*(_DWORD *)(v1 + 4184)];
    if ( v3 < v19 )
    {
      do
      {
        v7 = v6[1];
        v8 = v5[1];
        v9 = *v5;
        v18 = *v6;
        v10 = (v7 & 0xFFFF03E0) + (v9 & 0xFFFF03E0) + (v18 & 0xFFFF03E0) + (v8 & 0xFFFF03E0) + 64;
        v11 = (v9 & 0x7C1F) + (v18 & 0x7C1F) + (v8 & 0x7C1F);
        v5 = v17 + 2;
        v17 += 2;
        LOWORD(v10) = ((v11 + (v7 & 0x7C1Fu) + 2050) >> 2) & 0x7C1F | (v10 >> 2) & 0x3E0;
        v12 = v14++;
        *v12 = v10;
        v6 = v16 + 2;
        v16 += 2;
      }
      while ( v16 < v19 );
      a1 = v20;
      v4 = i;
    }
    v15 = (_WORD *)((char *)v15 + *(_DWORD *)(a1[1] + 4176));
    v1 = *a1;
    v2 = *(_DWORD *)(*a1 + 4176);
  }
  return 0;
}
