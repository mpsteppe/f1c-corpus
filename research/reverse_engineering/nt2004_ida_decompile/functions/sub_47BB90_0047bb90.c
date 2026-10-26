int __thiscall sub_47BB90(void *this)
{
  char v3; // [esp+8h] [ebp-8h]
  char v4; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v4 = 1;
  if ( (unsigned __int8)sub_4FB240(&unk_7D7428)
    || dword_75CBB0 == 5 && !*(_DWORD *)(dword_75AACC + 16584) && *(int *)(dword_75AACC + 20848) > 0 )
  {
    v3 = 1;
    v4 = 0;
  }
  if ( sub_42DBC0() && *(_DWORD *)(dword_75AACC + 20892) )
  {
    v3 = 1;
    v4 = 0;
  }
  if ( (dword_75CBB4 == 8 || dword_75CBB4 == 5) && flt_7D74C0 < dbl_7DA9D0 )
  {
    v3 = 1;
    v4 = 0;
  }
  if ( sub_463490(dword_764D70) && !sub_465320(dword_764D70) )
  {
    v3 = 1;
    v4 = 0;
  }
  (*(void (__thiscall **)(void *, char))(*(_DWORD *)this + 36))(this, v3);
  (*(void (__thiscall **)(void *, char))(*(_DWORD *)this + 40))(this, v4);
  return 0;
}
