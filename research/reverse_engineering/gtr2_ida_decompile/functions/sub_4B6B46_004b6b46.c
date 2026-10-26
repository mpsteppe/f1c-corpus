// positive sp value has been detected, the output may be wrong!
int __usercall sub_4B6B46@<eax>(int a1@<esi>)
{
  int v1; // eax
  float v3; // [esp-Ch] [ebp-Ch]

  if ( v3 <= 0.125 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 64))(a1);
  v1 = *(_DWORD *)(a1 + 280) - 1;
  *(_DWORD *)(a1 + 280) = v1;
  *(float *)(a1 + 308) = v3 - 0.125;
  if ( v1 < 0 )
    *(_DWORD *)(a1 + 280) = 0;
  sub_4A20B0();
  return (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 64))(a1);
}
