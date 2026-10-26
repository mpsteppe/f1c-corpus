int __thiscall sub_47F040(void *this)
{
  if ( dword_75CBA8 != 5 || *(_DWORD *)dword_7689CC == 5 || byte_7D74C8 )
  {
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
    return 0;
  }
}
