int __thiscall sub_603DD0(
        _DWORD *this,
        int a2,
        int a3,
        int a4,
        _DWORD *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  _DWORD *v12; // ebp
  int v14; // ebx
  int v15; // edi
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // [esp+68h] [ebp-40h] BYREF
  int v24; // [esp+6Ch] [ebp-3Ch] BYREF
  int v25; // [esp+70h] [ebp-38h] BYREF
  int v26; // [esp+74h] [ebp-34h]
  int v27; // [esp+78h] [ebp-30h] BYREF
  int v28; // [esp+7Ch] [ebp-2Ch]
  int v29; // [esp+80h] [ebp-28h]
  int v30; // [esp+84h] [ebp-24h]
  int v31; // [esp+88h] [ebp-20h] BYREF
  int v32; // [esp+8Ch] [ebp-1Ch]
  int v33; // [esp+90h] [ebp-18h]
  int v34; // [esp+94h] [ebp-14h]
  _DWORD v35[4]; // [esp+98h] [ebp-10h] BYREF

  v12 = a5;
  v14 = 0;
  v15 = 1;
  if ( *(_DWORD *)(a2 + 24) == a5[6] )
  {
    if ( (*(_BYTE *)a2 & 5) != 0 )
    {
      if ( (*a5 & 5) != 0 )
      {
        v15 = 0;
      }
      else if ( (*a5 & 0xA) != 0 )
      {
        v15 = 1;
      }
    }
  }
  else if ( (*a5 & 0x2000) == 0 )
  {
    v15 = 0;
    v14 = 1;
  }
  if ( (*(int (__thiscall **)(_DWORD *, int, int *, _DWORD, _DWORD, int))(*this + 12))(this, a2, &v23, 0, 0, 2)
    || (*(int (__thiscall **)(_DWORD *, _DWORD *, int *, _DWORD, _DWORD, int))(*this + 12))(this, a5, &v24, 0, 0, 2) )
  {
    return -1;
  }
  if ( v15 )
  {
    v28 = a4;
    v27 = a3;
    v29 = a8 + a3;
    v16 = this[2387];
    v30 = a9 + a4;
    v25 = a6;
    v26 = a7;
    v17 = (*(int (__stdcall **)(int, int, int *, int, int *))(*(_DWORD *)v16 + 120))(v16, v23, &v27, v24, &v25);
    this[2] = v17;
    if ( v17 )
    {
      v32 = a7;
      v31 = a6;
      v33 = a8 + a6;
      v34 = a9 + a7;
      v18 = sub_645971(v24, 0, &v31, v23, 0, &v27, 1, a10);
      this[2] = v18;
      if ( v18 )
        return -1;
    }
    v12 = a5;
  }
  else
  {
    v32 = a4;
    v31 = a3;
    if ( v14 )
    {
      v33 = a8 + a3;
      v34 = a9 + a4;
      v27 = a6;
      v28 = a7;
      v29 = a8 + a6;
      v30 = a9 + a7;
      v20 = sub_645971(v24, 0, &v27, v23, 0, &v31, 1, a10);
      this[2] = v20;
      if ( v20 )
        return -1;
    }
    else
    {
      v34 = a9 + a4;
      v33 = a8 + a3;
      v21 = (*(int (__stdcall **)(int, int *, int *, int))(*(_DWORD *)v23 + 52))(v23, &v27, &v31, 16);
      this[2] = v21;
      if ( v21 )
        return -1;
      v35[1] = a7;
      v35[3] = a9 + a7;
      v35[0] = a6;
      v35[2] = a8 + a6;
      v22 = (*(int (__stdcall **)(int, int *, _DWORD *, _DWORD))(*(_DWORD *)v24 + 52))(v24, &v25, v35, 0);
      this[2] = v22;
      if ( v22 )
      {
        (*(void (__stdcall **)(int))(*(_DWORD *)v23 + 56))(v23);
        (*(void (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 16))(this, a2, v23, 0);
        (*(void (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD))(*this + 16))(this, a5, v24, 0);
        return -1;
      }
      (*(void (__thiscall **)(_DWORD *, int, int, int, int, int, int, int, _DWORD))(*this + 80))(
        this,
        v28,
        v27,
        v26,
        v25,
        a8,
        a9,
        a10,
        *(_DWORD *)(a2 + 24));
      (*(void (__stdcall **)(int))(*(_DWORD *)v23 + 56))(v23);
      (*(void (__stdcall **)(int))(*(_DWORD *)v24 + 56))(v24);
    }
  }
  (*(void (__thiscall **)(_DWORD *, int, int, _DWORD))(*this + 16))(this, a2, v23, 0);
  (*(void (__thiscall **)(_DWORD *, _DWORD *, int, _DWORD))(*this + 16))(this, v12, v24, 0);
  *v12 &= ~0x100u;
  return 0;
}
