int __stdcall sub_6D6F10(int *a1)
{
  int (__stdcall **v1)(int *); // esi
  int v2; // eax
  int v3; // eax
  int result; // eax

  v1 = (int (__stdcall **)(int *))(*(int (__stdcall **)(int *, int, int))a1[1])(a1, 1, 48);
  v2 = a1[49];
  a1[92] = (int)v1;
  *v1 = sub_6D6180;
  switch ( v2 )
  {
    case 0:
    case 3:
    case 5:
      v1[1] = (int (__stdcall *)(int *))sub_6D6490;
      v1[2] = (int (__stdcall *)(int *))sub_6DEA30;
      break;
    case 1:
    case 4:
    case 6:
      v1[1] = (int (__stdcall *)(int *))sub_6D6490;
      v1[2] = (int (__stdcall *)(int *))sub_6DE7E0;
      break;
    case 2:
      v1[1] = (int (__stdcall *)(int *))sub_6D6920;
      v1[7] = (int (__stdcall *)(int *))sub_6DD790;
      break;
    default:
      v3 = *a1;
      *(_DWORD *)(v3 + 20) = 48;
      (*(void (__stdcall **)(int *))v3)(a1);
      break;
  }
  result = 0;
  v1[3] = 0;
  v1[8] = 0;
  v1[4] = 0;
  v1[9] = 0;
  v1[5] = 0;
  v1[10] = 0;
  v1[6] = 0;
  v1[11] = 0;
  return result;
}
