int (__stdcall **__stdcall sub_6B7100(int a1))(int *a1)
{
  int (__stdcall **result)(int *); // eax

  result = (int (__stdcall **)(int *))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 32);
  *(_DWORD *)(a1 + 356) = result;
  *result = sub_6B6E00;
  result[1] = sub_6B6E50;
  result[2] = sub_6B6F50;
  result[3] = sub_6B7020;
  result[4] = sub_6B7040;
  result[5] = (int (__stdcall *)(int *))sub_6B6D30;
  result[6] = (int (__stdcall *)(int *))sub_6B6DC0;
  result[7] = 0;
  return result;
}
