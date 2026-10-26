int __thiscall sub_6C6121(_DWORD *this, char *a2, unsigned int a3, int a4, _DWORD *a5)
{
  int v5; // ebx
  int v6; // esi
  int v7; // eax
  unsigned int v8; // edx
  unsigned int v9; // ebx
  unsigned int v10; // edx
  int v11; // ecx
  int v12; // eax
  unsigned int i; // eax
  unsigned int j; // eax
  int v15; // edi
  int v16; // edx
  int v17; // edx
  unsigned int v18; // ecx
  _DWORD *v19; // eax
  int v20; // esi
  _DWORD v22[4]; // [esp+Ch] [ebp-24h] BYREF
  _DWORD v23[4]; // [esp+1Ch] [ebp-14h] BYREF
  int v24; // [esp+2Ch] [ebp-4h]

  v5 = this[4];
  v6 = this[5];
  v7 = 4 * *(_DWORD *)a2;
  v24 = *(_DWORD *)(v6 + v7);
  v8 = 0;
  if ( *(char *)(*(_DWORD *)(v5 + 4 * *(_DWORD *)(v24 + 4)) + 4) >= 0 )
  {
    if ( (a4 & 0x10000) != 0 )
    {
      v23[0] = 0;
      v8 = 1;
    }
    if ( (a4 & 0x20000) != 0 )
      v23[v8++] = 1;
    if ( (a4 & 0x40000) != 0 )
      v23[v8++] = 2;
    if ( (a4 & 0x80000) != 0 )
      v23[v8++] = 3;
    v9 = a3;
    if ( a3 > v8 )
      v9 = v8;
    v10 = 0;
    if ( !v9 )
      goto LABEL_21;
    v11 = this[5];
    v12 = *(_DWORD *)(*(_DWORD *)(v11 + v7) + 16);
    do
    {
      if ( v12 != *(_DWORD *)(*(_DWORD *)(v11 + 4 * *(_DWORD *)&a2[4 * v10]) + 16) )
        break;
      ++v10;
    }
    while ( v10 < v9 );
    if ( v10 < v9 )
    {
      for ( i = 0; i < 4; ++i )
        v22[i] = i;
    }
    else
    {
LABEL_21:
      v22[0] = *(_DWORD *)(v24 + 16);
      v22[1] = v22[0];
      v22[2] = v22[0];
      v22[3] = v22[0];
    }
    for ( j = 0; j < v9; v22[v15] = v16 )
    {
      v15 = v23[j];
      v16 = *(_DWORD *)(*(_DWORD *)(v6 + 4 * *(_DWORD *)((char *)&v23[j++] + a2 - (char *)v23)) + 16);
    }
    v17 = 0;
    v18 = 16;
    v19 = v22;
    do
    {
      v20 = *v19++ << v18;
      v17 |= v20;
      v18 += 2;
    }
    while ( v18 < 0x18 );
    *a5 = v17;
  }
  else
  {
    *a5 = &unk_E40000;
  }
  return 0;
}
