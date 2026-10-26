int __fastcall sub_503CE3(_DWORD *a1)
{
  int v1; // esi
  int v2; // edi
  unsigned __int16 *v3; // eax
  unsigned __int16 *v4; // ebp
  _WORD *v5; // edi
  unsigned __int16 *v6; // ebx
  int v7; // ecx
  int v8; // esi
  int v9; // eax
  __int16 v10; // bx
  _WORD *v11; // eax
  bool v12; // cf
  _WORD *v14; // [esp+Ch] [ebp-24h]
  _WORD *v15; // [esp+10h] [ebp-20h]
  unsigned __int16 *v16; // [esp+14h] [ebp-1Ch]
  _WORD *v17; // [esp+18h] [ebp-18h]
  unsigned __int16 *v18; // [esp+1Ch] [ebp-14h]
  unsigned int v19; // [esp+24h] [ebp-Ch]
  _DWORD *v20; // [esp+28h] [ebp-8h]
  unsigned __int16 *i; // [esp+2Ch] [ebp-4h]

  v1 = *a1;
  v2 = *(_DWORD *)(*a1 + 4176);
  v15 = *(_WORD **)(a1[1] + 24);
  v3 = *(unsigned __int16 **)(*a1 + 24);
  v4 = (unsigned __int16 *)((char *)v3 + v2 * *(_DWORD *)(*a1 + 4188));
  v20 = a1;
  v18 = v3;
  for ( i = v4; v3 < v4; v18 = v3 )
  {
    v14 = v15;
    v5 = (unsigned __int16 *)((char *)v3 + v2);
    v6 = v3;
    v16 = v3;
    v17 = v5;
    v19 = (unsigned int)&v3[*(_DWORD *)(v1 + 4184)];
    if ( (unsigned int)v3 < v19 )
    {
      do
      {
        v7 = *v6;
        v8 = v6[1];
        v9 = (unsigned __int16)v5[1];
        v10 = (((*v5 & 0xF0F0) + (v7 & 0xF0F0) + (v9 & 0xF0F0) + (v8 & 0xF0F0u) + 8224) >> 2)
            ^ ((((v8 & 0xFFFF0F0F) + (*v5 & 0xF0F) + (v7 & 0xFFFF0F0F) + (v9 & 0xFFFF0F0F) + 514) >> 2)
             ^ (((*v5 & 0xF0F0) + (v7 & 0xFFFFF0F0) + (v9 & 0xFFFFF0F0) + (v8 & 0xFFFFF0F0) + 8224) >> 2))
            & 0xF0F;
        v11 = v14++;
        *v11 = v10;
        v6 = v16 + 2;
        v5 = v17 + 2;
        v12 = (unsigned int)(v16 + 2) < v19;
        v16 += 2;
        v17 += 2;
      }
      while ( v12 );
      a1 = v20;
      v3 = v18;
      v4 = i;
    }
    v15 = (_WORD *)((char *)v15 + *(_DWORD *)(a1[1] + 4176));
    v1 = *a1;
    v2 = *(_DWORD *)(*a1 + 4176);
    v3 += v2;
  }
  return 0;
}
