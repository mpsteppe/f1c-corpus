// positive sp value has been detected, the output may be wrong!
int __usercall sub_47AB35@<eax>(int a1@<eax>, int a2@<edx>, int a3@<ebx>, _DWORD *a4@<esi>)
{
  int v4; // edi
  int v5; // edi
  int v6; // edi

  v4 = a4[3];
  a4[60] = a1;
  a4[64] = (*(int (__thiscall **)(_DWORD *))(a2 + 24))(a4) - 2 * a4[62] - v4;
  if ( ConditionalDelegation_6460(3) )
    a4[70] = 20;
  else
    a4[70] = a3;
  v5 = (*(int (__thiscall **)(_DWORD *))(*a4 + 36))(a4) - a4[70];
  v6 = v5 - (*(int (__thiscall **)(_DWORD *))(*a4 + 28))(a4);
  a4[69] = v6;
  if ( v6 < 0 )
    a4[69] = a3;
  return 0;
}

