int __thiscall sub_64B45C(_DWORD *this)
{
  _DWORD *v2; // edx
  _WORD *v3; // ecx
  char *v4; // ebx
  char *v5; // esi
  char *v6; // edi
  int v7; // edx
  _WORD *v8; // ecx
  char *i; // [esp+Ch] [ebp-20h]
  char *v11; // [esp+10h] [ebp-1Ch]
  char *v12; // [esp+18h] [ebp-14h]
  _WORD *v13; // [esp+1Ch] [ebp-10h]
  char *v14; // [esp+20h] [ebp-Ch]
  int v15; // [esp+24h] [ebp-8h]
  _WORD *v16; // [esp+28h] [ebp-4h]

  v2 = (_DWORD *)*this;
  v3 = *(_WORD **)(this[1] + 32);
  v4 = (char *)v2[8];
  v5 = &v4[v2[24] * v2[27]];
  v13 = v3;
  v12 = v4;
  for ( i = v5; v4 < v5; v12 = v4 )
  {
    v6 = &v4[v2[24]];
    v16 = v3;
    v14 = v4;
    v11 = &v4[2 * v2[26]];
    if ( v4 < v11 )
    {
      do
      {
        v7 = *((unsigned __int16 *)v6 + 1);
        v15 = *(unsigned __int16 *)v6;
        v6 += 4;
        v8 = v16++;
        *v8 = (((v15 & 0x7C1F) + (*(_WORD *)v4 & 0x7C1F) + (v7 & 0x7C1F) + (*((_WORD *)v4 + 1) & 0x7C1Fu) + 2050) >> 2)
            & 0x7C1F
            | (((v15 & 0xFFFF03E0) + (*(_WORD *)v4 & 0x3E0) + (v7 & 0xFFFF03E0) + (*((_WORD *)v4 + 1) & 0x3E0) + 64) >> 2)
            & 0x3E0;
        v4 = v14 + 4;
        v14 += 4;
      }
      while ( v14 < v11 );
      v3 = v13;
      v4 = v12;
      v5 = i;
    }
    v3 = (_WORD *)((char *)v3 + *(_DWORD *)(this[1] + 96));
    v2 = (_DWORD *)*this;
    v4 += 2 * *(_DWORD *)(*this + 96);
    v13 = v3;
  }
  return 0;
}
