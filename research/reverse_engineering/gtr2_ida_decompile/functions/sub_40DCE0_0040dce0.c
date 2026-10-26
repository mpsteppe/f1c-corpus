int __thiscall sub_40DCE0(_DWORD *this)
{
  int result; // eax
  int v2; // eax

  result = this[13];
  if ( !result )
  {
    v2 = this[2];
    if ( v2 )
      return (*(int (**)(void))(*(_DWORD *)v2 + 24))();
    else
      return 0;
  }
  return result;
}
