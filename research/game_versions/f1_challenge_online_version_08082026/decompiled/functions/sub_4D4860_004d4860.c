int (__thiscall *__thiscall sub_4D4860(void *this))(void *this)
{
  int (__thiscall *result)(void *); // eax
  void *v3; // ecx
  bool v4; // zf

  *(_DWORD *)this = &off_5ACF08;
  result = off_5D43C8;
  if ( off_5D43C8 )
  {
    v3 = (void *)*((_DWORD *)this + 1);
    if ( v3 )
    {
      result = (int (__thiscall *)(void *))(*((_DWORD *)this + 2) - 1);
      v4 = *((_DWORD *)this + 2) == 1;
      *((_DWORD *)this + 2) = result;
      if ( (int)result < 0 || v4 )
      {
        off_5D43C8(v3);
        result = (int (__thiscall *)(void *))*((_DWORD *)this + 3);
        if ( result )
        {
          result = (int (__thiscall *)(void *))sub_587BCF(*((LPVOID *)this + 3));
          *((_DWORD *)this + 3) = 0;
        }
        *((_DWORD *)this + 1) = 0;
      }
    }
  }
  return result;
}
