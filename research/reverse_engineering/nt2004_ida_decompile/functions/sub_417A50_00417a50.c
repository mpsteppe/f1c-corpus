int __thiscall sub_417A50(int *this, float a2)
{
  int result; // eax
  int i; // esi
  _DWORD *v5; // ecx

  sub_4E07D0(&unk_7D5DD8);
  result = *this;
  for ( i = 0; i < *this; ++i )
  {
    if ( !sub_4162B0(*(_DWORD **)(this[2] + 4 * i), a2) )
    {
      v5 = *(_DWORD **)(this[2] + 4 * i--);
      sub_4161F0(v5);
    }
    result = *this;
  }
  return result;
}
