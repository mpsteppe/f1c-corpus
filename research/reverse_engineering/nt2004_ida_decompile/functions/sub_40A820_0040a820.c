int __thiscall sub_40A820(_DWORD *this)
{
  int v2; // esi
  int result; // eax
  _DWORD *v4; // ebp
  char v5; // cl
  void *v6; // ebx

  v2 = *this;
  for ( result = 0; v2; result = 0 )
  {
    v4 = (_DWORD *)v2;
    v5 = *(_BYTE *)(v2 + 12);
    v2 = *(_DWORD *)(v2 + 4);
    if ( v5 )
    {
      v6 = (void *)*v4;
      if ( *v4 )
      {
        sub_459AC0(*v4);
        sub_5BE8AE(v6);
      }
    }
    sub_5BE8AE(v4);
  }
  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[10] = 0;
  this[11] = 0;
  this[17] = 0;
  *((_BYTE *)this + 72) = 0;
  *((_BYTE *)this + 36) = 1;
  *((_BYTE *)this + 73) = 0;
  byte_762AF8 = 0;
  this[20] = 0;
  this[22] = 0;
  return result;
}
