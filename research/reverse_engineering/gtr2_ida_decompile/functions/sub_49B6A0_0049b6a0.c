int __thiscall sub_49B6A0(void *this)
{
  char *v3; // eax
  char v4; // [esp+7h] [ebp-221h]
  char v5; // [esp+8h] [ebp-220h]
  _DWORD v6[132]; // [esp+Ch] [ebp-21Ch] BYREF
  int v7; // [esp+224h] [ebp-4h]

  v5 = 0;
  if ( *(_DWORD *)dword_B72314 == 8 )
  {
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 40))(this, 0);
    return 0;
  }
  sub_4744D0(v6);
  v7 = 0;
  if ( !(unsigned __int8)sub_4735A0() || (v4 = 0, (unsigned __int8)sub_473720(&dword_B6CBA8, (int)v6)) )
    v4 = 1;
  if ( (dword_B6FA78 || !(unsigned __int8)sub_551D70(&unk_FADD40) || v4 && v6[0] != 3)
    && (!(unsigned __int8)sub_4735A0() && dword_B6FA78 || *(_DWORD *)(dword_91E084 + 19380) != 3) )
  {
    if ( *(_DWORD *)dword_B640C8 == 6 )
    {
      if ( *(_DWORD *)(dword_91E084 + 14820) || !*(_DWORD *)(dword_91E084 + 19380) )
        goto LABEL_23;
    }
    else if ( *(_DWORD *)dword_B640C8 != 3 && *(_DWORD *)dword_B640C8 != 4
           || *(_DWORD *)(dword_91E084 + 14820)
           || dword_B6FA78
           || *(_DWORD *)(dword_91E084 + 19284) < dword_FADE18 - 1 )
    {
      goto LABEL_23;
    }
  }
  v5 = 1;
LABEL_23:
  if ( (unsigned __int8)sub_4735A0() && (!v4 || v6[0] == 2) )
    v5 = 1;
  if ( (dword_B64134 == 8 || dword_B64134 == 5) && dbl_FB1D18 > flt_FADE20 )
    v5 = 1;
  (*(void (__thiscall **)(void *, char))(*(_DWORD *)this + 36))(this, v5);
  if ( *(_DWORD *)dword_B640C8 == 6 )
    v3 = sub_41D840(&byte_91CC38, "RACE");
  else
    v3 = sub_41D840(&byte_91CC38, "DRIVE");
  sub_615860(v3);
  v7 = -1;
  nullsub_7(v6);
  return 0;
}
