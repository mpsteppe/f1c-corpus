int __thiscall sub_6A0CC8(void *this, int a2, int a3, int a4, _DWORD *a5)
{
  int result; // eax

  result = sub_6C59C9((int)this, a2, a3, a4, (int)a5);
  if ( result >= 0 )
  {
    if ( (*(int (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 84))(this, *(_DWORD *)(a2 + 108)) == 17 )
      *a5 = 1;
    return 0;
  }
  return result;
}
