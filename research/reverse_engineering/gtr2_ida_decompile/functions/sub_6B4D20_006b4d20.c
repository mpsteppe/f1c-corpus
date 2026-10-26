_DWORD *__stdcall sub_6B4D20(int a1)
{
  int (__stdcall **v1)(int *); // eax

  v1 = (int (__stdcall **)(int *))(**(int (__stdcall ***)(int, int, int))(a1 + 4))(a1, 1, 28);
  *(_DWORD *)(a1 + 424) = v1;
  *v1 = sub_6B4BC0;
  v1[1] = sub_6B4CF0;
  v1[2] = 0;
  return sub_6B4A10((int *)a1);
}
