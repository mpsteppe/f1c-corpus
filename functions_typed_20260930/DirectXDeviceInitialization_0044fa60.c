int __thiscall DirectXDeviceInitialization(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // eax
  int v5; // ecx
  int (__stdcall ***v6)(_DWORD, void *, _DWORD *); // eax
  _DWORD *v7; // esi
  int v8; // ecx
  int v9; // eax
  int (__stdcall ***v11)(_DWORD, void *, _DWORD *); // [esp+50h] [ebp-18h] BYREF
  _DWORD v12[5]; // [esp+54h] [ebp-14h] BYREF

  v4 = this + 190;
  v5 = 8;
  do
  {
    *(v4 - 182) = 1028443341;
    *v4++ = 1065353216;
    --v5;
  }
  while ( v5 );
  if ( this[189] != 20 )
  {
    dword_7CB310 = 0;
    if ( (*(int (__stdcall **)(LPVOID, int, int (__stdcall *)(const void *, int), int, int))(*(_DWORD *)ppvOut + 16))(
           ppvOut,
           4,
           sub_44ED10,
           20,
           1)
      || this[189] != 20 )
    {
      return -1;
    }
  }
  if ( (*(int (__stdcall **)(LPVOID, _DWORD *, int (__stdcall ****)(_DWORD, void *, _DWORD *), _DWORD))(*(_DWORD *)ppvOut + 12))(
         ppvOut,
         this + 34,
         &v11,
         0) )
  {
    return -1;
  }
  v6 = v11;
  v7 = this + 32;
  this[32] = 0;
  if ( (**v6)(v6, &unk_5AD490, this + 32) )
    return -1;
  if ( !*v7 )
    return -1;
  ((void (__stdcall *)(int (__stdcall ***)(_DWORD, void *, _DWORD *)))(*v11)[2])(v11);
  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v7 + 32))(*v7);
  if ( (*(int (__stdcall **)(_DWORD, void *))(*(_DWORD *)*v7 + 44))(*v7, &unk_5B108C) )
    return -1;
  if ( (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)*v7 + 52))(*v7, a2, 9) )
    return -1;
  v8 = *v7;
  this[178] = 44;
  if ( (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v8 + 12))(v8, this + 178) )
    return -1;
  v9 = *v7;
  v12[1] = 16;
  v12[0] = 20;
  memset(&v12[2], 0, 12);
  (*(void (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v9 + 24))(v9, 5, v12);
  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v7 + 28))(*v7);
  return D3DTextureStage((int)this);
}

