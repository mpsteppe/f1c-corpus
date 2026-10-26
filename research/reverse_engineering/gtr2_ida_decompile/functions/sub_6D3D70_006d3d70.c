_DWORD *__stdcall sub_6D3D70(int *a1, int a2)
{
  _DWORD *result; // eax
  int v3; // eax

  result = (_DWORD *)a1[86];
  if ( !a1[44] )
  {
    result[2] = 0;
    result[3] = 0;
    result[4] = 0;
    result[5] = a2;
    if ( a2 )
    {
      v3 = *a1;
      *(_DWORD *)(v3 + 20) = 4;
      return (_DWORD *)(*(int (__stdcall **)(int *))v3)(a1);
    }
    else
    {
      result[1] = sub_6D3CC0;
    }
  }
  return result;
}
