int __usercall sub_5BD3E8@<eax>(char a1@<ah>, int a2@<ecx>, char a3@<bl>, int a4@<esi>)
{
  bool v4; // cf

  v4 = __CFADD__(a1, *(_BYTE *)(a4 - 119));
  *(_BYTE *)(a4 - 119) += a1;
  *(_BYTE *)(a4 - 62) += a3 + v4;
  return sub_5BD3F0(a2);
}
