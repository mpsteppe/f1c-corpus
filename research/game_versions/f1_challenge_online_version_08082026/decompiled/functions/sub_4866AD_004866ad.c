int __userpurge sub_4866AD@<eax>(char a1@<bl>, int a2@<esi>, int a3)
{
  int result; // eax
  _DWORD *v4; // esi

  result = (*(int (__cdecl **)(int))(*(_DWORD *)a2 + 44))(1);
  *(_BYTE *)(a2 + 101) = a1;
  v4 = *(_DWORD **)(a2 + 144);
  if ( v4 )
  {
    do
    {
      (*(void (__thiscall **)(_DWORD *, char))(*v4 + 60))(v4, a1);
      result = sub_486320(v4);
      v4 = (_DWORD *)result;
    }
    while ( result );
  }
  return result;
}
