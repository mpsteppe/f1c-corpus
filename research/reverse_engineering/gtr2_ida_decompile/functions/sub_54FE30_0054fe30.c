char __thiscall sub_54FE30(int this, _DWORD *a2, int a3, int a4)
{
  bool v5; // bl
  bool v6; // zf
  int v7; // eax
  char v9; // al
  bool v11; // al
  bool v12; // bl
  char v13; // al
  char v14; // [esp+9h] [ebp-3h]
  char v15; // [esp+Ah] [ebp-2h]
  bool v16; // [esp+Bh] [ebp-1h]
  char v17; // [esp+10h] [ebp+4h]

  v5 = *(float *)(this + 220) + 2.0 < dbl_FB1D18;
  if ( *(_DWORD *)dword_B640C8 != 6 )
  {
    v7 = dword_B64134;
    goto LABEL_11;
  }
  v6 = sub_42FE50(&dword_B640C0) == 0;
  v7 = dword_B64134;
  if ( v6 )
  {
LABEL_11:
    v14 = 0;
    goto LABEL_12;
  }
  if ( dword_B64134 )
  {
    if ( dword_B64134 != 2 && (dword_B64134 != 3 || v5) )
      goto LABEL_11;
  }
  else if ( dword_B70030 )
  {
    goto LABEL_11;
  }
  v14 = 1;
LABEL_12:
  v16 = *(_DWORD *)dword_B640C8 == 6 && (!v7 || v7 == 2);
  if ( a2[5646] )
  {
    if ( (dword_B640C4 & 1) != 0 )
    {
      if ( *(_DWORD *)dword_B640C8 != 6 || v7 != 3 || *(_DWORD *)(this + 240) == 2139095039 )
        goto LABEL_21;
    }
    else if ( *(_DWORD *)dword_B640C8 != 6 || v7 != 3 )
    {
LABEL_21:
      v9 = 0;
LABEL_22:
      if ( !v14 || v9 )
      {
        if ( (int)a2[5637] < 0 )
          sub_53E8B0();
        sub_401410();
        return 0;
      }
LABEL_59:
      sub_4035C0();
      return 1;
    }
    v9 = 1;
    goto LABEL_22;
  }
  if ( !byte_B6F118 || (v11 = sub_53F260(a2), v17 = 1, !v11) )
    v17 = 0;
  if ( (unsigned __int8)sub_4735A0() && v17 )
  {
    sub_54FDF0((void *)this, (int)a2, a3, a4);
    return 0;
  }
  if ( *(_DWORD *)dword_B640C8 != 6 || dword_B64134 != 4 || (v15 = 1, sub_42FE50(&dword_B640C0)) )
    v15 = 0;
  v12 = a2[3705] != 4 && *(_DWORD *)dword_B72314 == 7 && byte_B731C8;
  v13 = sub_4275E0();
  if ( !v17 && (v14 || v15 || v12) || v13 || v16 )
    goto LABEL_59;
  if ( (unsigned __int8)sub_4735A0() && *(_DWORD *)dword_B640C8 == 6 && !byte_B6F118 )
  {
    sub_54FDB0((void *)this, (int)a2, a3, a4);
    if ( sub_53F260(a2) )
    {
      sub_4495B0();
      return 0;
    }
  }
  else
  {
    sub_54FDF0((void *)this, (int)a2, a3, a4);
  }
  return 0;
}
