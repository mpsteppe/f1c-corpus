int __fastcall sub_64BA99(_DWORD *a1)
{
  _WORD *v1; // edi
  int v2; // eax
  unsigned __int16 *v3; // ebx
  unsigned __int16 *v4; // edx
  unsigned __int16 *v5; // esi
  int v6; // edx
  int v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  _WORD *v10; // eax
  unsigned __int16 *i; // [esp+8h] [ebp-20h]
  _DWORD *v13; // [esp+Ch] [ebp-1Ch]
  unsigned __int16 *v14; // [esp+10h] [ebp-18h]
  int v15; // [esp+14h] [ebp-14h]
  unsigned __int16 *v16; // [esp+18h] [ebp-10h]
  _WORD *v17; // [esp+1Ch] [ebp-Ch]
  unsigned __int16 *v18; // [esp+20h] [ebp-8h]
  _WORD *v19; // [esp+24h] [ebp-4h]

  v1 = *(_WORD **)(a1[1] + 32);
  v2 = *a1;
  v3 = *(unsigned __int16 **)(*a1 + 32);
  v4 = (unsigned __int16 *)((char *)v3 + *(_DWORD *)(*a1 + 96) * *(_DWORD *)(*a1 + 108));
  v13 = a1;
  v17 = v1;
  v16 = v3;
  for ( i = v4; v3 < v4; v16 = v3 )
  {
    v5 = (unsigned __int16 *)((char *)v3 + *(_DWORD *)(v2 + 96));
    v19 = v1;
    v18 = v3;
    v14 = &v3[*(_DWORD *)(v2 + 104)];
    if ( v3 < v14 )
    {
      do
      {
        v6 = v3[1];
        v7 = *v5;
        v15 = *v3;
        v8 = (v7 & 0xFFFF00F0) + (v15 & 0xFFFF00F0) + (v5[1] & 0xFFFF00F0) + (v6 & 0xFFFF00F0) + 32;
        v9 = (v15 & 0xFFFF0F0F) + (v5[1] & 0xF0F);
        LOWORD(v7) = v7 & 0xF0F;
        LOWORD(v6) = v6 & 0xF0F;
        v5 += 2;
        LOWORD(v8) = ((v7 + v9 + v6 + 514) >> 2) & 0xF0F | (v8 >> 2) & 0xF0;
        v10 = v19++;
        *v10 = v8;
        v3 = v18 + 2;
        v18 += 2;
      }
      while ( v18 < v14 );
      a1 = v13;
      v1 = v17;
      v3 = v16;
      v4 = i;
    }
    v1 = (_WORD *)((char *)v1 + *(_DWORD *)(a1[1] + 96));
    v2 = *a1;
    v3 += *(_DWORD *)(*a1 + 96);
    v17 = v1;
  }
  return 0;
}
