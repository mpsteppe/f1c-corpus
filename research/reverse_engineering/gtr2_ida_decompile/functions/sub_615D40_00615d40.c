int __thiscall sub_615D40(void *this)
{
  _DWORD *v1; // eax

  v1 = *(_DWORD **)(*(_DWORD *)this + 8);
  if ( v1 && *v1 )
    return off_16C9924();
  else
    return 0;
}
