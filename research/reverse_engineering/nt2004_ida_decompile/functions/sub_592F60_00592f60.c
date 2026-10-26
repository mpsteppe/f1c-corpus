int __fastcall sub_592F60(_DWORD *a1, int a2, int a3, int a4, char a5)
{
  _DWORD *v7; // eax
  _DWORD *v8; // eax

  v7 = operator new(0x30u);
  if ( v7 )
    v8 = sub_5918D0(v7);
  else
    v8 = 0;
  *a1 = v8;
  if ( v8 )
    return -(sub_591970(v8, a2, a3, a4, a5) != 0);
  else
    return -1;
}
