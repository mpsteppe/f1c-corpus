int __fastcall sub_540E16(_DWORD *a1)
{
  int v1; // edx
  int v2; // ebp
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // edi
  unsigned __int16 *v5; // ebp
  unsigned __int16 *v6; // ebx
  int v7; // edx
  int v8; // edi
  int v9; // eax
  int v10; // ebp
  unsigned int v11; // ebx
  int v12; // ecx
  int v13; // eax
  unsigned int v14; // edx
  int v15; // ebp
  unsigned int v16; // ecx
  int v17; // edi
  unsigned int v18; // edx
  _WORD *v19; // eax
  bool v20; // cf
  _WORD *v22; // [esp+8h] [ebp-24h]
  _WORD *v23; // [esp+Ch] [ebp-20h]
  int v24; // [esp+10h] [ebp-1Ch]
  unsigned __int16 *v25; // [esp+14h] [ebp-18h]
  unsigned __int16 *v26; // [esp+18h] [ebp-14h]
  unsigned __int16 *v27; // [esp+1Ch] [ebp-10h]
  unsigned int v28; // [esp+20h] [ebp-Ch]
  _DWORD *v29; // [esp+24h] [ebp-8h]
  unsigned __int16 *i; // [esp+28h] [ebp-4h]

  v1 = *a1;
  v2 = *(_DWORD *)(*a1 + 4176);
  v23 = *(_WORD **)(a1[1] + 24);
  v3 = *(unsigned __int16 **)(*a1 + 24);
  v4 = (unsigned __int16 *)((char *)v3 + v2 * *(_DWORD *)(*a1 + 4188));
  v29 = a1;
  v27 = v3;
  for ( i = v4; v3 < v4; v27 = v3 )
  {
    v22 = v23;
    v5 = (unsigned __int16 *)((char *)v3 + v2);
    v6 = v3;
    v25 = v3;
    v26 = v5;
    v28 = (unsigned int)&v3[*(_DWORD *)(v1 + 4184)];
    if ( (unsigned int)v3 < v28 )
    {
      do
      {
        v7 = *v6;
        v8 = v6[1];
        v9 = v5[1];
        v10 = *v5;
        v24 = v7;
        LOWORD(v7) = *v6 & 0xE3;
        v11 = (v10 & 0xFFFF00E3) + v7 + (v9 & 0xFFFF00E3);
        HIWORD(v12) = HIWORD(v9);
        v13 = v9 & 0xFF1C;
        LOWORD(v12) = v13;
        v14 = (v11 + (v8 & 0xFFFF00E3) + 66) >> 2;
        HIWORD(v11) = HIWORD(v10);
        v15 = v10 & 0xFF1C;
        LOWORD(v11) = v15;
        v16 = v11 + (v24 & 0xFFFFFF1C) + v12;
        HIWORD(v11) = HIWORD(v8);
        v17 = v8 & 0xFF1C;
        LOWORD(v11) = v17;
        LOBYTE(v14) = ((v16 + v11 + 520) >> 2) ^ v14;
        v18 = ((v15 + (v24 & 0xFF1Cu) + v13 + v17 + 520) >> 2) ^ v14 & 0xFFFF00E3;
        v19 = v22++;
        v6 = v25 + 2;
        v5 = v26 + 2;
        v20 = (unsigned int)(v25 + 2) < v28;
        *v19 = v18;
        v25 += 2;
        v26 += 2;
      }
      while ( v20 );
      a1 = v29;
      v3 = v27;
      v4 = i;
    }
    v23 = (_WORD *)((char *)v23 + *(_DWORD *)(a1[1] + 4176));
    v1 = *a1;
    v2 = *(_DWORD *)(*a1 + 4176);
    v3 += v2;
  }
  return 0;
}
