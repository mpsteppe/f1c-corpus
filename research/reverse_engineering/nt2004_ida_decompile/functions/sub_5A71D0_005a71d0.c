int __stdcall sub_5A71D0(int a1, int a2, int a3)
{
  int result; // eax
  int v4; // ebx

  result = a3;
  LOBYTE(v4) = a3;
  if ( !a3 )
    v4 = *(_DWORD *)(a1 + 56);
  if ( (v4 & 1) != 0 )
  {
    result = *(_DWORD *)(a1 + 12);
  }
  else
  {
    if ( (v4 & 2) == 0 )
      goto LABEL_9;
    result = *(_DWORD *)(a1 + 16);
  }
  if ( result )
    result = (*(int (__stdcall **)(int))(*(_DWORD *)result + 40))(result);
LABEL_9:
  if ( (v4 & 4) != 0 )
    return (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(a1 + 20) + 68))(*(_DWORD *)(a1 + 20), a2);
  return result;
}
