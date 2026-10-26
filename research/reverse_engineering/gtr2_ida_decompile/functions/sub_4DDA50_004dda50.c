bool __userpurge sub_4DDA50@<al>(int a1@<eax>, float *a2)
{
  int v2; // edx
  float *v3; // edi
  float *v4; // ebx
  float *v5; // ecx
  float *v6; // edx
  float *v7; // ebp
  float *v8; // esi
  double v10; // st7
  unsigned __int8 v11; // c0
  unsigned __int8 v12; // c2
  double v13; // st7
  double v14; // st6
  double v15; // st5
  float *v17; // [esp+0h] [ebp-14h]
  int i; // [esp+4h] [ebp-10h]
  int v19; // [esp+8h] [ebp-Ch]
  float v20; // [esp+Ch] [ebp-8h] BYREF
  float v21; // [esp+10h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a1 + 8) - 1;
  v20 = (float)(*(_DWORD *)(a1 + 4) - 1);
  v19 = 0;
  v21 = (float)v2;
  while ( 2 )
  {
    if ( v19 )
    {
      v4 = a2;
      v3 = a2 + 3;
    }
    else
    {
      v3 = a2;
      v4 = a2 + 3;
    }
    for ( i = 0; i < 2; ++i )
    {
      if ( i )
      {
        v5 = v3 + 1;
        v6 = v3;
        v17 = v4 + 1;
        v7 = v4;
        v8 = &v21;
      }
      else
      {
        v5 = v3;
        v6 = v3 + 1;
        v17 = v4;
        v7 = v4 + 1;
        v8 = &v20;
      }
      v10 = *v5;
      if ( v11 | v12 )
      {
        v13 = -v10;
        v14 = *v17 - *v5;
        if ( v14 < v13 )
          return 0;
        v15 = *v7 - *v6;
        *v5 = 0.0;
      }
      else
      {
        if ( v10 <= *v8 )
          continue;
        v13 = *v8 - *v5;
        v14 = *v17 - *v5;
        if ( v14 >= v13 )
          return 0;
        v15 = *v7 - *v6;
        *v5 = *v8;
      }
      *v6 = v13 * (v15 / v14) + *v6;
    }
    if ( ++v19 < 2 )
      continue;
    break;
  }
  return 0.0 != *a2 - a2[3] || 0.0 != a2[1] - a2[4];
}
