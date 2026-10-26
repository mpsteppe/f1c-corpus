int __thiscall sub_49BD20(void *this)
{
  char v2; // al
  int v3; // ecx
  char v5; // [esp+4h] [ebp-4h]

  v2 = sub_53A7E0(0, 0, 0, 0);
  LOBYTE(v3) = *(_DWORD *)dword_B72314 != 4;
  v5 = v2;
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 40))(this, v3);
  (*(void (__thiscall **)(void *, char))(*(_DWORD *)this + 36))(this, v5);
  return 0;
}
