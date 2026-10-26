char __thiscall UIActiveStateToggle(int this)
{
  bool v2; // zf
  char result; // al

  v2 = FieldGetter_79d0(*(_DWORD **)(this + 64)) == this;
  result = *(_BYTE *)(this + 224);
  if ( v2 )
  {
    if ( !result || (result = *(_BYTE *)(this + 225)) == 0 )
    {
      SetterVTableIDCheck((int *)this, 1);
      return (*(int (__thiscall **)(int, int))(*(_DWORD *)this + 44))(this, 1);
    }
  }
  else if ( result )
  {
    result = *(_BYTE *)(this + 225);
    if ( result )
    {
      SetterVTableIDCheck((int *)this, 0);
      return (*(int (__thiscall **)(int, int))(*(_DWORD *)this + 44))(this, 1);
    }
  }
  return result;
}

