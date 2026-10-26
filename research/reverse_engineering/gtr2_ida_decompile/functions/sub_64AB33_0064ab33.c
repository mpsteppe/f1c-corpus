_DWORD *__stdcall sub_64AB33(unsigned int a1, signed int a2, int a3)
{
  unsigned int v3; // edi
  double v4; // st7
  double v5; // st6
  size_t v6; // esi
  __int64 v7; // rax
  _DWORD *v8; // edi
  int v9; // ebx
  int v10; // esi
  double v11; // st7
  double v12; // st7
  int v13; // edx
  double v14; // st7
  int v15; // ecx
  float *v16; // eax
  double v17; // st6
  float *v18; // eax
  float v20; // [esp+0h] [ebp-4Ch]
  _DWORD *v21; // [esp+10h] [ebp-3Ch]
  int v22; // [esp+14h] [ebp-38h]
  float v23; // [esp+18h] [ebp-34h]
  float v24; // [esp+1Ch] [ebp-30h]
  float v25; // [esp+20h] [ebp-2Ch]
  float v26; // [esp+24h] [ebp-28h]
  int i; // [esp+28h] [ebp-24h]
  float v28; // [esp+2Ch] [ebp-20h]
  float v29; // [esp+30h] [ebp-1Ch]
  unsigned int v30; // [esp+34h] [ebp-18h]
  float v31; // [esp+38h] [ebp-14h]
  float v32; // [esp+3Ch] [ebp-10h]
  unsigned int v33; // [esp+40h] [ebp-Ch]
  float v34; // [esp+44h] [ebp-8h]
  float v35; // [esp+48h] [ebp-4h]

  v3 = 0;
  if ( a1 )
  {
    if ( a2 )
    {
      v29 = (float)(unsigned int)a2;
      v4 = (double)a1;
      v24 = v4;
      v5 = v29 / v4;
      v6 = 16;
      v26 = v5;
      v23 = 0.5 / v5;
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
        v30 = 0;
        v35 = 0.0;
        v10 = 1;
        while ( 1 )
        {
          v33 = 0;
          v21 = &v8[v10];
          v22 = v10 * 4;
          ++v10;
          do
          {
            v25 = (float)v30;
            v11 = (double)v33 + v25 - 0.5;
            v32 = v11;
            v12 = v11 * v26;
            v28 = v12;
            v34 = v26 + v12;
            if ( !a3 )
            {
              if ( v12 < 0.0 )
              {
                v12 = 0.0;
                v28 = 0.0;
              }
              if ( v34 > (double)v29 )
                v34 = (float)(unsigned int)a2;
            }
            v20 = v12;
            v13 = (__int64)sub_64AB05(v20);
            v14 = (double)v13;
            if ( v14 < v34 )
            {
              v15 = v13 - a2;
              for ( i = v13 - a2; ; v15 = i )
              {
                v31 = v14 + 1.0;
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
                  if ( v35 > 0.0000099999997 )
                  {
                    v16 = (float *)&v8[v10];
                    *(_DWORD *)v16 = v9;
                    v10 += 2;
                    v16[1] = v35;
                  }
                  v9 = v15;
                  v35 = 0.0;
                }
                if ( v14 < v28 )
                  v14 = v28;
                if ( v31 > (double)v34 )
                  v31 = v34;
                if ( a3 )
                  goto LABEL_33;
                if ( v32 < 0.0 )
                {
                  v17 = 1.0;
                  goto LABEL_34;
                }
                if ( v32 + 1.0 < v24 )
LABEL_33:
                  v17 = (v31 + v14) * v23 - v32;
                else
                  v17 = 0.0;
LABEL_34:
                if ( v33 )
                  v17 = 1.0 - v17;
                ++v13;
                ++i;
                v35 = (v31 - v14) * v17 + v35;
                v14 = (double)v13;
                if ( v14 >= v34 )
                  break;
              }
            }
            ++v33;
          }
          while ( v33 < 2 );
          if ( v35 > 0.0000099999997 )
          {
            v18 = (float *)&v8[v10];
            v10 += 2;
            *(_DWORD *)v18 = v9;
            v18[1] = v35;
          }
          v35 = 0.0;
          ++v30;
          *v21 = v10 * 4 - v22;
          if ( v30 >= a1 )
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
