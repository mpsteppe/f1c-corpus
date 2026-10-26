int __thiscall sub_4AB040(void *this)
{
  int v1; // edx

  v1 = *(_DWORD *)dword_B72314;
  LOBYTE(v1) = *(_DWORD *)dword_B72314 == 7;
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 40))(this, v1);
  return 0;
}
