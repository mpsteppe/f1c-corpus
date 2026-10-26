int __thiscall sub_603B90(_DWORD *this, _DWORD *a2, int a3, int a4, int a5, int a6, int a7)
{
  _DWORD *v7; // edi
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v16; // ebp
  int v17; // ebx
  int v18; // eax
  int v19; // eax
  _DWORD *v20; // [esp+5Ch] [ebp-38h]
  int v21; // [esp+5Ch] [ebp-38h]
  _DWORD *v22; // [esp+60h] [ebp-34h]
  _DWORD *v23; // [esp+60h] [ebp-34h]
  int v24; // [esp+60h] [ebp-34h]
  _DWORD *v25; // [esp+74h] [ebp-20h] BYREF
  int v26; // [esp+78h] [ebp-1Ch] BYREF
  _DWORD v27[2]; // [esp+7Ch] [ebp-18h] BYREF
  int v28; // [esp+84h] [ebp-10h] BYREF
  int v29; // [esp+88h] [ebp-Ch]
  int v30; // [esp+8Ch] [ebp-8h]
  int v31; // [esp+90h] [ebp-4h]

  v7 = a2;
  if ( (*(_BYTE *)a2 & 0x40) != 0 )
  {
    v9 = this[2387];
    a2 = 0;
    if ( !(*(int (__stdcall **)(int, _DWORD, _DWORD **))(*(_DWORD *)v9 + 152))(v9, 0, &v25) )
      this[2] = (*(int (__stdcall **)(_DWORD *))(*v25 + 8))(v25);
    if ( !(*(int (__stdcall **)(_DWORD, int *))(*(_DWORD *)this[2387] + 160))(this[2387], &v26) )
      this[2] = (*(int (__stdcall **)(int))(*(_DWORD *)v26 + 8))(v26);
    if ( (*v7 & 2) != 0 )
    {
      v10 = 2;
LABEL_10:
      if ( !(*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD **, _DWORD, int, int))(*this + 12))(
              this,
              v7,
              &a2,
              0,
              v10,
              2) )
      {
        if ( a2 != v25 )
        {
          v11 = this[2387];
          v22 = a2;
          v27[0] = this[2431];
          this[2431] = v7;
          this[2] = (*(int (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v11 + 148))(v11, 0, v22);
          this[2] = (*(int (__stdcall **)(_DWORD, _DWORD))(*(_DWORD *)this[2387] + 156))(this[2387], 0);
        }
        v28 = a3;
        v30 = a5 + a3;
        v29 = a4;
        v12 = this[2387];
        v31 = a6 + a4;
        v13 = (*(int (__stdcall **)(int, int, int *, int, int, _DWORD, _DWORD))(*(_DWORD *)v12 + 172))(
                v12,
                1,
                &v28,
                1,
                a7,
                0,
                0);
        v20 = a2;
        this[2] = v13;
        (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD *, int))(*this + 16))(this, v7, v20, v10);
        *v7 |= 0x100u;
      }
      if ( a2 != v25 )
      {
        if ( v25 )
        {
          v14 = this[2387];
          v23 = v25;
          this[2431] = v27[0];
          this[2] = (*(int (__stdcall **)(int, _DWORD, _DWORD *))(*(_DWORD *)v14 + 148))(v14, 0, v23);
        }
        if ( v26 )
          this[2] = (*(int (__stdcall **)(_DWORD, int))(*(_DWORD *)this[2387] + 156))(this[2387], v26);
      }
      return 0;
    }
    if ( (*v7 & 8) != 0 )
    {
      v10 = 8;
      goto LABEL_10;
    }
  }
  else
  {
    if ( (*(int (__thiscall **)(_DWORD *, _DWORD *, _DWORD **, _DWORD, _DWORD, int))(*this + 12))(
           this,
           a2,
           &a2,
           0,
           0,
           2) )
    {
      return 0;
    }
    v16 = a6;
    v17 = a5;
    v29 = a4;
    v31 = a6 + a4;
    v28 = a3;
    v30 = a5 + a3;
    v18 = (*(int (__stdcall **)(_DWORD *, _DWORD *, int *, _DWORD))(*a2 + 52))(a2, v27, &v28, 0);
    this[2] = v18;
    if ( !v18 )
    {
      v19 = v27[0];
      v24 = v7[6];
      v21 = a7;
      v7[4] = v27[0];
      (*(void (__thiscall **)(_DWORD *, _DWORD, int, int, int, int, int))(*this + 84))(
        this,
        v27[1],
        v19,
        v17,
        v16,
        v21,
        v24);
      (*(void (__stdcall **)(_DWORD *))(*a2 + 56))(a2);
      (*(void (__thiscall **)(_DWORD *, _DWORD *, _DWORD *, _DWORD))(*this + 16))(this, v7, a2, 0);
      *v7 &= ~0x100u;
      return 0;
    }
  }
  return -1;
}
