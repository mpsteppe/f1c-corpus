_DWORD *__thiscall sub_5267E0(_DWORD *this)
{
  char *v2; // eax
  _DWORD *v3; // ebx
  char *v4; // edi
  _DWORD *result; // eax
  int v6; // edi

  v2 = (char *)this[722647];
  v3 = 0;
  if ( v2 )
  {
    v4 = v2 - 4;
    `eh vector destructor iterator'(v2, 0xB8u, *((_DWORD *)v2 - 1), (void (__thiscall *)(void *))sub_525B50);
    j_j__free(v4);
    this[722647] = 0;
    this[722648] = 0;
  }
  result = (_DWORD *)this[722644];
  switch ( (unsigned int)result )
  {
    case 0u:
      this[722648] = 16;
      goto LABEL_9;
    case 1u:
      this[722648] = 24;
      goto LABEL_9;
    case 2u:
      this[722648] = 32;
      goto LABEL_9;
    case 3u:
      this[722648] = 48;
      goto LABEL_9;
    case 4u:
      this[722648] = 96;
LABEL_9:
      v6 = this[722648];
      result = operator new(184 * v6 + 4);
      if ( result )
      {
        v3 = result + 1;
        *result = v6;
        result = (_DWORD *)sub_630A11(result + 1, 184, v6, sub_5251A0, sub_525B50);
      }
      this[722647] = v3;
      break;
    default:
      return result;
  }
  return result;
}
