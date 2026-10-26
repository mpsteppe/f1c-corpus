int __userpurge sub_610910@<eax>(int *a1@<ecx>, int a2@<ebx>, _DWORD *a3, char *a4, char *a5, char a6)
{
  _DWORD *v7; // ebp
  int v8; // edi
  BOOL v9; // eax
  int result; // eax
  int v11; // edi
  signed int v12; // ebx
  int v13; // eax
  int v14; // ebp
  _DWORD *v15; // eax
  bool v16; // bl
  BOOL v17; // eax
  char v18; // al
  BOOL v19; // eax
  int v20; // eax
  int v21; // edi
  int v22; // eax
  int v23; // ebx
  int v24; // edi
  int v25; // edi
  char *v26; // ebx
  char v27; // bl
  int v28; // edx
  int v29; // eax
  int v30; // edi
  int v31; // eax
  bool v32; // zf
  int v33; // [esp+90h] [ebp-4Ch]
  int v34; // [esp+90h] [ebp-4Ch]
  int v35; // [esp+94h] [ebp-48h]
  int v36; // [esp+94h] [ebp-48h]
  signed int v38; // [esp+A8h] [ebp-34h]
  int v39; // [esp+ACh] [ebp-30h]
  int v40; // [esp+B0h] [ebp-2Ch]
  int i; // [esp+B4h] [ebp-28h]
  signed int v42; // [esp+B8h] [ebp-24h]
  signed int v43; // [esp+BCh] [ebp-20h]
  int v44; // [esp+C0h] [ebp-1Ch]
  int v45; // [esp+C4h] [ebp-18h]
  _DWORD *v46; // [esp+C8h] [ebp-14h]
  int v47; // [esp+CCh] [ebp-10h]
  int v48; // [esp+D0h] [ebp-Ch]
  _DWORD *v49; // [esp+D4h] [ebp-8h]
  int v50; // [esp+D8h] [ebp-4h]

  v7 = (_DWORD *)a1[2281];
  v8 = a1[2275];
  v46 = v7;
  v9 = a1[2253] && *((_BYTE *)a1 + 9056);
  result = (*(int (__thiscall **)(int *, int, BOOL))(*a1 + 44))(a1, 28, v9);
  if ( v8 > 0 )
  {
    v47 = v8;
    do
    {
      v11 = *v7;
      v39 = *v7;
      sub_5F7B20((int)a3);
      v12 = v43;
      v38 = v43;
      if ( v43 < v42 )
      {
        do
        {
          (*(void (__thiscall **)(int *, _DWORD, int, signed int, _DWORD))(*a1 + 40))(a1, 0, v11, v12, 0);
          v44 = sub_5F7B60((_DWORD *)v11, 0, v12);
          v49 = (_DWORD *)sub_5F7BF0((_DWORD *)v11, v12);
          (*(void (__thiscall **)(int *, _DWORD))(*a1 + 76))(a1, 0);
          v13 = 0;
          v45 = **(_DWORD **)(v11 + 772);
          for ( i = 0; i < v45; ++i )
          {
            v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v11 + 772) + 4) + 4 * v13);
            if ( (void *)v14 == dword_FB27AC )
            {
              if ( v12 == v43 )
              {
                v16 = 0;
                if ( (*a3 & 0x10000) != 0 && (*a4 & 0x40) != 0 )
                {
                  v15 = (_DWORD *)a3[149];
                  a3[151] = v15;
                  if ( v15 )
                  {
                    if ( *v15 )
                      v16 = 1;
                  }
                }
                v17 = a1[2253] && *((_BYTE *)a1 + 9057);
                (*(void (__thiscall **)(int *, int, BOOL, int))(*a1 + 44))(a1, 28, v17, a2);
                (*(void (__thiscall **)(int *, int, _DWORD))(*a1 + 44))(a1, 168, 0);
                (*(void (__thiscall **)(int *, int))(*a1 + 76))(a1, 1);
                sub_60EF10(a1, (int)a4, (int)a5, 0, 1);
                (*(void (__thiscall **)(int *, int, int))(*a1 + 44))(a1, 23, 3);
                (*(void (__thiscall **)(int *, int, int))(*a1 + 44))(a1, 168, 15);
                (*(void (__thiscall **)(int *, _DWORD))(*a1 + 76))(a1, 0);
                v18 = !v16 && a6;
                sub_60EF10(a1, (int)a4, (int)a5, v18, 0);
                (*(void (__thiscall **)(int *, int, int))(*a1 + 44))(a1, 23, 2);
                v19 = a1[2253] && *((_BYTE *)a1 + 9056);
                (*(void (__thiscall **)(int *, int, BOOL))(*a1 + 44))(a1, 28, v19);
                if ( v16 )
                  sub_60E9B0(a1, (int)a4, a5, a6);
                a2 = 0;
                (*(void (__thiscall **)(int *, _DWORD, int, int))(*a1 + 40))(a1, 0, v40, v39);
              }
            }
            else
            {
              v20 = sub_5E80D0((_DWORD *)v14, 0);
              v21 = *a1;
              v35 = *(_DWORD *)(v20 + 124);
              v33 = *(_DWORD *)(v14 + 236) | (*(_DWORD *)(v14 + 240) << 16);
              v22 = sub_5E8830((_DWORD *)v14, 0);
              (*(void (__thiscall **)(int *, int, int, int))(v21 + 20))(a1, v22, v33, v35);
              v23 = *(_DWORD *)(v14 + 212);
              v24 = 0;
              v40 = 0;
              v48 = v23;
              if ( *(int *)(v14 + 208) > 0 )
              {
                while ( 1 )
                {
                  sub_5EA5A0(*(const char **)(v23 + 4 * v24));
                  v25 = *(_DWORD *)(v23 + 4 * v24);
                  if ( (*(int (__thiscall **)(int *, int, _DWORD))(*a1 + 392))(a1, v25, 0) )
                  {
                    (*(void (__thiscall **)(int *, int, _DWORD))(*a1 + 28))(a1, v25, 0);
                    (*(void (__thiscall **)(int *, int, int))(*a1 + 48))(a1, v14, v25);
                    sub_5EA5A0((const char *)v25);
                    v26 = a4;
                    sub_5F77D0(v49, (int)a4, v25);
                    if ( (*(_DWORD *)v25 & 0x400000) != 0 )
                    {
                      if ( sub_5FA770(v44, (int)a4, v25, 1) )
                      {
                        v27 = 0;
                        if ( (*(_DWORD *)a4 & 0x40000) == 0 )
                        {
                          v50 = a1[1202];
                          (*(void (__thiscall **)(int *, int, int))(*a1 + 44))(a1, 22, 3);
                          v27 = 1;
                        }
                        a1[2] = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)a1[2387] + 328))(
                                  a1[2387],
                                  *(_DWORD *)(v25 + 80),
                                  *(_DWORD *)(v25 + 52),
                                  0,
                                  *(_DWORD *)(v25 + 8),
                                  *(_DWORD *)(v25 + 56),
                                  *(_DWORD *)(v25 + 84));
                        if ( v27 )
                        {
                          v28 = *a1;
                          a1[1202] = v50;
                          (*(void (__thiscall **)(int *, int, int))(v28 + 44))(a1, 22, v50);
                        }
                        v26 = a4;
                      }
                      dword_FB3EBC = 0;
                      dword_FB3EB8 = 0;
                    }
                    if ( ((unsigned int)&byte_800000 & *(_DWORD *)v25) == 0 && sub_5FA770(v44, (int)v26, v25, 0) )
                      a1[2] = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)a1[2387] + 328))(
                                a1[2387],
                                *(_DWORD *)(v25 + 80),
                                *(_DWORD *)(v25 + 52),
                                0,
                                *(_DWORD *)(v25 + 8),
                                *(_DWORD *)(v25 + 56),
                                *(_DWORD *)(v25 + 84));
                    if ( (*(_DWORD *)v25 & 0xC0000000) == 0xC0000000 && sub_60E820(a1, (int)v26, a3, v26, (char *)v25) )
                    {
                      if ( v40 + 1 >= *(_DWORD *)(v14 + 208) )
                      {
                        if ( i + 1 < v45 )
                          (*(void (__thiscall **)(int *, _DWORD, int, signed int, _DWORD))(*a1 + 40))(
                            a1,
                            0,
                            v39,
                            v38,
                            0);
                      }
                      else
                      {
                        (*(void (__thiscall **)(int *, _DWORD, int, signed int, _DWORD))(*a1 + 40))(a1, 0, v39, v38, 0);
                        v29 = sub_5E80D0((_DWORD *)v14, 0);
                        v30 = *a1;
                        v36 = *(_DWORD *)(v29 + 124);
                        v34 = *(_DWORD *)(v14 + 236) | (*(_DWORD *)(v14 + 240) << 16);
                        v31 = sub_5E8830((_DWORD *)v14, 0);
                        (*(void (__thiscall **)(int *, int, int, int))(v30 + 20))(a1, v31, v34, v36);
                      }
                    }
                  }
                  v24 = ++v40;
                  if ( v40 >= *(_DWORD *)(v14 + 208) )
                    break;
                  v23 = v48;
                }
              }
            }
            v12 = v38;
            if ( (_BYTE)a5 && v38 == v42 - 1 )
            {
              *(_BYTE *)(v14 + 200) = 0;
              *(_DWORD *)(v14 + 208) = 0;
            }
            v11 = v39;
            v13 = i + 1;
          }
          v38 = ++v12;
        }
        while ( v12 < v42 );
        v7 = v46;
      }
      if ( (_BYTE)a5 )
      {
        *v7 = 0;
        **(_DWORD **)(v11 + 772) = 0;
        *(_DWORD *)(v11 + 724) = 0;
        *(_DWORD *)(v11 + 796) = 0;
      }
      ++v7;
      result = v47 - 1;
      v32 = v47 == 1;
      v46 = v7;
      --v47;
    }
    while ( !v32 );
  }
  return result;
}
