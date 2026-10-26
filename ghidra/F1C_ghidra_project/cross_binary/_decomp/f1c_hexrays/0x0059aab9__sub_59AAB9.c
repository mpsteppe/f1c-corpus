// f1c  0x0059aab9  size=276
int __usercall sub_59AAB9@<eax>(int a1@<ebp>)
{
  int v1; // eax
  int v2; // eax
  _DWORD *v3; // edi
  char *v4; // eax
  int v5; // esi

  sub_58A5D8();
  sub_59A54D((void *)(a1 - 16));
  *(_DWORD *)(a1 - 4) = 0;
  if ( !dword_8D4650 )
  {
    v1 = sub_587C03(40);
    *(_DWORD *)(a1 - 20) = v1;
    *(_BYTE *)(a1 - 4) = 1;
    if ( v1 )
      v2 = sub_59ABCD(0);
    else
      v2 = 0;
    *(_BYTE *)(a1 - 4) = 0;
    dword_8D4650 = v2;
    sub_587B3E((int)&loc_59AB83);
    *(_DWORD *)(dword_8D4650 + 16) = 63;
    v3 = (_DWORD *)(dword_8D4650 + 24);
    v4 = sub_58E1B0(dword_5B9D44);
    sub_599615(v3, dword_5B9D44, (unsigned int)v4);
    dword_8D464C = dword_8D4650;
    sub_598C4A((_DWORD *)dword_8D4650);
    if ( &dword_8D4648 )
      dword_8D4648 = dword_8D464C;
  }
  v5 = dword_8D4650;
  *(_DWORD *)(a1 - 4) = -1;
  sub_59A5E9();
  return v5;
}
