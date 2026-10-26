// f1c  0x0041e890  size=135
int __thiscall sub_41E890(void *this)
{
  int v2; // esi
  char *v3; // eax

  v2 = 0;
  while ( 1 )
  {
    if ( sub_4C2850(&unk_7D2DB0) )
    {
      sub_4C2850(&unk_7D2DB0);
      if ( sub_4C13A0(v2) )
      {
        sub_4C2850(&unk_7D2DB0);
        v3 = *(char **)sub_4C13A0(v2);
        if ( !v3 )
          v3 = &byte_5EA438;
        if ( !sub_588410(v3, this) )
          break;
      }
    }
    if ( ++v2 >= 103 )
      return 0;
  }
  sub_4C2850(&unk_7D2DB0);
  return *(_DWORD *)(sub_4C13A0(v2) + 408);
}
