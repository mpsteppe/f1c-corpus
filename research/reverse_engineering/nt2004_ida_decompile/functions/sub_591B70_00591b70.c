int __thiscall sub_591B70(void *this)
{
  if ( dword_7E8E60 )
  {
    j_nullsub_6((void *)dword_7E8E60);
    sub_5BE8AE();
    dword_7E8E60 = 0;
  }
  sub_5A97A0(this);
  sub_5A46F0(&unk_7E6B48);
  if ( dword_7FBE80 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_7FBE80 + 8))(dword_7FBE80);
    if ( dword_7FBE80 )
      (**(void (__thiscall ***)(int, int))dword_7FBE80)(dword_7FBE80, 1);
    dword_7FBE80 = 0;
  }
  if ( dword_7E8E38 )
  {
    j_nullsub_6((void *)dword_7E8E38);
    sub_5BE8AE();
    dword_7E8E38 = 0;
  }
  nullsub_6(this);
  nullsub_6(this);
  if ( dword_7E8E4C )
  {
    sub_5BE8AE();
    dword_7E8E4C = 0;
  }
  if ( dword_7E8E50 )
  {
    sub_590220((_DWORD *)dword_7E8E50);
    sub_5BE8AE();
    dword_7E8E50 = 0;
  }
  if ( dword_7E8E54 )
  {
    sub_5BE8AE();
    dword_7E8E54 = 0;
  }
  return 0;
}
