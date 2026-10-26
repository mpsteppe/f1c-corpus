int __thiscall sub_64B561(_DWORD *this)
{
  int v1; // eax
  _DWORD *v2; // ecx
  char *v3; // ebx
  _WORD *v4; // esi
  char *v5; // edi
  __int16 v6; // si
  __int16 v7; // cx
  __int16 v8; // di
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  int v11; // esi
  _WORD *v12; // ecx
  char *i; // [esp+8h] [ebp-2Ch]
  char *v16; // [esp+10h] [ebp-24h]
  char *v17; // [esp+18h] [ebp-1Ch]
  _WORD *v18; // [esp+1Ch] [ebp-18h]
  char *v19; // [esp+20h] [ebp-14h]
  char *v20; // [esp+24h] [ebp-10h]
  _WORD *v21; // [esp+28h] [ebp-Ch]
  __int16 v22; // [esp+2Ch] [ebp-8h]
  __int16 v23; // [esp+30h] [ebp-4h]

  v1 = this[1];
  v2 = (_DWORD *)*this;
  v3 = (char *)v2[8];
  v4 = *(_WORD **)(v1 + 32);
  v18 = v4;
  v17 = v3;
  for ( i = &v3[v2[24] * v2[27]]; v3 < i; v17 = v3 )
  {
    v5 = &v3[v2[24]];
    v21 = v4;
    v20 = v3;
    v19 = v5;
    v16 = &v3[2 * v2[26]];
    if ( v3 < v16 )
    {
      do
      {
        v6 = *((_WORD *)v5 + 1);
        v22 = *((_WORD *)v3 + 1);
        v7 = *(_WORD *)v5;
        v8 = *(_WORD *)v3;
        v23 = v7;
        v9 = (v7 & 0x83E0) + (*(_WORD *)v3 & 0x83E0) + (v6 & 0x83E0) + (v22 & 0x83E0) + 65600;
        v10 = ((v7 & 0x7C1F) + (v8 & 0x7C1F) + (v6 & 0x7C1F) + (v22 & 0x7C1Fu) + 2050) >> 2;
        v11 = (v23 & 0x83E0) + (v8 & 0x83E0) + (v6 & 0x83E0);
        v5 = v19 + 4;
        v19 += 4;
        LOWORD(v9) = ((v11 + (v22 & 0x83E0u) + 65600) >> 2) ^ (v10 ^ (v9 >> 2)) & 0x7C1F;
        v12 = v21++;
        *v12 = v9;
        v3 = v20 + 4;
        v20 += 4;
      }
      while ( v20 < v16 );
      v3 = v17;
    }
    v4 = (_WORD *)((char *)v18 + *(_DWORD *)(this[1] + 96));
    v2 = (_DWORD *)*this;
    v3 += 2 * *(_DWORD *)(*this + 96);
    v18 = v4;
  }
  return 0;
}
