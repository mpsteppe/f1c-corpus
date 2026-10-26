_DWORD **__thiscall sub_4BA740(void *this)
{
  _DWORD **result; // eax

  if ( dword_7D005C && *(_DWORD *)this == 1 )
    sub_4B9880((_DWORD **)this + 2);
  result = RenderToggleRefresh((int *)this + 2);
  *((_BYTE *)this + 4) = 0;
  return result;
}
