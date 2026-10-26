int __thiscall sub_536480(void *this)
{
  int result; // eax
  int v3; // eax
  int v4; // edx

  if ( *((_DWORD *)this + 15) )
    return -1;
  if ( *((_DWORD *)this + 1) )
    goto LABEL_8;
  *_errno() = 0;
  v3 = sub_5BED6F(*((void **)this + 17), 1u, 0x4000u, *((FILE **)this + 16));
  *((_DWORD *)this + 1) = v3;
  if ( v3 )
  {
    *(_DWORD *)this = *((_DWORD *)this + 17);
LABEL_8:
    --*((_DWORD *)this + 1);
    return *(unsigned __int8 *)(*(_DWORD *)this)++;
  }
  v4 = *((_DWORD *)this + 16);
  *((_DWORD *)this + 15) = 1;
  result = -1;
  if ( (*(_BYTE *)(v4 + 12) & 0x20) != 0 )
    *((_DWORD *)this + 14) = -1;
  return result;
}
