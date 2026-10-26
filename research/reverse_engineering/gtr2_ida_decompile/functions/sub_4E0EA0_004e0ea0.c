char __thiscall sub_4E0EA0(int this)
{
  char result; // al
  int i; // esi

  result = *(_BYTE *)(this + 56);
  if ( result )
  {
    for ( i = *(_DWORD *)(this + 64); i; i = sub_4CD340() )
      (*(void (__thiscall **)(int))(*(_DWORD *)i + 92))(i);
    result = sub_4E0D20(*(_DWORD **)(this + 68));
    *(_BYTE *)(this + 56) = 0;
  }
  return result;
}
