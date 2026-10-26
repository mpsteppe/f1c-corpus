int __usercall sub_50B830@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi

  sub_58A5D8();
  v2 = v1;
  *(_DWORD *)(a1 - 16) = v1;
  *v1 = &off_5ADBB8;
  *(_DWORD *)(a1 - 4) = 0;
  sub_50A92D(v1);
  if ( v2[1051] )
    sub_587BCF((LPVOID)v2[1051]);
  *(_DWORD *)(a1 - 4) = -1;
  return sub_506CCC(v2);
}
