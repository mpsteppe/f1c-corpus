int (__stdcall **__stdcall sub_6B52F0(int a1))(int *a1)
{
  int (__stdcall **result)(int *); // eax

  result = (int (__stdcall **)(int *))(**(int (__stdcall ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 28);
  *(_DWORD *)(a1 + 440) = result;
  *result = sub_6B51B0;
  result[1] = (int (__stdcall *)(int *))sub_6B5280;
  result[2] = (int (__stdcall *)(int *))sub_6B5170;
  result[3] = (int (__stdcall *)(int *))sub_6B52D0;
  result[4] = 0;
  result[5] = 0;
  result[6] = (int (__stdcall *)(int *))1;
  return result;
}
