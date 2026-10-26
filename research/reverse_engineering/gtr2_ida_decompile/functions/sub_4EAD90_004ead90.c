int __usercall sub_4EAD90@<eax>(int a1@<ebx>, int a2@<esi>)
{
  char v2; // al
  bool v3; // bl
  int v4; // eax
  int i; // esi
  int v6; // ecx
  char v7; // al
  int v8; // ecx
  int v9; // ecx
  char v10; // al
  int v11; // ecx
  int v12; // esi
  _BYTE *v13; // eax
  int v14; // eax
  _BYTE v16[4]; // [esp+0h] [ebp-6Ch] BYREF
  int v17; // [esp+4h] [ebp-68h]
  int v18[4]; // [esp+8h] [ebp-64h] BYREF
  int v19; // [esp+18h] [ebp-54h]
  int v20; // [esp+1Ch] [ebp-50h]
  int v21; // [esp+20h] [ebp-4Ch]
  int v22; // [esp+24h] [ebp-48h]

  sub_45DDE0();
  sub_475BF0(&dword_B6CBA8);
  v22 = 0;
  sub_4304C0();
  if ( *(_DWORD *)dword_B640C8 == 6 && *(_DWORD *)dword_B72314 != 6 )
  {
    v21 = a1;
    v2 = sub_551A90();
    v3 = *(_DWORD *)dword_B72314 == 5;
    if ( v2 )
    {
      if ( *(_DWORD *)(dword_91E084 + 14820) <= 1u )
        sub_52BF50(1);
      if ( !v3 )
      {
        v4 = byte_B722E4
           ? (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 22, v21, v22)
           : (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 21, v21, v22);
        if ( v4 )
        {
          sub_4AE810(v4, 0);
          sub_573540(dword_91E084 + 16);
        }
      }
      v19 = 0;
      if ( byte_B722E4 )
        sub_4E1810((_DWORD *)dword_B6E090, (int)"ENDURANCE POST RACE MONITOR", v19);
      else
        sub_4E1810((_DWORD *)dword_B6E090, (int)"POST RACE MONITOR", v19);
    }
    else if ( *(_DWORD *)dword_B72314 != 5 && !dword_B70030 )
    {
      v20 = 1;
      byte_B6F121 = 1;
      sub_4304C0();
      sub_540130(&unk_BE1D30);
    }
  }
  sub_557150(&dword_903A10);
  sub_55EDA0(&dword_903A10);
  if ( byte_B6F118 != 1 )
  {
    byte_B6F118 = 1;
    dword_B6F114 = 0;
  }
  if ( (_BYTE)dword_757C1C )
  {
    sub_573540(dword_91E084 + 16);
    sub_53E6F0(0.0);
    *(_DWORD *)(dword_91E084 + 19428) = 0;
  }
  sub_5400F0(&unk_BE1D30, a2);
  sub_4EDFE0(dword_B6F1C8);
  sub_5403D0(&dword_BE1D20);
  for ( i = 0; i < dword_757C10; ++i )
  {
    v6 = *(&dword_91E088 + i);
    v7 = *(_BYTE *)(v6 + 276);
    v8 = v6 + 24;
    if ( v7 )
      sub_58CD40(v8, 0);
    v9 = *(&dword_91E088 + i);
    v10 = *(_BYTE *)(v9 + 2864);
    v11 = v9 + 2704;
    if ( !v10 )
      sub_56FD00(v11);
  }
  sub_413E70();
  sub_413DC0((int)&dword_91BF20);
  sub_414450(&dword_91BF20, *(_DWORD *)(*(&dword_91E088 + dword_91E080) + 22468));
  if ( (byte_B722CC || byte_B722FC) && dword_91BF40 )
  {
    v18[3] = 0;
    sub_4124A0();
  }
  sub_40E040((int)&flt_757718, 0.0);
  sub_410C90((int)&dword_91BF20, 0);
  sub_562430(&dword_FAE988, -1, 0);
  sub_4E5FC0(&dword_B6E4D0, 0);
  if ( byte_B722CC == 1 )
  {
    if ( byte_B70900 != 1 )
      goto LABEL_38;
LABEL_37:
    sub_5400B0(&unk_BE1D30);
    sub_540850(-1.0);
    goto LABEL_38;
  }
  if ( !byte_B722CC && byte_B70918 == 1 )
    goto LABEL_37;
LABEL_38:
  sub_408A50(dword_91BE2C);
  if ( *(_DWORD *)dword_B72314 == 8 )
  {
    sub_540150(&unk_BE1D30);
    if ( byte_91E048 == 2 )
    {
      v12 = byte_91E050;
      v18[1] = dword_91E054;
      v17 = byte_91E050;
      sub_41EBB0();
      sub_41DF60(dword_B761EC, v12, *(float *)v18, 0);
      sub_41DC90((int)dword_B761EC);
      v13 = (_BYTE *)(*(int (__thiscall **)(int, int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 57, v17);
      if ( v13 )
        sub_497E00(v13);
      sub_41E1E0();
      sub_4E1810((_DWORD *)dword_B6E090, (int)v16, 0);
      v14 = (*(int (__thiscall **)(int, int, int *, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 58, v18, 63);
      if ( v14 )
        *(_BYTE *)(v14 + 597) = 1;
    }
    sub_42A720();
  }
  return 0;
}
