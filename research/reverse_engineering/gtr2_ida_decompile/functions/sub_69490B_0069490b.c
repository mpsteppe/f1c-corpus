int __thiscall sub_69490B(_DWORD *this)
{
  int result; // eax
  unsigned int i; // edi

  result = sub_68AD21(this);
  if ( result >= 0 )
  {
    result = sub_6925FA(this);
    if ( result >= 0 )
    {
      result = sub_68C54F(this, 1);
      if ( result >= 0 )
      {
        for ( i = 0; i < 0x100; ++i )
        {
          result = sub_69056E(this, 1);
          if ( result )
          {
            if ( result < 0 )
              return result;
            if ( result == 1 )
              break;
          }
        }
        result = sub_68AF5A((int)this);
        if ( result >= 0 )
        {
          result = sub_692CC1((int)this);
          if ( result >= 0 )
          {
            result = (*(int (__thiscall **)(_DWORD *))(*this + 16))(this);
            if ( result >= 0 )
            {
              result = sub_68C54F(this, 0);
              if ( result >= 0 )
              {
                result = sub_693B65(this);
                if ( result >= 0 )
                {
                  this[55] = 1;
                  result = sub_68C799((int)this);
                  if ( result >= 0 )
                  {
                    result = sub_6940BF((int)this);
                    if ( result >= 0 )
                    {
                      result = sub_684C5D(this);
                      if ( result >= 0 )
                      {
                        result = (*(int (__thiscall **)(_DWORD *))(*this + 20))(this);
                        if ( result >= 0 )
                        {
                          result = (*(int (__thiscall **)(_DWORD *))(*this + 24))(this);
                          if ( result >= 0 )
                          {
                            result = sub_6825A9(this);
                            if ( result >= 0 )
                            {
                              result = sub_688BDF(this);
                              if ( result >= 0 )
                              {
                                result = sub_6942F3((int)this);
                                if ( result >= 0 )
                                {
                                  result = sub_68CAD5(this);
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
