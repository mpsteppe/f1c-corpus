int __usercall sub_4D8400@<eax>(_DWORD *a1@<ecx>, __int32 a2@<ebx>)
{
  int *v3; // edi
  int v5; // [esp+0h] [ebp-18h]

  *a1 = &off_711C78;
  v3 = a1 + 210;
  sub_4D5D40(a1 + 210);
  sub_4D5D40(v3);
  *a1 = &off_711BC8;
  return sub_4D82A0(a2, v5);
}
