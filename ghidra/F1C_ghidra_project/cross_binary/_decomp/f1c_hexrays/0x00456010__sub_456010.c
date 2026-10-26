// f1c  0x00456010  size=37
int __thiscall sub_456010(void *this)
{
  int v1; // eax

  if ( !byte_7CD1FC )
  {
    v1 = sub_5896EE(0);
    sub_5884E0(v1);
    byte_7CD1FC = 1;
  }
  return sub_5884ED(this);
}
