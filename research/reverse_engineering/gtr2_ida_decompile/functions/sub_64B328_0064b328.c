int __thiscall sub_64B328(_DWORD *this)
{
  _DWORD *v2; // edx
  _WORD *v3; // ecx
  unsigned __int16 *v4; // ebx
  unsigned __int16 *v5; // esi
  unsigned __int16 *v6; // edi
  int v7; // edx
  int v8; // esi
  int v9; // ecx
  __int16 v10; // di
  int v11; // edx
  _WORD *v12; // ecx
  unsigned __int16 *i; // [esp+Ch] [ebp-24h]
  unsigned __int16 *v15; // [esp+10h] [ebp-20h]
  unsigned __int16 *v16; // [esp+18h] [ebp-18h]
  _WORD *v17; // [esp+1Ch] [ebp-14h]
  unsigned __int16 *v18; // [esp+20h] [ebp-10h]
  unsigned __int16 *v19; // [esp+24h] [ebp-Ch]
  _WORD *v20; // [esp+28h] [ebp-8h]
  int v21; // [esp+2Ch] [ebp-4h]

  v2 = (_DWORD *)*this;
  v3 = *(_WORD **)(this[1] + 32);
  v4 = (unsigned __int16 *)v2[8];
  v5 = (unsigned __int16 *)((char *)v4 + v2[24] * v2[27]);
  v17 = v3;
  v16 = v4;
  for ( i = v5; v4 < v5; v16 = v4 )
  {
    v6 = (unsigned __int16 *)((char *)v4 + v2[24]);
    v20 = v3;
    v19 = v4;
    v18 = v6;
    v15 = &v4[v2[26]];
    if ( v4 < v15 )
    {
      do
      {
        v7 = v6[1];
        v8 = v4[1];
        v21 = *v6;
        v9 = *v4;
        v10 = (((v21 & 0xFFFF07E0) + (v9 & 0xFFFF07E0) + (v7 & 0xFFFF07E0) + (v8 & 0xFFFF07E0) + 64) >> 2)
            ^ (((v21 & 0xFFFFF81F) + (v9 & 0xFFFFF81F) + (v7 & 0xF81F) + (v8 & 0xFFFFF81F) + 4098) >> 2);
        v11 = (v21 & 0xF81F) + (v9 & 0xF81F) + (v7 & 0xF81F);
        v12 = v20++;
        *v12 = ((v11 + (v8 & 0xF81Fu) + 4098) >> 2) ^ v10 & 0x7E0;
        v4 = v19 + 2;
        v6 = v18 + 2;
        v19 = v4;
        v18 += 2;
      }
      while ( v4 < v15 );
      v3 = v17;
      v4 = v16;
      v5 = i;
    }
    v3 = (_WORD *)((char *)v3 + *(_DWORD *)(this[1] + 96));
    v2 = (_DWORD *)*this;
    v4 += *(_DWORD *)(*this + 96);
    v17 = v3;
  }
  return 0;
}
