void __stdcall sub_682274(int (__stdcall *a1)(int, int, int), int *a2, unsigned int a3, int a4)
{
  unsigned int v4; // ebx
  unsigned int v6; // edi
  unsigned int v7; // ecx
  int *v8; // eax
  unsigned int v9; // edi
  int v10; // ebx
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // [esp+4h] [ebp-14h]
  int v14; // [esp+8h] [ebp-10h]
  int v15; // [esp+Ch] [ebp-Ch]
  int v16; // [esp+Ch] [ebp-Ch]
  int v17; // [esp+10h] [ebp-8h]
  int v18; // [esp+14h] [ebp-4h]
  unsigned int v19; // [esp+24h] [ebp+Ch]
  unsigned int v20; // [esp+24h] [ebp+Ch]

  if ( a3 > 1 )
  {
    v4 = a3 >> 1;
    if ( a3 >> 1 )
    {
      v18 = 2 * v4 + 1;
      do
      {
        --v4;
        v6 = v18 - 2;
        v18 -= 2;
        v19 = v4;
        v15 = a2[v4];
        while ( v6 < a3 )
        {
          v17 = a2[v6];
          if ( v6 + 1 < a3 )
          {
            v13 = a2[v6 + 1];
            if ( a1(v13, a2[v6], a4) > 0 )
            {
              ++v6;
              v17 = v13;
            }
          }
          if ( a1(v17, v15, a4) <= 0 )
            break;
          v7 = v19;
          v19 = v6;
          a2[v7] = a2[v6];
          v6 = 2 * v6 + 1;
        }
        a2[v19] = v15;
      }
      while ( v4 );
    }
    while ( --a3 )
    {
      v20 = 0;
      v8 = &a2[a3];
      v16 = *v8;
      v9 = 1;
      for ( *v8 = *a2; v9 < a3; a2[v11] = v12 )
      {
        v10 = a2[v9];
        if ( v9 + 1 < a3 )
        {
          v14 = a2[v9 + 1];
          if ( a1(v14, v10, a4) > 0 )
          {
            ++v9;
            v10 = v14;
          }
        }
        if ( a1(v10, v16, a4) <= 0 )
          break;
        v11 = v20;
        v12 = a2[v9];
        v20 = v9;
        v9 = 2 * v9 + 1;
      }
      a2[v20] = v16;
    }
  }
}
