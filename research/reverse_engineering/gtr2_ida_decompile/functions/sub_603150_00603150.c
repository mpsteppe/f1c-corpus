int __thiscall sub_603150(_DWORD *this, _DWORD *a2, _DWORD *a3, int a4)
{
  _DWORD *v4; // ebx
  int v6; // edi
  int v7; // ebp
  int v8; // eax
  int v10; // [esp+30h] [ebp-4h]

  v4 = a2;
  v10 = 1;
  if ( (*(_BYTE *)a2 & 0x10) != 0 && (*(_BYTE *)a3 & 0x10) != 0 )
    v10 = 6;
  v6 = 0;
  v7 = a4;
  while ( !(*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD **, int, _DWORD, int))(*this + 12))(
             this,
             v4,
             &a2,
             v7,
             *v4,
             v6)
       && !(*(int (__thiscall **)(_DWORD *, _DWORD *, int *, int, _DWORD, int))(*this + 12))(this, a3, &a4, v7, *a3, v6) )
  {
    v8 = sub_645971(a4, 0, 0, a2, 0, 0, 1, 0);
    this[2] = v8;
    if ( v8 )
    {
      sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x from D3DXLoadSurfaceFromSurface", v8);
      return -1;
    }
    if ( (*(_BYTE *)v4 & 0xC) != 0 )
      (*(void (__stdcall **)(_DWORD *))(*a2 + 8))(a2);
    if ( (*(_BYTE *)a3 & 0xC) != 0 )
      (*(void (__stdcall **)(int))(*(_DWORD *)a4 + 8))(a4);
    if ( ++v6 >= v10 )
      return 0;
  }
  return -1;
}
