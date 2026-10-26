void __cdecl sub_550831(jmp_buf Buf)
{
  if ( !Buf[55] )
    sub_54E7FC(Buf, (int)"NULL row buffer");
  if ( (*((_BYTE *)Buf + 97) & 0x10) != 0 )
  {
    if ( *((_BYTE *)Buf + 248) == 3 )
    {
      sub_54FDAD(Buf + 60, Buf[55] + 1, Buf[65], Buf[87], *((unsigned __int16 *)Buf + 133));
    }
    else if ( *((_WORD *)Buf + 133) )
    {
      sub_54FFB5(Buf + 60, Buf[55] + 1, (_WORD *)Buf + 176);
    }
    else
    {
      sub_54FFB5(Buf + 60, Buf[55] + 1, 0);
    }
  }
  if ( (*((_BYTE *)Buf + 97) & 0x20) != 0 && *((_BYTE *)Buf + 278) != 3 )
    sub_54FA5F(Buf + 60, (_BYTE *)(Buf[55] + 1), (unsigned __int8 *)Buf[78], Buf[81], Buf[75]);
  if ( (*((_BYTE *)Buf + 97) & 4) != 0 )
    sub_54F7E3((int)(Buf + 60), (_BYTE *)(Buf[55] + 1));
  if ( (Buf[24] & 0x40) != 0 )
  {
    sub_550307(Buf + 60, (char *)(Buf[55] + 1), Buf[93], Buf[94]);
    if ( !Buf[61] )
      sub_54E7FC(Buf, (int)"png_do_dither returned rowbytes=0");
  }
  if ( (Buf[24] & 8) != 0 )
    sub_54F66C(Buf + 60, (_BYTE *)(Buf[55] + 1), (unsigned __int8 *)Buf + 341);
  if ( (Buf[24] & 4) != 0 )
    sub_54F55C(Buf + 60, Buf[55] + 1);
  if ( (Buf[24] & 1) != 0 )
    sub_54F373(Buf + 60, (char *)(Buf[55] + 1));
  if ( *((char *)Buf + 97) < 0 )
    sub_54F827((int)(Buf + 60), Buf[55] + 1, *((unsigned __int16 *)Buf + 143), Buf[23]);
  if ( (Buf[24] & 0x10) != 0 )
    sub_54F346((int)(Buf + 60), (char *)(Buf[55] + 1));
}
