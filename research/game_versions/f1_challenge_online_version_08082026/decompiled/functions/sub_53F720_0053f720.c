int __thiscall sub_53F720(int this, _DWORD *a2, int a3)
{
  int v3; // eax
  _DWORD *v4; // ebp
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int *v12; // edx
  __int64 v13; // rax
  int v15; // eax
  int v16; // eax
  int *v17; // edx
  __int64 v18; // rax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int *v22; // edx
  __int64 v23; // rax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // [esp+30h] [ebp-128h]
  int v36; // [esp+38h] [ebp-120h]
  int v37; // [esp+38h] [ebp-120h]
  int v38; // [esp+38h] [ebp-120h]
  int v39; // [esp+4Ch] [ebp-10Ch] BYREF
  int v40; // [esp+50h] [ebp-108h]
  int v41; // [esp+54h] [ebp-104h]
  char v42[256]; // [esp+58h] [ebp-100h] BYREF

  v3 = a2[12];
  v4 = a2 + 12;
  v6 = *(_DWORD *)(this + 4364);
  v41 = 0;
  if ( v3 == 7 )
    sub_55C650(&v39, 8, 0);
  else
    sub_55C650(&v39, v3, 0);
  v7 = a2[6];
  if ( (v7 & 0x10) != 0 )
  {
    if ( v39 == 21 )
    {
      v39 = 22;
    }
    else if ( v39 == 25 )
    {
      v39 = 24;
    }
  }
  if ( (v7 & 1) != 0 )
  {
    v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD *))(**(_DWORD **)(this + 4352) + 108))(
           *(_DWORD *)(this + 4352),
           a2[7],
           a2[8],
           v39,
           a2 + 2);
    *(_DWORD *)this = v8;
    if ( v8 )
      goto LABEL_19;
  }
  v9 = a2[6];
  if ( (v9 & 2) != 0 )
  {
    if ( (v9 & 0x40000) != 0 )
    {
      v10 = a2[9];
      if ( v10 == 32 )
        v11 = *(_DWORD *)(this + 5100);
      else
        v11 = v10 == 16 ? *(_DWORD *)(this + 5096) : v6;
      v12 = *(int **)(this + 4348);
      v36 = v11;
      v39 = v11;
      v40 = *v12;
      v13 = sub_55BFC0(this);
      v8 = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, int, int, int))(v40 + 40))(
             HIDWORD(v13),
             v13,
             1,
             v6,
             1,
             1,
             v36);
      *(_DWORD *)this = v8;
      if ( v8 )
        goto LABEL_19;
    }
    v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, _DWORD, _DWORD *))(**(_DWORD **)(this + 4352) + 100))(
           *(_DWORD *)(this + 4352),
           a2[7],
           a2[8],
           v39,
           0,
           0,
           a2 + 3);
    *(_DWORD *)this = v8;
    if ( v8 )
      goto LABEL_19;
  }
  if ( (a2[6] & 0x40008) != 0 )
  {
    v15 = a2[9];
    if ( v15 == 32 )
    {
      v16 = *(_DWORD *)(this + 5100);
    }
    else if ( v15 == 16 )
    {
      v16 = *(_DWORD *)(this + 5096);
    }
    else
    {
      v16 = v6;
    }
    v17 = *(int **)(this + 4348);
    v37 = v16;
    v39 = v16;
    v40 = *v17;
    v18 = sub_55BFC0(this);
    v19 = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, int, int, int))(v40 + 40))(
            HIDWORD(v18),
            v18,
            1,
            v6,
            1,
            3,
            v37);
    *(_DWORD *)this = v19;
    if ( !v19 )
      goto LABEL_52;
    v20 = a2[9];
    v41 = 0;
    if ( v20 == 32 )
      v21 = *(_DWORD *)(this + 5096);
    else
      v21 = v20 == 16 ? *(_DWORD *)(this + 5100) : v6;
    v22 = *(int **)(this + 4348);
    v38 = v21;
    v39 = v21;
    v40 = *v22;
    v23 = sub_55BFC0(this);
    v24 = (*(int (__stdcall **)(_DWORD, _DWORD, int, int, int, int, int))(v40 + 40))(
            HIDWORD(v23),
            v23,
            1,
            v6,
            1,
            3,
            v38);
    *(_DWORD *)this = v24;
    if ( v24 )
    {
      if ( !v39 )
      {
        v25 = a2[9];
        if ( v25 == 16 )
        {
          v26 = *(_DWORD *)(this + 5032);
          if ( (v26 & 0x1000000) != 0 )
          {
            v39 = 23;
          }
          else if ( (v26 & 0x4000000) != 0 )
          {
            v39 = 24;
          }
          else if ( (v26 & 0x2000000) != 0 )
          {
            v39 = 25;
          }
        }
        else if ( v25 == 24 || v25 == 32 )
        {
          v27 = *(_DWORD *)(this + 5032);
          if ( (v27 & 0x8000000) != 0 )
          {
            v39 = 20;
          }
          else if ( (v27 & 0x20000000) != 0 )
          {
            v39 = 22;
          }
          else if ( (v27 & 0x10000000) != 0 )
          {
            v39 = 21;
          }
        }
      }
      v28 = a3;
      v35 = v39;
      a2[6] = a2[6] & 0xFFFBFFF3 | 4;
      sub_55C450(v35, 0, v4);
    }
    else
    {
LABEL_52:
      a2[6] |= 0x80400u;
      v28 = 1;
      v41 = 1;
      sub_55C450(v39, 0, v4);
    }
  }
  else
  {
    v28 = a3;
  }
  if ( (a2[6] & 8) != 0 )
  {
    v29 = v28;
    if ( !v28 )
      v29 = 1;
    v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD *))(**(_DWORD **)(this + 4352) + 80))(
           *(_DWORD *)(this + 4352),
           a2[7],
           a2[8],
           v29,
           v41,
           v39,
           0,
           a2 + 5);
    *(_DWORD *)this = v8;
    if ( v8 )
    {
      v30 = a2[6];
      if ( (v30 & 0x40000) == 0 )
      {
LABEL_19:
        sub_58815F(v42, "%s - 0x%x", aCouldNotAlloca, v8);
        sub_53C590(-1, v42);
        return -1;
      }
      a2[6] = v30 & 0xFFFBFFF3 | 4;
    }
    else
    {
      v31 = a2[6];
      if ( (v31 & 0x40000) != 0 && (v31 & 0x200000) == 0 )
      {
        v32 = sub_587C03(60);
        if ( v32 )
          v33 = sub_5426A0(v32);
        else
          v33 = 0;
        a2[1] = v33;
        if ( sub_53F3F0((int *)this, 0, a2, v33, 0) )
          return 0;
        sub_5404D0(a2, 0, 0, a2[7], a2[8], 0);
      }
    }
  }
  if ( (a2[6] & 4) != 0 )
  {
    v34 = v28;
    if ( !v28 )
      v34 = 1;
    v8 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, int, _DWORD, int, int, _DWORD *))(**(_DWORD **)(this + 4352) + 80))(
           *(_DWORD *)(this + 4352),
           a2[7],
           a2[8],
           v34,
           0,
           v39,
           2,
           a2 + 4);
    *(_DWORD *)this = v8;
    if ( v8 )
      goto LABEL_19;
  }
  return 0;
}
