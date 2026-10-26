int __thiscall sub_45E910(_DWORD *this, int a2, int a3, int a4)
{
  _BYTE *v5; // eax
  _DWORD *v6; // ecx
  int v7; // edx
  int v8; // eax
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  _DWORD v14[5]; // [esp+5Ch] [ebp-14h] BYREF

  v5 = this + 224;
  v6 = this + 288;
  v7 = 256;
  do
  {
    *(v5 - 256) = 1;
    *v5 = 0;
    *v6++ = 0;
    ++v5;
    --v7;
  }
  while ( v7 );
  v8 = a4;
  this[800] = -1090519040;
  this[801] = -1110651699;
  *this = v8;
  this[159] = 1;
  if ( (*(int (__stdcall **)(int, int, int (__stdcall *)(const void *, int), int, int))(*(_DWORD *)dword_B69668 + 16))(
         dword_B69668,
         19,
         sub_45E800,
         19,
         1)
    || this[158] != 19
    || (*(int (__stdcall **)(int, void *, int *, _DWORD))(*(_DWORD *)dword_B69668 + 12))(
         dword_B69668,
         &unk_726964,
         &a4,
         0) )
  {
    return -1;
  }
  v9 = this + 1;
  this[1] = 0;
  if ( (**(int (__stdcall ***)(int, void *, int))a4)(a4, &unk_726A04, (int)(this + 1)) || !*v9 )
  {
    *v9 = 0;
    return -1;
  }
  else
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)a4 + 8))(a4);
    v10 = *v9;
    a4 = 0;
    if ( (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v10 + 52))(v10, a2, 4 * (a3 != 0) + 22)
      && (*(int (__stdcall **)(_DWORD, int, int))(*(_DWORD *)*v9 + 52))(*v9, a2, 4 * (a3 == 0) + 22) )
    {
      return -1;
    }
    v11 = *v9;
    this[147] = 44;
    if ( (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v11 + 12))(v11, this + 147) )
      return -1;
    if ( (*(int (__stdcall **)(_DWORD, void *))(*(_DWORD *)*v9 + 44))(*v9, &unk_7266B4) )
      return -1;
    if ( *this == 1
      && (v14[2] = 0,
          v14[3] = 0,
          v12 = *v9,
          v14[0] = 20,
          v14[1] = 16,
          v14[4] = 1024,
          (*(int (__stdcall **)(int, int, _DWORD *))(*(_DWORD *)v12 + 24))(v12, 1, v14)) )
    {
      return -1;
    }
    else
    {
      return -((*(int (__stdcall **)(_DWORD))(*(_DWORD *)*v9 + 28))(*v9) != 0);
    }
  }
}
