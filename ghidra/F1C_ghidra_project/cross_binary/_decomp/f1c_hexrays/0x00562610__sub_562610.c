// f1c  0x00562610  size=158
int __fastcall sub_562610(SOCKET *a1, const struct sockaddr *a2, char *buf)
{
  int result; // eax
  int v5; // edi
  char v7[80]; // [esp+10h] [ebp-50h] BYREF

  result = 0;
  if ( strlen(buf) )
  {
    v5 = a1[56] + 1;
    a1[56] = v5;
    sub_58815F(v7, "\\queryid\\%d.%d", a1[55], v5);
    strcat(buf, v7);
    result = sendto(*a1, buf, strlen(buf), 0, a2, 16);
    *buf = 0;
  }
  return result;
}
