char __fastcall sub_57B170(unsigned __int8 a1)
{
  char v3; // [esp+7h] [ebp-1h]

  v3 = 0;
  if ( isalnum(a1) )
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
      return v3;
  }
}
