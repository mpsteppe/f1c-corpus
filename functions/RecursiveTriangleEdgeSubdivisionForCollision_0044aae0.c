int __stdcall sub_44AAE0(_DWORD *a1, int a2, int a3, int a4, char **a5)
{
  double v5; // st7
  char v7[16]; // [esp+10h] [ebp-28h] BYREF
  double v8; // [esp+20h] [ebp-18h]
  double v9; // [esp+28h] [ebp-10h]

  Vec3Subtract(v7, (int)a1, a2);
  v8 = EmptyFunction(v7);
  Vec3Subtract(v7, a2, a3);
  v9 = EmptyFunction(v7);
  Vec3Subtract(v7, a3, (int)a1);
  v5 = EmptyFunction(v7);
  if ( v8 < v9 || v8 < v5 || v8 <= 22500.0 )
  {
    if ( v9 < v8 || v9 < v5 || v9 <= 22500.0 )
    {
      if ( v5 < v8 || v5 < v9 || v5 <= 22500.0 )
      {
        return TriangleMeshAdjacencyBuilder(a5, a1, a2, a3, a4, 0);
      }
      else
      {
        WeightedAverageInterpolation(v7, a3, (int)a1);
        RecursiveTriangleEdgeSubdivisionForCollision(a1, a2, v7, a4, a5);
        return RecursiveTriangleEdgeSubdivisionForCollision(v7, a2, a3, a4, a5);
      }
    }
    else
    {
      WeightedAverageInterpolation(v7, a2, a3);
      RecursiveTriangleEdgeSubdivisionForCollision(a1, a2, v7, a4, a5);
      return RecursiveTriangleEdgeSubdivisionForCollision(a1, v7, a3, a4, a5);
    }
  }
  else
  {
    WeightedAverageInterpolation(v7, (int)a1, a2);
    RecursiveTriangleEdgeSubdivisionForCollision(a1, v7, a3, a4, a5);
    return RecursiveTriangleEdgeSubdivisionForCollision(v7, a2, a3, a4, a5);
  }
}
