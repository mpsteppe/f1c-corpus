int __stdcall sub_677144(_DWORD *a1)
{
  int v1; // eax
  int v2; // esi

  v1 = a1[1];
  v2 = v1 - 1;
  a1[1] = v1 - 1;
  if ( v1 == 1 )
    (*(void (__thiscall **)(_DWORD *, int))(*a1 + 20))(a1, 1);
  return v2;
}
