int __usercall sub_6772E0@<eax>(int *a1@<esi>)
{
  int v1; // eax

  if ( a1[5] != 204 )
  {
    (*(void (__stdcall **)(int *))a1[106])(a1);
    a1[35] = 0;
    a1[5] = 204;
  }
  while ( *(_DWORD *)(a1[106] + 8) )
  {
    v1 = *a1;
    *(_DWORD *)(v1 + 20) = 48;
    (*(void (__stdcall **)(int *))v1)(a1);
  }
  a1[5] = (a1[17] != 0) + 205;
  return 1;
}
