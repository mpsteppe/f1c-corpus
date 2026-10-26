int __thiscall sub_601300(int this)
{
  int v2; // eax
  IDirect3D9 *v3; // eax
  char v5; // [esp+0h] [ebp-8h]

  if ( *(_DWORD *)(this + 9544) )
  {
    v2 = *(_DWORD *)(this + 9548);
    if ( v2 )
    {
      *(_DWORD *)(this + 8) = (*(int (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
      *(_DWORD *)(this + 9548) = 0;
      memset((void *)(this + 9552), 0, 0x38u);
    }
    *(_DWORD *)(this + 8) = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(this + 9544) + 8))(*(_DWORD *)(this + 9544));
    *(_DWORD *)(this + 9544) = 0;
  }
  v3 = Direct3DCreate9(0x20u);
  *(_DWORD *)(this + 9544) = v3;
  if ( v3 )
  {
    *(_DWORD *)(this + 9012) = 0;
    *(_DWORD *)(this + 9664) = 0;
    *(_DWORD *)(this + 9668) = 0;
    *(_DWORD *)(this + 9672) = 0;
    *(_DWORD *)(this + 9676) = 0;
    *(_DWORD *)(this + 9680) = 0;
    *(_DWORD *)(this + 9684) = 0;
    *(_DWORD *)(this + 9688) = 0;
    *(_DWORD *)(this + 9692) = 0;
    return 0;
  }
  else
  {
    sub_5D8C80(this + 4, (char *)0xFFFFFFFF, "Error creating the Direct3D9 object", v5);
    return -1;
  }
}
