double __thiscall sub_529CA0(void *this)
{
  CHAR *v1; // ecx
  int v3; // [esp+0h] [ebp-8h]
  float v4; // [esp+4h] [ebp-4h]

  switch ( (unsigned int)this )
  {
    case 0u:
    case 8u:
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
      v3 = 4;
      v4 = 9.5;
      break;
    case 7u:
      v3 = 4;
      v4 = 14.0;
      break;
    default:
      break;
  }
  if ( dword_75CBB0 == 1 || dword_75CBB0 == 2 )
  {
    v1 = dword_766578;
    if ( !dword_766578 )
      v1 = &byte_629120;
    if ( sub_579060(v1, aMonaco) )
      --v3;
  }
  return (double)v3 * 86400.0 + v4 * 3600.0;
}
