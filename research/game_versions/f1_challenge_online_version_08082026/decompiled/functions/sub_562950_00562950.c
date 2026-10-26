char *__fastcall sub_562950(SOCKET *a1, const struct sockaddr *a2, char *buf, const char *a4)
{
  char *result; // eax
  char v7[1400]; // [esp+Ch] [ebp-578h] BYREF

  result = 0;
  if ( strlen(a4) <= 0x546 )
  {
    sub_58815F(v7, "\\echo\\%s", a4);
    return sub_562710(a1, a2, buf, v7);
  }
  return result;
}
