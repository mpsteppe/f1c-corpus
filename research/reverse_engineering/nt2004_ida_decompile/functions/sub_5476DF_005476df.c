int __fastcall sub_5476DF(_DWORD *a1)
{
  unsigned int v1; // edx
  float *v2; // eax
  int v3; // edx
  int v4; // esi
  int v5; // ebx
  int v6; // edi
  float v8; // [esp+4h] [ebp-28h]
  float v9; // [esp+4h] [ebp-28h]
  float v10; // [esp+Ch] [ebp-20h]
  float v11; // [esp+Ch] [ebp-20h]
  float v12; // [esp+14h] [ebp-18h]
  float v13; // [esp+14h] [ebp-18h]
  float v14; // [esp+1Ch] [ebp-10h]
  _WORD *v15; // [esp+20h] [ebp-Ch]
  unsigned int v16; // [esp+24h] [ebp-8h]
  _DWORD *v17; // [esp+28h] [ebp-4h]

  v17 = a1;
  if ( a1[1059] && a1[1060] )
  {
    v1 = a1[1052];
    v15 = (_WORD *)(a1[6] + a1[1044] * a1[1053] + a1[1045] * a1[1056] + 2 * v1);
    v2 = (float *)a1[1051];
    v16 = v1;
    if ( v1 < a1[1054] )
    {
      do
      {
        v12 = v2[4] * 65.481003 + v2[6] * 24.966 + v2[5] * 128.55299;
        v10 = v2[2] * 112.0 - v2[1] * 74.203003 - *v2 * 37.797001;
        v8 = *v2 * 112.0 - (v2[1] * 93.786003 + v2[2] * 18.214001);
        v14 = *v2 * 65.481003 + v2[1] * 128.55299 + v2[2] * 24.966 + 0.5;
        v3 = (int)v14 + 16;
        v13 = v12 + 0.5;
        v4 = (int)v13 + 16;
        v11 = v10 + 0.5;
        v5 = (int)v11 + 128;
        v9 = v8 + 0.5;
        v6 = (int)v9 + 128;
        if ( v3 >= 0 )
        {
          if ( v3 > 255 )
            v3 = 255;
        }
        else
        {
          v3 = 0;
        }
        if ( v4 >= 0 )
        {
          if ( v4 > 255 )
            LOWORD(v4) = 255;
        }
        else
        {
          LOWORD(v4) = 0;
        }
        if ( v5 >= 0 )
        {
          if ( v5 > 255 )
            v5 = 255;
        }
        else
        {
          v5 = 0;
        }
        if ( v6 >= 0 )
        {
          if ( v6 > 255 )
            LOWORD(v6) = 255;
        }
        else
        {
          LOWORD(v6) = 0;
        }
        v16 += 2;
        v2 += 8;
        *v15 = (v5 << v17[1062]) | (v3 << v17[1061]);
        v15 += 2;
        *(v15 - 1) = ((_WORD)v6 << v17[1062]) | ((_WORD)v4 << v17[1061]);
        a1 = v17;
      }
      while ( v16 < v17[1054] );
    }
    a1[1059] = 0;
  }
  return 0;
}
