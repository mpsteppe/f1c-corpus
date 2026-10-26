int __thiscall sub_598CDC(void *this)
{
  int result; // eax

  result = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 16))(this);
  if ( result != -1 )
    return *(unsigned __int8 *)sub_599475(this);
  return result;
}
