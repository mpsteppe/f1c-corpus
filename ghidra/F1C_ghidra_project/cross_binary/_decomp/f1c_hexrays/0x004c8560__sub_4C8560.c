// f1c  0x004c8560  size=30
void sub_4C8560()
{
  if ( dword_8AC4C4 )
  {
    if ( !dword_8AC4CC )
      dword_8AC4CC = (*(int (**)(void))(*(_DWORD *)dword_8AC4C4 + 96))();
  }
}
