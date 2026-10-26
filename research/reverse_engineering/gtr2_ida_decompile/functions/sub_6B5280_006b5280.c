int __stdcall sub_6B5280(int a1)
{
  int (__stdcall **v1)(int *); // eax
  int result; // eax

  v1 = *(int (__stdcall ***)(int *))(a1 + 440);
  *v1 = sub_6B51B0;
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = (int (__stdcall *)(int *))1;
  (*(void (__stdcall **)(int))(*(_DWORD *)a1 + 16))(a1);
  result = (**(int (__stdcall ***)(int))(a1 + 444))(a1);
  *(_DWORD *)(a1 + 164) = 0;
  return result;
}
