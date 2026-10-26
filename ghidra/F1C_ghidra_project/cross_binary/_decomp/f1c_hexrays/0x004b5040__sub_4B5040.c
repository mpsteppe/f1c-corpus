// f1c  0x004b5040  size=124
char __thiscall sub_4B5040(_BYTE *this, unsigned __int8 a2)
{
  sub_566C00(this, 1);
  sub_566C00(&a2, 1);
  sub_566C00(this + 1, a2);
  this[a2 + 1] = 0;
  sub_566C00(this + 65, 32);
  sub_566C00(this + 97, 32);
  sub_566C00(this + 132, 4);
  sub_566C00(this + 136, 4);
  return 1;
}
