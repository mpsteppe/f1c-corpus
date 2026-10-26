int __usercall sub_48EF70@<eax>(_DWORD *a1@<ecx>, int a2@<edi>)
{
  int v3; // eax
  const CHAR *v4; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edx
  int v8; // edi
  int v9; // edi
  int v10; // edi
  _BYTE v12[8]; // [esp+4h] [ebp-8h] BYREF

  v3 = a1[61];
  a1[67] = &unk_B641B8;
  a1[68] = 0;
  a1[69] = 0;
  a1[70] = 0;
  a1[79] = 0;
  if ( v3 )
  {
    v4 = *(const CHAR **)(v3 + 64);
    if ( !v4 )
      v4 = WindowName;
    sub_4DF1B0(a1[12], v4);
  }
  sub_4E08C0(a1[12], "Ttgjz", v12, a1 + 72, 1, a2);
  v5 = a1[1];
  a1[73] = 5;
  a1[74] = 5;
  v6 = (a1[2] - v5 - 10) / a1[72];
  v7 = *a1;
  v8 = a1[3];
  a1[71] = v6;
  a1[75] = (*(int (__thiscall **)(_DWORD *))(v7 + 4))(a1) - 2 * a1[73] - v8;
  if ( sub_4CD450(3) )
    a1[81] = 20;
  else
    a1[81] = 0;
  v9 = (*(int (__thiscall **)(_DWORD *))(*a1 + 16))(a1) - a1[81];
  v10 = v9 - (*(int (__thiscall **)(_DWORD *))(*a1 + 8))(a1);
  a1[80] = v10;
  if ( v10 < 0 )
    a1[80] = 0;
  return 0;
}
