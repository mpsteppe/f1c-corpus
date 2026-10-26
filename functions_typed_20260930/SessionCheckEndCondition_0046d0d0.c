int __thiscall sub_46D0D0(void *this)
{
  bool v2; // bl
  int v3; // eax
  char v5; // [esp+8h] [ebp-4h]

  v5 = 0;
  v2 = dword_7D0410 == 3 || dword_7D0410 == 4;
  if ( !dword_7CE814 && (unsigned __int8)sub_4D24A0(&dword_8ACEE0)
    || (!dword_7C56A4 || v2) && *(_DWORD *)(dword_7C54E8 + 16484) == 3 )
  {
    goto LABEL_18;
  }
  if ( dword_7C56A4 == 7 )
  {
    if ( !*(_DWORD *)(dword_7C54E8 + 13000) && *(_DWORD *)(dword_7C54E8 + 16484) )
LABEL_18:
      v5 = 1;
  }
  else if ( dword_7C56A4 == 5
         && !*(_DWORD *)(dword_7C54E8 + 13000)
         && !dword_7CE814
         && *(_DWORD *)(dword_7C54E8 + 16444) >= dword_8ACF8C - 1 )
  {
    goto LABEL_18;
  }
  if ( SessionStateCheckWrapper(dword_7CD25C) )
  {
    v3 = 0;
    if ( dword_5C329C <= 0 )
    {
LABEL_23:
      v5 = 1;
    }
    else
    {
      while ( *(_DWORD *)(dword_7C54F0[v3] + 13000) )
      {
        if ( ++v3 >= dword_5C329C )
          goto LABEL_23;
      }
    }
  }
  if ( (dword_7C56A8 == 8 || dword_7C56A8 == 5) && flt_8ACF94 < dbl_8AFEA0 )
    v5 = 1;
  (*(void (__thiscall **)(void *, char))(*(_DWORD *)this + 56))(this, v5);
  return 0;
}

