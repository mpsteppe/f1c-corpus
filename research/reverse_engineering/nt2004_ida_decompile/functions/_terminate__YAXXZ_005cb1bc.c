void __cdecl __noreturn terminate()
{
  _DWORD *v0; // eax

  if ( _getptd()[24] )
  {
    v0 = _getptd();
    ((void (*)(void))v0[24])();
  }
  abort();
}
