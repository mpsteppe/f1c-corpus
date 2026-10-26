unsigned int __thiscall sub_6442A0(const void **this, void *a2, unsigned int a3)
{
  qmemcpy(a2, this[2], a3);
  (*((void (__thiscall **)(const void **, unsigned int))*this + 35))(this, a3);
  return a3;
}
