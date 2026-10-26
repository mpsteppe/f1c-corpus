int __thiscall sub_559A70(_DWORD *this)
{
  int v2; // ecx
  int v3; // eax
  int v4; // eax
  char v5; // dl
  int result; // eax

  v2 = 0;
  while ( 1 )
  {
    v3 = this[1];
    if ( v3 >= this[2] )
      break;
    *((_BYTE *)this + v2 + 12) = *(_BYTE *)(v3 + this[196]);
    v4 = this[1];
    v5 = *(_BYTE *)(v4 + this[196]);
    ++v2;
    this[1] = v4 + 1;
    if ( v5 == 10 )
      goto LABEL_6;
  }
  *this = 3;
LABEL_6:
  *((_BYTE *)this + v2 + 12) = 0;
  result = *this;
  if ( v2 > 0 )
  {
    if ( result != 3 )
      *this = sub_559AD0(this);
    return *this;
  }
  return result;
}

