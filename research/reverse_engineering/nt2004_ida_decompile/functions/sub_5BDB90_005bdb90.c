int sub_5BDB90()
{
  WSAData WSAData; // [esp+0h] [ebp-190h] BYREF

  return WSAStartup(0x101u, &WSAData);
}
