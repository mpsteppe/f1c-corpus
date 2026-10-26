int __thiscall sub_5A4A50(int this, unsigned int *a2, int a3)
{
  int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // ecx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edx
  int v23; // eax
  unsigned int v24; // edx
  int v25; // ebp
  int v26; // eax
  unsigned int v27; // eax
  int v28; // [esp+1DCh] [ebp-528h] BYREF
  int v29; // [esp+1E0h] [ebp-524h] BYREF
  unsigned int v30; // [esp+1E4h] [ebp-520h] BYREF
  unsigned int v31; // [esp+1E8h] [ebp-51Ch]
  int v32; // [esp+1ECh] [ebp-518h]
  int v33; // [esp+1F0h] [ebp-514h]
  _DWORD v34[3]; // [esp+1F4h] [ebp-510h] BYREF
  int v35; // [esp+200h] [ebp-504h]
  char v36[12]; // [esp+204h] [ebp-500h] BYREF
  int v37; // [esp+210h] [ebp-4F4h]
  char v38; // [esp+218h] [ebp-4ECh]
  int v39; // [esp+220h] [ebp-4E4h]
  char v40[1032]; // [esp+2D8h] [ebp-42Ch] BYREF
  int v41; // [esp+6E0h] [ebp-24h]

  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, unsigned int, int, char *))(**(_DWORD **)(this + 4444) + 20))(
                      *(_DWORD *)(this + 4444),
                      a2[65],
                      2,
                      v40);
  if ( v41 == 4170 )
    sub_5A47F0((_DWORD *)this, -1, -1, 1024, 768);
  v4 = 0;
  v5 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4444) + 36))(
         *(_DWORD *)(this + 4444),
         a2[65],
         1,
         23,
         23,
         0);
  *(_DWORD *)this = v5;
  if ( !v5 )
    *a2 |= 0x1000000u;
  v6 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4444) + 36))(
         *(_DWORD *)(this + 4444),
         a2[65],
         1,
         24,
         25,
         0);
  *(_DWORD *)this = v6;
  if ( !v6 )
    *a2 |= 0x2000000u;
  v7 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4444) + 36))(
         *(_DWORD *)(this + 4444),
         a2[65],
         1,
         24,
         24,
         0);
  *(_DWORD *)this = v7;
  if ( !v7 )
    *a2 |= 0x4000000u;
  v8 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4444) + 36))(
         *(_DWORD *)(this + 4444),
         a2[65],
         1,
         20,
         20,
         0);
  *(_DWORD *)this = v8;
  if ( !v8 )
    *a2 |= 0x8000000u;
  v9 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4444) + 36))(
         *(_DWORD *)(this + 4444),
         a2[65],
         1,
         22,
         22,
         0);
  *(_DWORD *)this = v9;
  if ( !v9 )
    *a2 |= 0x20000000u;
  v10 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4444) + 36))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          21,
          0);
  *(_DWORD *)this = v10;
  if ( !v10 )
    *a2 |= 0x10000000u;
  v11 = (*(int (__stdcall **)(_DWORD, unsigned int, int, char *))(**(_DWORD **)(this + 4444) + 52))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          v36);
  *(_DWORD *)this = v11;
  if ( v11 )
    return -1;
  v13 = v39;
  v14 = *a2;
  if ( (v39 & 0x10000) != 0 )
    v15 = v14 | 4;
  else
    v15 = v14 & 0xFFFFFFFB;
  *a2 = v15;
  if ( (v13 & 0x100000) != 0 )
    v16 = v15 | 0x400000;
  else
    v16 = v15 & 0xFFBFFFFF;
  *a2 = v16;
  if ( (v13 & 0x80000) != 0 )
    v17 = v16 | 8;
  else
    v17 = v16 & 0xFFFFFFF7;
  *a2 = v17;
  v18 = *a2;
  if ( (v37 & 0x80000) != 0 )
    v19 = v18 | 1;
  else
    v19 = v18 & 0xFFFFFFFE;
  *a2 = v19;
  v20 = *a2;
  if ( (v38 & 1) != 0 )
    v21 = v20 | 0x10;
  else
    v21 = v20 & 0xFFFFFFEF;
  v22 = a2[65];
  *a2 = v21;
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          v22,
          1,
          23,
          0,
          2)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          0,
          2) )
  {
    *a2 |= 0x20u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          0,
          3)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          0,
          3) )
  {
    *a2 |= 0x80u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          0,
          4)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          0,
          4) )
  {
    *a2 |= 0x40u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          0,
          6)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          0,
          6) )
  {
    *a2 |= 0x200u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          23,
          0,
          16)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4444) + 44))(
          *(_DWORD *)(this + 4444),
          a2[65],
          1,
          22,
          0,
          16) )
  {
    *a2 |= 0x80000u;
  }
  v23 = (*(int (__stdcall **)(_DWORD, unsigned int, _DWORD *))(**(_DWORD **)(this + 4444) + 32))(
          *(_DWORD *)(this + 4444),
          a2[65],
          v34);
  *(_DWORD *)this = v23;
  if ( v23 )
  {
    sub_591C60(this, -1, aCouldNotGetCur);
    return -1;
  }
  else
  {
    if ( v35 == 22 )
      sub_5B41C0(21, &v28, &v29);
    else
      sub_5B41C0(v35, &v28, &v29);
    a2[68] = v34[0] * v34[1] * (v28 >> 3);
    v24 = a2[65];
    a2[69] = 0;
    v25 = (*(int (__stdcall **)(_DWORD, unsigned int))(**(_DWORD **)(this + 4444) + 24))(*(_DWORD *)(this + 4444), v24);
    if ( v25 > 0 )
    {
      do
      {
        v26 = (*(int (__stdcall **)(_DWORD, unsigned int, int, unsigned int *))(**(_DWORD **)(this + 4444) + 28))(
                *(_DWORD *)(this + 4444),
                a2[65],
                v4,
                &v30);
        *(_DWORD *)this = v26;
        if ( !v26 )
        {
          *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, int))(**(_DWORD **)(this + 4444)
                                                                                           + 36))(
                              *(_DWORD *)(this + 4444),
                              a2[65],
                              1,
                              v35,
                              v33,
                              1);
          v28 = 0;
          if ( v33 == 22 )
            sub_5B41C0(21, &v28, &v29);
          else
            sub_5B41C0(v33, &v28, &v29);
          if ( v28 >= 16 && v30 >= *(_DWORD *)(this + 8564) && v31 >= *(_DWORD *)(this + 8568) )
          {
            v27 = *(_DWORD *)(this + 8572);
            if ( v30 <= v27 && v31 <= v27 )
              sub_5A93C0(v30, v31, v29, v32);
          }
        }
        ++v4;
      }
      while ( v4 < v25 );
      return 0;
    }
    else
    {
      sub_591C60(this, -1, aErrorEnumDispl);
      return -1;
    }
  }
}
