int __thiscall sub_47B830(void *this)
{
  if ( sub_41F230(dword_62A170, aOscLocaleStrin, Destination) )
  {
    strncpy(Destination, aOscLocaleStrin, 0x1FFu);
    byte_62A37B = 0;
  }
  if ( _strcmpi(Destination, aAmerican_0) )
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 40))(this, 0);
  }
  return 0;
}
