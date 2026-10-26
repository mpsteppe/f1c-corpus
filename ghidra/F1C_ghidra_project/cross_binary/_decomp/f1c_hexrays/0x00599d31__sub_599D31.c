// f1c  0x00599d31  size=33
__int16 __thiscall sub_599D31(void *this)
{
  if ( (*(unsigned __int16 (__thiscall **)(void *))(*(_DWORD *)this + 16))(this) == 0xFFFF )
    return -1;
  else
    return *(_WORD *)sub_59A418(this);
}
