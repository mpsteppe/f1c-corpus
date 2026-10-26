int __stdcall sub_680652(_DWORD *a1, int a2, int a3, int a4, _DWORD *a5)
{
  int v5; // edi
  _DWORD *v6; // esi
  unsigned int v7; // ebx
  char *v8; // edi
  int v10; // edi
  float *v11; // ecx
  int v12; // eax
  char *Block; // [esp+4h] [ebp-4h]
  float *v15; // [esp+14h] [ebp+Ch]
  int v16; // [esp+1Ch] [ebp+14h]

  v5 = 0;
  Block = 0;
  if ( *(_DWORD *)(a4 + 4) != 13 )
    return 0;
  v6 = *(_DWORD **)(a4 + 32);
  if ( v6[1] == 1 )
  {
    v7 = 16 * a2;
    v8 = (char *)operator new(16 * a2);
    Block = v8;
    if ( v8 )
    {
      memset(v8, 0, v7);
      if ( a2 )
      {
        v15 = (float *)v8;
        v16 = a2;
        do
        {
          v10 = a3;
          if ( a3 )
          {
            v11 = v15;
            do
            {
              v12 = v6[2];
              if ( *(_DWORD *)(v12 + 16) == 3 )
                *v11 = *(double *)(v12 + 24);
              else
                *v11 = *(float *)(v12 + 24);
              v6 = (_DWORD *)v6[3];
              ++v11;
              --v10;
            }
            while ( v10 );
          }
          v15 += 4;
          --v16;
        }
        while ( v16 );
      }
      v5 = sub_68024C(a1, Block, v7, 6, a5);
    }
    else
    {
      v5 = -2147024882;
    }
  }
  j__free(Block);
  return v5;
}
