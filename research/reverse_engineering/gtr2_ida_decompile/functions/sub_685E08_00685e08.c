int __thiscall sub_685E08(_DWORD *this, _DWORD *a2, int a3, unsigned int a4, int a5)
{
  unsigned int v5; // edx
  unsigned int i; // eax
  unsigned int v8; // eax
  int v9; // ebx
  int *v10; // edx
  int v11; // esi
  unsigned int v12; // edi
  unsigned int v13; // eax
  int *v14; // ebx
  unsigned int v15; // eax
  int v16; // ecx
  _DWORD v18[4]; // [esp+8h] [ebp-20h] BYREF
  unsigned int v19; // [esp+18h] [ebp-10h]
  unsigned int v20; // [esp+1Ch] [ebp-Ch]
  _DWORD *v21; // [esp+20h] [ebp-8h]
  unsigned int v22; // [esp+24h] [ebp-4h]
  unsigned int v23; // [esp+34h] [ebp+Ch]
  unsigned int v24; // [esp+3Ch] [ebp+14h]

  v5 = a4;
  v21 = this;
  if ( !a5 )
    goto LABEL_14;
  for ( i = 0; i < a4; ++i )
    *(_DWORD *)(a3 + 4 * i) = i;
  v8 = 0;
  if ( !a4 )
    goto LABEL_14;
  do
  {
    v9 = v21[5];
    v10 = (int *)(a3 + 4 * v8);
    v11 = *v10;
    v12 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * a2[*v10]) + 16);
    v22 = v8++;
    v23 = v12;
    v19 = v8;
    v24 = v8;
    if ( v8 >= a4 )
      goto LABEL_13;
    do
    {
      v20 = *(_DWORD *)(*(_DWORD *)(v9 + 4 * a2[*(_DWORD *)(a3 + 4 * v24)]) + 16);
      v13 = v20;
      if ( v20 < v23 )
        goto LABEL_10;
      if ( v20 == v23 && v24 < v22 )
      {
        v13 = v20;
LABEL_10:
        v22 = v24;
        v23 = v13;
      }
      ++v24;
    }
    while ( v24 < a4 );
    v8 = v19;
LABEL_13:
    v14 = (int *)(a3 + 4 * v22);
    *v10 = *v14;
    v5 = a4;
    *v14 = v11;
  }
  while ( v8 < a4 );
LABEL_14:
  v15 = 0;
  if ( v5 )
  {
    v16 = a3 - (_DWORD)v18;
    do
    {
      v18[v15] = a2[*(_DWORD *)((char *)&v18[v15] + v16)];
      ++v15;
    }
    while ( v15 < v5 );
    qmemcpy(a2, v18, 4 * v5);
  }
  return 0;
}
