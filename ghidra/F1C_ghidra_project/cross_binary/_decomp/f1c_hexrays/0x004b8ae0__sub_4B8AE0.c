// f1c  0x004b8ae0  size=228
char __thiscall sub_4B8AE0(float *this, float *a2)
{
  char v3; // bl

  v3 = 1;
  if ( this[973] - this[972] <= 0.0 )
    return 0;
  sub_4B8C40(*a2, 0);
  sub_4BA180(&dword_8AB6E4);
  sub_4CFCC0(&unk_8ACEA0);
  sub_404460((int)dword_5EA2C0);
  sub_4D4580(&unk_8ACEE0);
  sub_455E50((float *)&ppvOut);
  sub_42C690(&unk_5EC6D0);
  sub_40CA30((int)&dword_5EA510);
  sub_4C8B70(&byte_8AC494);
  sub_4B40A0(byte_8AB678);
  sub_49F070(&dword_7CE048);
  sub_4FA7E0(&unk_8AFE18);
  sub_4A1830();
  if ( dword_7CC4C8 || sub_44F460(byte_7CA594, 1) || sub_4B8790(this) >= this[973] )
    return 0;
  return v3;
}
