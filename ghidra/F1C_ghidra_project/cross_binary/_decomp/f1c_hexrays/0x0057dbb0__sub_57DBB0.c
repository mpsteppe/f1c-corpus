// f1c  0x0057dbb0  size=81
int __thiscall sub_57DBB0(void *this, int a2, int a3, int a4, int a5)
{
  int v6; // edi
  float v8; // [esp+8h] [ebp-4h] BYREF

  v6 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 88))(this);
  sub_586800(0, 11, 0, 2, -1);
  v8 = sub_584F90(this);
  sub_586A00(&v8, 4);
  sub_57AFA0(*(_DWORD *)(v6 + 72), &a2);
  return sub_584C70(v6);
}
