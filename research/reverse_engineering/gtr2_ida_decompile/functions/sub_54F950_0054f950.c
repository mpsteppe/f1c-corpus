int __usercall sub_54F950@<eax>(int a1@<ecx>, int a2@<esi>)
{
  _DWORD *v3; // esi
  _DWORD *v4; // ecx
  int v7; // [esp+4h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h] BYREF

  sub_5DA960(&v8, 2048);
  sub_5DA960(&v9, 2048);
  if ( v8 >= 104 )
    goto LABEL_13;
  v3 = (_DWORD *)((char *)&unk_9204A0 + 22616 * v8);
  if ( v9 != -11 )
  {
    sub_427C40((int)v3, 5, 0);
    sub_4FC460(v3 + 3706);
    if ( sub_53F260(v3) )
      sub_413EA0();
    goto LABEL_13;
  }
  sub_427C40((int)v3, 4, 0);
  sub_4FC3A0();
  if ( sub_53F260(v3) && !(unsigned __int8)sub_5785A0(dword_91E07C + 16, a2) )
    sub_4EE320(13, 0);
  if ( fabs(dbl_FB1D18 - *(float *)&dword_BE1D20) <= 3.0 )
  {
LABEL_13:
    sub_5ED990(*(_DWORD *)(a1 + 20));
    return 0;
  }
  if ( dword_82F4A0 >= 1023 )
  {
    v4 = (_DWORD *)off_9034A4;
  }
  else
  {
    ++dword_82F4A0;
    v4 = (_DWORD *)off_9034A4;
    off_9034A4 += 848;
  }
  *(float *)&v7 = dbl_FB1D18;
  sub_51B2A0(v4, 3, 2, 0, v3[5617], v7, 0);
  *(float *)&dword_BE1D20 = dbl_FB1D18;
  sub_5ED990(*(_DWORD *)(a1 + 20));
  return 0;
}
