_DWORD *__thiscall sub_5F2350(_DWORD *this, int a2, _DWORD *a3, int a4, int a5)
{
  _DWORD *v6; // ebx
  int v7; // eax
  int v8; // ebp
  int v10; // eax
  _DWORD *result; // eax
  int v12; // ecx
  signed int v13; // edx
  unsigned int v14; // ecx
  _DWORD *v15; // eax
  int v16; // edx
  _DWORD *v17; // esi
  int v18; // edx
  int v19; // edx
  int v20; // ecx
  _DWORD *v21; // eax
  unsigned int v22; // ecx
  _DWORD *v23; // eax
  _DWORD *v24; // esi
  int v25; // edx
  int v26; // edx
  int v27; // ecx
  _DWORD *v28; // eax
  signed int v30; // [esp+90h] [ebp+8h]
  int v31; // [esp+94h] [ebp+Ch]

  v6 = this;
  (*(void (__stdcall **)(_DWORD))(*this + 460))(0);
  (*(void (__stdcall **)(_DWORD, int, _DWORD))(*(_DWORD *)v6[2387] + 228))(v6[2387], 7, 0);
  sub_609BF0(0);
  (*(void (__thiscall **)(_DWORD *, int, _DWORD, _DWORD))(*v6 + 20))(v6, 256, 0, 0);
  if ( *((_BYTE *)v6 + 4844) != 1 )
  {
    v7 = v6[2387];
    *((_BYTE *)v6 + 4844) = 1;
    v6[2] = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v7 + 228))(v7, 136, 1);
  }
  v6[2] = (*(int (__stdcall **)(_DWORD, int, char *))(*(_DWORD *)v6[2387] + 176))(
            v6[2387],
            256,
            (char *)dword_FB27A8 + 4);
  v8 = (*(int (__thiscall **)(_DWORD *, const char *, _DWORD))(*v6 + 632))(v6, "L0SCREENT0", 0);
  (*(void (__thiscall **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(*v6 + 40))(v6, 0, v8, 0, 0);
  (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD))(*v6 + 28))(v6, 0, v6[165]);
  sub_5F7B60(0, 0);
  sub_5FA770(0, 0, 0);
  if ( a5 <= 0 )
  {
LABEL_27:
    (*(void (__stdcall **)(_DWORD, int, _DWORD))(*(_DWORD *)v6[2387] + 228))(v6[2387], 7, v6[1208]);
    return (_DWORD *)(*(int (__thiscall **)(_DWORD *, _DWORD))(*v6 + 464))(v6, 0);
  }
  else
  {
    while ( 1 )
    {
      v10 = 2 * a5;
      if ( 2 * a5 >= 1024 )
        v10 = 1024;
      (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, int, int))(*this + 412))(this, this[165], 0, v10, 0x2000);
      result = *(_DWORD **)(this[165] + 76);
      if ( !result )
        break;
      v12 = a5;
      if ( a5 >= 32 )
        v12 = 32;
      v31 = v12;
      if ( a4 == 405222981 )
      {
        v13 = 0;
        v30 = 0;
        if ( v12 >= 4 )
        {
          v30 = 4 * (((unsigned int)(v12 - 4) >> 2) + 1);
          v14 = ((unsigned int)(v12 - 4) >> 2) + 1;
          a5 -= v30;
          do
          {
            *result = *a3;
            result[1] = a3[1];
            result[2] = 0;
            result[3] = 1065353216;
            result[4] = a3[6];
            result[7] = a3[3];
            result[8] = a3[4];
            result[9] = 0;
            result[10] = 1065353216;
            result[11] = a3[7];
            v15 = result + 7;
            v15[7] = a3[8];
            v15[8] = a3[9];
            v15[9] = 0;
            v15[10] = 1065353216;
            v15[11] = a3[14];
            v15 += 7;
            v15[7] = a3[11];
            v15[8] = a3[12];
            v15[9] = 0;
            v15[10] = 1065353216;
            v16 = a3[15];
            v17 = a3 + 8;
            v15[11] = v16;
            v15 += 7;
            v15[7] = v17[8];
            v15[8] = v17[9];
            v15[9] = 0;
            v15[10] = 1065353216;
            v15[11] = v17[14];
            v18 = v17[11];
            v17 += 8;
            v15 += 7;
            v15[7] = v18;
            v15[8] = v17[4];
            v15[9] = 0;
            v15[10] = 1065353216;
            v15 += 7;
            v15[4] = v17[7];
            v19 = v17[8];
            v17 += 8;
            v15[7] = v19;
            v15 += 7;
            v15[1] = v17[1];
            v15[2] = 0;
            v15[3] = 1065353216;
            v15[4] = v17[6];
            v15 += 7;
            *v15 = v17[3];
            v15[1] = v17[4];
            v15[2] = 0;
            v15[3] = 1065353216;
            v15[4] = v17[7];
            result = v15 + 7;
            a3 = v17 + 8;
            --v14;
          }
          while ( v14 );
          v12 = v31;
          v13 = v30;
        }
        if ( v13 < v12 )
        {
          v20 = v12 - v13;
          a5 -= v20;
          v30 += v20;
          do
          {
            *result = *a3;
            result[1] = a3[1];
            result[2] = 0;
            result[3] = 1065353216;
            result[4] = a3[6];
            v21 = result + 7;
            *v21 = a3[3];
            v21[1] = a3[4];
            v21[2] = 0;
            v21[3] = 1065353216;
            v21[4] = a3[7];
            result = v21 + 7;
            a3 += 8;
            --v20;
          }
          while ( v20 );
        }
      }
      else
      {
        v30 = 0;
        if ( v12 >= 4 )
        {
          v30 = 4 * (((unsigned int)(v12 - 4) >> 2) + 1);
          v22 = ((unsigned int)(v12 - 4) >> 2) + 1;
          a5 -= v30;
          do
          {
            *result = *a3;
            result[1] = a3[1];
            result[2] = 0;
            result[3] = 1065353216;
            result[4] = a4;
            result[7] = a3[3];
            result[8] = a3[4];
            result[9] = 0;
            result[10] = 1065353216;
            result[11] = a4;
            v23 = result + 7;
            v23[7] = a3[8];
            v23[8] = a3[9];
            v23[9] = 0;
            v23[10] = 1065353216;
            v23[11] = a4;
            v23 += 7;
            v23[7] = a3[11];
            v23[8] = a3[12];
            v23[9] = 0;
            v23[10] = 1065353216;
            v23[11] = a4;
            v24 = a3 + 8;
            v23 += 7;
            v23[7] = v24[8];
            v23[8] = v24[9];
            v23[9] = 0;
            v23[10] = 1065353216;
            v23[11] = a4;
            v25 = v24[11];
            v23 += 7;
            v24 += 8;
            v23[7] = v25;
            v23 += 7;
            v23[1] = v24[4];
            v23[2] = 0;
            v23[3] = 1065353216;
            v23[4] = a4;
            v26 = v24[8];
            v23 += 7;
            v24 += 8;
            *v23 = v26;
            v23[1] = v24[1];
            v23[2] = 0;
            v23[3] = 1065353216;
            v23[4] = a4;
            v23 += 7;
            *v23 = v24[3];
            v23[1] = v24[4];
            v23[2] = 0;
            v23[3] = 1065353216;
            v23[4] = a4;
            result = v23 + 7;
            a3 = v24 + 8;
            --v22;
          }
          while ( v22 );
          v12 = v31;
        }
        if ( v30 < v12 )
        {
          v27 = v12 - v30;
          a5 -= v27;
          v30 += v27;
          do
          {
            *result = *a3;
            result[1] = a3[1];
            result[2] = 0;
            result[3] = 1065353216;
            result[4] = a4;
            v28 = result + 7;
            *v28 = a3[3];
            v28[1] = a3[4];
            v28[2] = 0;
            v28[3] = 1065353216;
            v28[4] = a4;
            result = v28 + 7;
            a3 += 8;
            --v27;
          }
          while ( v27 );
        }
      }
      (*(void (__thiscall **)(_DWORD *, _DWORD, int))(*this + 416))(this, this[165], 0x2000);
      this[2] = (*(int (__stdcall **)(_DWORD, int, _DWORD, signed int))(*(_DWORD *)this[2387] + 324))(
                  this[2387],
                  2,
                  0,
                  v30);
      if ( a5 <= 0 )
      {
        v6 = this;
        goto LABEL_27;
      }
    }
  }
  return result;
}
