int __fastcall sub_5411CF(_DWORD *a1)
{
  int v1; // edx
  _BYTE *v2; // ebp
  unsigned __int8 *v3; // eax
  int v4; // edi
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  int v8; // ebp
  int v9; // esi
  int v10; // eax
  int v11; // edi
  char v12; // dl
  _BYTE *v13; // eax
  bool v14; // cf
  _BYTE *v16; // [esp+Ch] [ebp-20h]
  unsigned __int8 *v17; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *v18; // [esp+14h] [ebp-18h]
  _BYTE *v19; // [esp+18h] [ebp-14h]
  unsigned __int8 *v20; // [esp+1Ch] [ebp-10h]
  unsigned int v21; // [esp+20h] [ebp-Ch]
  _DWORD *v22; // [esp+24h] [ebp-8h]
  unsigned __int8 *i; // [esp+28h] [ebp-4h]

  v1 = *a1;
  v2 = *(_BYTE **)(a1[1] + 24);
  v3 = *(unsigned __int8 **)(*a1 + 24);
  v4 = *(_DWORD *)(*a1 + 4176);
  v5 = &v3[v4 * *(_DWORD *)(*a1 + 4188)];
  v22 = a1;
  v19 = v2;
  v20 = v3;
  for ( i = v5; v3 < v5; v20 = v3 )
  {
    v6 = &v3[v4];
    v7 = v3;
    v16 = v2;
    v17 = v3;
    v18 = v6;
    v21 = (unsigned int)&v3[*(_DWORD *)(v1 + 4184)];
    if ( (unsigned int)v3 < v21 )
    {
      do
      {
        v8 = *v7;
        v9 = v7[1];
        v10 = v6[1];
        v11 = *v6;
        LOWORD(v8) = v8 & 0xF0;
        LOWORD(v9) = v9 & 0xF0;
        v12 = (((v11 & 0xF0) + v8 + (v10 & 0xF0u) + v9 + 32) >> 2)
            ^ ((((v11 & 0xFFFF00F0) + (*v7 & 0xF0) + (v10 & 0xFFFF00F0) + (v7[1] & 0xF0) + 32) >> 2)
             ^ (((v11 & 0xF) + (*v7 & 0xF) + (v10 & 0xF) + (v7[1] & 0xFu) + 2) >> 2))
            & 0xF;
        v13 = v16++;
        v7 = v17 + 2;
        v6 = v18 + 2;
        v14 = (unsigned int)(v17 + 2) < v21;
        *v13 = v12;
        v17 += 2;
        v18 += 2;
      }
      while ( v14 );
      a1 = v22;
      v2 = v19;
      v3 = v20;
      v5 = i;
    }
    v2 += *(_DWORD *)(a1[1] + 4176);
    v1 = *a1;
    v4 = *(_DWORD *)(*a1 + 4176);
    v3 += 2 * v4;
    v19 = v2;
  }
  return 0;
}
