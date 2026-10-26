int __thiscall FlagClearZeroBytes(int this)
{
  FieldSetterCall(*(_DWORD **)(this + 64), 2);
  *(_BYTE *)(this + 244) = 0;
  *(_BYTE *)(this + 245) = 0;
  return 0;
}

