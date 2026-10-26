_DWORD *__thiscall sub_5BC7A0(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // ecx

  result = this;
  v2 = this[1];
  *result = &off_729660;
  result[1] = 0;
  if ( v2 )
    return (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v2 + 4))(v2);
  return result;
}
