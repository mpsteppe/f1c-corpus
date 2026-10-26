void __usercall sub_540C90(_BYTE *a1@<ecx>, float a2@<ebx>)
{
  char v3; // al
  int v4; // ecx
  char v5; // bl
  int v6; // edi
  int i; // esi
  int v8; // edi
  int v9; // esi
  _BYTE *v10; // [esp-2h] [ebp-30h]
  float v11; // [esp+Ah] [ebp-24h] BYREF
  float v12; // [esp+Eh] [ebp-20h]
  char v13; // [esp+15h] [ebp-19h]
  _BYTE v14[12]; // [esp+16h] [ebp-18h] BYREF
  _BYTE v15[12]; // [esp+22h] [ebp-Ch] BYREF

  if ( sub_473630(&dword_B6CBA8) )
    return;
  if ( dword_BE1204 != 2 || sub_5210D0(&dword_BE120C) == 5 )
  {
    v13 = 0;
    v3 = 0;
  }
  else
  {
    v3 = 1;
    v13 = 1;
  }
  v11 = a2;
  v4 = dword_BE1D0C;
  v5 = 1;
  if ( byte_B6F118 && (byte_B708E8 || a1[28] ? (v5 = 1) : (v5 = 0), dword_BE1D0C) )
  {
    if ( v3 )
      goto LABEL_24;
    if ( !a1[28] )
    {
      v10 = v14;
      if ( (unsigned __int8)sub_42C980() )
        sub_54FDF0(&unk_FADD40, dword_91E084, v15, v14);
      else
        sub_401470();
      v12 = 3.1415927 - v12;
      (*(void (__thiscall **)(int, _BYTE *, float *))(*(_DWORD *)dword_BE1D0C + 28))(dword_BE1D0C, v14, &v11);
      v4 = dword_BE1D0C;
    }
  }
  else if ( v3 )
  {
    goto LABEL_24;
  }
  if ( byte_B6413C || !v5 )
  {
    v6 = dword_757C10;
    for ( i = 0; i < v6; ++i )
      sub_58C720(*(&dword_91E088 + i) + 24);
    goto LABEL_30;
  }
LABEL_24:
  v8 = dword_757C10;
  v9 = 0;
  if ( dword_757C10 > 0 )
  {
    do
      sub_58E910(*(&dword_91E088 + v9++) + 24);
    while ( v9 < v8 );
    v4 = dword_BE1D0C;
  }
  if ( v4 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(v4);
  sub_5E5B30(32, 1);
  sub_540640((int)&dword_BE1D20);
  if ( HIBYTE(v10) )
    goto LABEL_34;
LABEL_30:
  if ( !byte_B6413C )
  {
    if ( byte_B6F118 )
    {
LABEL_35:
      sub_540B20();
      return;
    }
    sub_4EF5B0((float *)dword_B6F1C8);
    sub_540850(a1, -1.0);
  }
  if ( byte_B6F118 )
    goto LABEL_35;
LABEL_34:
  if ( dword_B64134 == 2 )
    goto LABEL_35;
  if ( byte_B6F118 || !(*(int (__thiscall **)(int))(*(_DWORD *)dword_BE1D14 + 8))(dword_BE1D14) )
  {
    if ( dword_BE1D14 )
      (*(void (__thiscall **)(int))(*(_DWORD *)dword_BE1D14 + 12))(dword_BE1D14);
  }
}
