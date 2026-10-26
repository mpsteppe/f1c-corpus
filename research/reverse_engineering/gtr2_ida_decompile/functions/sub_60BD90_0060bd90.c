int __stdcall sub_60BD90(char *String1, _DWORD *a2)
{
  int result; // eax

  if ( !_stricmp(String1, "NSHADEDECL") )
  {
    *a2 = dword_FB410C;
    return 0;
  }
  else if ( !_stricmp(String1, "GSHADEDECL") )
  {
    *a2 = dword_FB4114;
    return 0;
  }
  else
  {
    result = _stricmp(String1, "PSHADEDECL");
    if ( result )
    {
      if ( !_stricmp(String1, "PSHADEEXDECL") )
      {
        *a2 = dword_FB411C;
        return 0;
      }
      else if ( !_stricmp(String1, "PSHADEBUMPDECL") )
      {
        *a2 = dword_FB4120;
        return 0;
      }
      else
      {
        result = _stricmp(String1, "PSHADEBUMPEXDECL");
        if ( result )
        {
          if ( !_stricmp(String1, "ASHADEDECL") )
          {
            *a2 = dword_FB4128;
            return 0;
          }
          else if ( !_stricmp(String1, "ASHADEEXDECL") )
          {
            *a2 = dword_FB412C;
            return 0;
          }
          else
          {
            result = _stricmp(String1, "SSHADEDECL");
            if ( result )
            {
              if ( !_stricmp(String1, "SSHADETEXDECL") )
              {
                *a2 = dword_FB4110;
                return 0;
              }
              else
              {
                result = _stricmp(String1, "SSHADEPROJDECL");
                if ( result )
                {
                  result = _stricmp(String1, "SSHADEPROJTEXDECL");
                  if ( result )
                    return -1;
                  else
                    *a2 = &unk_911120;
                }
                else
                {
                  *a2 = &unk_911108;
                }
              }
            }
            else
            {
              *a2 = &unk_911080;
            }
          }
        }
        else
        {
          *a2 = dword_FB4124;
        }
      }
    }
    else
    {
      *a2 = dword_FB4118;
    }
  }
  return result;
}
