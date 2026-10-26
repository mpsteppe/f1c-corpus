int __thiscall sub_64ADF1(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edi
  int v7; // edx
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // esi
  char *v14; // edi
  int v15; // ecx
  int v16; // esi
  unsigned int v17; // [esp+8h] [ebp-18h]
  _DWORD *v18; // [esp+Ch] [ebp-14h]
  char *i; // [esp+Ch] [ebp-14h]
  char *v20; // [esp+10h] [ebp-10h]
  unsigned int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+1Ch] [ebp-4h]
  unsigned int v24; // [esp+1Ch] [ebp-4h]

  v2 = (_DWORD *)*this;
  v3 = *(_DWORD *)(*this + 68) | *(_DWORD *)(*this + 72);
  v4 = *(_DWORD *)(*this + 64);
  v5 = v2[15];
  v18 = this;
  if ( (((unsigned __int8)v4 | (unsigned __int8)(v5 | v3)) & 3) != 0 )
    return -2147467259;
  if ( ((*(_BYTE *)(this[1] + 60)
       | (unsigned __int8)(*(_BYTE *)(this[1] + 64) | *(_BYTE *)(this[1] + 68) | *(_BYTE *)(this[1] + 72)))
      & 3) != 0 )
    return -2147467259;
  v7 = *(_DWORD *)(this[1] + 4);
  if ( v7 == 827611204 )
  {
    v23 = 8;
  }
  else
  {
    if ( v7 != 844388420 && v7 != 861165636 && v7 != 877942852 && v7 != 894720068 )
      return -2147467259;
    v23 = 16;
  }
  v8 = (_DWORD *)this[1];
  v17 = v23 * (v8[26] >> 2);
  v21 = 0;
  v9 = v8[8] + v23 * (v8[15] >> 2) + v8[19] * v8[25] + v8[24] * (v8[16] >> 2);
  v10 = v18;
  v22 = v2[8] + v23 * (v5 >> 2) + v2[19] * v2[25] + v2[24] * (v4 >> 2);
  v11 = v18[1];
  if ( *(_DWORD *)(v11 + 112) )
  {
    v12 = *(_DWORD *)(v11 + 108);
    do
    {
      v13 = (char *)v22;
      v24 = 0;
      v14 = (char *)v9;
      v20 = (char *)v9;
      for ( i = (char *)v22; v24 < v12; i = v13 )
      {
        v24 += 4;
        qmemcpy(v14, v13, v17);
        v15 = v10[1];
        v14 = &v20[*(_DWORD *)(v15 + 96)];
        v13 = &i[*(_DWORD *)(*v10 + 96)];
        v12 = *(_DWORD *)(v15 + 108);
        v20 = v14;
      }
      v16 = v10[1];
      v22 += *(_DWORD *)(*v10 + 100);
      v9 += *(_DWORD *)(v16 + 100);
      ++v21;
    }
    while ( v21 < *(_DWORD *)(v16 + 112) );
  }
  return 0;
}
