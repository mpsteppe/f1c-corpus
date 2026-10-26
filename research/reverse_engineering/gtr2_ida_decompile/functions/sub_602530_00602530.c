int __thiscall sub_602530(_DWORD *this, int a2, int a3)
{
  int *v3; // edi
  int v4; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int *v10; // edx
  int v11; // ebx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // ebx
  int v16; // eax
  int v17; // ebx
  int v18; // eax
  int *v19; // ecx
  int v20; // edx
  int v21; // ebp
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int *v26; // edx
  int v27; // ebp
  int v28; // eax
  int v29; // eax
  int v31; // [esp+84h] [ebp-4h] BYREF

  v3 = (int *)a2;
  v4 = *(_DWORD *)(a2 + 24);
  if ( v4 == 7 )
    (*(void (__thiscall **)(_DWORD *, int *, int, _DWORD))(*this + 168))(this, &a2, 14, 0);
  else
    (*(void (__thiscall **)(_DWORD *, int *, int, _DWORD))(*this + 168))(this, &a2, v4, 0);
  v6 = *v3;
  if ( (*v3 & 0x80u) != 0 )
  {
    if ( a2 == 21 )
    {
      a2 = 22;
    }
    else if ( a2 == 25 )
    {
      a2 = 24;
    }
  }
  if ( (v6 & 1) == 0 || sub_5E7120(v3, 1) )
  {
LABEL_14:
    if ( (*(_BYTE *)v3 & 2) != 0 && !sub_5E7120(v3, 2) )
    {
      if ( (*(_BYTE *)v3 & 0x40) != 0 )
      {
        v8 = v3[3];
        if ( v8 == 32 )
        {
          v9 = this[2417];
        }
        else if ( v8 == 16 )
        {
          v9 = this[2416];
        }
        else
        {
          v9 = this[2390];
        }
        v10 = (int *)this[2386];
        a2 = v9;
        v11 = *v10;
        v12 = (*(int (__thiscall **)(_DWORD *, int, _DWORD, int, int, int))(*this + 192))(this, 1, this[2415], 1, 1, v9);
        v13 = (*(int (__stdcall **)(_DWORD, int))(v11 + 40))(this[2386], v12);
        this[2] = v13;
        if ( v13 )
        {
          sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x while verifying render target format", v13);
          return -1;
        }
        v14 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, _DWORD, _DWORD, int *, _DWORD))(*(_DWORD *)this[2387]
                                                                                                 + 112))(
                this[2387],
                v3[1],
                v3[2],
                a2,
                0,
                0,
                0,
                &v31,
                0);
        this[2] = v14;
        if ( v14 )
        {
          sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x creating D3D render target", v14);
          return -1;
        }
      }
      else
      {
        v7 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int *, _DWORD))(*(_DWORD *)this[2387] + 144))(
               this[2387],
               v3[1],
               v3[2],
               a2,
               0,
               &v31,
               0);
        this[2] = v7;
        if ( v7 )
          goto LABEL_12;
      }
      sub_5E7180(v3, v31, 2);
    }
    if ( (*v3 & 0xC) != 0 )
    {
      v15 = v3[5];
      if ( !v15 )
        v15 = 1;
      if ( (*v3 & 4) != 0
        && !sub_5E7150(v3, 4)
        && (*(int (__thiscall **)(_DWORD *, int *, int, _DWORD, int, int))(*this + 228))(this, v3, v15, 0, a2, 2) )
      {
        return -1;
      }
      if ( (*(_BYTE *)v3 & 8) != 0 && !sub_5E7150(v3, 8) )
      {
        v16 = *v3;
        if ( (*v3 & 0x40) != 0 )
        {
          if ( (v16 & 0x20) != 0 )
            v17 = 4;
          else
            v17 = (v16 & 0x10) != 0 ? 5 : 3;
          if ( v3[3] == 16 )
            v18 = this[2416];
          else
            v18 = this[2417];
          v19 = (int *)this[2386];
          v20 = this[2415];
          a2 = v18;
          v21 = *v19;
          v22 = (*(int (__thiscall **)(_DWORD *, int, int, int, int, int))(*this + 192))(this, 1, v20, 1, v17, v18);
          v23 = (*(int (__stdcall **)(_DWORD, int))(v21 + 40))(this[2386], v22);
          this[2] = v23;
          if ( v23 )
          {
            v24 = v3[3];
            if ( v24 == 32 )
              v25 = this[2416];
            else
              v25 = v24 == 16 ? this[2417] : this[2390];
            v26 = (int *)this[2386];
            a2 = v25;
            v27 = *v26;
            v28 = (*(int (__thiscall **)(_DWORD *, int, _DWORD, int, int, int))(*this + 192))(
                    this,
                    1,
                    this[2415],
                    1,
                    v17,
                    v25);
            v29 = (*(int (__stdcall **)(_DWORD, int))(v27 + 40))(this[2386], v28);
            this[2] = v29;
            if ( v29 )
            {
              sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x creating D3D render target texture", v29);
              return -1;
            }
          }
          if ( (*(int (__thiscall **)(_DWORD *, int *, int, int, int, _DWORD))(*this + 228))(this, v3, 1, 1, a2, 0) )
          {
            (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 340))(this, 0);
            if ( (*(int (__thiscall **)(_DWORD *, int *, int, int, int, _DWORD))(*this + 228))(this, v3, 1, 1, a2, 0) )
            {
              sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x creating D3D render target texture", this[2]);
              return -1;
            }
          }
          if ( (*v3 & 0x40000) == 0 )
            (*(void (__thiscall **)(_DWORD *, _DWORD, int *, _DWORD, _DWORD))(*this + 244))(this, 0, v3, 0, 0);
        }
        else if ( (*(int (__thiscall **)(_DWORD *, int *, int, _DWORD, int, _DWORD))(*this + 228))(
                    this,
                    v3,
                    v15,
                    0,
                    a2,
                    0) )
        {
          sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x creating D3D texture", this[2]);
          return -1;
        }
      }
    }
    return 0;
  }
  v7 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int *, _DWORD))(*(_DWORD *)this[2387] + 144))(
         this[2387],
         v3[1],
         v3[2],
         a2,
         2,
         &v31,
         0);
  this[2] = v7;
  if ( !v7 )
  {
    sub_5E7180(v3, v31, 1);
    goto LABEL_14;
  }
LABEL_12:
  sub_5D8C80((int)(this + 1), (char *)0xFFFFFFFF, "Error 0x%x creating D3D image surface", v7);
  return -1;
}
