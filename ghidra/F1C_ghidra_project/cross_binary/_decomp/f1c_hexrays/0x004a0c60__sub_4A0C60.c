// f1c  0x004a0c60  size=74
int sub_4A0C60()
{
  if ( sub_404F00(&dword_5EA43C) )
  {
    dword_7C569C = 6;
    sub_404F30(&dword_5EA43C);
    return 0;
  }
  else
  {
    if ( !dword_7CE814 )
    {
      sub_408420((int)&flt_5EA4E8, 0.5);
      sub_4A0D10(&unk_7CE24D);
    }
    return 0;
  }
}
