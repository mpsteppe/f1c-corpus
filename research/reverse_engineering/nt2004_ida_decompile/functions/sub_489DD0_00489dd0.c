int __thiscall sub_489DD0(void *this)
{
  char *v2; // eax

  v2 = (char *)sub_4ED720(&dword_7D6B74);
  if ( v2 )
    sub_4A1AC0(v2);
  else
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
  return 0;
}
