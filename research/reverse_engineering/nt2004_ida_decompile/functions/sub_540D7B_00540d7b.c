int __thiscall sub_540D7B(_DWORD *this)
{
  _BYTE *v1; // ebx
  int v2; // eax
  unsigned __int8 *v3; // edx
  int v4; // edi
  unsigned __int8 *v5; // esi
  unsigned int v6; // eax
  unsigned __int8 *v7; // edi
  bool i; // cf
  int v9; // edi
  int v10; // ebx
  unsigned int v11; // ebx
  _BYTE *v12; // edi
  _BYTE *v14; // [esp+Ch] [ebp-10h]
  unsigned __int8 *v15; // [esp+10h] [ebp-Ch]
  _BYTE *v16; // [esp+14h] [ebp-8h]
  unsigned __int8 *v17; // [esp+18h] [ebp-4h]

  v1 = *(_BYTE **)(this[1] + 24);
  v2 = *this;
  v3 = *(unsigned __int8 **)(*this + 24);
  v4 = *(_DWORD *)(*this + 4176);
  v5 = &v3[v4 * *(_DWORD *)(*this + 4188)];
  while ( 1 )
  {
    v14 = v1;
    if ( v3 >= v5 )
      break;
    v6 = (unsigned int)&v3[*(_DWORD *)(v2 + 4184)];
    v7 = &v3[v4];
    v16 = v1;
    v17 = v3;
    for ( i = (unsigned int)v3 < v6; ; i = (unsigned int)v17 < v6 )
    {
      v15 = v7;
      if ( !i )
        break;
      v9 = *v7 + v17[1] + v7[1];
      v10 = *v17;
      v17 += 2;
      v11 = v9 + v10 + 2;
      v12 = v16++;
      *v12 = v11 >> 2;
      v7 = v15 + 2;
    }
    v1 = &v14[*(_DWORD *)(this[1] + 4176)];
    v2 = *this;
    v4 = *(_DWORD *)(*this + 4176);
    v3 += 2 * v4;
  }
  return 0;
}
