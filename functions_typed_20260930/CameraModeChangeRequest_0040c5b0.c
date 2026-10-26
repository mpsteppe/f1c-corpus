int __thiscall sub_40C5B0(_DWORD *this)
{
  int result; // eax
  int v2; // edx

  result = *(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580);
  if ( result != *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580) )
  {
    v2 = this[3];
    result = v2 + 1;
    switch ( v2 )
    {
      case -1:
      case 1:
        goto LABEL_4;
      case 2:
        result = dword_7CFCC8;
        if ( !dword_7CFCC8 )
        {
LABEL_4:
          this[5] = v2;
          result = GameActionStateMachine(5, 0);
        }
        break;
      default:
        return result;
    }
  }
  return result;
}

