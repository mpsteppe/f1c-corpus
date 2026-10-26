int sub_4B8BD0()
{
  if ( SessionTypeFlagGuard(byte_7CA594, 203) )
    return 0;
  if ( SessionTypeFlagGuard(byte_7CA594, 200) )
    return 1;
  if ( SessionTypeFlagGuard(byte_7CA594, 208) )
    return 3;
  return SessionTypeFlagGuard(byte_7CA594, 205) ? 4 : 2;
}

