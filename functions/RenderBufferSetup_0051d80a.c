int __usercall sub_51D80A@<eax>(int a1@<edi>, int a2)
{
  int *v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // eax
  int *v7; // [esp+8h] [ebp-4h]
  int v8; // [esp+14h] [ebp+8h]

  v2 = (int *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 32 * a2);
  v2[1] = 31;
  v2[5] = 31;
  *v2 = 0;
  v2[2] = 0;
  v2[3] = 63;
  v2[4] = 0;
  GridOccupancyBoundingBoxScan(a1, v2);
  v3 = sub_51D57F(a1, (int)v2, 1, a2);
  v8 = 0;
  v4 = v3;
  if ( v3 > 0 )
  {
    v7 = v2;
    do
    {
      F_2DImageWeightedAverage(v7, a1, v8++);
      v7 += 8;
    }
    while ( v8 < v4 );
  }
  v5 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 112) = v4;
  *(_DWORD *)(v5 + 20) = 95;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = v4;
  return (*(int (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, 1);
}
