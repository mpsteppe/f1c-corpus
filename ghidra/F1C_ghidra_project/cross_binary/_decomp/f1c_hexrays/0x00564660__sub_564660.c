// f1c  0x00564660  size=28
int sub_564660()
{
  WSAData WSAData; // [esp+0h] [ebp-190h] BYREF

  return WSAStartup(0x101u, &WSAData);
}
