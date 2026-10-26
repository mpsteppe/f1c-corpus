int __thiscall sub_4B7410(int this)
{
  int v1; // eax

  if ( *(_DWORD *)(this + 276) == 676
    && (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 60) )
  {
    sub_4915F0();
    v1 = dword_B7231C;
    *(_DWORD *)dword_B72314 = 3;
    if ( dword_B7231C > 3 || (v1 = dword_B72320, dword_B72320 < 3) )
      *(_DWORD *)dword_B72314 = v1;
    sub_4E1810("MAIN MENU", 0);
  }
  return 0;
}
