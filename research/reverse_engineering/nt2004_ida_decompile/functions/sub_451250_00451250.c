int __thiscall sub_451250(_DWORD *this, int a2, int a3, int a4)
{
  _BYTE *v5; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  _DWORD v13[5]; // [esp+5Ch] [ebp-14h] BYREF

  v5 = this + 224;
  v6 = this + 288;
  do
  {
    *(v5 - 256) = 1;
    *v5 = 0;
    *v6++ = 0;
    ++v5;
  }
  while ( (int)&v5[-896 - (_DWORD)this] < 256 );
  v7 = a4;
  this[800] = -1090519040;
  this[801] = -1110651699;
  *this = v7;
  this[159] = 1;
  if ( !(*(int (__stdcall **)(LPVOID, int, int (__stdcall *)(int, int), int, int))(*(_DWORD *)ppvOut + 16))(
          ppvOut,
          19,
          sub_451150,
          19,
          1)
    && this[158] == 19
    && !(*(int (__stdcall **)(LPVOID, void *, int *, _DWORD))(*(_DWORD *)ppvOut + 12))(ppvOut, &unk_5F297C, &a4, 0) )
  {
    v8 = this + 1;
    this[1] = 0;
    if ( (**(int (__stdcall ***)(int, void *, int))a4)(a4, &unk_5F2A1C, (int)(this + 1)) || !*v8 )
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
          && !(*(int (__stdcall **)(_DWORD, void *))(*(_DWORD *)*v8 + 44))(*v8, &unk_5F26CC) )
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
