void __thiscall sub_4F0F50(char *Base)
{
  signed int v1; // edi
  void *v2; // esi
  int v3; // edx
  size_t v4; // ebx
  float *v5; // eax
  signed int i; // ecx
  double v7; // st7

  v1 = NumOfElements;
  v2 = Base;
  if ( (int)NumOfElements > 0 )
  {
    v3 = (char *)dword_75AAD0 - Base;
    v4 = NumOfElements;
    do
    {
      v5 = (float *)(*(_DWORD *)&Base[v3] + 84);
      *(_DWORD *)Base = v5;
      Base += 4;
      --v4;
      v5[1166] = v5[462] * v5[1165] + v5[461] * v5[1164] + v5[460] * v5[1163];
      v5[1167] = v5[463] * v5[1163] + v5[465] * v5[1165] + v5[464] * v5[1164];
      v5[1168] = v5[466] * v5[1163] + v5[468] * v5[1165] + v5[467] * v5[1164];
      v5[1166] = v5[1166] + v5[454];
      v5[1167] = v5[455] + v5[1167];
      v5[1168] = v5[456] + v5[1168];
    }
    while ( v4 );
  }
  qsort(v2, v1, 4u, sub_4F0EF0);
  for ( i = 0; i < v1; *((float *)v2 + i + 47) = v7 )
  {
    v7 = *(float *)(*((_DWORD *)v2 + i) + 4672) + *(float *)(*((_DWORD *)v2 + i) + 4664);
    ++i;
  }
}
