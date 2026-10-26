// f1c  0x004fb910  size=223
double __thiscall sub_4FB910(void *this)
{
  char *v1; // ecx
  int v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]

  switch ( (unsigned int)this )
  {
    case 0u:
      v3 = 1;
      v4 = 12.0;
      break;
    case 1u:
      v3 = 2;
      v4 = 11.0;
      break;
    case 2u:
      v3 = 2;
      v4 = 13.0;
      break;
    case 3u:
      v3 = 3;
      v4 = 9.0;
      break;
    case 4u:
      v3 = 3;
      v4 = 10.25;
      break;
    case 5u:
      v3 = 3;
      v4 = 13.0;
      break;
    case 6u:
      v4 = 9.5;
      goto LABEL_10;
    case 7u:
      v4 = 14.0;
LABEL_10:
      v3 = 4;
      break;
    default:
      break;
  }
  if ( dword_7C56A4 == 1 || dword_7C56A4 == 2 )
  {
    v1 = (char *)dword_7CE5D0;
    if ( !dword_7CE5D0 )
      v1 = byte_5EA438;
    if ( sub_566810(v1, aMonaco) )
      --v3;
  }
  return (double)v3 * 86400.0 + v4 * 3600.0;
}
