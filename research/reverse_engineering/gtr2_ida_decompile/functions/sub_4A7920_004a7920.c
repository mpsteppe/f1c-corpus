int __usercall sub_4A7920@<eax>(int a1@<ecx>, int a2@<esi>)
{
  int v3; // ecx
  const char *v5; // eax
  int v6; // kr04_4
  int v7; // esi
  char *v8; // eax
  float v9; // [esp+0h] [ebp-4A8h]
  _BYTE v10[61]; // [esp+8h] [ebp-4A0h] BYREF
  __int16 v11; // [esp+45h] [ebp-463h]
  char v12; // [esp+47h] [ebp-461h]
  char Buffer[256]; // [esp+58h] [ebp-450h] BYREF
  _BYTE v14[840]; // [esp+160h] [ebp-348h] BYREF

  if ( (unsigned __int8)sub_4735A0() )
  {
    v3 = *(_DWORD *)(a1 + 276);
    if ( v3 == -1 )
    {
      *(_DWORD *)&v10[4] = 0;
      sub_41D840(&byte_91CC38, "Please Select Player");
      return off_16C9214();
    }
    *(_DWORD *)&v10[12] = a1 + 168;
    v5 = *(const char **)(a1 + 176);
    if ( !v5 )
      v5 = WindowName;
    sprintf(Buffer, "%s%d", v5, v3);
    v6 = strlen(Buffer);
    *(_DWORD *)&v10[4] = a2;
    v7 = v6;
    if ( v6 > 0 )
    {
      if ( v6 > 159 )
        v7 = 159;
      v9 = dbl_FB1D18;
      sub_51B2A0(4, 6, v7, 0, LODWORD(v9), 3);
      sub_630FE0(v14, Buffer, v7);
      v14[v7] = 0;
      sub_4745E0();
      memset(v10, 0, sizeof(v10));
      v11 = 0;
      v12 = 0;
      sub_501490(v10, 64);
    }
    *(_DWORD *)(a1 + 276) = -1;
    v8 = sub_41D840(&byte_91CC38, "select player");
    sub_615860(v8);
  }
  return 0;
}
