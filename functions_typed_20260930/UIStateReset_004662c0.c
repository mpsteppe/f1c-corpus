int __thiscall UIStateReset(int this)
{
  FieldSetterCall(*(_DWORD **)(this + 64), 0);
  *(_BYTE *)(this + 244) = 0;
  *(_BYTE *)(this + 245) = 0;
  return 0;
}

