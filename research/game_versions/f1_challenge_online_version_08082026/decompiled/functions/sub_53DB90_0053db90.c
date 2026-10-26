int __thiscall sub_53DB90(int this, unsigned int *a2, int a3)
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
  unsigned int v23; // edx
  int v24; // eax
  int v25; // ebp
  int v26; // eax
  bool v27; // zf
  unsigned int v28; // edx
  int v29; // [esp+1DCh] [ebp-528h] BYREF
  int v30; // [esp+1E0h] [ebp-524h] BYREF
  unsigned int v31; // [esp+1E4h] [ebp-520h] BYREF
  unsigned int v32; // [esp+1E8h] [ebp-51Ch]
  int v33; // [esp+1ECh] [ebp-518h]
  int v34; // [esp+1F0h] [ebp-514h]
  char v35[12]; // [esp+1F4h] [ebp-510h] BYREF
  int v36; // [esp+200h] [ebp-504h]
  char v37[12]; // [esp+204h] [ebp-500h] BYREF
  int v38; // [esp+210h] [ebp-4F4h]
  char v39; // [esp+218h] [ebp-4ECh]
  int v40; // [esp+220h] [ebp-4E4h]
  char v41[1032]; // [esp+2D8h] [ebp-42Ch] BYREF
  int v42; // [esp+6E0h] [ebp-24h]

  *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, unsigned int, int, char *))(**(_DWORD **)(this + 4348) + 20))(
                      *(_DWORD *)(this + 4348),
                      a2[65],
                      2,
                      v41);
  if ( v42 == 4170 )
    sub_53D930((_DWORD *)this, -1, -1, 1024, 768);
  v4 = 0;
  v5 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4348) + 36))(
         *(_DWORD *)(this + 4348),
         a2[65],
         1,
         23,
         23,
         0);
  *(_DWORD *)this = v5;
  if ( !v5 )
    *a2 |= 0x1000000u;
  v6 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4348) + 36))(
         *(_DWORD *)(this + 4348),
         a2[65],
         1,
         24,
         25,
         0);
  *(_DWORD *)this = v6;
  if ( !v6 )
    *a2 |= 0x2000000u;
  v7 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4348) + 36))(
         *(_DWORD *)(this + 4348),
         a2[65],
         1,
         24,
         24,
         0);
  *(_DWORD *)this = v7;
  if ( !v7 )
    *a2 |= 0x4000000u;
  v8 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4348) + 36))(
         *(_DWORD *)(this + 4348),
         a2[65],
         1,
         20,
         20,
         0);
  *(_DWORD *)this = v8;
  if ( !v8 )
    *a2 |= 0x8000000u;
  v9 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4348) + 36))(
         *(_DWORD *)(this + 4348),
         a2[65],
         1,
         22,
         22,
         0);
  *(_DWORD *)this = v9;
  if ( !v9 )
    *a2 |= 0x20000000u;
  v10 = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, _DWORD))(**(_DWORD **)(this + 4348) + 36))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          21,
          0);
  *(_DWORD *)this = v10;
  if ( !v10 )
    *a2 |= 0x10000000u;
  v11 = (*(int (__stdcall **)(_DWORD, unsigned int, int, char *))(**(_DWORD **)(this + 4348) + 52))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          v37);
  *(_DWORD *)this = v11;
  if ( v11 )
    return -1;
  v13 = v40;
  v14 = *a2;
  if ( (v40 & 0x10000) != 0 )
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
  if ( (v38 & 0x80000) != 0 )
    v19 = v18 | 1;
  else
    v19 = v18 & 0xFFFFFFFE;
  *a2 = v19;
  v20 = *a2;
  if ( (v39 & 1) != 0 )
    v21 = v20 | 0x10;
  else
    v21 = v20 & 0xFFFFFFEF;
  v22 = a2[65];
  *a2 = v21;
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          v22,
          1,
          23,
          0,
          2)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          0,
          2) )
  {
    *a2 |= 0x20u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          0,
          3)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          0,
          3) )
  {
    *a2 |= 0x80u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          0,
          4)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          0,
          4) )
  {
    *a2 |= 0x40u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          0,
          6)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          0,
          6) )
  {
    *a2 |= 0x200u;
  }
  if ( !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          23,
          0,
          16)
    || !(*(int (__stdcall **)(_DWORD, unsigned int, int, int, _DWORD, int))(**(_DWORD **)(this + 4348) + 44))(
          *(_DWORD *)(this + 4348),
          a2[65],
          1,
          22,
          0,
          16) )
  {
    *a2 |= 0x80000u;
  }
  v23 = a2[65];
  a2[68] = 0;
  a2[69] = 0;
  v24 = (*(int (__stdcall **)(_DWORD, unsigned int, char *))(**(_DWORD **)(this + 4348) + 32))(
          *(_DWORD *)(this + 4348),
          v23,
          v35);
  *(_DWORD *)this = v24;
  if ( v24 )
  {
    sub_53C590(-1, aCouldNotGetCur);
    return -1;
  }
  if ( v36 == 22 )
    sub_55C450(21, &v29, &v30);
  else
    sub_55C450(v36, &v29, &v30);
  v25 = (*(int (__stdcall **)(_DWORD, unsigned int))(**(_DWORD **)(this + 4348) + 24))(*(_DWORD *)(this + 4348), a2[65]);
  if ( v25 <= 0 )
  {
    sub_53C590(-1, aErrorEnumDispl);
    return -1;
  }
  do
  {
    v26 = (*(int (__stdcall **)(_DWORD, unsigned int, int, unsigned int *))(**(_DWORD **)(this + 4348) + 28))(
            *(_DWORD *)(this + 4348),
            a2[65],
            v4,
            &v31);
    *(_DWORD *)this = v26;
    if ( !v26 )
    {
      *(_DWORD *)this = (*(int (__stdcall **)(_DWORD, unsigned int, int, int, int, int))(**(_DWORD **)(this + 4348) + 36))(
                          *(_DWORD *)(this + 4348),
                          a2[65],
                          1,
                          v36,
                          v34,
                          1);
      v29 = 0;
      if ( v34 == 22 )
        sub_55C450(21, &v29, &v30);
      else
        sub_55C450(v34, &v29, &v30);
      if ( v29 >= 16 )
      {
        switch ( v31 )
        {
          case 0x2C0u:
            v27 = v32 == 480;
            break;
          case 0x2D0u:
            v27 = v32 == 480;
            break;
          case 0x358u:
            v27 = v32 == 480;
            break;
          case 0x3C0u:
          case 0x500u:
            v27 = v32 == 720;
            break;
          default:
LABEL_69:
            if ( v31 >= *(_DWORD *)(this + 5384) && v32 >= *(_DWORD *)(this + 5388) )
            {
              v28 = *(_DWORD *)(this + 5392);
              if ( v31 <= v28 && v32 <= v28 )
                sub_55BC00(v31, v32, v30, v33);
            }
            goto LABEL_74;
        }
        if ( v27 )
          goto LABEL_74;
        goto LABEL_69;
      }
    }
LABEL_74:
    ++v4;
  }
  while ( v4 < v25 );
  return 0;
}
