int __thiscall FlagSetter(int this)
{
  FieldSetterCall(*(_DWORD **)(this + 64), 3);
  *(_BYTE *)(this + 244) = 1;
  return 0;
}

