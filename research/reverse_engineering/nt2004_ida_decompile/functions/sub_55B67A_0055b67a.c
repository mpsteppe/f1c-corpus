int __cdecl sub_55B67A(_DWORD *a1, int a2, void **a3, int a4)
{
  _DWORD *v4; // esi
  int result; // eax
  void **v6; // ebx
  int v7; // edi
  int v8; // eax
  _BYTE *v9; // edi
  unsigned __int8 *v10; // eax
  int v11; // ecx
  int v12; // edx
  bool v13; // zf
  char v14; // [esp+4h] [ebp-2Ch]
  int v15; // [esp+Ch] [ebp-24h]
  int v16; // [esp+10h] [ebp-20h]
  _DWORD *v17; // [esp+14h] [ebp-1Ch]
  int v18; // [esp+18h] [ebp-18h]
  void **v19; // [esp+1Ch] [ebp-14h]
  unsigned int v20; // [esp+20h] [ebp-10h]
  unsigned int v21; // [esp+24h] [ebp-Ch]
  int v22; // [esp+28h] [ebp-8h]
  _DWORD *v23; // [esp+2Ch] [ebp-4h]
  int v24; // [esp+38h] [ebp+8h]
  int v25; // [esp+44h] [ebp+14h]

  v4 = (_DWORD *)a1[105];
  v21 = a1[23];
  result = a4;
  v22 = a1[25];
  if ( a4 > 0 )
  {
    v6 = a3;
    v7 = a2 - (_DWORD)a3;
    v19 = a3;
    v18 = a4;
    do
    {
      sub_55293B(*v6, v21);
      v8 = v4[12];
      v24 = 0;
      v14 = v8;
      if ( v22 > 0 )
      {
        v16 = v8 << 6;
        v17 = (void **)((char *)v6 + v7);
        v23 = v4 + 13;
        do
        {
          v25 = 0;
          v9 = *v6;
          v10 = (unsigned __int8 *)(v24 + *v17);
          v15 = *(_DWORD *)(v4[6] + 4 * v24);
          v11 = v16 + *v23;
          if ( v21 )
          {
            v20 = v21;
            do
            {
              v12 = *v10;
              v10 += v22;
              *v9++ += *(_BYTE *)(v12 + *(_DWORD *)(v11 + 4 * v25) + v15);
              v13 = v20-- == 1;
              v25 = ((_BYTE)v25 + 1) & 0xF;
            }
            while ( !v13 );
            v6 = v19;
          }
          ++v24;
          ++v23;
        }
        while ( v24 < v22 );
        v7 = a2 - (_DWORD)a3;
        LOBYTE(v8) = v14;
      }
      result = ((_BYTE)v8 + 1) & 0xF;
      ++v6;
      v13 = v18-- == 1;
      v4[12] = result;
      v19 = v6;
    }
    while ( !v13 );
  }
  return result;
}
