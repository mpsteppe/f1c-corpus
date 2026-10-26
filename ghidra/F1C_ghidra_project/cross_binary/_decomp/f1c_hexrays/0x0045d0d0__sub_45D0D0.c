// f1c  0x0045d0d0  size=88
unsigned int __thiscall sub_45D0D0(char *this, int a2)
{
  unsigned int v3; // kr04_4
  char v5[16]; // [esp+8h] [ebp-10h] BYREF

  v5[0] = 0;
  v3 = strlen((const char *)sub_463750(0)) + 1;
  sub_58815F(v5, "%d", v3 != 1);
  return sub_45CE30(aPassword_0, v5, this);
}
