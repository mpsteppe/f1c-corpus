void __cdecl __noreturn abort()
{
  _NMSG_WRITE(0xAu);
  raise(22);
  _exit(3);
}
