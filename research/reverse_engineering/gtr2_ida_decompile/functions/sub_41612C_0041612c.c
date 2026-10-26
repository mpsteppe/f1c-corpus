void __usercall sub_41612C(int a1@<eax>, int a2@<esi>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(a2 + 4);
  if ( v2 )
    sub_413CB0(v2, *(_DWORD *)(a1 + 44), 1);
  JUMPOUT(0x41615E);
}
