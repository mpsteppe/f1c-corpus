void __userpurge sub_60E3E0(_DWORD *a1@<ecx>, int a2@<edi>, _DWORD *a3, float *a4)
{
  float *v5; // ebx
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  int v8; // eax
  int v9; // edx
  int *v10; // eax
  int v11; // edi
  int v12; // eax
  int v13; // eax
  int *v14; // eax
  int **v15; // eax
  int *v16; // edi
  int v17; // ebp
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  int **v21; // eax
  int v22; // [esp+18h] [ebp-2Ch]
  int v23; // [esp+1Ch] [ebp-28h]
  bool v24; // [esp+33h] [ebp-11h]
  char *v25; // [esp+34h] [ebp-10h] BYREF
  int v26; // [esp+38h] [ebp-Ch] BYREF
  int v27; // [esp+3Ch] [ebp-8h] BYREF
  int v28; // [esp+40h] [ebp-4h]

  if ( (*a3 & 0xF0000) != 0 )
  {
    v5 = a4;
    if ( (*(_BYTE *)a4 & 0x40) != 0 )
    {
      if ( (v6 = (_DWORD *)a3[149], (a3[151] = v6) != 0) && *v6 || (v7 = (_DWORD *)a3[153], (a3[155] = v7) != 0) && *v7 )
      {
        sub_5E4DD0(a4, &v27, &v26);
        *(float *)&v23 = *(float *)&v26 + 0.001;
        *(float *)&v22 = *(float *)&v27 + 0.00050000002;
        sub_5E54E0((int)a4, v22, v23);
        sub_5E5050((char *)a4, 262);
        (*(void (__thiscall **)(_DWORD *, int, int, int, int))(*a1 + 20))(a1, 2304, 393221, 127, a2);
        if ( !a1[2412] )
        {
          sub_609BF0(6);
          sub_60A000(1);
          sub_60A790(a1 + 257);
          v8 = (*(int (__thiscall **)(_DWORD *))(*a1 + 532))(a1);
          v9 = *a1;
          a1[1212] = 255 - v8;
          (*(void (__thiscall **)(_DWORD *, int, int))(v9 + 44))(a1, 60, 255 - v8);
        }
        sub_60A500(0);
        sub_60A3A0(a1 + 705, 1);
        sub_60A3F0(a1 + 705, 1);
        v24 = (*a3 & 0x80000) != 0;
        if ( (*a3 & 0x10000) != 0 )
        {
          v10 = (int *)a3[149];
          a3[151] = v10;
          if ( v10 )
          {
            v11 = *v10;
            if ( *v10 )
            {
              do
              {
                if ( (*(_BYTE *)v11 & 4) != 0 )
                  v25 = *(char **)(*(_DWORD *)(v11 + 64) + 44);
                else
                  v25 = *(char **)(v11 + 44);
                if ( sub_5FE680(v25, a4) )
                {
                  v12 = (*(_DWORD *)v11 & 0x4000) != 0 && v24 ? (int)(a3 + 161) : 0;
                  if ( !sub_5E6A50((int *)v11, (int)(a3 + 157), 0, v12) )
                  {
                    sub_60DC90((int)v25);
                    sub_60DF60(a1, (int)v25, (int)a4, (_DWORD *)v11);
                  }
                }
                v13 = a3[151];
                if ( !v13 )
                  break;
                v14 = *(int **)(v13 + 4);
                a3[151] = v14;
                if ( !v14 )
                  break;
                v11 = *v14;
              }
              while ( *v14 );
            }
          }
        }
        if ( (*a3 & 0x20000) != 0 )
        {
          v15 = (int **)a3[153];
          a3[155] = v15;
          if ( v15 )
          {
            v16 = *v15;
            if ( *v15 )
            {
              do
              {
                if ( (*(_BYTE *)v16 & 4) != 0 )
                  v17 = *(_DWORD *)(v16[16] + 44);
                else
                  v17 = v16[11];
                if ( sub_5FE680((char *)v17, v5) )
                {
                  if ( (*v16 & 0x4000) != 0 && v24 )
                    v18 = (int)(a3 + 161);
                  else
                    v18 = 0;
                  if ( !sub_5E6A50(v16, (int)(a3 + 157), 0, v18) )
                  {
                    if ( (*(_DWORD *)v17 & 0x10000000) != 0 )
                    {
                      sub_5E8E20((float *)dword_FB27AC, 2, (float *)&v25);
                      if ( a1[2412] )
                      {
                        sub_5F7BF0(*(_DWORD **)(v17 + 280), 0);
                        *(float *)&dword_FB3F10 = 1.0 - (1.0 - *(float *)&dword_FB3F10) * *(float *)&v25;
                        *(float *)&dword_FB3F14 = 1.0 - (1.0 - *(float *)&dword_FB3F14) * *(float *)&v25;
                        *(float *)&dword_FB3F18 = 1.0 - (1.0 - *(float *)&dword_FB3F18) * *(float *)&v25;
                        *(float *)&dword_FB3F1C = 1.0 - (1.0 - *(float *)&dword_FB3F1C) * *(float *)&v25;
                        a1[2] = (*(int (__stdcall **)(_DWORD, int, int *, int))(*(_DWORD *)a1[2387] + 436))(
                                  a1[2387],
                                  5,
                                  &dword_FB3F10,
                                  1);
                        sub_60DC90(v17);
                        sub_60DF60(a1, v17, (int)v5, v16);
                        dword_FB3F10 = dword_FB2F58;
                        dword_FB3F14 = dword_FB2F5C;
                        dword_FB3F18 = dword_FB2F60;
                        dword_FB3F1C = LODWORD(flt_FB2F64);
                        a1[2] = (*(int (__stdcall **)(_DWORD, int, int *, int))(*(_DWORD *)a1[2387] + 436))(
                                  a1[2387],
                                  5,
                                  &dword_FB3F10,
                                  1);
                      }
                      else
                      {
                        v19 = *a1;
                        v28 = *((unsigned __int8 *)a1 + 4851);
                        (*(void (__fastcall **)(_DWORD *, _DWORD, int, unsigned int))(v19 + 44))(
                          a1,
                          (unsigned __int64)((double)v28 * *(float *)&v25) >> 32,
                          60,
                          (unsigned int)(unsigned __int64)((double)v28 * *(float *)&v25) << 24);
                        v5 = a4;
                        sub_60DC90(v17);
                        sub_60DF60(a1, v17, (int)a4, v16);
                        (*(void (__thiscall **)(_DWORD *, int, _DWORD))(*a1 + 44))(a1, 60, a1[1212]);
                      }
                    }
                    else
                    {
                      sub_60DC90(v17);
                      sub_60DF60(a1, v17, (int)v5, v16);
                    }
                  }
                }
                v20 = a3[155];
                if ( !v20 )
                  break;
                v21 = *(int ***)(v20 + 4);
                a3[155] = v21;
                if ( !v21 )
                  break;
                v16 = *v21;
              }
              while ( *v21 );
            }
          }
        }
        sub_5E54E0((int)v5, v27, v26);
        sub_5E5050((char *)v5, 262);
      }
    }
  }
}
