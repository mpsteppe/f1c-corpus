int __stdcall sub_6792D0(int *Parameter, int a2, int a3)
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
  if ( a3 != 384 )
  {
    v5 = *Parameter;
    *(_DWORD *)(v5 + 20) = 21;
    *(_DWORD *)(v5 + 24) = 384;
    *(_DWORD *)(v5 + 28) = a3;
    (*(void (__stdcall **)(int *))v5)(Parameter);
  }
  v6 = *Parameter;
  Parametera = Parameter[3];
  memset(Parameter, 0, 0x180u);
  *Parameter = v6;
  Parameter[3] = Parametera;
  Parameter[4] = 0;
  result = sub_6B5E20((ULONG_PTR)Parameter);
  Parameter[2] = 0;
  Parameter[6] = 0;
  Parameter[17] = 0;
  Parameter[18] = 0;
  Parameter[19] = 0;
  Parameter[20] = 0;
  Parameter[21] = 0;
  Parameter[22] = 0;
  Parameter[26] = 0;
  Parameter[23] = 0;
  Parameter[27] = 0;
  Parameter[24] = 0;
  Parameter[28] = 0;
  Parameter[25] = 0;
  Parameter[29] = 0;
  *((double *)Parameter + 6) = 1.0;
  Parameter[94] = 0;
  Parameter[5] = 100;
  return result;
}
