int __userpurge sub_59A5FE@<eax>(int a1@<ebp>, int a2, int a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // ecx
  char *v6; // esi
  char *v7; // eax

  sub_58A5D8();
  result = *(_DWORD *)(a1 + 8) & 7;
  *(_DWORD *)(v4 + 4) = result;
  v5 = result & *(_DWORD *)(v4 + 8);
  if ( v5 )
  {
    if ( *(_BYTE *)(a1 + 12) )
      sub_59BFC3(0, 0);
    if ( (v5 & 4) != 0 )
    {
      v6 = "ios::badbit set";
    }
    else
    {
      v6 = "ios::failbit set";
      if ( (v5 & 2) == 0 )
        v6 = "ios::eofbit set";
    }
    *(_BYTE *)(a1 - 28) = *(_BYTE *)(a1 + 15);
    sub_5993AF((_DWORD *)(a1 - 28), 0);
    v7 = sub_58E1B0(v6);
    sub_599615((_DWORD *)(a1 - 28), v6, (unsigned int)v7);
    *(_DWORD *)(a1 - 4) = 0;
    sub_59A69A(a1 - 28);
    *(_DWORD *)(a1 - 56) = &std::ios_base::failure::`vftable';
    return sub_59BFC3(a1 - 56, &_TI3_AVfailure_ios_base_std__);
  }
  return result;
}
