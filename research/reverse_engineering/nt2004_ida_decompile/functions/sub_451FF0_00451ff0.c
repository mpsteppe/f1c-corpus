int __thiscall sub_451FF0(_DWORD *this, int a2, int a3)
{
  _DWORD *v4; // eax
  int v5; // ecx
  int (__stdcall ***v6)(_DWORD, void *, int); // eax
  _DWORD *v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int (__stdcall ***v12)(_DWORD, void *, int); // [esp+50h] [ebp-18h] BYREF
  _DWORD v13[5]; // [esp+54h] [ebp-14h] BYREF

  v4 = this + 190;
  v5 = 8;
  do
  {
    *(v4 - 182) = 1028443341;
    *v4++ = 1065353216;
    --v5;
  }
  while ( v5 );
  if ( this[189] == 20
    || (dword_762B00 = 0,
        !(*(int (__stdcall **)(LPVOID, int, int (__stdcall *)(int, int), int, int))(*(_DWORD *)ppvOut + 16))(
           ppvOut,
           4,
           sub_451150,
           20,
           1))
    && this[189] == 20 )
  {
    if ( !(*(int (__stdcall **)(LPVOID, _DWORD *, int (__stdcall ****)(_DWORD, void *, int), _DWORD))(*(_DWORD *)ppvOut + 12))(
            ppvOut,
            this + 34,
            &v12,
            0) )
    {
      v6 = v12;
      v7 = this + 32;
      this[32] = 0;
      if ( (**v6)(v6, &unk_5F2A1C, (int)(this + 32)) || !*v7 )
      {
        *v7 = 0;
      }
      else
      {
        ((void (__stdcall *)(int (__stdcall ***)(_DWORD, void *, int)))(*v12)[2])(v12);
        v8 = *v7;
        v12 = 0;
        (*(void (__stdcall **)(int))(*(_DWORD *)v8 + 32))(v8);
        if ( !(*(int (__stdcall **)(_DWORD, void *))(*(_DWORD *)*v7 + 44))(*v7, &unk_5F28D4)
          && !(*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)*v7 + 52))(*v7, a2, 9) )
        {
          v9 = *v7;
          this[178] = 44;
          if ( !(*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v9 + 12))(v9, this + 178) )
          {
            v10 = *v7;
            v13[1] = 16;
            v13[0] = 20;
            memset(&v13[2], 0, 12);
            (*(void (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v10 + 24))(v10, 5, v13);
            (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v7 + 28))(*v7);
            return sub_451E80((int)this);
          }
        }
      }
    }
  }
  return -1;
}
