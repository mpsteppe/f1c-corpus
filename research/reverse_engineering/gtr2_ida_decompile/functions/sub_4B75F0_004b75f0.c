int __usercall sub_4B75F0@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<esi>)
{
  int v4; // eax
  int v5; // esi
  char v6; // bl
  int v7; // eax
  const CHAR *v8; // eax
  int v10; // [esp-8h] [ebp-420h]
  int v11; // [esp+0h] [ebp-418h] BYREF
  int v12; // [esp+4h] [ebp-414h]
  char v13[4]; // [esp+8h] [ebp-410h] BYREF
  int v14; // [esp+Ch] [ebp-40Ch] BYREF
  char v15[1028]; // [esp+14h] [ebp-404h] BYREF

  sub_4DE540(&v14, v15);
  v4 = (*(int (__thiscall **)(_DWORD *))(*a1 + 4))(a1);
  if ( v14 < v4 && v14 > sub_4CFCC0(4) )
  {
    v12 = a2;
    v11 = a3;
    v5 = a1[105];
    LOBYTE(v14) = (unsigned __int8)sub_53A120() == 0;
    v10 = v14;
    sub_53B1C0(&unk_BE1CFC);
    v6 = sub_53A120();
    v7 = sub_4D2DB0(a1, v5, v5, v10, v5, v11, v12);
    if ( v7 )
      *(_BYTE *)(v7 + 64) = v6;
    sub_53B0D0(&unk_BE1CFC, v13, 1023);
    sub_53BDE0(&unk_BE1CE0, &v11);
    sub_4D7D70(a1);
    v8 = dword_B7235C;
    if ( !dword_B7235C )
      v8 = WindowName;
    sub_5100A0(&byte_B6F530, v8);
    sub_4B5120();
  }
  return 0;
}
