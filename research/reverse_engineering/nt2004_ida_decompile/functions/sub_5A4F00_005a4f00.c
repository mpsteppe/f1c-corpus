int __thiscall sub_5A4F00(int this, int *a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  BOOL v15; // edi
  BOOL v16; // ebx
  bool v17; // zf
  int v18; // eax
  BOOL v19; // ebx
  BOOL v20; // edi
  BOOL v21; // edi
  BOOL v22; // ebx
  BOOL v23; // edi
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  _DWORD *v28; // edi
  int v29; // eax
  int v31; // eax
  int v32; // eax
  int v33; // edx
  int v34; // eax
  int v35; // edx
  int v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // eax
  int v41; // eax
  char v42; // ch
  __int16 v43; // ax
  char v44; // al
  int v45; // edi
  BOOL v46; // [esp+194h] [ebp-610h]
  BOOL v47; // [esp+194h] [ebp-610h]
  BOOL v48; // [esp+194h] [ebp-610h]
  int v49; // [esp+198h] [ebp-60Ch]
  int v50; // [esp+19Ch] [ebp-608h]
  int v51; // [esp+1A0h] [ebp-604h] BYREF
  _BYTE v52[28]; // [esp+1A4h] [ebp-600h] BYREF
  int v53; // [esp+1C0h] [ebp-5E4h]
  int v54; // [esp+1C8h] [ebp-5DCh]
  int v55; // [esp+1E4h] [ebp-5C0h]
  int v56; // [esp+234h] [ebp-570h]
  int v57; // [esp+23Ch] [ebp-568h]
  char Buffer[256]; // [esp+278h] [ebp-52Ch] BYREF
  _BYTE v59[1032]; // [esp+378h] [ebp-42Ch] BYREF
  int v60; // [esp+780h] [ebp-24h]

  v49 = 0;
  v50 = 0;
  sub_5A59C0(this, a3);
  if ( !*(_DWORD *)(this + 4448) )
  {
    sub_5A4830((int *)this, a7);
    v50 = 1;
  }
  sub_5A9580(a2);
  v9 = operator new(0x40u);
  if ( v9 )
    v10 = sub_59F160(v9);
  else
    v10 = 0;
  *(_DWORD *)(this + 8592) = v10;
  v11 = operator new(0x40u);
  if ( v11 )
    v12 = sub_59F160(v11);
  else
    v12 = 0;
  *(_DWORD *)(this + 8596) = v12;
  v13 = operator new(0x40u);
  if ( v13 )
    v14 = sub_59F160(v13);
  else
    v14 = 0;
  *(_DWORD *)(this + 8600) = v14;
  memset((void *)(this + 4452), 0, 0x34u);
  sub_5B43F0(this + 4460, a6, 0);
  sub_5B41C0(*(_DWORD *)(this + 4460), &v51, 0);
  v46 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          1,
          3,
          23) == 0;
  v15 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          24,
          1,
          3,
          24) == 0;
  v16 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          24,
          1,
          3,
          25) == 0;
  v17 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          24,
          1,
          3,
          23) == 0;
  v18 = 1;
  if ( !v17 )
    v18 = v46;
  if ( v16 )
  {
    *(_DWORD *)(this + 8276) = 25;
  }
  else if ( v15 )
  {
    *(_DWORD *)(this + 8276) = 24;
  }
  else if ( v18 )
  {
    *(_DWORD *)(this + 8276) = 23;
  }
  v47 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          1,
          3,
          21) == 0;
  v19 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          1,
          3,
          22) == 0;
  v20 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          1,
          3,
          23) == 0;
  if ( v47 )
  {
    *(_DWORD *)(this + 8280) = 21;
  }
  else if ( v19 )
  {
    *(_DWORD *)(this + 8280) = 22;
  }
  else if ( v20 )
  {
    *(_DWORD *)(this + 8280) = 23;
  }
  v48 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          0,
          3,
          23) == 0;
  v21 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          0,
          3,
          24) == 0;
  v22 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          0,
          3,
          25) == 0;
  if ( v48 )
    *(_DWORD *)(this + 8300) = 23;
  if ( v22 )
  {
    if ( !v21 )
    {
      *(_DWORD *)(this + 8304) = 25;
      goto LABEL_33;
    }
  }
  else if ( !v21 )
  {
    goto LABEL_33;
  }
  *(_DWORD *)(this + 8304) = 24;
LABEL_33:
  v23 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          0,
          3,
          21) == 0;
  v24 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          0,
          3,
          22);
  if ( v23 )
    *(_DWORD *)(this + 8288) = 21;
  if ( !v24 )
    *(_DWORD *)(this + 8284) = 22;
  if ( v51 == 16 )
  {
    v25 = *a2;
    if ( (*a2 & 0x1000000) != 0 )
    {
      *(_DWORD *)(this + 4460) = 23;
    }
    else if ( (v25 & 0x4000000) != 0 )
    {
      *(_DWORD *)(this + 4460) = 24;
    }
    else if ( (v25 & 0x2000000) != 0 )
    {
      *(_DWORD *)(this + 4460) = 25;
    }
    sub_5B41C0(*(_DWORD *)(this + 8276), 0, this + 8644);
  }
  else if ( v51 == 24 || v51 == 32 )
  {
    v26 = *a2;
    if ( (*a2 & 0x8000000) != 0 )
    {
      *(_DWORD *)(this + 4460) = 20;
    }
    else if ( (v26 & 0x20000000) != 0 )
    {
      *(_DWORD *)(this + 4460) = 22;
    }
    else if ( (v26 & 0x10000000) != 0 )
    {
      *(_DWORD *)(this + 4460) = 21;
    }
    sub_5B41C0(*(_DWORD *)(this + 8280), 0, this + 8644);
  }
  if ( (a7 & 0x100560) != 0 && (*a2 & 0x802E0) != 0 )
  {
    if ( (a7 & 0x20) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              *(_DWORD *)(this + 4460),
              0,
              2) )
      {
        *(_DWORD *)(this + 4468) = 2;
        v49 = 32;
      }
    }
    else if ( (a7 & 0x100) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              *(_DWORD *)(this + 4460),
              0,
              3) )
      {
        *(_DWORD *)(this + 4468) = 3;
        v49 = 256;
      }
    }
    else if ( (a7 & 0x40) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              *(_DWORD *)(this + 4460),
              0,
              4) )
      {
        *(_DWORD *)(this + 4468) = 4;
        v49 = 64;
      }
    }
    else if ( (a7 & 0x400) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              *(_DWORD *)(this + 4460),
              0,
              6) )
      {
        *(_DWORD *)(this + 4468) = 6;
        v49 = 1024;
      }
    }
    else if ( (a7 & 0x100000) != 0
           && !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
                 *(_DWORD *)(this + 4444),
                 a2[65],
                 1,
                 *(_DWORD *)(this + 4460),
                 0,
                 16) )
    {
      *(_DWORD *)(this + 4468) = 16;
      v49 = 0x100000;
    }
  }
  if ( (a7 & 2) != 0 )
  {
    *(_DWORD *)(this + 4480) = 0;
    if ( v49 )
    {
      *(_DWORD *)(this + 4472) = 1;
    }
    else
    {
      *(_DWORD *)(this + 4468) = 0;
      *(_DWORD *)(this + 4472) = 2;
    }
    if ( (a7 & 0x80u) != 0 && (*(_BYTE *)a2 & 0x10) != 0 )
    {
      *(_DWORD *)(this + 4500) = 1;
      *(_DWORD *)(this + 4496) = a8;
    }
    else
    {
      *(_DWORD *)(this + 4500) = 0x80000000;
      *(_DWORD *)(this + 4496) = a8;
    }
  }
  else
  {
    *(_DWORD *)(this + 4480) = 1;
    if ( v49 )
    {
      *(_DWORD *)(this + 4472) = 1;
    }
    else
    {
      *(_DWORD *)(this + 4468) = 0;
      if ( (a7 & 0x80u) != 0 && (*(_BYTE *)a2 & 0x10) != 0 )
        *(_DWORD *)(this + 4472) = 4;
      else
        *(_DWORD *)(this + 4472) = 3;
    }
    *(_DWORD *)(this + 4496) = 0;
  }
  *(_DWORD *)(this + 4452) = a4;
  *(_DWORD *)(this + 4456) = a5;
  *(_DWORD *)(this + 4476) = a3;
  *(_DWORD *)(this + 4464) = 1;
  *(_DWORD *)(this + 4484) = 0;
  *(_DWORD *)(this + 4488) = 80;
  if ( v50 )
  {
    if ( (*(_BYTE *)a2 & 4) != 0 )
    {
      v17 = *(_DWORD *)(this + 5176) == 0;
      *(_DWORD *)(this + 5180) = 0;
      if ( v17 )
      {
        v27 = 64;
        *(_DWORD *)(this + 4504) = 2;
      }
      else
      {
        v27 = 128;
        *(_DWORD *)(this + 4504) = 1;
      }
      if ( *(_DWORD *)(this + 5188) == 2 )
      {
LABEL_95:
        v28 = (_DWORD *)(this + 4448);
        v29 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4444) + 60))(
                *(_DWORD *)(this + 4444),
                a2[65],
                1,
                a3,
                v27 | 4,
                this + 4452,
                this + 4448);
        *(_DWORD *)this = v29;
        if ( v29 )
        {
LABEL_96:
          sprintf(Buffer, "%s - 0x%X", aCouldNotSetDis, v29);
          sub_591C60(this, -1, Buffer);
          return -1;
        }
        goto LABEL_98;
      }
      v27 = 128;
      *(_DWORD *)(this + 4504) = 1;
    }
    else
    {
      v27 = 32;
      *(_DWORD *)(this + 4504) = 0;
    }
    *(_DWORD *)(this + 5180) = 0;
    goto LABEL_95;
  }
  v28 = (_DWORD *)(this + 4448);
  v29 = (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 4448) + 56))(*(_DWORD *)(this + 4448), this + 4452);
  *(_DWORD *)this = v29;
  if ( v29 )
    goto LABEL_96;
LABEL_98:
  v31 = *v28;
  *(_DWORD *)(this + 100) = a2[65];
  v32 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v31 + 64))(v31, 0, 0, *(_DWORD *)(this + 8596) + 16);
  v33 = *(_DWORD *)(this + 8596);
  *(_DWORD *)this = v32;
  v34 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v33 + 16) + 8))(*(_DWORD *)(v33 + 16));
  v35 = *(_DWORD *)(this + 8596);
  *(_DWORD *)this = v34;
  *(_DWORD *)(v35 + 28) = a4;
  *(_DWORD *)(*(_DWORD *)(this + 8596) + 32) = a5;
  *(_DWORD *)(*(_DWORD *)(this + 8596) + 56) = 262146;
  *(_DWORD *)(*(_DWORD *)(this + 8596) + 48) = sub_5B4140(*(_DWORD *)(this + 8596));
  if ( (*(_BYTE *)a2 & 8) == 0 )
    goto LABEL_106;
  v36 = *v28;
  if ( v49 )
    v37 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v36 + 200))(v36, 161, 1);
  else
    v37 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v36 + 200))(v36, 161, 0);
  v38 = *(_DWORD *)(this + 8596);
  *(_DWORD *)this = v37;
  if ( sub_5A62C0(this, (int)a2, v38, *(_DWORD *)(this + 8600), v49) )
    return -1;
  v39 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)*v28 + 124))(
          *v28,
          0,
          *(_DWORD *)(*(_DWORD *)(this + 8600) + 16));
  *(_DWORD *)this = v39;
  if ( v39 )
  {
    sub_591C60(this, -1, aInvalidParamet);
    return -1;
  }
  else
  {
LABEL_106:
    a2[69] = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)*v28 + 16))(*v28);
    v40 = (*(int (__stdcall **)(_DWORD, _BYTE *))(*(_DWORD *)*v28 + 28))(*v28, v52);
    *(_DWORD *)this = v40;
    if ( !v40 )
    {
      v41 = v57;
      *(_DWORD *)(this + 5132) = v57;
      *(_DWORD *)(this + 5136) = v41;
      *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int, _BYTE *))(**(_DWORD **)(this + 4444) + 20))(
                          *(_DWORD *)(this + 4444),
                          a2[65],
                          2,
                          v59);
      if ( v60 == 4170 )
      {
        *(_DWORD *)(this + 5128) |= 0x2000u;
        *(_DWORD *)(this + 8636) = 1;
        *(_DWORD *)(this + 8640) = 256;
      }
      if ( (v55 & 0x20000) != 0 )
        *(_DWORD *)(this + 5128) |= 1u;
      v42 = BYTE1(v53);
      if ( (v53 & 0x4000) != 0 )
        *(_DWORD *)(this + 5128) |= 2u;
      v43 = v54;
      v17 = (v54 & 0x4000) == 0;
      *(_DWORD *)(this + 5144) = 1;
      if ( !v17 )
        *(_DWORD *)(this + 5128) |= 0x100u;
      if ( (v43 & 0x100) != 0 )
        *(_DWORD *)(this + 5128) |= 0x4000u;
      if ( (v43 & 0x80u) != 0 )
        *(_DWORD *)(this + 5128) |= 0x8000u;
      v44 = v56;
      if ( ((unsigned int)&unk_800000 & v56) != 0 )
        *(_DWORD *)(this + 5128) |= 0x20u;
      if ( (v44 & 0x16) != 0 )
        *(_DWORD *)(this + 5128) |= 0x40u;
      if ( (v42 & 0x10) != 0 )
        *(_DWORD *)(this + 5128) |= 4u;
      v45 = *(_DWORD *)(this + 4460);
      if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              v45,
              0,
              3,
              827611204) )
        *(_DWORD *)(this + 5128) |= 0x1000u;
      if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              v45,
              0,
              3,
              844388420) )
        *(_DWORD *)(this + 5128) |= 0x10000u;
      if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              v45,
              0,
              3,
              861165636) )
        *(_DWORD *)(this + 5128) |= 0x20000u;
      if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              v45,
              0,
              3,
              877942852) )
        *(_DWORD *)(this + 5128) |= 0x40000u;
      if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4444) + 40))(
              *(_DWORD *)(this + 4444),
              a2[65],
              1,
              v45,
              0,
              3,
              894720068) )
        *(_DWORD *)(this + 5128) |= 0x80000u;
    }
    return -(sub_5A5A60(this, 0) != 0);
  }
}
