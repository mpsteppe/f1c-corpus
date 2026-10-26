int __thiscall sub_4E0D70(_DWORD *this)
{
  int result; // eax
  int v3; // esi

  for ( result = sub_4DF840(); (_BYTE)result; result = sub_4DF840() )
    this = (_DWORD *)sub_4DF700();
  v3 = this[13];
  if ( v3 )
  {
    do
    {
      (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 96))(v3);
      result = sub_4CD340();
      v3 = result;
    }
    while ( result );
  }
  return result;
}
