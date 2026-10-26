int __thiscall sub_617260(int this, int a2, int a3)
{
  int v5; // eax

  if ( !*(_BYTE *)(this + 92) )
    return sub_613C90((_DWORD *)this, a2, a3);
  v5 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)(this + 96) + 20))(this + 96, a2, a3);
  return sub_613C90((_DWORD *)this, v5, a3);
}
