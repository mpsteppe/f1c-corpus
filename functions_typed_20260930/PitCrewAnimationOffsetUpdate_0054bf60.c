void __thiscall sub_54BF60(_DWORD *this, int a2, int a3, float a4, float a5)
{
  _DWORD *i; // edi
  int v6; // ebx
  int *v7; // ecx
  int v8; // esi
  int v9; // edx
  int v10; // eax
  double v11; // st7
  int v12; // edx
  int v13; // eax
  double v14; // st7

  for ( i = (_DWORD *)this[129]; i; i = (_DWORD *)i[4] )
  {
    v6 = 0;
    if ( (int)i[70] > 0 )
    {
      v7 = (int *)(i[71] + 8);
      do
      {
        if ( *(v7 - 1) == a2 )
        {
          v8 = v7[1];
          if ( a3 )
          {
            if ( a3 == 1 )
            {
              v9 = 0;
              if ( *v7 > 0 )
              {
                v10 = v8 + 44;
                do
                {
                  ++v9;
                  v11 = a4 + *(float *)(v10 - 4);
                  v10 += 48;
                  *(float *)(v10 - 52) = v11;
                  *(float *)(v10 - 48) = a5 + *(float *)(v10 - 48);
                }
                while ( v9 < *v7 );
              }
            }
          }
          else
          {
            v12 = 0;
            if ( *v7 > 0 )
            {
              v13 = v8 + 36;
              do
              {
                ++v12;
                v14 = a4 + *(float *)(v13 - 4);
                v13 += 48;
                *(float *)(v13 - 52) = v14;
                *(float *)(v13 - 48) = a5 + *(float *)(v13 - 48);
              }
              while ( v12 < *v7 );
            }
          }
          v7[12] |= 0x800u;
        }
        v7 += 16;
        ++v6;
      }
      while ( v6 < i[70] );
    }
  }
}

