ULONG_PTR __stdcall sub_6B5E20(int *Parameter)
{
  int (__stdcall **v2)(int *, unsigned int, unsigned int); // esi
  int v3; // eax
  ULONG_PTR result; // eax
  ULONG_PTR Parametera; // [esp+14h] [ebp+8h]

  Parameter[1] = 0;
  Parametera = sub_6D3CB0(Parameter);
  v2 = (int (__stdcall **)(int *, unsigned int, unsigned int))sub_6D3B00(Parameter, 84);
  if ( !v2 )
  {
    pfnAPC((ULONG_PTR)Parameter);
    v3 = *Parameter;
    *(_DWORD *)(v3 + 20) = 54;
    *(_DWORD *)(v3 + 24) = 0;
    (*(void (__stdcall **)(int *))v3)(Parameter);
  }
  result = Parametera;
  *v2 = sub_6B5340;
  v2[1] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5480;
  v2[2] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5530;
  v2[3] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B55E0;
  v2[4] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5690;
  v2[5] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5700;
  v2[6] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5770;
  v2[7] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5A60;
  v2[8] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5BA0;
  v2[9] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5CE0;
  v2[10] = (int (__stdcall *)(int *, unsigned int, unsigned int))sub_6B5DE0;
  v2[12] = (int (__stdcall *)(int *, unsigned int, unsigned int))1000000000;
  v2[11] = (int (__stdcall *)(int *, unsigned int, unsigned int))Parametera;
  v2[14] = 0;
  v2[16] = 0;
  v2[13] = 0;
  v2[15] = 0;
  Parameter[1] = (int)v2;
  v2[17] = 0;
  v2[18] = 0;
  v2[19] = (int (__stdcall *)(int *, unsigned int, unsigned int))84;
  return result;
}
