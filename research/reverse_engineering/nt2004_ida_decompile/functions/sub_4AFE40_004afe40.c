char __thiscall sub_4AFE40(int *this, char a2)
{
  if ( sub_5A1A60(this, 2, 0, a2 != 0 ? 48 : 16, 3136) )
    return 0;
  sub_5A16E0(*this, 0, 0.0, 0.0, 1.0, 0.0, 0.0, -1);
  sub_5A16E0(*this, 1, 0.0, 0.0, 1.0, 0.0, 1.0, -1);
  sub_5A16E0(*this, 2, 0.0, 0.0, 1.0, 1.0, 1.0, -1);
  sub_5A16E0(*this, 3, 0.0, 0.0, 1.0, 1.0, 0.0, -1);
  return 1;
}
