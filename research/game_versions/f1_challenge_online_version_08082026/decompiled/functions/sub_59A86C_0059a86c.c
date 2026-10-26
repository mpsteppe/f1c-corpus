void __usercall sub_59A86C(int a1@<ebp>)
{
  _DWORD *v1; // ecx
  _DWORD *v2; // esi
  int v3; // eax

  sub_58A5D8();
  v2 = v1;
  *(_DWORD *)(a1 - 16) = v1;
  *v1 = &off_5B9D3C;
  v3 = v1[9];
  *(_DWORD *)(a1 - 4) = 0;
  if ( !v3 || (--byte_8D463C[v3], byte_8D463C[v1[9]] <= 0) )
    sub_59A980(v1);
  sub_598C70(v2 + 8);
}
