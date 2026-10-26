_DWORD *__stdcall sub_6CE380(int *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // eax
  _DWORD *result; // eax

  v2 = (_DWORD *)a1[107];
  if ( a2 )
  {
    v3 = *a1;
    *(_DWORD *)(v3 + 20) = 4;
    return (_DWORD *)(*(int (__stdcall **)(int *))v3)(a1);
  }
  else
  {
    result = (_DWORD *)a1[114];
    if ( result[2] )
    {
      v2[1] = sub_6CE250;
      result = sub_6CDF00(a1);
      v2[16] = 0;
      v2[17] = 0;
      v2[19] = 0;
      v2[12] = 0;
      v2[13] = 0;
    }
    else
    {
      v2[12] = 0;
      v2[13] = 0;
      v2[1] = sub_6CE1D0;
    }
  }
  return result;
}
