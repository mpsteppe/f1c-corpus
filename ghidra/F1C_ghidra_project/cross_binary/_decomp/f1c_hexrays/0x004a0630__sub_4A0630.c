// f1c  0x004a0630  size=96
int __thiscall sub_4A0630(void *this)
{
  char *v2; // eax

  sub_42CF10(&dword_7C569C, 1);
  sub_4C2780(&unk_7D2DB0);
  sub_4C2810(&unk_7D2DB0);
  v2 = (char *)dword_7CE5EC;
  if ( !dword_7CE5EC )
    v2 = byte_5EA438;
  sub_4C55B0(v2);
  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  sub_4186A0(flt_5EA618);
  sub_4A09F0(this);
  return 0;
}
