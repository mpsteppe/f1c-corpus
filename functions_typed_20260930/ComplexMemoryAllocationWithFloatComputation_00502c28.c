_DWORD *__cdecl sub_502C28(unsigned int a1, signed int a2, int a3)
{
  unsigned int v3; // edi
  double v4; // st7
  double v5; // st6
  int v6; // esi
  _DWORD *v7; // edi
  int v8; // ebx
  int v9; // esi
  double v10; // st7
  double v11; // st7
  int v12; // edx
  double v13; // st7
  int v14; // ecx
  float *v15; // eax
  double v16; // st6
  float *v17; // eax
  _DWORD *v19; // [esp+14h] [ebp-3Ch]
  int v20; // [esp+18h] [ebp-38h]
  float v21; // [esp+1Ch] [ebp-34h]
  float v22; // [esp+20h] [ebp-30h]
  float v23; // [esp+24h] [ebp-2Ch]
  float v24; // [esp+28h] [ebp-28h]
  int i; // [esp+2Ch] [ebp-24h]
  float v26; // [esp+30h] [ebp-20h]
  float v27; // [esp+34h] [ebp-1Ch]
  unsigned int v28; // [esp+38h] [ebp-18h]
  float v29; // [esp+3Ch] [ebp-14h]
  float v30; // [esp+40h] [ebp-10h]
  unsigned int v31; // [esp+44h] [ebp-Ch]
  float v32; // [esp+48h] [ebp-8h]
  float v33; // [esp+4Ch] [ebp-4h]

  v3 = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v27 = (float)(unsigned int)a2;
      v4 = (double)a1;
      v22 = v4;
      v5 = v27 / v4;
      v6 = 16;
      v24 = v5;
      v21 = 0.5 / v5;
      do
      {
        ++v3;
        v6 += 16 * CRTFtol(v5) + 12;
      }
      while ( v3 < a1 );
      v7 = (_DWORD *)OperatorNewNhMallocWrapper(v6);
      if ( v7 )
      {
        v8 = 0;
        v28 = 0;
        v33 = 0.0;
        v9 = 1;
        while ( 1 )
        {
          v31 = 0;
          v19 = &v7[v9];
          v20 = v9 * 4;
          ++v9;
          do
          {
            v23 = (float)v28;
            v10 = (double)v31 + v23 - 0.5;
            v30 = v10;
            v11 = v10 * v24;
            v26 = v11;
            v32 = v24 + v11;
            if ( !a3 )
            {
              if ( v11 < 0.0 )
              {
                v11 = 0.0;
                v26 = 0.0;
              }
              if ( v32 > (double)v27 )
                v32 = (float)(unsigned int)a2;
            }
            sub_5895A2(v11);
            v12 = CRTFtol(v11);
            v13 = (double)v12;
            if ( v13 < v32 )
            {
              v14 = v12 - a2;
              for ( i = v12 - a2; ; v14 = i )
              {
                v29 = v13 + 1.0;
                if ( v12 >= 0 )
                {
                  if ( v12 < a2 )
                    v14 = v12;
                }
                else
                {
                  v14 = v12 + a2;
                }
                if ( v14 != v8 )
                {
                  if ( v33 > 0.0000099999997 )
                  {
                    v15 = (float *)&v7[v9];
                    *(_DWORD *)v15 = v8;
                    v9 += 2;
                    v15[1] = v33;
                  }
                  v8 = v14;
                  v33 = 0.0;
                }
                if ( v13 < v26 )
                  v13 = v26;
                if ( v29 > (double)v32 )
                  v29 = v32;
                if ( a3 )
                  goto LABEL_33;
                if ( v30 < 0.0 )
                {
                  v16 = 1.0;
                  goto LABEL_34;
                }
                if ( v30 + 1.0 < v22 )
LABEL_33:
                  v16 = (v29 + v13) * v21 - v30;
                else
                  v16 = 0.0;
LABEL_34:
                if ( v31 )
                  v16 = 1.0 - v16;
                ++v12;
                ++i;
                v33 = (v29 - v13) * v16 + v33;
                v13 = (double)v12;
                if ( v13 >= v32 )
                  break;
              }
            }
            ++v31;
          }
          while ( v31 < 2 );
          if ( v33 > 0.0000099999997 )
          {
            v17 = (float *)&v7[v9];
            v9 += 2;
            *(_DWORD *)v17 = v8;
            v17[1] = v33;
          }
          v33 = 0.0;
          ++v28;
          *v19 = v9 * 4 - v20;
          if ( v28 >= a1 )
          {
            *v7 = v9 * 4;
            return v7;
          }
        }
      }
    }
  }
  return 0;
}

