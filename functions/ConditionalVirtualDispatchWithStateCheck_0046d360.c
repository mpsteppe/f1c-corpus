int __thiscall ConditionalVirtualDispatchWithStateCheck(void *this)
{
  if ( !sub_4D24A0() )
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 56))(this, 1);
  (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 56))(this, 0);
  return 0;
}
