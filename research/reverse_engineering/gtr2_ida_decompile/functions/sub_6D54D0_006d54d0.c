int (__stdcall **__stdcall sub_6D54D0(int a1))(int a1, int a2)
{
  int (__stdcall **result)(int, int); // eax

  result = (int (__stdcall **)(int, int))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 108);
  *result = sub_6D5360;
  *(_DWORD *)(a1 + 372) = result;
  result[15] = 0;
  result[11] = 0;
  result[23] = 0;
  result[19] = 0;
  result[16] = 0;
  result[12] = 0;
  result[24] = 0;
  result[20] = 0;
  result[17] = 0;
  result[13] = 0;
  result[25] = 0;
  result[21] = 0;
  result[18] = 0;
  result[14] = 0;
  result[26] = 0;
  result[22] = 0;
  return result;
}
