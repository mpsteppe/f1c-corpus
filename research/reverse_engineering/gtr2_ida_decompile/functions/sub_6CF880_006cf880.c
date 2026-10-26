int __usercall sub_6CF880@<eax>(_DWORD *a1@<esi>)
{
  int v1; // ecx
  _DWORD *v2; // ebx
  int result; // eax
  int v4; // ecx

  v1 = a1[111];
  v2 = (_DWORD *)a1[112];
  *(_DWORD *)(v1 + 24) += v2[4] / 8;
  v2[4] = 0;
  result = (*(int (__stdcall **)(_DWORD *))(v1 + 8))(a1);
  if ( result )
  {
    v4 = a1[83];
    if ( v4 > 0 )
      memset(v2 + 5, 0, 4 * v4);
    v2[9] = a1[70];
    if ( !a1[105] )
      v2[2] = 0;
    return 1;
  }
  return result;
}
