int __thiscall sub_56DBC0(void *this, int a2, int a3, int a4, int a5)
{
  int v6; // edi
  float v8; // [esp+8h] [ebp-4h] BYREF

  v6 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 88))(this);
  sub_576880(0, 11, 0, 2, -1);
  v8 = sub_575000(this);
  sub_576A80(&v8, 4);
  sub_56ACD0(*(_DWORD *)(v6 + 72), &a2);
  return sub_574CE0(v6);
}
