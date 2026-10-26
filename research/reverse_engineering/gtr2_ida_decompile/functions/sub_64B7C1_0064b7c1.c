int __thiscall sub_64B7C1(_DWORD *this)
{
  _BYTE *v2; // ecx
  _DWORD *v3; // eax
  _BYTE *v4; // ebx
  _BYTE *v5; // edi
  unsigned __int8 *v6; // edx
  int v7; // eax
  int v8; // edi
  char v9; // dl
  _BYTE *v10; // eax
  _DWORD *v12; // [esp+8h] [ebp-28h]
  _BYTE *i; // [esp+Ch] [ebp-24h]
  _BYTE *v14; // [esp+10h] [ebp-20h]
  _BYTE *v15; // [esp+18h] [ebp-18h]
  _BYTE *v16; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *v17; // [esp+20h] [ebp-10h]
  _BYTE *v18; // [esp+24h] [ebp-Ch]
  _BYTE *v19; // [esp+28h] [ebp-8h]
  int v20; // [esp+2Ch] [ebp-4h]

  v2 = *(_BYTE **)(this[1] + 32);
  v12 = this;
  v3 = (_DWORD *)*this;
  v4 = (_BYTE *)v3[8];
  v5 = &v4[v3[24] * v3[27]];
  v16 = v2;
  v15 = v4;
  for ( i = v5; v4 < v5; v15 = v4 )
  {
    v6 = &v4[v3[24]];
    v19 = v2;
    v18 = v4;
    v17 = v6;
    v14 = &v4[v3[26]];
    if ( v4 < v14 )
    {
      do
      {
        v7 = v6[1];
        v8 = (unsigned __int8)v4[1];
        v20 = *v6;
        v9 = (((v20 & 0xFFFF00E3) + (*v4 & 0xE3) + (v7 & 0xE3) + (v8 & 0xE3) + 66) >> 2)
           ^ ((((v20 & 0xFFFF00E3) + (*v4 & 0xE3) + (v7 & 0xFFFF00E3) + (v8 & 0xFFFF00E3) + 66) >> 2)
            ^ (((v20 & 0x1C) + (*v4 & 0x1C) + (v7 & 0x1C) + (v8 & 0x1Cu) + 8) >> 2))
           & 0x1C;
        v10 = v19++;
        *v10 = v9;
        v4 = v18 + 2;
        v6 = v17 + 2;
        v18 = v4;
        v17 += 2;
      }
      while ( v4 < v14 );
      v2 = v16;
      v4 = v15;
      v5 = i;
    }
    v2 += *(_DWORD *)(v12[1] + 96);
    v3 = (_DWORD *)*v12;
    v4 += 2 * *(_DWORD *)(*v12 + 96);
    v16 = v2;
  }
  return 0;
}
