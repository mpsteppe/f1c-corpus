int __thiscall sub_4D2530(_DWORD *this)
{
  float v3; // [esp+0h] [ebp-8h]

  v3 = sub_4DE460(this[12]);
  sub_4D2370((int)this, v3);
  (*(void (__thiscall **)(_DWORD *))(*this + 164))(this);
  return 0;
}
