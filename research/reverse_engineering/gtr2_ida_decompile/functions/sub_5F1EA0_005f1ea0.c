_DWORD *__thiscall sub_5F1EA0(_DWORD *this, char *a2, int a3, _DWORD *a4, int a5, int a6)
{
  int v8; // eax
  int v9; // edi
  int v10; // ebp
  int v11; // eax
  _DWORD *result; // eax
  int v13; // ecx
  int v14; // ebp
  _DWORD *v15; // eax
  int v16; // edx
  _DWORD *v17; // esi
  int v18; // edx
  int v19; // edx
  int v20; // ecx
  _DWORD *v21; // eax
  _DWORD *v22; // eax
  int v23; // edx
  _DWORD *v24; // esi
  int v25; // edx
  int v26; // edx
  int v27; // ecx
  _DWORD *v28; // eax
  unsigned int v29; // [esp+6Ch] [ebp+4h]
  unsigned int v30; // [esp+6Ch] [ebp+4h]
  int v31; // [esp+74h] [ebp+Ch]

  (*(void (__thiscall **)(_DWORD *, _DWORD))(*this + 460))(this, 0);
  if ( a2 )
    sub_5E5050(a2, 286);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD))(*this + 20))(this, 256, 0, 0);
  sub_609BF0(0);
  if ( *((_BYTE *)this + 4844) != 1 )
  {
    v8 = this[2387];
    *((_BYTE *)this + 4844) = 1;
    this[2] = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v8 + 228))(v8, 136, 1);
  }
  this[2] = (*(int (__stdcall **)(_DWORD, int, char *))(*(_DWORD *)this[2387] + 176))(
              this[2387],
              256,
              (char *)dword_FB27A8 + 4);
  v9 = (*(int (__thiscall **)(_DWORD *, const char *, _DWORD))(*this + 632))(this, "L0NOLIGHTING", 0);
  (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(*this + 40))(this, 0, v9, 0, 0);
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*this + 28))(this, 0, this[164]);
  sub_5F7B60(0, 0);
  sub_5FA770(a2, 0, 0);
  v10 = a6;
  v31 = a6;
  if ( a6 <= 0 )
    return (_DWORD *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 464))(this, 0);
  while ( 1 )
  {
    v11 = 2 * v10;
    if ( 2 * v10 >= 1024 )
      v11 = 1024;
    (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, int, int))(*this + 412))(this, this[164], 0, v11, 4096);
    result = *(_DWORD **)(this[164] + 76);
    if ( !result )
      break;
    v13 = v10;
    if ( v10 >= 512 )
      v13 = 512;
    v14 = 0;
    if ( a5 == 405222981 )
    {
      if ( v13 >= 4 )
      {
        v29 = ((unsigned int)(v13 - 4) >> 2) + 1;
        v31 -= 4 * v29;
        v14 = 4 * v29;
        do
        {
          *result = *a4;
          result[1] = a4[1];
          result[2] = a4[2];
          result[6] = a4[6];
          result[16] = a4[3];
          result[17] = a4[4];
          result[18] = a4[5];
          result[22] = a4[7];
          v15 = result + 16;
          v15[16] = a4[8];
          v15[17] = a4[9];
          v15[18] = a4[10];
          v15[22] = a4[14];
          v16 = a4[11];
          v17 = a4 + 8;
          v15 += 16;
          v15[16] = v16;
          v15[17] = v17[4];
          v15[18] = v17[5];
          v15[22] = v17[7];
          v15 += 16;
          v15[16] = v17[8];
          v15[17] = v17[9];
          v15[18] = v17[10];
          v15[22] = v17[14];
          v18 = v17[11];
          v17 += 8;
          v15 += 16;
          v15[16] = v18;
          v15[17] = v17[4];
          v15[18] = v17[5];
          v15 += 16;
          v15[6] = v17[7];
          v15[16] = v17[8];
          v19 = v17[9];
          v17 += 8;
          v15[17] = v19;
          v15 += 16;
          v15[2] = v17[2];
          v15[6] = v17[6];
          v15 += 16;
          *v15 = v17[3];
          v15[1] = v17[4];
          v15[2] = v17[5];
          v15[6] = v17[7];
          result = v15 + 16;
          a4 = v17 + 8;
          --v29;
        }
        while ( v29 );
      }
      if ( v14 < v13 )
      {
        v20 = v13 - v14;
        v31 -= v20;
        v14 += v20;
        do
        {
          *result = *a4;
          result[1] = a4[1];
          result[2] = a4[2];
          result[6] = a4[6];
          v21 = result + 16;
          *v21 = a4[3];
          v21[1] = a4[4];
          v21[2] = a4[5];
          v21[6] = a4[7];
          result = v21 + 16;
          a4 += 8;
          --v20;
        }
        while ( v20 );
      }
    }
    else
    {
      if ( v13 >= 4 )
      {
        v30 = ((unsigned int)(v13 - 4) >> 2) + 1;
        v31 -= 4 * v30;
        v14 = 4 * v30;
        do
        {
          *result = *a4;
          result[1] = a4[1];
          result[2] = a4[2];
          result[6] = a5;
          result[16] = a4[3];
          result[17] = a4[4];
          result[18] = a4[5];
          result[22] = a5;
          v22 = result + 16;
          v22[16] = a4[8];
          v22[17] = a4[9];
          v22[18] = a4[10];
          v22[22] = a5;
          v23 = a4[11];
          v24 = a4 + 8;
          v22 += 16;
          v22[16] = v23;
          v22[17] = v24[4];
          v22[18] = v24[5];
          v22[22] = a5;
          v22 += 16;
          v22[16] = v24[8];
          v22[17] = v24[9];
          v22[18] = v24[10];
          v22[22] = a5;
          v25 = v24[11];
          v24 += 8;
          v22 += 16;
          v22[16] = v25;
          v22[17] = v24[4];
          v22 += 16;
          v22[2] = v24[5];
          v22[6] = a5;
          v22[16] = v24[8];
          v26 = v24[9];
          v24 += 8;
          v22 += 16;
          v22[1] = v26;
          v22[2] = v24[2];
          v22[6] = a5;
          v22 += 16;
          *v22 = v24[3];
          v22[1] = v24[4];
          v22[2] = v24[5];
          v22[6] = a5;
          result = v22 + 16;
          a4 = v24 + 8;
          --v30;
        }
        while ( v30 );
      }
      if ( v14 < v13 )
      {
        v27 = v13 - v14;
        v31 -= v27;
        v14 += v27;
        do
        {
          *result = *a4;
          result[1] = a4[1];
          result[2] = a4[2];
          result[6] = a5;
          v28 = result + 16;
          *v28 = a4[3];
          v28[1] = a4[4];
          v28[2] = a4[5];
          v28[6] = a5;
          result = v28 + 16;
          a4 += 8;
          --v27;
        }
        while ( v27 );
      }
    }
    (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*this + 416))(this, this[164], 4096);
    this[2] = (*(int (__stdcall **)(_DWORD, int, _DWORD, int))(*(_DWORD *)this[2387] + 324))(this[2387], 2, 0, v14);
    if ( v31 <= 0 )
      return (_DWORD *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*this + 464))(this, 0);
    v10 = v31;
  }
  return result;
}
