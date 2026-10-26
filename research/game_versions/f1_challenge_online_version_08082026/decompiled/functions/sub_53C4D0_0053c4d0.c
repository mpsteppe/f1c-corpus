int __thiscall sub_53C4D0(void *this)
{
  void *v1; // esi
  void *v3; // esi
  void *v4; // esi

  v1 = (void *)dword_8B8F2C;
  if ( dword_8B8F2C )
  {
    j_nullsub_3(dword_8B8F2C);
    sub_587BCF(v1);
    dword_8B8F2C = 0;
  }
  sub_55BF70(this);
  sub_53D850(&unk_8B78A0);
  v3 = (void *)dword_8B8F04;
  if ( dword_8B8F04 )
  {
    j_nullsub_3(dword_8B8F04);
    sub_587BCF(v3);
    dword_8B8F04 = 0;
  }
  nullsub_3();
  nullsub_3();
  if ( dword_8B8F18 )
  {
    sub_587BCF((LPVOID)dword_8B8F18);
    dword_8B8F18 = 0;
  }
  v4 = (void *)dword_8B8F1C;
  if ( dword_8B8F1C )
  {
    sub_53AD50((void *)dword_8B8F1C);
    sub_587BCF(v4);
    dword_8B8F1C = 0;
  }
  if ( dword_8B8F20 )
  {
    sub_587BCF((LPVOID)dword_8B8F20);
    dword_8B8F20 = 0;
  }
  return 0;
}
