int __thiscall sub_602EB0(int this, void **a2)
{
  void **v2; // ebx
  int *v3; // edi
  int v5; // edi
  int v6; // eax
  char v8; // [esp+0h] [ebp-Ch]

  v2 = a2;
  v3 = (int *)a2[29];
  if ( v3 && sub_5E7120(v3, 2) )
  {
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, void ***))(**(_DWORD **)(this + 9548) + 160))(
                              *(_DWORD *)(this + 9548),
                              &a2);
    if ( a2 )
      (*((void (__stdcall **)(void **))*a2 + 2))(a2);
    v5 = sub_5E7120(v3, 2);
    if ( (void **)v5 == a2 )
      *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)(this + 9548) + 156))(
                                *(_DWORD *)(this + 9548),
                                0);
    v6 = (*(int (__stdcall **)(int))(*(_DWORD *)v5 + 8))(v5);
    *(_DWORD *)(this + 8) = v6;
    if ( v6 )
    {
      sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Reference count not zero while releasing zbuffer", v8);
      return -1;
    }
    sub_5E6E40(v2);
  }
  return 0;
}
