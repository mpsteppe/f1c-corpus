_DWORD *__userpurge sub_5F1CC0@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5,
        _DWORD *a6,
        int a7)
{
  _DWORD *result; // eax
  int v9; // eax
  int v10; // eax

  (*(void (__thiscall **)(int, int, _DWORD, _DWORD))(*(_DWORD *)a1 + 20))(a1, 256, 0, 0);
  sub_609BF0(0);
  sub_60AAF0(a1 + 2820);
  sub_60A790(a1 + 1028);
  sub_60AAF0(a1 + 3068);
  (*(void (__thiscall **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)a1 + 412))(
    a1,
    *(_DWORD *)(a1 + 656),
    0,
    0,
    4096);
  result = *(_DWORD **)(*(_DWORD *)(a1 + 656) + 76);
  if ( result )
  {
    *result = *a6;
    result[1] = a6[1];
    result[2] = a6[2];
    result[6] = a7;
    result[16] = a6[3];
    result[17] = a6[4];
    result[18] = a6[5];
    result[22] = a7;
    result[32] = a6[6];
    result[33] = a6[7];
    result[34] = a6[8];
    result[38] = a7;
    result[48] = a6[9];
    result[49] = a6[10];
    result[50] = a6[11];
    result[54] = a7;
    result[64] = a6[12];
    result[65] = a6[13];
    result[66] = a6[14];
    result[70] = a7;
    result[80] = a6[15];
    result[81] = a6[16];
    result[82] = a6[17];
    result[86] = a7;
    (*(void (__thiscall **)(int, _DWORD, int, int, int, int))(*(_DWORD *)a1 + 416))(
      a1,
      *(_DWORD *)(a1 + 656),
      4096,
      a4,
      a3,
      a2);
    if ( *(_BYTE *)(a1 + 4844) != 1 )
    {
      v9 = *(_DWORD *)(a1 + 9548);
      *(_BYTE *)(a1 + 4844) = 1;
      *(_DWORD *)(a1 + 8) = (*(int (__stdcall **)(int, int, int))(*(_DWORD *)v9 + 228))(v9, 136, 1);
    }
    v10 = (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)a1 + 632))(a1, "L0NOLIGHTING", 0);
    (*(void (__thiscall **)(int, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)a1 + 40))(a1, 0, v10, 0, 0);
    (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)a1 + 28))(a1, 0, *(_DWORD *)(a1 + 656));
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a1 + 36))(a1, *(_DWORD *)(a1 + 664));
    sub_5F7B60(0, 0);
    sub_5FA770(dword_FB3EBC, 0, 0);
    result = (_DWORD *)(*(int (__stdcall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)(a1 + 9548) + 324))(
                         *(_DWORD *)(a1 + 9548),
                         2,
                         0,
                         3);
    *(_DWORD *)(a1 + 8) = result;
  }
  return result;
}
