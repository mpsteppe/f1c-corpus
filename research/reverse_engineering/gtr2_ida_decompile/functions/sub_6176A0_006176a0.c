char __usercall sub_6176A0@<al>(unsigned __int8 a1@<bl>)
{
  char v2; // [esp+1h] [ebp-1h]

  v2 = 0;
  if ( isalnum(a1) || a1 >= 0x80u )
    return 1;
  switch ( a1 )
  {
    case ' ':
    case '!':
    case '#':
    case '$':
    case '%':
    case '&':
    case '\'':
    case '(':
    case ')':
    case ',':
    case '-':
    case '.':
    case '/':
    case ':':
    case ';':
    case '=':
    case '@':
    case '[':
    case '\\':
    case ']':
    case '^':
    case '_':
    case '`':
    case '{':
    case '}':
    case '~':
      return 1;
    default:
      return v2;
  }
}
