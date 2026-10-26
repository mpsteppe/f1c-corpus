unsigned __int8 __thiscall sub_460630(int this)
{
  int v2; // ebp
  signed __int8 v3; // bl
  int v4; // ecx
  unsigned int v5; // kr08_4
  unsigned __int8 result; // al
  const char *v7; // eax
  __int16 *v8; // [esp+8h] [ebp-90h]
  float v9; // [esp+8h] [ebp-90h]
  char Source[136]; // [esp+10h] [ebp-88h] BYREF

  if ( *(_BYTE *)(this + 676) )
  {
    v2 = 0;
    v8 = &word_762A08;
    while ( 1 )
    {
      if ( v2 >= ((dword_761FF8 & 4) != 0 ? dword_762A04 : 0) )
      {
        if ( !*(_BYTE *)(this + 676) )
        {
          if ( sub_41F230(dword_62A170, aChat, Destination) )
          {
            strncpy(Destination, aChat, 0x1FFu);
            byte_62A37B = 0;
          }
          sub_45D270(&byte_764D68, Destination, 1);
          sub_45D100(&byte_764D68, (int)byte_764DC8, 0, 15790320, 1);
          sub_451510(word_761D7C, 1, 0.25);
          sub_451510(word_761D7C, 28, 0.25);
        }
        goto LABEL_23;
      }
      switch ( *v8 )
      {
        case 1:
          goto LABEL_12;
        case 14:
          v5 = strlen((const char *)(this + 677)) + 1;
          if ( (int)(v5 - 1) <= 0 )
            goto LABEL_13;
          *(_BYTE *)(this + v5 - 1 + 676) = 0;
          ++v2;
          ++v8;
          break;
        case 28:
          if ( *(_BYTE *)(this + 677) )
            sub_460490((_DWORD *)this, (char *)(this + 677), 1);
LABEL_12:
          sub_460930(this);
          goto LABEL_13;
        default:
          v3 = sub_458220((unsigned __int16)*v8);
          if ( v3 < 32 || (v4 = strlen((const char *)(this + 677)), v4 >= 69) )
          {
LABEL_13:
            ++v2;
            ++v8;
          }
          else
          {
            *(_BYTE *)(v4 + this + 678) = 0;
            ++v2;
            *(_BYTE *)(this + 677 + v4) = v3;
            ++v8;
          }
          break;
      }
    }
  }
  if ( dword_763C08 && !byte_76617C )
    sub_4608F0(this);
LABEL_23:
  result = *(_BYTE *)(this + 676);
  if ( result )
  {
    v9 = dbl_7DA9D8 + dbl_7DA9D8;
    if ( sub_41F230(dword_62A170, aChat, Destination) )
    {
      strncpy(Destination, aChat, 0x1FFu);
      byte_62A37B = 0;
    }
    v7 = asc_5FFD80;
    if ( ((int)v9 & 1) == 0 )
      v7 = word_5FBEBC;
    _snprintf(Source, 0x85u, "%s %s%s", Destination, (const char *)(this + 677), v7);
    Source[133] = 0;
    sub_45D270(&byte_764D68, Destination, 1);
    sub_45D100(&byte_764D68, (int)byte_764DC8, 0, 15790320, 1);
    sub_45D100(&byte_764D68, (int)Source, 0, 15790320, 0);
    result = (unsigned __int8)strncpy(byte_764DC8, Source, 0xFFu);
    byte_764EC7 = 0;
  }
  return result;
}
