int (__stdcall **__stdcall sub_6CFE20(int a1))(int *a1)
{
  int (__stdcall **result)(int *); // eax

  result = (int (__stdcall **)(int *))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 232);
  *result = sub_6CFCC0;
  result[1] = (int (__stdcall *)(int *))sub_6CF8F0;
  *(_DWORD *)(a1 + 448) = result;
  result[14] = 0;
  result[10] = 0;
  result[15] = 0;
  result[11] = 0;
  result[16] = 0;
  result[12] = 0;
  result[17] = 0;
  result[13] = 0;
  return result;
}
