char __fastcall sub_568750(char a1)
{
  int v1; // esi
  char v2; // bl

  v1 = a1;
  v2 = 0;
  if ( sub_589C1B(a1) )
    return 1;
  switch ( v1 )
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

