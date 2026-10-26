int __fastcall sub_50415C(_DWORD *a1)
{
  _WORD *v1; // ebp
  int v2; // eax
  unsigned __int16 *v3; // esi
  int v4; // edi
  unsigned __int16 *v5; // edx
  unsigned __int16 *v6; // edi
  unsigned __int16 *v7; // ebx
  int v8; // edx
  int v9; // eax
  int v10; // ebx
  int v11; // edi
  unsigned int v12; // ebp
  unsigned int v13; // eax
  unsigned int v14; // ebp
  _WORD *v15; // eax
  _WORD *v17; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 *v18; // [esp+10h] [ebp-18h]
  unsigned __int16 *v19; // [esp+14h] [ebp-14h]
  _WORD *v20; // [esp+18h] [ebp-10h]
  unsigned int v21; // [esp+1Ch] [ebp-Ch]
  _DWORD *v22; // [esp+20h] [ebp-8h]
  unsigned __int16 *i; // [esp+24h] [ebp-4h]

  v1 = *(_WORD **)(a1[1] + 24);
  v2 = *a1;
  v3 = *(unsigned __int16 **)(*a1 + 24);
  v4 = *(_DWORD *)(*a1 + 4176);
  v5 = (unsigned __int16 *)((char *)v3 + v4 * *(_DWORD *)(*a1 + 4188));
  v22 = a1;
  v20 = v1;
  for ( i = v5; v3 < v5; v20 = v1 )
  {
    v6 = (unsigned __int16 *)((char *)v3 + v4);
    v7 = v3;
    v17 = v1;
    v18 = v3;
    v19 = v6;
    v21 = (unsigned int)&v3[*(_DWORD *)(v2 + 4184)];
    if ( (unsigned int)v3 < v21 )
    {
      do
      {
        v8 = v7[1];
        v9 = v6[1];
        v10 = *v7;
        v11 = *v6;
        v12 = (v11 & 0xFFFF00F0) + (v10 & 0xFFFF00F0) + (v9 & 0xFFFF00F0) + (v8 & 0xFFFF00F0) + 32;
        LOWORD(v9) = v9 & 0xF0F;
        LOWORD(v10) = v10 & 0xF0F;
        LOWORD(v11) = v11 & 0xF0F;
        LOWORD(v8) = v8 & 0xF0F;
        v13 = (unsigned int)(v11 + v10 + v9 + v8 + 514) >> 2;
        LOWORD(v13) = v13 & 0xF0F;
        v7 = v18 + 2;
        v6 = v19 + 2;
        v18 = v7;
        v19 += 2;
        v14 = v13 | (v12 >> 2) & 0xFFFF00F0;
        v15 = v17++;
        *v15 = v14;
      }
      while ( (unsigned int)v7 < v21 );
      a1 = v22;
      v1 = v20;
      v5 = i;
    }
    v1 = (_WORD *)((char *)v1 + *(_DWORD *)(a1[1] + 4176));
    v2 = *a1;
    v4 = *(_DWORD *)(*a1 + 4176);
    v3 += v4;
  }
  return 0;
}
