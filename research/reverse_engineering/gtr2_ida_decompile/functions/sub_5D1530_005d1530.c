_DWORD *__stdcall sub_5D1530(_DWORD *a1, int a2, _DWORD *a3)
{
  int v3; // edx
  _DWORD *result; // eax

  v3 = *(_DWORD *)(a2 + 76);
  result = a3;
  if ( (v3 & 2) == 0 )
  {
    a1[4] = a3[57];
    a1[5] = a3[58];
    a1[6] = a3[59];
  }
  if ( (v3 & 4) == 0 )
  {
    *a1 = a3[53];
    a1[1] = a3[54];
    a1[2] = a3[55];
    a1[3] = a3[56];
  }
  if ( (v3 & 8) == 0 )
  {
    a1[7] = a3[60];
    a1[8] = a3[61];
    result = (_DWORD *)a3[62];
    a1[9] = result;
  }
  return result;
}
