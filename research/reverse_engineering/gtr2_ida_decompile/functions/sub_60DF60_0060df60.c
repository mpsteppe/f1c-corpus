int __thiscall sub_60DF60(_DWORD *this, int a2, int a3, _DWORD *a4)
{
  int result; // eax
  int *v7; // esi
  int v8; // ebp
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  int *v11; // eax
  _DWORD *v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // edx
  float v16; // [esp+50h] [ebp-3Ch]
  int i; // [esp+64h] [ebp-28h]
  int v18; // [esp+68h] [ebp-24h] BYREF
  float v19; // [esp+6Ch] [ebp-20h] BYREF
  int v20; // [esp+70h] [ebp-1Ch] BYREF
  int v21[3]; // [esp+74h] [ebp-18h] BYREF
  int v22[3]; // [esp+80h] [ebp-Ch] BYREF
  _DWORD *v23; // [esp+90h] [ebp+4h]
  int *v24; // [esp+90h] [ebp+4h]

  result = 0;
  for ( i = 0; i < *(_DWORD *)(a2 + 172); ++i )
  {
    v7 = *(int **)(*(_DWORD *)(a2 + 184) + 4 * result);
    if ( *v7 >= 0 )
    {
      if ( (*v7 & 8) != 0 )
        v23 = *(_DWORD **)(a2 + 288);
      else
        v23 = *(_DWORD **)(a2 + 284);
      v8 = sub_5F7B60(v23, 0, 0);
      sub_5F6FC0(v8, a2, a3, v7, 0);
      (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD *, _DWORD, _DWORD))(*this + 40))(this, 0, v23, 0, 0);
      (*(void (__thiscall **)(_DWORD *, int *, _DWORD))(*this + 28))(this, v7, 0);
      v9 = a4;
      if ( (*a4 & 0x40000) == 0 )
      {
        v10 = *(_DWORD **)(a2 + 268);
        if ( v10 )
          v11 = (int *)sub_5E2E00(v10, *(_DWORD *)(a2 + 248));
        else
          v11 = 0;
        sub_60A820(this + 705, v11);
        sub_5F7460();
        this[2] = (*(int (__stdcall **)(_DWORD, int, int, _DWORD, int, int, int))(*(_DWORD *)this[2387] + 328))(
                    this[2387],
                    v7[20],
                    v7[13],
                    0,
                    v7[2],
                    v7[14],
                    v7[21]);
        v9 = a4;
      }
      if ( (*v9 & 0x20000) != 0 )
      {
        v12 = (_DWORD *)v9[10];
        if ( v12 )
          v24 = (int *)sub_5E2E00(v12, 0);
        else
          v24 = 0;
        if ( (*(int (__thiscall **)(_DWORD *, int *))(*this + 328))(this, v24) )
        {
          v13 = *(_DWORD *)(a2 + 204);
          v14 = *(_DWORD *)(a2 + 208);
          v22[0] = *(_DWORD *)(a2 + 200);
          v22[1] = v13;
          v22[2] = v14;
          v15 = a4[12];
          v21[0] = 0;
          v21[1] = -1082130432;
          v21[2] = 0;
          sub_5DA5C0(*(_DWORD **)(v15 + 392), &v18, &v19, &v20);
          v16 = -v19;
          sub_5FEEB0((void *)a2, v21, v16);
          sub_5E5050(*(char **)(a2 + 272), 2);
          sub_5F7460();
          sub_60A820(this + 705, v24);
          this[2] = (*(int (__stdcall **)(_DWORD, int, int, _DWORD, int, int, int))(*(_DWORD *)this[2387] + 328))(
                      this[2387],
                      v7[20],
                      v7[13],
                      0,
                      v7[2],
                      v7[14],
                      v7[21]);
          sub_5FEEB0((void *)a2, v22, 0.0);
          sub_5E5050(*(char **)(a2 + 272), 2);
        }
      }
    }
    result = i + 1;
  }
  return result;
}
