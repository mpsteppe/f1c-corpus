// f1c  0x0053d470  size=77
int __fastcall sub_53D470(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  _DWORD *v7; // eax
  _DWORD *v8; // eax

  v7 = (_DWORD *)sub_587C03(48);
  if ( v7 )
    v8 = sub_53C2C0(v7);
  else
    v8 = 0;
  *a1 = v8;
  if ( v8 )
    return -(sub_53C360(v8, a2, a3, a4, a5) != 0);
  else
    return -1;
}
