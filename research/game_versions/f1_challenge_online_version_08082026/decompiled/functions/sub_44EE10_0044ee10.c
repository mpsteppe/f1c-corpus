int __thiscall sub_44EE10(_DWORD *this, int a2, int a3, int a4)
{
  _BYTE *v5; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  _DWORD v13[5]; // [esp+5Ch] [ebp-14h] BYREF

  v5 = this + 223;
  v6 = this + 287;
  do
  {
    *(v5 - 256) = 1;
    *v5 = 0;
    *v6++ = 0;
    ++v5;
  }
  while ( (int)&v5[-892 - (_DWORD)this] < 256 );
  v7 = a4;
  this[799] = -1090519040;
  this[800] = -1110651699;
  *this = v7;
  if ( !(*(int (__stdcall **)(LPVOID, int, int (__stdcall *)(int, int), int, int))(*(_DWORD *)ppvOut + 16))(
          ppvOut,
          19,
          sub_44ED10,
          19,
          1)
    && this[158] == 19
    && !(*(int (__stdcall **)(LPVOID, void *, int *, _DWORD))(*(_DWORD *)ppvOut + 12))(ppvOut, &unk_5AD3F0, &a4, 0) )
  {
    v8 = this + 1;
    this[1] = 0;
    if ( (**(int (__stdcall ***)(int, void *, int))a4)(a4, &unk_5AD490, (int)(this + 1)) || !*v8 )
    {
      *v8 = 0;
    }
    else
    {
      (*(void (__stdcall **)(int))(*(_DWORD *)a4 + 8))(a4);
      v9 = *v8;
      a4 = 0;
      if ( !(*(int (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 52))(v9, a2, 4 * (a3 != 0) + 22)
        || !(*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)*v8 + 52))(*v8, a2, 4 * (a3 == 0) + 22) )
      {
        v10 = *v8;
        this[147] = 44;
        if ( !(*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v10 + 12))(v10, this + 147)
          && !(*(int (__stdcall **)(_DWORD, void *))(*(_DWORD *)*v8 + 44))(*v8, &unk_5B0E84) )
        {
          if ( *this != 1 )
            return -((*(int (__stdcall **)(_DWORD))(*(_DWORD *)*v8 + 28))(*v8) != 0);
          v13[2] = 0;
          v13[3] = 0;
          v11 = *v8;
          v13[0] = 20;
          v13[1] = 16;
          v13[4] = 1024;
          if ( !(*(int (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v11 + 24))(v11, 1, v13) )
            return -((*(int (__stdcall **)(_DWORD))(*(_DWORD *)*v8 + 28))(*v8) != 0);
        }
      }
    }
  }
  return -1;
}
