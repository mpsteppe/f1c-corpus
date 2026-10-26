int (__thiscall *__thiscall sub_4FD680(_DWORD *this))(FILE *Stream)
{
  int (__thiscall *result)(FILE *); // eax
  FILE *v3; // ecx
  bool v4; // zf

  *this = &off_5EA878;
  result = off_612324;
  if ( off_612324 )
  {
    v3 = (FILE *)this[1];
    if ( v3 )
    {
      result = (int (__thiscall *)(FILE *))(this[2] - 1);
      v4 = this[2] == 1;
      this[2] = result;
      if ( (int)result < 0 || v4 )
      {
        off_612324(v3);
        result = (int (__thiscall *)(FILE *))this[3];
        if ( result )
        {
          result = (int (__thiscall *)(FILE *))sub_5BE8AE();
          this[3] = 0;
        }
        this[1] = 0;
      }
    }
  }
  return result;
}
