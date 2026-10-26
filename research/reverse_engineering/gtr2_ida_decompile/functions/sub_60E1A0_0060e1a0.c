int __thiscall sub_60E1A0(_DWORD *this, int a2, int a3, char *a4, _DWORD *a5)
{
  int result; // eax
  char *v8; // esi
  int v9; // ebp
  _DWORD *v10; // eax
  _DWORD *v11; // ecx
  int *v12; // eax
  _DWORD *v13; // eax
  int v14; // edx
  int v15; // eax
  int v16; // edx
  float v17; // [esp+50h] [ebp-3Ch]
  int i; // [esp+64h] [ebp-28h]
  int v19; // [esp+68h] [ebp-24h] BYREF
  float v20; // [esp+6Ch] [ebp-20h] BYREF
  int v21; // [esp+70h] [ebp-1Ch] BYREF
  int v22[3]; // [esp+74h] [ebp-18h] BYREF
  int v23[3]; // [esp+80h] [ebp-Ch] BYREF
  _DWORD *v24; // [esp+90h] [ebp+4h]
  int *v25; // [esp+90h] [ebp+4h]

  result = 0;
  for ( i = 0; i < *(_DWORD *)(a2 + 172); ++i )
  {
    v8 = *(char **)(*(_DWORD *)(a2 + 184) + 4 * result);
    if ( v8 == a4 )
    {
      if ( (*v8 & 8) != 0 )
        v24 = *(_DWORD **)(a2 + 288);
      else
        v24 = *(_DWORD **)(a2 + 284);
      v9 = sub_5F7B60(v24, 0, 0);
      sub_5F6FC0(v9, a2, a3, v8, 0);
      sub_5EA5A0(v8);
      (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD *, _DWORD, _DWORD))(*this + 40))(this, 0, v24, 0, 0);
      (*(void (__thiscall **)(_DWORD *, char *, _DWORD))(*this + 28))(this, v8, 0);
      v10 = a5;
      if ( (*a5 & 0x40000) == 0 )
      {
        v11 = *(_DWORD **)(a2 + 268);
        if ( v11 )
          v12 = (int *)sub_5E2E00(v11, *(_DWORD *)(a2 + 248));
        else
          v12 = 0;
        sub_60A820(this + 705, v12);
        sub_5F7460();
        this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387]
                                                                                               + 328))(
                    this[2387],
                    *((_DWORD *)v8 + 20),
                    *((_DWORD *)v8 + 13),
                    0,
                    *((_DWORD *)v8 + 2),
                    *((_DWORD *)v8 + 14),
                    *((_DWORD *)v8 + 21));
        v10 = a5;
      }
      if ( (*v10 & 0x20000) != 0 )
      {
        v13 = (_DWORD *)v10[10];
        if ( v13 )
          v25 = (int *)sub_5E2E00(v13, 0);
        else
          v25 = 0;
        if ( (*(int (__thiscall **)(_DWORD *, int *))(*this + 328))(this, v25) )
        {
          v14 = *(_DWORD *)(a2 + 204);
          v15 = *(_DWORD *)(a2 + 208);
          v23[0] = *(_DWORD *)(a2 + 200);
          v23[1] = v14;
          v23[2] = v15;
          v16 = a5[12];
          v22[0] = 0;
          v22[1] = -1082130432;
          v22[2] = 0;
          sub_5DA5C0(*(_DWORD **)(v16 + 392), &v19, &v20, &v21);
          v17 = -v20;
          sub_5FEEB0((void *)a2, v22, v17);
          sub_5E5050(*(char **)(a2 + 272), 2);
          sub_5F7460();
          sub_60A820(this + 705, v25);
          this[2] = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)this[2387]
                                                                                                 + 328))(
                      this[2387],
                      *((_DWORD *)v8 + 20),
                      *((_DWORD *)v8 + 13),
                      0,
                      *((_DWORD *)v8 + 2),
                      *((_DWORD *)v8 + 14),
                      *((_DWORD *)v8 + 21));
          sub_5FEEB0((void *)a2, v23, 0.0);
          sub_5E5050(*(char **)(a2 + 272), 2);
        }
      }
    }
    result = i + 1;
  }
  return result;
}
