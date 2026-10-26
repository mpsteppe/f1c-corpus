int __stdcall sub_6774C0(int *Parameter, int a2, int a3)
{
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int result; // eax
  ULONG_PTR Parametera; // [esp+14h] [ebp+8h]

  Parameter[1] = 0;
  if ( a2 != 62 )
  {
    v4 = *Parameter;
    *(_DWORD *)(v4 + 20) = 12;
    *(_DWORD *)(v4 + 24) = 62;
    *(_DWORD *)(v4 + 28) = a2;
    (*(void (__stdcall **)(int *))v4)(Parameter);
  }
  if ( a3 != 472 )
  {
    v5 = *Parameter;
    *(_DWORD *)(v5 + 20) = 21;
    *(_DWORD *)(v5 + 24) = 472;
    *(_DWORD *)(v5 + 28) = a3;
    (*(void (__stdcall **)(int *))v5)(Parameter);
  }
  v6 = *Parameter;
  Parametera = Parameter[3];
  memset(Parameter, 0, 0x1D8u);
  *Parameter = v6;
  Parameter[3] = Parametera;
  Parameter[4] = 1;
  sub_6B5E20((ULONG_PTR)Parameter);
  Parameter[2] = 0;
  Parameter[6] = 0;
  Parameter[42] = 0;
  Parameter[43] = 0;
  Parameter[44] = 0;
  Parameter[45] = 0;
  Parameter[46] = 0;
  Parameter[50] = 0;
  Parameter[47] = 0;
  Parameter[51] = 0;
  Parameter[48] = 0;
  Parameter[52] = 0;
  Parameter[49] = 0;
  Parameter[53] = 0;
  Parameter[77] = 0;
  sub_679080(Parameter);
  result = sub_6B52F0(Parameter);
  Parameter[5] = 200;
  return result;
}
