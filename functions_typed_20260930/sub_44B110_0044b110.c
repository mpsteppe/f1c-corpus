int __stdcall sub_44B110(int *a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // esi
  int v4; // edx
  int v5; // edx
  int v6; // eax
  int v8; // eax
  int v9; // eax
  int v10; // [esp+10h] [ebp-88h]
  __int16 v11; // [esp+14h] [ebp-84h] BYREF
  char v12; // [esp+16h] [ebp-82h]
  int i; // [esp+18h] [ebp-80h]
  int v14; // [esp+1Ch] [ebp-7Ch]
  int v15; // [esp+20h] [ebp-78h] BYREF
  _DWORD v16[6]; // [esp+24h] [ebp-74h] BYREF
  _DWORD v17[23]; // [esp+3Ch] [ebp-5Ch] BYREF

  RGBColorPacking(*a1, &v15);
  CollisionFaceVerticesGather(v16, (int)a1);
  CollisionCapsuleShapeCopyToPipeline(v16, (int)&v15, v17);
  v1 = 0;
  v2 = 2 - (_DWORD)&v11;
  v10 = 0;
  for ( i = 2 - (_DWORD)&v11; ; v2 = i )
  {
    *((_BYTE *)&v11 + v1) = 0;
    v3 = v1;
    if ( v1 < (int)&v11 + v1 + v2 )
    {
      while ( TriangleProximityTest(
                (int)&a1[23 * (v3 == 3 ? 0 : v3) + 4],
                (int)v17,
                *(_DWORD *)(a1[v3 == 3 ? 0 : v3] + 8 * v1 + 4)) )
      {
        if ( ++v3 >= v4 )
          goto LABEL_8;
      }
      *((_BYTE *)&v11 + v1) = 1;
      ++v10;
    }
LABEL_8:
    if ( ++v1 >= 3 )
      break;
  }
  v5 = 1;
  if ( v10 > 1 )
    return 0;
  if ( !v10 )
  {
    v3 = 0;
    while ( 1 )
    {
      v6 = v3 == 2 ? 0 : v3 + 1;
      if ( !TriangleProximityTest((int)&a1[23 * v3 + 4], (int)v17, *(_DWORD *)(a1[v3] + 8 * v6 + 4)) )
        break;
      if ( ++v3 >= 3 )
        return 4;
    }
    v11 = 257;
    v12 = 1;
    v1 = 3;
  }
  v8 = 0;
  i = 0;
  while ( !*((_BYTE *)&v11 + v8) )
  {
LABEL_31:
    i = ++v8;
    if ( v8 >= 3 )
      return 0;
  }
  if ( !v8 )
  {
    v10 = v5;
    v1 = 0;
    v3 = v5;
    v14 = 2;
    goto LABEL_27;
  }
  v9 = v8 - 1;
  if ( !v9 )
  {
    v3 = 2;
    v10 = 2;
    v1 = v5;
    v14 = 0;
    AxisPermutationMatrixRead(v16, (int)a1, 2, 0);
    goto LABEL_28;
  }
  if ( v9 != 1 )
  {
LABEL_27:
    AxisPermutationMatrixRead(v16, (int)a1, v10, 0);
    goto LABEL_28;
  }
  v10 = 3;
  v1 = 2;
  v3 = 0;
  v14 = v5;
  AxisPermutationMatrixRead(v16, (int)a1, 3, 0);
LABEL_28:
  CollisionCapsuleShapeCopyToPipeline(v16, (int)&v15, v17);
  if ( !TriangleProximityTest((int)&a1[23 * v1 + 4], (int)v17, *(_DWORD *)(a1[v1] + 8 * v3 + 4))
    || (AxisPermutationMatrixRead(v16, (int)a1, v10, 1),
        CollisionCapsuleShapeCopyToPipeline(v16, (int)&v15, v17),
        !TriangleProximityTest((int)&a1[23 * v3 + 4], (int)v17, *(_DWORD *)(a1[v3] + 8 * v14 + 4))) )
  {
    v8 = i;
    v5 = 1;
    goto LABEL_31;
  }
  return v10;
}

