_DWORD *__cdecl sub_53FA2E(unsigned int a1, signed int a2, int a3)
{
  unsigned int v3; // edi
  double v4; // st7
  double v5; // st6
  unsigned int v6; // esi
  __int64 v7; // rax
  _DWORD *v8; // edi
  int v9; // ebx
  int v10; // esi
  double v11; // st7
  double X; // st7
  int v13; // edx
  double v14; // st7
  int v15; // ecx
  float *v16; // eax
  double v17; // st6
  float *v18; // eax
  _DWORD *v20; // [esp+14h] [ebp-3Ch]
  int v21; // [esp+18h] [ebp-38h]
  float v22; // [esp+1Ch] [ebp-34h]
  float v23; // [esp+20h] [ebp-30h]
  float v24; // [esp+24h] [ebp-2Ch]
  float v25; // [esp+28h] [ebp-28h]
  int i; // [esp+2Ch] [ebp-24h]
  float v27; // [esp+30h] [ebp-20h]
  float v28; // [esp+34h] [ebp-1Ch]
  unsigned int v29; // [esp+38h] [ebp-18h]
  float v30; // [esp+3Ch] [ebp-14h]
  float v31; // [esp+40h] [ebp-10h]
  unsigned int v32; // [esp+44h] [ebp-Ch]
  float v33; // [esp+48h] [ebp-8h]
  float v34; // [esp+4Ch] [ebp-4h]

  v3 = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v28 = (float)(unsigned int)a2;
      v4 = (double)a1;
      v23 = v4;
      v5 = v28 / v4;
      v6 = 16;
      v25 = v5;
      v22 = 0.5 / v5;
      do
      {
        v7 = (__int64)(((double)v3 - 0.5) * v5 + v5 - ((double)v3 - 0.5) * v5 + (double)(a3 != 0) + 1.0);
        ++v3;
        v6 += 16 * v7 + 12;
      }
      while ( v3 < a1 );
      v8 = operator new(v6);
      if ( v8 )
      {
        v9 = 0;
        v29 = 0;
        v34 = 0.0;
        v10 = 1;
        while ( 1 )
        {
          v32 = 0;
          v20 = &v8[v10];
          v21 = v10 * 4;
          ++v10;
          do
          {
            v24 = (float)v29;
            v11 = (double)v32 + v24 - 0.5;
            v31 = v11;
            X = v11 * v25;
            v27 = X;
            v33 = v25 + X;
            if ( !a3 )
            {
              if ( X < 0.0 )
              {
                X = 0.0;
                v27 = 0.0;
              }
              if ( v33 > (double)v28 )
                v33 = (float)(unsigned int)a2;
            }
            v13 = (__int64)floor(X);
            v14 = (double)v13;
            if ( v14 < v33 )
            {
              v15 = v13 - a2;
              for ( i = v13 - a2; ; v15 = i )
              {
                v30 = v14 + 1.0;
                if ( v13 >= 0 )
                {
                  if ( v13 < a2 )
                    v15 = v13;
                }
                else
                {
                  v15 = v13 + a2;
                }
                if ( v15 != v9 )
                {
                  if ( v34 > 0.0000099999997 )
                  {
                    v16 = (float *)&v8[v10];
                    *(_DWORD *)v16 = v9;
                    v10 += 2;
                    v16[1] = v34;
                  }
                  v9 = v15;
                  v34 = 0.0;
                }
                if ( v14 < v27 )
                  v14 = v27;
                if ( v30 > (double)v33 )
                  v30 = v33;
                if ( a3 )
                  goto LABEL_33;
                if ( v31 < 0.0 )
                {
                  v17 = 1.0;
                  goto LABEL_34;
                }
                if ( v31 + 1.0 < v23 )
LABEL_33:
                  v17 = (v30 + v14) * v22 - v31;
                else
                  v17 = 0.0;
LABEL_34:
                if ( v32 )
                  v17 = 1.0 - v17;
                ++v13;
                ++i;
                v34 = (v30 - v14) * v17 + v34;
                v14 = (double)v13;
                if ( v14 >= v33 )
                  break;
              }
            }
            ++v32;
          }
          while ( v32 < 2 );
          if ( v34 > 0.0000099999997 )
          {
            v18 = (float *)&v8[v10];
            v10 += 2;
            *(_DWORD *)v18 = v9;
            v18[1] = v34;
          }
          v34 = 0.0;
          ++v29;
          *v20 = v10 * 4 - v21;
          if ( v29 >= a1 )
          {
            *v8 = v10 * 4;
            return v8;
          }
        }
      }
    }
  }
  return 0;
}
