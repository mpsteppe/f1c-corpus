// f1c  0x0040be70  size=337
int __thiscall sub_40BE70(int this)
{
  int v2; // edi
  __int16 *v3; // ebx
  int v4; // eax
  int v6; // [esp+8h] [ebp-4h]

  v2 = 0;
  if ( !*(_BYTE *)(this + 36) )
  {
    v6 = 0;
    if ( dword_7CB218 > 0 )
    {
      v3 = &word_7CB21C;
      do
      {
        switch ( *v3 )
        {
          case 74:
            sub_40D290(1);
            goto LABEL_24;
          case 78:
            sub_40D290(0);
            goto LABEL_24;
          case 156:
            sub_40D340(this);
            goto LABEL_24;
          case 199:
            if ( (unsigned __int8)sub_40C720(4) && !sub_40CDE0(4, 1) )
              goto LABEL_24;
            break;
          case 201:
            if ( (!*(_BYTE *)(dword_7C54E0 + 13388) || (unsigned __int8)sub_40C720(3)) && !sub_40CDE0(3, 1)
              || byte_7CFE88 )
            {
              goto LABEL_24;
            }
            break;
          case 209:
            if ( (unsigned __int8)sub_40C720(5) && !sub_40CDE0(5, 1) )
              goto LABEL_24;
            break;
          case 210:
            v4 = *(_DWORD *)(this + 24);
            if ( (*(_DWORD *)(this + 8) != v4 || !*(_DWORD *)(v4 + 64))
              && (unsigned __int8)sub_40C720(0)
              && !sub_40CDE0(0, 1) )
            {
LABEL_24:
              v2 = 1;
            }
            break;
          default:
            break;
        }
        ++v3;
        ++v6;
      }
      while ( v6 < dword_7CB218 );
    }
  }
  if ( !*(_BYTE *)(this + 44) )
    return v2;
  *(_BYTE *)(this + 44) = 0;
  return 1;
}
