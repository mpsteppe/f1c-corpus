// f1_2002_full  0x0055b160  size=94
int __thiscall sub_55B160(int this, const char *a2)
{
  unsigned int v4; // kr04_4

  if ( !a2 )
    return -1;
  v4 = strlen(a2) + 1;
  if ( !*(_DWORD *)this )
    goto LABEL_6;
  if ( *(_DWORD *)(this + 4) < (signed int)(v4 - 1) )
  {
    sub_56BEF1(*(LPVOID *)this);
LABEL_6:
    *(_DWORD *)this = operator new(v4);
    *(_DWORD *)(this + 4) = v4 - 1;
  }
  strcpy(*(char **)this, a2);
  return 0;
}
