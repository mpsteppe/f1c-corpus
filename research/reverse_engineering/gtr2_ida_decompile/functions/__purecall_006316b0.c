void __noreturn _purecall()
{
  if ( dword_FB8180 )
    dword_FB8180();
  _amsg_exit(0x19u);
}
