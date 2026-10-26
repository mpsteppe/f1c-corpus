int __thiscall sub_4A73E0(int *this)
{
  bool v3; // [esp+4h] [ebp-4h]

  v3 = byte_B6F118 != 0;
  if ( this[69] == 766 && *(_DWORD *)dword_B72314 == 4 )
    v3 = 1;
  (*(void (__thiscall **)(int *, bool))(*this + 36))(this, v3);
  return sub_4A7340(this);
}
