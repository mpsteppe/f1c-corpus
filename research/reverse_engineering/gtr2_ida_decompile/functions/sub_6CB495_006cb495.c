int __thiscall sub_6CB495(_DWORD *this, unsigned int a2, int *a3)
{
  unsigned int v4; // eax
  unsigned int v5; // esi
  int result; // eax
  _DWORD *v7; // eax
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  if ( this[86] )
  {
    sprintf(Buffer, "c_$zz%d", a2);
    result = sub_66078B(this + 109, Buffer, a2, 1);
    if ( result >= 0 )
    {
      v7 = (_DWORD *)sub_65EBEC(this + 109, Buffer);
      v7[3] = 1;
      v7[4] = *a3;
      v7[5] = a3[1];
      v7[6] = a3[2];
      v7[7] = a3[3];
      ++this[125];
      return 0;
    }
  }
  else
  {
    if ( a2 >= 0x800 )
    {
      if ( a2 >= 0x1000 )
      {
        if ( a2 >= 0x1800 )
          v4 = a2 & 0x7FF | 0xD0000800;
        else
          v4 = a2 & 0x7FF | 0xC0000800;
      }
      else
      {
        v4 = a2 & 0x7FF | 0xB0000800;
      }
    }
    else
    {
      v4 = a2 & 0x7FF | 0xA0000000;
    }
    v5 = v4;
    result = sub_6CB0CE((int)this, 81);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, _DWORD))(*this + 100))(this, v5, 983040, 0);
      if ( result >= 0 )
      {
        result = sub_6C9357(this, *a3);
        if ( result >= 0 )
        {
          result = sub_6C9357(this, a3[1]);
          if ( result >= 0 )
          {
            result = sub_6C9357(this, a3[2]);
            if ( result >= 0 )
            {
              result = sub_6C9357(this, a3[3]);
              if ( result >= 0 )
              {
                result = (*(int (__thiscall **)(_DWORD *))(*this + 96))(this);
                if ( result >= 0 )
                {
                  result = sub_6C64E6(this);
                  if ( result >= 0 )
                    return 0;
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}
