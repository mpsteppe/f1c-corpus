bool __fastcall sub_494C80(int a1, float *a2)
{
  int v2; // eax
  int v3; // ecx
  float *v4; // ebp
  float *v5; // ebx
  float *v6; // edx
  float *v7; // ecx
  float *v8; // esi
  float *v9; // edi
  double v11; // st7
  unsigned __int8 v12; // c0
  unsigned __int8 v13; // c2
  double v14; // st7
  double v15; // st6
  double v16; // st5
  float *v18; // [esp+0h] [ebp-18h]
  int i; // [esp+4h] [ebp-14h]
  int v20; // [esp+8h] [ebp-10h]
  float v22; // [esp+10h] [ebp-8h] BYREF
  float v23; // [esp+14h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a1 + 28);
  v3 = *(_DWORD *)(a1 + 32) - 1;
  v22 = (float)(v2 - 1);
  v4 = a2;
  v23 = (float)v3;
  v20 = 0;
  while ( 2 )
  {
    if ( v20 )
    {
      v5 = v4 + 3;
    }
    else
    {
      v5 = v4;
      v4 += 3;
    }
    for ( i = 0; i < 2; ++i )
    {
      v6 = v4 + 1;
      if ( i )
      {
        v18 = v4 + 1;
        v7 = v5 + 1;
        v8 = v5;
        v6 = v4;
        v9 = &v23;
      }
      else
      {
        v7 = v5;
        v8 = v5 + 1;
        v18 = v4;
        v9 = &v22;
      }
      v11 = *v7;
      if ( v12 | v13 )
      {
        v14 = -v11;
        v15 = *v18 - *v7;
        if ( v15 < v14 )
          return 0;
        v16 = *v6 - *v8;
        *v7 = 0.0;
      }
      else
      {
        if ( v11 <= *v9 )
          continue;
        v14 = *v9 - *v7;
        v15 = *v18 - *v7;
        if ( v15 >= v14 )
          return 0;
        v16 = *v6 - *v8;
        *v7 = *v9;
      }
      *v8 = v14 * (v16 / v15) + *v8;
    }
    if ( ++v20 < 2 )
    {
      v4 = a2;
      continue;
    }
    break;
  }
  return *a2 - a2[3] != 0.0 || a2[1] - a2[4] != 0.0;
}
