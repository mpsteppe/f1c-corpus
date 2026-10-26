int __thiscall sub_6CB5D2(_DWORD *this, int a2, int *a3)
{
  int result; // eax
  _DWORD *v5; // eax
  char Buffer[32]; // [esp+8h] [ebp-20h] BYREF

  if ( this[86] )
  {
    sprintf(Buffer, "i_$zz%d", a2);
    result = sub_66078B(this + 109, Buffer, a2, 1);
    if ( result >= 0 )
    {
      v5 = (_DWORD *)sub_65EBEC(this + 109, Buffer);
      v5[3] = 1;
      v5[4] = *a3;
      v5[5] = a3[1];
      v5[6] = a3[2];
      v5[7] = a3[3];
      ++this[125];
      return 0;
    }
  }
  else
  {
    result = sub_6CB0CE((int)this, 48);
    if ( result >= 0 )
    {
      result = (*(int (__thiscall **)(_DWORD *, unsigned int, int, _DWORD))(*this + 100))(
                 this,
                 a2 & 0x7FF | 0xF0000000,
                 983040,
                 0);
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
