_DWORD *__stdcall sub_475CC0(int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  int v4; // esi
  int v5; // esi
  _DWORD *result; // eax

  if ( *a2 == *a3 )
  {
    result = a4;
    *a4 = 10;
    a4[1] = 10;
  }
  else
  {
    v4 = a3[1];
    v5 = v4 - CRTFtol((double)(v4 - a2[1]) / (double)(*a3 - *a2) * (double)(*a3 - a1));
    result = a4;
    *a4 = a1;
    a4[1] = v5;
  }
  return result;
}
