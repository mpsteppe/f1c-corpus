int __thiscall sub_452740(int *this, int a2, int a3)
{
  CollisionNodePropertySetter(byte_7CA594, *this, 0);
  this[1] = a3;
  *this = a2;
  return CollisionNodePropertySetter(byte_7CA594, a2, a3);
}
