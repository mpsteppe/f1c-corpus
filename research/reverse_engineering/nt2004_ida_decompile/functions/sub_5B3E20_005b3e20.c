int __userpurge sub_5B3E20@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  _DWORD *v5; // eax
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  int *v12; // esi
  _DWORD *v13; // eax
  int v14; // edx
  _DWORD *v15; // ecx
  int v16; // edx
  int v17; // eax
  int result; // eax
  _DWORD v20[6]; // [esp+Ch] [ebp-58h] BYREF
  _DWORD v21[16]; // [esp+24h] [ebp-40h] BYREF
  int v22; // [esp+68h] [ebp+4h]

  sub_5A9F40(v21);
  v5 = *(_DWORD **)(a3 + 16);
  v20[0] = v5[26] + 1;
  v20[1] = v5[25] + 1;
  v20[2] = v5[21] - 2;
  v6 = v5[22];
  v7 = *(_DWORD *)(a1 + 4448);
  v20[3] = v6 - 2;
  v20[4] = 0;
  v20[5] = 1065353216;
  *(_DWORD *)a1 = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v7 + 160))(v7, v20);
  v21[8] = 5;
  sub_5AA830((float *)(a1 + 4568), (int)v21, 0);
  sub_5AA930((int *)a1, 256, 0, 0);
  v8 = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(a1 + 4448) + 200))(*(_DWORD *)(a1 + 4448), 7, 0);
  v9 = *(_DWORD *)(a1 + 5168);
  *(_DWORD *)a1 = v8;
  v10 = *(_DWORD *)(a3 + 28);
  v11 = *(_DWORD *)(v10 + 312);
  if ( v11 != v9 )
  {
    *(_DWORD *)(a1 + 5168) = v11;
    sub_59E670(*(char **)(v10 + 312));
  }
  v22 = 0;
  if ( *(int *)(v10 + 280) > 0 )
  {
    v12 = (int *)(*(_DWORD *)(v10 + 284) + 28);
    do
    {
      if ( (v12[7] & 0x200) == 0 && !*(_DWORD *)(v10 + 316) )
      {
        v13 = (_DWORD *)sub_5A8020((int *)a1, (_DWORD *)*v12, 160, v12[4], *(v12 - 5));
        v14 = *(v12 - 5);
        v15 = (_DWORD *)*(v12 - 4);
        v12[1] = (int)v13;
        if ( v14 > 0 )
        {
          do
          {
            *v13 = *v15;
            v13[1] = v15[1];
            v13[2] = v15[2];
            v13 += 16;
            v15 += 12;
            --v14;
          }
          while ( v14 );
        }
        sub_5A80B0((int *)a1, *v12);
      }
      sub_5AA8A0((int *)a1, (_DWORD *)*v12);
      *(_DWORD *)a1 = (*(int (__stdcall **)(_DWORD, _DWORD, int, int))(**(_DWORD **)(a1 + 4448) + 340))(
                        *(_DWORD *)(a1 + 4448),
                        *(_DWORD *)(v12[2] + 24),
                        v12[4],
                        a2);
      v16 = *(v12 - 3);
      if ( (BYTE1(*(_DWORD *)(v10 + 20)) & 0x80u) == 0 )
      {
        a2 = v16 - 2;
        v17 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, int))(**(_DWORD **)(a1 + 4448) + 284))(
                *(_DWORD *)(a1 + 4448),
                5,
                0,
                *(v12 - 5),
                v12[5]);
      }
      else
      {
        a2 = v16 / 3;
        v17 = (*(int (__stdcall **)(_DWORD, int, _DWORD, _DWORD, int))(**(_DWORD **)(a1 + 4448) + 284))(
                *(_DWORD *)(a1 + 4448),
                4,
                0,
                *(v12 - 5),
                v12[5]);
      }
      *(_DWORD *)a1 = v17;
      v12 += 16;
      ++v22;
    }
    while ( v22 < *(_DWORD *)(v10 + 280) );
  }
  result = (*(int (__stdcall **)(_DWORD, int, _DWORD))(**(_DWORD **)(a1 + 4448) + 200))(
             *(_DWORD *)(a1 + 4448),
             7,
             *(_DWORD *)(a1 + 5144));
  *(_DWORD *)a1 = result;
  return result;
}
