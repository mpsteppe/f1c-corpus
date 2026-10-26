int __cdecl sub_51D57F(int a1, int a2, int a3, int a4)
{
  int result; // eax
  int v5; // ecx
  _DWORD *v6; // edi
  int *v7; // esi
  int v8; // ebx
  int *v9; // ecx
  int *v10; // ecx
  int v11; // eax
  int v12; // ebx
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // [esp+0h] [ebp-8h]
  int v18; // [esp+0h] [ebp-8h]
  int v19; // [esp+4h] [ebp-4h]

  result = a3;
  v5 = a2;
  if ( a3 < a4 )
  {
    v19 = 2 * a3;
    v6 = (_DWORD *)(32 * a3 + a2 + 12);
    while ( 1 )
    {
      v7 = 0;
      v8 = 0;
      if ( v19 > a4 )
      {
        if ( v19 > 0 )
        {
          v10 = (int *)(v5 + 24);
          v18 = result;
          do
          {
            if ( *v10 > v8 )
            {
              v7 = v10 - 6;
              v8 = *v10;
            }
            v10 += 8;
            --v18;
          }
          while ( v18 );
        }
      }
      else if ( v19 > 0 )
      {
        v9 = (int *)(v5 + 28);
        v17 = result;
        do
        {
          if ( *v9 > v8 && *(v9 - 1) > 0 )
          {
            v7 = v9 - 7;
            v8 = *v9;
          }
          v9 += 8;
          --v17;
        }
        while ( v17 );
      }
      if ( !v7 )
        break;
      *(v6 - 2) = v7[1];
      *v6 = v7[3];
      v6[2] = v7[5];
      *(v6 - 3) = *v7;
      *(v6 - 1) = v7[2];
      v6[1] = v7[4];
      v11 = 12 * (v7[3] - v7[2]);
      v12 = 1;
      if ( 16 * (v7[1] - *v7) > v11 )
      {
        v11 = 16 * (v7[1] - *v7);
        v12 = 0;
      }
      if ( 8 * (v7[5] - v7[4]) > v11 )
        v12 = 2;
      if ( v12 )
      {
        v13 = v12 - 1;
        if ( v13 )
        {
          if ( v13 == 1 )
          {
            v14 = (v7[4] + v7[5]) / 2;
            v7[5] = v14;
            v6[1] = v14 + 1;
          }
        }
        else
        {
          v15 = (v7[2] + v7[3]) / 2;
          v7[3] = v15;
          *(v6 - 1) = v15 + 1;
        }
      }
      else
      {
        v16 = (*v7 + v7[1]) / 2;
        v7[1] = v16;
        *(v6 - 3) = v16 + 1;
      }
      GridOccupancyBoundingBoxScan(a1, v7);
      GridOccupancyBoundingBoxScan(a1, v6 - 3);
      v19 += 2;
      result = a3 + 1;
      v6 += 8;
      if ( ++a3 >= a4 )
        break;
      v5 = a2;
    }
  }
  return result;
}

