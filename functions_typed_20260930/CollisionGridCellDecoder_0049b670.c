int __stdcall CollisionGridCellDecoder(float a1, int *a2, _DWORD *a3, float *a4)
{
  int v4; // eax
  float v6; // [esp+0h] [ebp-14h]
  int v7; // [esp+10h] [ebp-4h]

  v4 = CRTFtol(a1);
  v7 = CRTFtol((double)v4 * 0.00027777778);
  *a2 = v7;
  v6 = a1 - (double)v7 * 3600.0;
  return SpatialGridCell(v6, a3, a4);
}

