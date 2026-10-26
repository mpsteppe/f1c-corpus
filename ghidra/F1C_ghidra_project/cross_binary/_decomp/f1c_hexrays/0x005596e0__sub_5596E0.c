// f1c  0x005596e0  size=120
_DWORD *__stdcall sub_5596E0(int *a1)
{
  _DWORD *result; // eax
  int v2; // ebx
  _DWORD *i; // esi
  int v4; // ecx

  result = (_DWORD *)a1[2];
  v2 = *a1;
  if ( result )
  {
    for ( i = (_DWORD *)result[137]; i; i = (_DWORD *)i[1] )
    {
      result = (_DWORD *)*i;
      if ( *(_DWORD *)(*i + 20) == *(_DWORD *)(v2 + 544) )
      {
        v4 = result[6];
        if ( *(_DWORD *)(v4 + 20) )
        {
          a1[8] = *(_DWORD *)(v4 + 24);
          result = (_DWORD *)(*(int (__thiscall **)(int *))(result[6] + 20))(a1);
        }
      }
    }
  }
  if ( v2 )
  {
    result = *(_DWORD **)(v2 + 544);
    if ( result )
    {
      if ( result[5] )
      {
        a1[8] = result[6];
        return (_DWORD *)(*(int (__thiscall **)(int *))(*(_DWORD *)(v2 + 544) + 20))(a1);
      }
    }
  }
  return result;
}
