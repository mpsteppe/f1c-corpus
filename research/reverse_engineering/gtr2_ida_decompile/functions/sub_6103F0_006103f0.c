float *__userpurge sub_6103F0@<eax>(
        int *a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5,
        float *a6,
        _DWORD *a7)
{
  float *result; // eax
  bool v10; // zf
  int v11; // ebp
  int v12; // edi
  void *v13; // eax
  int v14; // ebp
  int v15; // edi
  char *v16; // ebx
  int v17; // edi
  _DWORD *v18; // ebp
  int v19; // edx
  int v20; // eax
  int v21; // ecx
  _DWORD *v22; // ecx
  int v23; // eax
  _DWORD *v24; // ecx
  int *v25; // eax
  int v26; // eax
  char *v27; // edi
  int v28; // ebx
  int v29; // eax
  _DWORD *v30; // ebx
  int v31; // eax
  int v32; // ebx
  int v33; // eax
  int *v34; // eax
  _DWORD *v35; // ebx
  int v36; // ebx
  int v37; // [esp+50h] [ebp-48h]
  int v38; // [esp+54h] [ebp-44h]
  bool v42; // [esp+6Bh] [ebp-2Dh]
  int v43; // [esp+6Ch] [ebp-2Ch]
  _DWORD *v44; // [esp+70h] [ebp-28h]
  int v45; // [esp+78h] [ebp-20h]
  _DWORD *v46; // [esp+7Ch] [ebp-1Ch]
  _DWORD *v47; // [esp+80h] [ebp-18h] BYREF
  int v48; // [esp+84h] [ebp-14h] BYREF
  int v49; // [esp+88h] [ebp-10h]
  int v50; // [esp+94h] [ebp-4h]
  bool v51; // [esp+9Ch] [ebp+4h]

  result = *(float **)a6;
  if ( (*(_DWORD *)a6 & 0x400) != 0 )
  {
    result = *(float **)a5;
    v10 = *(_DWORD *)a5 == 0;
    *(_DWORD *)(a5 + 8) = *(_DWORD *)a5;
    if ( !v10 )
    {
      if ( *(_DWORD *)result )
      {
        v11 = 0;
        if ( *(_DWORD *)(a5 + 12) > a1[2283] )
        {
          if ( a1[2284] )
            j__free((void *)a1[2284]);
          v12 = *(_DWORD *)(a5 + 12);
          a1[2283] = v12;
          v13 = operator new(8 * v12);
          v14 = (int)v13;
          v50 = 0;
          if ( v13 )
            sub_41D1B0((int)v13, 8, v12, (int)Concurrency::details::_ReaderWriterLock::_ReaderWriterLock);
          else
            v14 = 0;
          a1[2284] = v14;
          v11 = 0;
          v50 = -1;
        }
        v42 = (*a7 & 0x200000) != 0;
        result = *(float **)a5;
        v10 = *(_DWORD *)a5 == 0;
        v51 = (*a7 & 0x100000) != 0;
        *(_DWORD *)(a5 + 8) = *(_DWORD *)a5;
        if ( !v10 )
        {
          v15 = *(_DWORD *)result;
          if ( *(_DWORD *)result )
          {
            do
            {
              if ( sub_5FE680((char *)v15, a6) )
              {
                if ( *(_DWORD *)(v15 + 276) == a7[94] )
                  *(_DWORD *)(a1[2284] + 8 * v11) = 0;
                else
                  *(float *)(a1[2284] + 8 * v11) = sub_5D7980((float *)(v15 + 44), a6 + 13);
                *(_DWORD *)(a1[2284] + 8 * v11++ + 4) = v15;
              }
              result = *(float **)(a5 + 8);
              if ( !result )
                break;
              result = (float *)*((_DWORD *)result + 1);
              *(_DWORD *)(a5 + 8) = result;
              if ( !result )
                break;
              v15 = *(_DWORD *)result;
            }
            while ( *(_DWORD *)result );
            v43 = v11;
            if ( v11 > 0 )
            {
              v16 = (char *)a6;
              sub_5E4DD0(a6, &v48, &v47);
              *(float *)&v38 = *(float *)&v47 + 0.00050000002;
              *(float *)&v37 = *(float *)&v48 + 0.00025000001;
              sub_5E54E0((int)a6, v37, v38);
              sub_5E5050((char *)a6, 286);
              if ( a1[2253] )
                (*(void (__thiscall **)(int *, int, _DWORD))(*a1 + 44))(a1, 28, 0);
              if ( !a1[2412] )
              {
                sub_609BF0(7);
                sub_60A000(3);
                sub_609BF0(7);
                sub_60A000(2);
              }
              sub_60A500(0);
              sub_60A3A0(a1 + 705, 1);
              sub_60A3F0(a1 + 705, 1);
              if ( v11 > a7[93] )
              {
                sub_632C60(a1[2284], v11);
                if ( v11 >= a7[93] )
                  v11 = a7[93];
                v43 = v11;
              }
              v17 = 0;
              v46 = 0;
              if ( v11 > 0 )
              {
                do
                {
                  v18 = *(_DWORD **)(a1[2284] + 8 * v17 + 4);
                  v19 = 0;
                  v20 = 0;
                  if ( v51 && (*(_BYTE *)v18 & 0x20) != 0 )
                  {
                    v21 = v18[66];
                    if ( v21 == 0x4000000 )
                    {
                      v19 = (int)(a7 + 121);
                    }
                    else if ( v21 == 1024 )
                    {
                      v19 = (int)(a7 + 113);
                    }
                  }
                  if ( v42 && *(char *)v18 < 0 )
                  {
                    if ( v18[66] == 0x4000000 )
                      v20 = (int)(a7 + 117);
                    else
                      v20 = (int)(a7 + 109);
                  }
                  *v18 |= 4u;
                  if ( !sub_6004D0(v18, v17, v19, 0, v20) )
                  {
                    v22 = (_DWORD *)v18[67];
                    v23 = v22 ? sub_5E2E00(v22, v18[62]) : 0;
                    if ( (*(int (__thiscall **)(int *, int))(*a1 + 328))(a1, v23) )
                    {
                      v24 = (_DWORD *)v18[67];
                      v25 = v24 ? (int *)sub_5E2E00(v24, v18[62]) : 0;
                      sub_60A820(a1 + 705, v25);
                      v26 = 0;
                      v45 = 0;
                      if ( (int)v18[43] > 0 )
                      {
                        do
                        {
                          v27 = *(char **)(v18[46] + 4 * v26);
                          v28 = *a1;
                          v44 = (_DWORD *)*((_DWORD *)v27 + 1);
                          v29 = sub_5E3450(v44, v27, 0);
                          if ( (*(int (__thiscall **)(int *, int))(v28 + 328))(a1, v29) )
                          {
                            sub_5EA5A0(v27);
                            v30 = v44;
                            if ( (*(_BYTE *)v44 & 0x20) != 0 )
                            {
                              v31 = sub_5E8830(v44, 0);
                              (*(void (__thiscall **)(int *, int, int, int, int, int, int))(*a1 + 20))(
                                a1,
                                v31 | 0x800,
                                393221,
                                127,
                                a4,
                                a3,
                                a2);
                            }
                            else
                            {
                              v32 = v18[64];
                              v49 = v18[63];
                              v33 = sub_5E8830(v44, 0);
                              (*(void (__thiscall **)(int *, int, int, int, int, int, int))(*a1 + 20))(
                                a1,
                                v33 | 0x800,
                                v49 | (v32 << 16),
                                127,
                                a4,
                                a3,
                                a2);
                              v30 = v46;
                            }
                            v34 = (int *)sub_5E3450(v30, v27, 0);
                            sub_60A820(a1 + 767, v34);
                            v35 = v47;
                            a2 = 0;
                            a3 = 0;
                            a4 = (int)v47;
                            (*(void (__thiscall **)(int *, _DWORD))(*a1 + 40))(a1, 0);
                            (*(void (__thiscall **)(int *, char *, _DWORD))(*a1 + 28))(a1, v27, 0);
                            v36 = sub_5F7B60(v35, 0, 0);
                            sub_5F7460();
                            sub_5F6FC0(v36, (int)v27, (int)a6, v27, 0);
                            a1[2] = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)a1[2387] + 328))(
                                      a1[2387],
                                      *((_DWORD *)v27 + 20),
                                      *((_DWORD *)v27 + 13),
                                      0,
                                      *((_DWORD *)v27 + 2),
                                      *((_DWORD *)v27 + 14),
                                      *((_DWORD *)v27 + 21));
                          }
                          v26 = ++v45;
                        }
                        while ( v45 < v18[43] );
                        v17 = (int)v46;
                      }
                    }
                  }
                  v46 = (_DWORD *)++v17;
                }
                while ( v17 < v43 );
                v16 = (char *)a6;
              }
              if ( a1[2253] )
                (*(void (__thiscall **)(int *, int, int))(*a1 + 44))(a1, 28, 1);
              sub_5E54E0((int)v16, v48, (int)v47);
              return sub_5E5050(v16, 262);
            }
          }
        }
      }
    }
  }
  return result;
}
