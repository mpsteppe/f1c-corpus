// f1c  0x0055cc20  size=453
int __thiscall sub_55CC20(int *this, int a2)
{
  int v3; // eax
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int result; // eax
  int v11; // eax
  _DWORD v12[6]; // [esp+40h] [ebp-218h] BYREF
  _BYTE v13[64]; // [esp+58h] [ebp-200h] BYREF
  _BYTE v14[64]; // [esp+98h] [ebp-1C0h] BYREF
  _BYTE v15[64]; // [esp+D8h] [ebp-180h] BYREF
  _BYTE v16[64]; // [esp+118h] [ebp-140h] BYREF
  _BYTE v17[64]; // [esp+158h] [ebp-100h] BYREF
  _BYTE v18[64]; // [esp+198h] [ebp-C0h] BYREF
  _BYTE v19[64]; // [esp+1D8h] [ebp-80h] BYREF

  sub_55CA90(this, *(_DWORD **)(a2 + 412), 0);
  v3 = *(_DWORD *)(a2 + 84);
  v4 = *(_DWORD *)(a2 + 100);
  v12[0] = *(_DWORD *)(a2 + 104);
  v12[3] = *(_DWORD *)(a2 + 88);
  v12[2] = v3;
  v5 = this[1088];
  v12[1] = v4;
  v12[4] = 0;
  v12[5] = 1065353216;
  *this = (*(int (__stdcall **)(int, _DWORD *))(*(_DWORD *)v5 + 160))(v5, v12);
  v6 = this[1257];
  if ( (*(_BYTE *)(a2 + 128) & 0x10) != 0 )
  {
    if ( v6 == 3 )
      goto LABEL_7;
    v7 = this[1088];
    this[1257] = 3;
    v8 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v7 + 200))(v7, 22, 3);
  }
  else
  {
    if ( v6 == 2 )
      goto LABEL_7;
    v9 = this[1088];
    this[1257] = 2;
    v8 = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 200))(v9, 22, 2);
  }
  *this = v8;
  this[1117] &= ~4u;
LABEL_7:
  result = this[1269];
  if ( result )
  {
    *this = (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)this[1088] + 152))(this[1088], 256, v17);
    *this = (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)this[1088] + 152))(this[1088], 3, v19);
    v11 = (*(int (__stdcall **)(int, int, _BYTE *))(*(_DWORD *)this[1088] + 152))(this[1088], 2, v14);
    qmemcpy(v16, v17, sizeof(v16));
    qmemcpy(v18, v19, sizeof(v18));
    *this = v11;
    qmemcpy(v15, v14, sizeof(v15));
    sub_50CBB0();
    sub_50CBB0();
    sub_50CDF9();
    result = (*(int (__stdcall **)(int, _DWORD, _BYTE *, int))(*(_DWORD *)this[1088] + 316))(this[1088], 0, v13, 4);
    *this = result;
  }
  return result;
}
