int sub_4586B0()
{
  __time32_t v0; // eax

  if ( !byte_764D60 )
  {
    v0 = time(0);
    srand(v0);
    byte_764D60 = 1;
  }
  return rand();
}
