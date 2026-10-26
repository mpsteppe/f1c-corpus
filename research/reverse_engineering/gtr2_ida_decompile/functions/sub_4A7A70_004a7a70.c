int __usercall sub_4A7A70@<eax>(int a1@<ecx>, int a2@<edi>)
{
  const char *v3; // eax
  const char *v4; // edi
  int v5; // eax
  int v6; // esi
  _BYTE v8[61]; // [esp+0h] [ebp-3A0h] BYREF
  __int16 v9; // [esp+3Dh] [ebp-363h]
  char v10; // [esp+3Fh] [ebp-361h]
  _BYTE v11[840]; // [esp+58h] [ebp-348h] BYREF

  if ( !(unsigned __int8)sub_4735A0() )
    return 0;
  v3 = *(const char **)(a1 + 176);
  *(_DWORD *)&v8[8] = a2;
  v4 = v3;
  if ( !v3 )
    v4 = WindowName;
  v5 = strlen(v4);
  v6 = v5;
  if ( v5 > 0 )
  {
    if ( v5 > 159 )
      v6 = 159;
    *(float *)v8 = dbl_FB1D18;
    sub_51B2A0(4, 6, v6, 0, *(_DWORD *)v8, 3);
    sub_630FE0(v11, v4, v6);
    v11[v6] = 0;
    sub_4745E0();
    memset(v8, 0, sizeof(v8));
    v9 = 0;
    v10 = 0;
    sub_501490(v8, 64);
  }
  return 0;
}
