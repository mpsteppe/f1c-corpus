_DWORD *__stdcall sub_48BA50(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // esi
  _DWORD *result; // eax

  if ( *a2 == *a3 )
  {
    result = a4;
    *a4 = 10;
    a4[1] = 10;
  }
  else
  {
    v4 = a3[1] - (__int64)((double)(a3[1] - a2[1]) / (double)(*a3 - *a2) * (double)(*a3 - a1));
    result = a4;
    *a4 = a1;
    a4[1] = v4;
  }
  return result;
}
