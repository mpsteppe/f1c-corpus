int __thiscall sub_5BBD90(int this)
{
  int result; // eax

  result = *(_DWORD *)(this + 16);
  if ( result )
  {
    sub_5BBDD0();
    sub_5BC020(this);
    if ( *(int *)(this + 28) > 0 )
      sub_5BC0A0(this);
    result = *(_DWORD *)(this + 16);
    if ( !result )
      return (*(int (__fastcall **)(int, int, _DWORD, _DWORD))(this + 64))(this, 2, 0, *(_DWORD *)(this + 68));
  }
  return result;
}
