int __thiscall sub_602AD0(int *this, int a2, void **a3, int a4, unsigned int a5)
{
  _DWORD *v5; // edi
  int v7; // ebp
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // eax
  int v16; // edi
  int v17; // edi
  int v18; // ebx
  int v19; // edi
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  void **v25; // esi
  _DWORD *v26; // [esp+74h] [ebp-54h]
  char v27; // [esp+80h] [ebp-48h]
  int v28; // [esp+90h] [ebp-38h] BYREF
  int v29; // [esp+94h] [ebp-34h] BYREF
  int v30; // [esp+98h] [ebp-30h] BYREF
  unsigned int v31; // [esp+9Ch] [ebp-2Ch] BYREF
  int v32; // [esp+A0h] [ebp-28h]
  int v33; // [esp+A4h] [ebp-24h] BYREF
  _DWORD v34[8]; // [esp+A8h] [ebp-20h] BYREF

  v5 = (_DWORD *)a2;
  if ( !a2 )
    v5 = (_DWORD *)dword_FB275C;
  if ( v5 )
  {
    v7 = v5[67];
    v32 = v7;
    v8 = sub_5FAFF0(v5);
    v9 = sub_5FB0A0(v8);
    (*(void (__thiscall **)(int *, int *, _DWORD, _DWORD))(*this + 168))(this, &a2, *(_DWORD *)(v9 + 20), 0);
    (*(void (__thiscall **)(int *, int, int *, _DWORD))(*this + 172))(this, a2, &v29, 0);
    if ( v29 == 16 )
    {
      v10 = v5[65];
      if ( (v10 & 0x4000000) != 0 )
      {
        a2 = 23;
      }
      else if ( (v10 & 0x10000000) != 0 )
      {
        a2 = 24;
      }
      else if ( (v10 & 0x8000000) != 0 )
      {
        a2 = 25;
      }
    }
    else if ( v29 == 24 || v29 == 32 )
    {
      v11 = v5[65];
      if ( (v11 & 0x20000000) != 0 )
      {
        a2 = 20;
      }
      else if ( v11 >= 0 )
      {
        if ( (v11 & 0x40000000) != 0 )
          a2 = 21;
      }
      else
      {
        a2 = 22;
      }
    }
  }
  else
  {
    (*(void (__thiscall **)(int *, int *, void *, _DWORD))(*this + 168))(this, &a2, a3[6], 0);
    if ( a2 == 21 )
    {
      a2 = 22;
    }
    else if ( a2 == 25 )
    {
      a2 = 24;
    }
    v7 = 0;
    v32 = 0;
  }
  v12 = *this;
  if ( ((unsigned __int8)*a3 & 2) == 0 )
  {
    if ( ((unsigned __int8)*a3 & 0x48) == 0x48 )
    {
      if ( !(*(int (__thiscall **)(int *, void **, int *, _DWORD, int, int))(v12 + 12))(this, a3, &v30, 0, 8, 2) )
      {
        (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v30 + 48))(v30, v34);
        v14 = *this;
        v28 = v34[0];
        (*(void (__thiscall **)(int *, void **, int, int))(v14 + 16))(this, a3, v30, 8);
      }
      goto LABEL_51;
    }
    (*(void (__thiscall **)(int *, int *, void *, _DWORD))(v12 + 168))(this, &v28, a3[6], 0);
    v15 = v28;
    if ( v28 == 21 )
    {
      v15 = 22;
    }
    else
    {
      if ( v28 != 25 )
        goto LABEL_35;
      v15 = 24;
    }
    v28 = v15;
LABEL_35:
    if ( v5 )
    {
      (*(void (__thiscall **)(int *, int, int *, _DWORD))(*this + 172))(this, v15, &v29, 0);
      if ( v29 == 16 )
      {
        v16 = v5[65];
        if ( (v16 & 0x4000000) != 0 )
        {
          v28 = 23;
        }
        else if ( (v16 & 0x10000000) != 0 )
        {
          v28 = 24;
        }
        else if ( (v16 & 0x8000000) != 0 )
        {
          v28 = 25;
        }
      }
      else if ( v29 == 24 || v29 == 32 )
      {
        v17 = v5[65];
        if ( (v17 & 0x20000000) != 0 )
        {
          v28 = 20;
        }
        else if ( v17 >= 0 )
        {
          if ( (v17 & 0x40000000) != 0 )
            v28 = 21;
        }
        else
        {
          v28 = 22;
        }
      }
    }
    goto LABEL_51;
  }
  if ( !(*(int (__thiscall **)(int *, void **, int *, _DWORD, int, int))(v12 + 12))(this, a3, &v30, 0, 2, 2) )
  {
    (*(void (__stdcall **)(int, _DWORD *))(*(_DWORD *)v30 + 48))(v30, v34);
    v13 = *this;
    v28 = v34[0];
    (*(void (__thiscall **)(int *, void **, int, int))(v13 + 16))(this, a3, v30, 2);
  }
LABEL_51:
  v18 = a4;
  v19 = (int)a3;
  v30 = 0;
  while ( 1 )
  {
    if ( v30 )
    {
      if ( v30 == 1 )
      {
        v19 = 77;
      }
      else if ( v30 == 2 )
      {
        v19 = 80;
      }
    }
    else
    {
      v19 = 71;
    }
    v20 = (*(int (__stdcall **)(int, int, int, int, int, int, int))(*(_DWORD *)this[2386] + 40))(
            this[2386],
            v7,
            1,
            a2,
            2,
            1,
            v19);
    this[2] = v20;
    if ( v20 )
      goto LABEL_64;
    v21 = (*(int (__stdcall **)(int, int, int, int, int, int))(*(_DWORD *)this[2386] + 48))(
            this[2386],
            v7,
            1,
            a2,
            v28,
            v19);
    this[2] = v21;
    if ( v21 )
      goto LABEL_64;
    v26 = (_DWORD *)this[2358];
    v31 = 0;
    v22 = (*(int (__stdcall **)(int, int, int, int, _DWORD *, int, unsigned int *))(*(_DWORD *)this[2386] + 44))(
            this[2386],
            v7,
            1,
            v19,
            v26,
            v18,
            &v31);
    this[2] = v22;
    if ( v22 || v31 < a5 )
      goto LABEL_64;
    v18 = a4;
    v23 = (*(int (__stdcall **)(int, void *, void *, int, int, unsigned int, int, int *, _DWORD))(*(_DWORD *)this[2387]
                                                                                                + 116))(
            this[2387],
            a3[1],
            a3[2],
            v19,
            a4,
            a5,
            1,
            &v33,
            0);
    this[2] = v23;
    if ( !v23 )
      break;
    v7 = v32;
LABEL_64:
    if ( ++v30 >= 3 )
    {
      sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error creating zbuffer", v27);
      return -1;
    }
  }
  v25 = a3;
  sub_5E7330(a3);
  sub_5E7180(v25[29], v33, 2);
  *(_DWORD *)v25[29] |= 2u;
  return 0;
}
