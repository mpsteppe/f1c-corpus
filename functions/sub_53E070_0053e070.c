int __thiscall sub_53E070(int this, int *a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
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
  int v27; // ecx
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
  char v58[256]; // [esp+278h] [ebp-52Ch] BYREF
  _BYTE v59[1032]; // [esp+378h] [ebp-42Ch] BYREF
  int v60; // [esp+780h] [ebp-24h]

  v49 = 0;
  v50 = 0;
  RendererResourceCleanup(a3);
  if ( !*(_DWORD *)(this + 4352) )
  {
    sub_53D970((int *)this, a7);
    v50 = 1;
  }
  FieldGetterAt0x118(a2);
  v9 = OperatorNewNhMallocWrapper(60);
  if ( v9 )
    v10 = AudioEmitterCreate(v9);
  else
    v10 = 0;
  *(_DWORD *)(this + 5412) = v10;
  v11 = OperatorNewNhMallocWrapper(60);
  if ( v11 )
    v12 = AudioEmitterCreate(v11);
  else
    v12 = 0;
  *(_DWORD *)(this + 5416) = v12;
  v13 = OperatorNewNhMallocWrapper(60);
  if ( v13 )
    v14 = AudioEmitterCreate(v13);
  else
    v14 = 0;
  *(_DWORD *)(this + 5420) = v14;
  memset((void *)(this + 4356), 0, 0x34u);
  sub_55C650(this + 4364, a6, 0);
  sub_55C450(*(_DWORD *)(this + 4364), &v51, 0);
  v46 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          1,
          3,
          23) == 0;
  v15 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          24,
          1,
          3,
          24) == 0;
  v16 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          24,
          1,
          3,
          25) == 0;
  v17 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
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
    *(_DWORD *)(this + 5096) = 25;
  }
  else if ( v15 )
  {
    *(_DWORD *)(this + 5096) = 24;
  }
  else if ( v18 )
  {
    *(_DWORD *)(this + 5096) = 23;
  }
  v47 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          1,
          3,
          21) == 0;
  v19 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          1,
          3,
          22) == 0;
  v20 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          1,
          3,
          23) == 0;
  if ( v47 )
  {
    *(_DWORD *)(this + 5100) = 21;
  }
  else if ( v19 )
  {
    *(_DWORD *)(this + 5100) = 22;
  }
  else if ( v20 )
  {
    *(_DWORD *)(this + 5100) = 23;
  }
  v48 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          0,
          3,
          23) == 0;
  v21 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          0,
          3,
          24) == 0;
  v22 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          0,
          3,
          25) == 0;
  if ( v48 )
    *(_DWORD *)(this + 5120) = 23;
  if ( v22 )
  {
    if ( !v21 )
    {
      *(_DWORD *)(this + 5124) = 25;
      goto LABEL_33;
    }
  }
  else if ( !v21 )
  {
    goto LABEL_33;
  }
  *(_DWORD *)(this + 5124) = 24;
LABEL_33:
  v23 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          0,
          3,
          21) == 0;
  v24 = (*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          0,
          3,
          22);
  if ( v23 )
    *(_DWORD *)(this + 5108) = 21;
  if ( !v24 )
    *(_DWORD *)(this + 5104) = 22;
  if ( v51 == 16 )
  {
    v25 = *a2;
    if ( (*a2 & 0x1000000) != 0 )
    {
      *(_DWORD *)(this + 4364) = 23;
    }
    else if ( (v25 & 0x4000000) != 0 )
    {
      *(_DWORD *)(this + 4364) = 24;
    }
    else if ( (v25 & 0x2000000) != 0 )
    {
      *(_DWORD *)(this + 4364) = 25;
    }
    sub_55C450(*(_DWORD *)(this + 5096), 0, this + 5464);
  }
  else if ( v51 == 24 || v51 == 32 )
  {
    v26 = *a2;
    if ( (*a2 & 0x8000000) != 0 )
    {
      *(_DWORD *)(this + 4364) = 20;
    }
    else if ( (v26 & 0x20000000) != 0 )
    {
      *(_DWORD *)(this + 4364) = 22;
    }
    else if ( (v26 & 0x10000000) != 0 )
    {
      *(_DWORD *)(this + 4364) = 21;
    }
    sub_55C450(*(_DWORD *)(this + 5100), 0, this + 5464);
  }
  if ( (a7 & 0x100560) != 0 && (*a2 & 0x802E0) != 0 )
  {
    if ( (a7 & 0x20) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
              *(_DWORD *)(this + 4348),
              a2[65],
              1,
              *(_DWORD *)(this + 4364),
              0,
              2) )
      {
        *(_DWORD *)(this + 4372) = 2;
        v49 = 32;
      }
    }
    else if ( (a7 & 0x100) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
              *(_DWORD *)(this + 4348),
              a2[65],
              1,
              *(_DWORD *)(this + 4364),
              0,
              3) )
      {
        *(_DWORD *)(this + 4372) = 3;
        v49 = 256;
      }
    }
    else if ( (a7 & 0x40) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
              *(_DWORD *)(this + 4348),
              a2[65],
              1,
              *(_DWORD *)(this + 4364),
              0,
              4) )
      {
        *(_DWORD *)(this + 4372) = 4;
        v49 = 64;
      }
    }
    else if ( (a7 & 0x400) != 0 )
    {
      if ( !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
              *(_DWORD *)(this + 4348),
              a2[65],
              1,
              *(_DWORD *)(this + 4364),
              0,
              6) )
      {
        *(_DWORD *)(this + 4372) = 6;
        v49 = 1024;
      }
    }
    else if ( (a7 & 0x100000) != 0
           && !(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
                 *(_DWORD *)(this + 4348),
                 a2[65],
                 1,
                 *(_DWORD *)(this + 4364),
                 0,
                 16) )
    {
      *(_DWORD *)(this + 4372) = 16;
      v49 = 0x100000;
    }
  }
  if ( (a7 & 2) != 0 )
  {
    *(_DWORD *)(this + 4384) = 0;
    if ( v49 )
    {
      *(_DWORD *)(this + 4376) = 1;
    }
    else
    {
      *(_DWORD *)(this + 4372) = 0;
      *(_DWORD *)(this + 4376) = 2;
    }
    if ( (a7 & 0x80u) != 0 && (*(_BYTE *)a2 & 0x10) != 0 )
    {
      *(_DWORD *)(this + 4404) = 1;
      *(_DWORD *)(this + 4400) = a8;
    }
    else
    {
      *(_DWORD *)(this + 4404) = 0x80000000;
      *(_DWORD *)(this + 4400) = a8;
    }
  }
  else
  {
    *(_DWORD *)(this + 4384) = 1;
    if ( v49 )
    {
      *(_DWORD *)(this + 4376) = 1;
    }
    else
    {
      *(_DWORD *)(this + 4372) = 0;
      if ( (a7 & 0x80u) != 0 && (*(_BYTE *)a2 & 0x10) != 0 )
        *(_DWORD *)(this + 4376) = 4;
      else
        *(_DWORD *)(this + 4376) = 3;
    }
    *(_DWORD *)(this + 4400) = 0;
  }
  *(_DWORD *)(this + 4356) = a4;
  *(_DWORD *)(this + 4360) = a5;
  *(_DWORD *)(this + 4380) = a3;
  *(_DWORD *)(this + 4368) = 1;
  *(_DWORD *)(this + 4388) = 0;
  *(_DWORD *)(this + 4392) = 80;
  if ( v50 )
  {
    if ( (*(_BYTE *)a2 & 4) != 0 )
    {
      v17 = *(_DWORD *)(this + 5076) == 0;
      *(_DWORD *)(this + 5080) = 0;
      if ( v17 )
      {
        v27 = 64;
        *(_DWORD *)(this + 4408) = 2;
      }
      else
      {
        v27 = 128;
        *(_DWORD *)(this + 4408) = 1;
      }
      if ( *(_DWORD *)(this + 5088) == 2 )
        goto LABEL_95;
      v27 = 128;
      *(_DWORD *)(this + 4408) = 1;
    }
    else
    {
      v27 = 32;
      *(_DWORD *)(this + 4408) = 0;
    }
    *(_DWORD *)(this + 5080) = 0;
LABEL_95:
    v28 = (_DWORD *)(this + 4352);
    v29 = (*(int (__stdcall **)(_DWORD, int, int, int, int, int, int))(**(_DWORD **)(this + 4348) + 60))(
            *(_DWORD *)(this + 4348),
            a2[65],
            1,
            a3,
            v27,
            this + 4356,
            this + 4352);
    goto LABEL_96;
  }
  v28 = (_DWORD *)(this + 4352);
  v29 = (*(int (__stdcall **)(_DWORD, int))(**(_DWORD **)(this + 4352) + 56))(*(_DWORD *)(this + 4352), this + 4356);
LABEL_96:
  *(_DWORD *)this = v29;
  if ( v29 )
  {
    StringFormatWithBufferOverflowCheck(v58, "%s - 0x%X", aCouldNotSetDis, v29);
    sub_53C590(-1, v58);
    return -1;
  }
  v31 = *v28;
  *(_DWORD *)(this + 4) = a2[65];
  v32 = (*(int (__stdcall **)(int, _DWORD, _DWORD, int))(*(_DWORD *)v31 + 64))(v31, 0, 0, *(_DWORD *)(this + 5416) + 12);
  v33 = *(_DWORD *)(this + 5416);
  *(_DWORD *)this = v32;
  v34 = (*(int (__stdcall **)(_DWORD))(**(_DWORD **)(v33 + 12) + 8))(*(_DWORD *)(v33 + 12));
  v35 = *(_DWORD *)(this + 5416);
  *(_DWORD *)this = v34;
  *(_DWORD *)(v35 + 28) = a4;
  *(_DWORD *)(*(_DWORD *)(this + 5416) + 32) = a5;
  *(_DWORD *)(*(_DWORD *)(this + 5416) + 24) = 262146;
  *(_DWORD *)(*(_DWORD *)(this + 5416) + 48) = GetVTableParamBasedOnFlagBits(*(_DWORD *)(this + 5416));
  if ( (*(_BYTE *)a2 & 8) != 0 )
  {
    v36 = *v28;
    if ( v49 )
      v37 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v36 + 200))(v36, 161, 1);
    else
      v37 = (*(int (__stdcall **)(int, int, _DWORD))(*(_DWORD *)v36 + 200))(v36, 161, 0);
    v38 = *(_DWORD *)(this + 5416);
    *(_DWORD *)this = v37;
    if ( sub_53F3F0(a2, v38, *(_DWORD *)(this + 5420), v49) )
      return -1;
    v39 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)*v28 + 124))(
            *v28,
            0,
            *(_DWORD *)(*(_DWORD *)(this + 5420) + 12));
    *(_DWORD *)this = v39;
    if ( v39 )
    {
      sub_53C590(-1, aInvalidParamet);
      return -1;
    }
  }
  a2[69] = (*(int (__stdcall **)(_DWORD))(*(_DWORD *)*v28 + 16))(*v28);
  v40 = (*(int (__stdcall **)(_DWORD, _BYTE *))(*(_DWORD *)*v28 + 28))(*v28, v52);
  *(_DWORD *)this = v40;
  if ( !v40 )
  {
    v41 = v57;
    *(_DWORD *)(this + 5036) = v57;
    *(_DWORD *)(this + 5040) = v41;
    *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, int, int, _BYTE *))(**(_DWORD **)(this + 4348) + 20))(
                        *(_DWORD *)(this + 4348),
                        a2[65],
                        2,
                        v59);
    if ( v60 == 4170 )
    {
      *(_DWORD *)(this + 5032) |= 0x2000u;
      *(_DWORD *)(this + 5456) = 1;
      *(_DWORD *)(this + 5460) = 256;
    }
    if ( (v55 & 0x20000) != 0 )
      *(_DWORD *)(this + 5032) |= 1u;
    v42 = BYTE1(v53);
    if ( (v53 & 0x4000) != 0 )
      *(_DWORD *)(this + 5032) |= 2u;
    v43 = v54;
    v17 = (v54 & 0x4000) == 0;
    *(_DWORD *)(this + 5048) = 1;
    if ( !v17 )
      *(_DWORD *)(this + 5032) |= 0x100u;
    if ( (v43 & 0x100) != 0 )
      *(_DWORD *)(this + 5032) |= 0x4000u;
    if ( (v43 & 0x80u) != 0 )
      *(_DWORD *)(this + 5032) |= 0x8000u;
    v44 = v56;
    if ( ((unsigned int)&unk_800000 & v56) != 0 )
      *(_DWORD *)(this + 5032) |= 0x20u;
    if ( (v44 & 0x16) != 0 )
      *(_DWORD *)(this + 5032) |= 0x40u;
    if ( (v42 & 0x10) != 0 )
      *(_DWORD *)(this + 5032) |= 4u;
    v45 = *(_DWORD *)(this + 4364);
    if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
            *(_DWORD *)(this + 4348),
            a2[65],
            1,
            v45,
            0,
            3,
            827611204) )
      *(_DWORD *)(this + 5032) |= 0x1000u;
    if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
            *(_DWORD *)(this + 4348),
            a2[65],
            1,
            v45,
            0,
            3,
            844388420) )
      *(_DWORD *)(this + 5032) |= 0x10000u;
    if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
            *(_DWORD *)(this + 4348),
            a2[65],
            1,
            v45,
            0,
            3,
            861165636) )
      *(_DWORD *)(this + 5032) |= 0x20000u;
    if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
            *(_DWORD *)(this + 4348),
            a2[65],
            1,
            v45,
            0,
            3,
            877942852) )
      *(_DWORD *)(this + 5032) |= 0x40000u;
    if ( !(*(int (__stdcall **)(_DWORD, int, int, int, _DWORD, int, int))(**(_DWORD **)(this + 4348) + 40))(
            *(_DWORD *)(this + 4348),
            a2[65],
            1,
            v45,
            0,
            3,
            894720068) )
      *(_DWORD *)(this + 5032) |= 0x80000u;
  }
  return -(sub_53EB70(0) != 0);
}
