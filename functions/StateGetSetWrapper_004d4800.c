int __thiscall StateGetSetWrapper(void *this)
{
  int v2; // edi
  int v3; // ebx

  v2 = ArrayStateRead(this);
  Delegation_47c0((int)this, 0, 2);
  v3 = ArrayStateRead(this);
  Delegation_47c0((int)this, v2, 0);
  return v3;
}
