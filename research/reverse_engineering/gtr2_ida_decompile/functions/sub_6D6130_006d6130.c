int (__stdcall **__stdcall sub_6D6130(int a1))(int a1, int a2)
{
  int (__stdcall **result)(int, int); // eax

  result = (int (__stdcall **)(int, int))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 108);
  *result = sub_6D5FB0;
  *(_DWORD *)(a1 + 372) = result;
  result[19] = 0;
  result[23] = 0;
  result[20] = 0;
  result[24] = 0;
  result[21] = 0;
  result[25] = 0;
  result[22] = 0;
  result[26] = 0;
  result[16] = 0;
  return result;
}
