int __fastcall sub_64B8DF(_DWORD *a1)
{
  _BYTE *v1; // ebx
  int v2; // eax
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // edx
  unsigned int v6; // eax
  unsigned __int8 *v7; // edx
  int v8; // ecx
  int v9; // ebx
  unsigned int v10; // ecx
  _BYTE *v11; // ebx
  _DWORD *v13; // [esp+Ch] [ebp-10h]
  _BYTE *v14; // [esp+10h] [ebp-Ch]
  _BYTE *v15; // [esp+14h] [ebp-8h]
  unsigned __int8 *v16; // [esp+18h] [ebp-4h]

  v1 = *(_BYTE **)(a1[1] + 32);
  v2 = *a1;
  v3 = *(unsigned __int8 **)(*a1 + 32);
  v13 = a1;
  v4 = &v3[*(_DWORD *)(*a1 + 96) * *(_DWORD *)(*a1 + 108)];
  while ( 1 )
  {
    v14 = v1;
    if ( v3 >= v4 )
      break;
    v5 = *(_DWORD *)(v2 + 96);
    v6 = (unsigned int)&v3[*(_DWORD *)(v2 + 104)];
    v7 = &v3[v5];
    v15 = v1;
    v16 = v3;
    if ( (unsigned int)v3 < v6 )
    {
      do
      {
        v8 = *v7 + v16[1] + v7[1];
        v9 = *v16;
        v16 += 2;
        v10 = v8 + v9 + 2;
        v11 = v15++;
        v7 += 2;
        *v11 = v10 >> 2;
      }
      while ( (unsigned int)v16 < v6 );
      v1 = v14;
      a1 = v13;
    }
    v1 += *(_DWORD *)(a1[1] + 96);
    v2 = *a1;
    v3 += 2 * *(_DWORD *)(*a1 + 96);
  }
  return 0;
}
